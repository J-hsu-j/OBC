# hsmgen

This script is used to generate C source code from a YAML hierarchical state machine model description. The generated code can be used as a configuration and user layer in combination with the EnduroSat libhsm library.

### Dependencies
The project relies on Poetry as a package manager. Check [here](https://python-poetry.org/docs/#installation) on installation details and then follow the next instructions to work with the project.

### Building the project
```bash
poetry build
```

### Using the project in a virtual environment
```bash
poetry shell
poetry install
py -m hsmgen
```

### Installing the project to your system with all dependencies
After the build step, `poetry` will create a `dist` folder under the project root. Perform the following steps to install (file names are exemplary):
```bash
cd dist
pip install hsmgen-x.x.x-py3-none-any.whl
```
After this step, you can run the script from anywhere by typing:
```bash
py -m hsmgen
```

### Publishing the repository to EnduroSat PyPi server
First, configure your PyPi credentials and then publish the module:
```bash
poetry config http-basic.endurosat-pypi <username> <password>
poetry publish --build --repository endurosat-pypi
```