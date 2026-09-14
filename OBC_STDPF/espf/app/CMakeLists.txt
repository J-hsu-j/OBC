# This cmake sources is only to add the required sources and includes to the OBC target.
#  It does not define the target itself.

list(APPEND OBC_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/payload_communication.c
    ${CMAKE_CURRENT_SOURCE_DIR}/init_service/AppTasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/init_service/DefTasks.c
)

list(APPEND OBC_includes
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/init_service
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/conops)

list(APPEND OBC_libraries conops)

# Make the app sources visible to the parent scope
set(OBC_sources ${OBC_sources} PARENT_SCOPE)
set(OBC_includes ${OBC_includes} PARENT_SCOPE)
set(OBC_libraries ${OBC_libraries} PARENT_SCOPE)
