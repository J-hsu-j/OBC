'''
    es_sys_config_configs.py

    (C) Copyright Endurosat

    Contents and presentations are protected world-wide.
    Any kind of using, copying etc. is prohibited without prior permission.
    All rights, incl. industrial property rights, are reserved.
'''

from enum import Enum
from typing import Union
import typer


class SysMod(Enum):
    EPS_I = "EPS I"
    EPS_II = "EPS II"
    EPS_III = "EPS III"
    EPS_M = "EPS M (third party)"
    ES_ADCS = "ES ADCS"
    CUBE_ADCS_GEN1 = "Cube ADCS Gen1"
    GNSS = "GNSS"
    SX_BAND = "S/X Band"
    PANELS = "Solar Panels"
    CUBE_ADCS_GEN2 = "Cube ADCS Gen2"


class ConfigVariant:
    '''Represents a single variant of a hardware module'''

    def __init__(self, module: SysMod, token: str, byte_position: int, is_binary: bool) -> None:
        self.module = module
        self.name = module.value
        self.token = token
        self.byte_position = byte_position
        self.is_binary = is_binary

    def check_active(self, token: str) -> bool:
        '''Determine whether the particular variant is active'''

        if self.is_binary and token == "y":
            # The module has a single variant and it is active
            return True

        if token == self.token:
            # The module has multiple variants and this particular one is active
            return True

        return False


class ConfigModule:
    '''Represents a hardware module, e.g. EPS, ADCS, etc.'''

    def __init__(self, name: str, prompt: str, variants: list[ConfigVariant]) -> None:
        self.name = name
        self.prompt = prompt
        self.variants = variants

    def get_prompt(self) -> str:
        '''Get the user prompt string for a module, containing the tokens of all the variants.'''

        if self.prompt is not None and self.prompt.strip() != "":
            return self.prompt

        if len(self.variants) == 1 and self.variants[0].is_binary:
            return f"{self.name} active, yes or no (y/n): "

        return f"{', '.join([variant.name for variant in self.variants])} or none ({'/'.join([variant.token for variant in self.variants])}/0): "

    def get_variant_tokens(self) -> list[str]:
        '''Get a list of the tokens for each of the module's variants. Used in validation of the user input.'''

        if len(self.variants) == 1 and self.variants[0].is_binary:
            # Modules with a single variant have only have the options to be active or inactive
            return ["y", "n"]

        variants = [variant.token for variant in self.variants]
        # For all modules with multiple variants there is the option that none of the variants is active
        variants.append("0")

        return variants


class ConfigData:
    '''Represents the collection of hardware modules and their variants as well as the layout in memory of their activation flags.'''

    def __init__(self, version: bytes, modules: list[ConfigModule], compat_func) -> None:
        self.version = version
        self.modules = modules
        self.modules_compatible = compat_func

    def is_valid(self) -> bool:
        '''Check the validity of the configuration. Using this method outside ConfigDataRegistry should not be needed.'''

        positions = []

        # Collect the byte positions of all variants of all modules
        for module in self.modules:
            for variant in module.variants:
                positions.append(variant.byte_position)

        # If all byte positions are properly configured, a sorted list of them should contain
        # an arithmetic progression with difference of 1 between two consecutive members
        idx = 0
        sorted_pos = sorted(positions)
        while idx < len(sorted_pos) - 1:
            if sorted_pos[idx] + 1 != sorted_pos[idx + 1]:
                return False
            idx += 1

        return True

    def get_variant_at_position(self, pos: int) -> Union[ConfigVariant, None]:
        '''Get the object of the variant which is related to the specified position in the configuration bytes'''

        for module in self.modules:
            for variant in module.variants:
                if variant.byte_position == pos:
                    return variant

        # We should not get here
        raise IndexError(f"No variant found for position {pos}")

    def get_num_cfg_bytes(self):
        '''Get the number of module configuration bytes'''

        result = 0

        for module in self.modules:
            for _ in module.variants:
                result += 1

        return result


