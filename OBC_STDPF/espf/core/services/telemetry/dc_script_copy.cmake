#
# This file ensures that the generated data cache structure sizes can fit at least individually in
# the configured telemetry queue. If that check is violated, the build will be interrupted. 
#

cmake_path(SET dc_py_file_path "${PROJECT_ROOT}/config/datacache/datacache.py")
cmake_path(SET tlm_scripts_dir "${PROJECT_SOURCE_DIR}/scripts")

get_filename_component(py_file_name ${dc_py_file_path} NAME)

add_custom_command(
	OUTPUT "${tlm_scripts_dir}/${py_file_name}"
	COMMAND ${CMAKE_COMMAND} -E copy ${dc_py_file_path} "${tlm_scripts_dir}/${py_file_name}"
	DEPENDS "${dc_py_file_path}"
)

add_custom_target(dc_script_copy ALL DEPENDS "${tlm_scripts_dir}/${py_file_name}")
add_dependencies(dc_script_copy datacache)

