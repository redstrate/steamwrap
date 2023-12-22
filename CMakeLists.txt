cmake_minimum_required(VERSION 3.10)
project(steamwrap)

set(CMAKE_CXX_STANDARD 17)

add_library(Steamworks IMPORTED SHARED)
set_target_properties(Steamworks PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${STEAMWORKS_INCLUDE_DIR}
        IMPORTED_LOCATION ${STEAMWORKS_LIBRARIES})

add_executable(steamwrap main.cpp)
target_link_libraries(steamwrap PRIVATE Steamworks)
set_target_properties(steamwrap
        PROPERTIES
        BUILD_RPATH "$ORIGIN"
)