def comp_func1(modules: dict[str, bool]) -> bool:
    '''Verify the modules compatibility'''

    # ES ADCS is not supported with OBC v3.0.2
    if modules[SysMod.ES_ADCS]:
        typer.secho("INFO: ES ADCS is not supported with the OBC firmware v3.0.2", fg=typer.colors.YELLOW)

    # ES ADCS only works with the EPS I
    if modules[SysMod.ES_ADCS] and not modules[SysMod.EPS_I]:
        typer.secho('ATTENTION! ES ADCS needs to have the EPS I', fg=typer.colors.YELLOW)
        return False

    # Only one ADCS can be active at the same time
    b_adcs_valid = True
    if modules[SysMod.ES_ADCS] and modules[SysMod.CUBE_ADCS_GEN1]:
        b_adcs_valid = False

    if not b_adcs_valid:
        typer.secho('ATTENTION! Only one ADCS module can be active at a time', fg=typer.colors.YELLOW)
        return False

    # One EPS but at least one
    b_eps_valid = True
    if modules[SysMod.EPS_I]:
        if modules[SysMod.EPS_II] or modules[SysMod.EPS_M]:
            b_eps_valid = False
    else:
        if modules[SysMod.EPS_II] and modules[SysMod.EPS_M]:
            b_eps_valid = False
        elif not (modules[SysMod.EPS_II] or modules[SysMod.EPS_M]):
            b_eps_valid = False

    if not b_eps_valid:
        typer.secho('ATTENTION! Only one EPS module can be active at a time. But at least one.', fg=typer.colors.YELLOW)
        return False

    return True


def comp_func2(modules: dict[str, bool]) -> bool:
    '''Verify the modules compatibility'''

    # ES ADCS is not supported with OBC v3.0.2
    if modules[SysMod.ES_ADCS]:
        typer.secho("INFO: ES ADCS is not supported with the OBC firmware v3.0.2", fg=typer.colors.YELLOW)

    # ES ADCS only works with the EPS I
    if modules[SysMod.ES_ADCS] and not modules[SysMod.EPS_I]:
        typer.secho('ATTENTION! ES ADCS needs to have the EPS I', fg=typer.colors.YELLOW)
        return False

    # Only one ADCS can be active at the same time
    b_adcs_valid = True
    if modules[SysMod.ES_ADCS]:
        if modules[SysMod.CUBE_ADCS_GEN1] or modules[SysMod.CUBE_ADCS_GEN2]:
            b_adcs_valid = False
    elif modules[SysMod.CUBE_ADCS_GEN1] and modules[SysMod.CUBE_ADCS_GEN2]:
        b_adcs_valid = False

    if not b_adcs_valid:
        typer.secho('ATTENTION! Only one ADCS module can be active at a time', fg=typer.colors.YELLOW)
        return False

    # One EPS but at least one
    b_eps_valid = True
    if modules[SysMod.EPS_I]:
        if modules[SysMod.EPS_II] or modules[SysMod.EPS_M]:
            b_eps_valid = False
    else:
        if modules[SysMod.EPS_II] and modules[SysMod.EPS_M]:
            b_eps_valid = False
        elif not (modules[SysMod.EPS_II] or modules[SysMod.EPS_M]):
            b_eps_valid = False

    if not b_eps_valid:
        typer.secho('ATTENTION! Only one EPS module can be active at a time. But at least one.', fg=typer.colors.YELLOW)
        return False

    return True


def comp_func3(modules: dict[str, bool]) -> bool:
    '''Verify the modules compatibility'''

    # Only one ADCS can be active at the same time
    if modules[SysMod.CUBE_ADCS_GEN1] and modules[SysMod.CUBE_ADCS_GEN2]:
        typer.secho('ATTENTION! Only one ADCS module can be active at a time', fg=typer.colors.YELLOW)
        return False

    # One EPS but at least one
    b_eps_valid = True
    if modules[SysMod.EPS_I]:
        if modules[SysMod.EPS_II] or modules[SysMod.EPS_M]:
            b_eps_valid = False
    else:
        if modules[SysMod.EPS_II] and modules[SysMod.EPS_M]:
            b_eps_valid = False
        elif not (modules[SysMod.EPS_II] or modules[SysMod.EPS_M]):
            b_eps_valid = False

    if not b_eps_valid:
        typer.secho('ATTENTION! Only one EPS module can be active at a time. But at least one.', fg=typer.colors.YELLOW)
        return False

    return True

def comp_func4(modules: dict[str, bool]) -> bool:
    '''Verify the modules compatibility'''

    # Only one ADCS can be active at the same time
    if modules[SysMod.CUBE_ADCS_GEN1] and modules[SysMod.CUBE_ADCS_GEN2]:
        typer.secho('ATTENTION! Only one ADCS module can be active at a time', fg=typer.colors.YELLOW)
        return False

    # One EPS but at least one
    b_eps_valid = True
    if modules[SysMod.EPS_I]:
        if modules[SysMod.EPS_II] or modules[SysMod.EPS_III] or modules[SysMod.EPS_M]:
            b_eps_valid = False
    else:
        if modules[SysMod.EPS_II]:
            if modules[SysMod.EPS_III] or modules[SysMod.EPS_M]:
                b_eps_valid = False
        else:
            if modules[SysMod.EPS_III]:
                if (modules[SysMod.EPS_M]):
                    b_eps_valid = False
            else:
                # None of the EPS modules is active, but we must have atleast one
                typer.secho('ATTENTION! No EPS module has been chosen. You must choose at least one.', fg=typer.colors.YELLOW)
                return False

    if not b_eps_valid:
        typer.secho('ATTENTION! Only one EPS module can be active at a time. But at least one.', fg=typer.colors.YELLOW)
        return False

    return True


config1 = ConfigData(
    b'\x00\x01',
    [
        ConfigModule(
            "EPS",
            "",
            [
                ConfigVariant(SysMod.EPS_I, "1", 0, False),
                ConfigVariant(SysMod.EPS_II, "2", 1, False),
                ConfigVariant(SysMod.EPS_M, "m", 2, False),
            ],
        ),
        ConfigModule(
            "ADCS",
            "",
            [
                ConfigVariant(SysMod.ES_ADCS, "e", 3, True),
                ConfigVariant(SysMod.CUBE_ADCS_GEN1, "c", 4, True),
            ],
        ),
        ConfigModule("GNSS", "", [ConfigVariant(SysMod.GNSS, "", 5, True)]),
        ConfigModule("Solar Panels", "", [ConfigVariant(SysMod.PANELS, "", 7, True)]),
        ConfigModule("S/X Band", "", [ConfigVariant(SysMod.SX_BAND, "", 6, True)]),
    ],
    comp_func1,
)

config2 = ConfigData(
    b'\x00\x02',
    [
        ConfigModule(
            "EPS",
            "",
            [
                ConfigVariant(SysMod.EPS_I, "1", 0, False),
                ConfigVariant(SysMod.EPS_II, "2", 1, False),
                ConfigVariant(SysMod.EPS_M, "m", 2, False),
            ],
        ),
        ConfigModule(
            "ADCS",
            "",
            [
                ConfigVariant(SysMod.ES_ADCS, "e", 3, False),
                ConfigVariant(SysMod.CUBE_ADCS_GEN1, "1", 4, False),
                ConfigVariant(SysMod.CUBE_ADCS_GEN2, "2", 8, False),
            ],
        ),
        ConfigModule("GNSS", "", [ConfigVariant(SysMod.GNSS, "", 5, True)]),
        ConfigModule("Solar Panels", "", [ConfigVariant(SysMod.PANELS, "", 7, True)]),
        ConfigModule("S/X Band", "", [ConfigVariant(SysMod.SX_BAND, "", 6, True)]),
    ],
    comp_func2,
)

config3 = ConfigData(
    b'\x00\x03',
    [
        ConfigModule(
            "EPS",
            "",
            [
                ConfigVariant(SysMod.EPS_I, "1", 0, False),
                ConfigVariant(SysMod.EPS_II, "2", 1, False),
                ConfigVariant(SysMod.EPS_M, "m", 2, False),
            ],
        ),
        ConfigModule(
            "ADCS",
            "\nINFO! Choose 0 for ADCS if your build has ES ADCS.\nCubeADCS Gen1, CubeADCS Gen2 or none (1/2/0):",
            [
                ConfigVariant(SysMod.CUBE_ADCS_GEN1, "1", 3, False),
                ConfigVariant(SysMod.CUBE_ADCS_GEN2, "2", 7, False),
            ],
        ),
        ConfigModule("GNSS", "", [ConfigVariant(SysMod.GNSS, "", 4, True)]),
        ConfigModule("Solar Panels", "", [ConfigVariant(SysMod.PANELS, "", 6, True)]),
        ConfigModule("S/X Band", "", [ConfigVariant(SysMod.SX_BAND, "", 5, True)]),
    ],
    comp_func3,
)

config4 = ConfigData(
    b'\x00\x04',
    [
        ConfigModule(
            "EPS",
            "",
            [
                ConfigVariant(SysMod.EPS_I, "1", 0, False),
                ConfigVariant(SysMod.EPS_II, "2", 1, False),
                ConfigVariant(SysMod.EPS_III, "3", 8, False),
                ConfigVariant(SysMod.EPS_M, "m", 2, False),
            ],
        ),
        ConfigModule(
            "ADCS",
            "\nINFO! Choose 0 for ADCS if your build has ES ADCS.\nCubeADCS Gen1, CubeADCS Gen2 or none (1/2/0):",
            [
                ConfigVariant(SysMod.CUBE_ADCS_GEN1, "1", 3, False),
                ConfigVariant(SysMod.CUBE_ADCS_GEN2, "2", 7, False),
            ],
        ),
        ConfigModule("GNSS", "", [ConfigVariant(SysMod.GNSS, "", 4, True)]),
        ConfigModule("Solar Panels", "", [ConfigVariant(SysMod.PANELS, "", 6, True)]),
        ConfigModule("S/X Band", "", [ConfigVariant(SysMod.SX_BAND, "", 5, True)]),
    ],
    comp_func4,
)


class ObcVersion:
    '''Represents a version with the OBC. Provides validity checks and comparison metods.'''

    def __init__(self, version: str) -> None:
        try:
            version_elements = version.split(".")
            if len(version_elements) == 3:
                self.major = int(version_elements[0])
                self.minor = int(version_elements[1])
                self.patch = int(version_elements[2])
            else:
                raise IndexError
        except (IndexError, TypeError):
            self.major = 0
            self.minor = 0
            self.patch = 0

    def is_valid(self) -> bool:
        '''Verifies that the OBC version object is properly constructed from a string version input'''

        return (self.major > 0) or (self.minor > 0) or (self.patch > 0)

    def at_least(self, other: 'ObcVersion') -> bool:
        '''Implements greater than or equal comparison of the ObcVersion with another one.'''

        if self.major == other.major and self.minor == other.minor and self.patch == other.patch:
            return True
        if self.major > other.major:
            return True
        if self.major == other.major and self.minor > other.minor:
            return True
        if self.minor == other.minor and self.patch > other.patch:
            return True

        return False


class ConfigDataRegistry:
    '''Provides access to all configuration data instances.'''

    configurations = [config1, config2, config3, config4]

    @staticmethod
    def get_config_for_obc_version(obc_version: str) -> Union[ConfigData, None]:
        '''Get a reference to the configuration data object corresponding to a given OBC version.'''

        obc_ver = ObcVersion(obc_version)

        if obc_ver.is_valid():
            if obc_ver.at_least(ObcVersion("7.1.0")):
                result = config4
            elif obc_ver.at_least(ObcVersion("6.5.0")):
                result = config3
            elif obc_ver.at_least(ObcVersion("5.0.0")):
                result = config2
            else:
                result = config1  # This assignment is currently redundant, but is kept for robustness
        else:
            # Return the first configuration as default
            typer.secho(
                "WARNING! Invalid OBC version provided. Default configuration layout shall be used.",
                fg=typer.colors.YELLOW,
            )
            result = config1

        if result.is_valid():
            return result

        return None

    @staticmethod
    def get_config_for_layout_version(layout_version: int) -> Union[ConfigData, None]:
        '''Get a reference to the configuration data object corresponding to a given configuration data version.'''

        # Use the first configuration as default.
        result = ConfigDataRegistry.configurations[0]
        for config in ConfigDataRegistry.configurations:
            if int.from_bytes(config.version, "big") == layout_version:
                result = config

        if result.is_valid():
            return result

        return None
