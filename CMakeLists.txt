cmake_minimum_required(VERSION 3.28)
project(miller-sdk VERSION 0.0.1
                   DESCRIPTION "An SDK for Sonic Forces"
                   LANGUAGES CXX ASM_MASM)

# Temporary workaround for bug, see
# - https://discourse.cmake.org/t/building-lib-file-from-asm-cmake-bug/1959
# - https://gitlab.kitware.com/cmake/cmake/-/issues/18889
set(CMAKE_ASM_MASM_CREATE_STATIC_LIBRARY "<CMAKE_AR> /OUT:<TARGET> <LINK_FLAGS> <OBJECTS>")

set(UCSL_EIGEN_MATH ON)

include(FetchContent)
FetchContent_Declare(universal-cslib GIT_REPOSITORY https://github.com/angryzor/universal-cslib.git GIT_TAG v1.0.37 FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(universal-cslib)

add_library(miller-sdk STATIC)
target_compile_features(miller-sdk PUBLIC cxx_std_17)
target_link_libraries(miller-sdk PUBLIC universal-cslib)
target_include_directories(miller-sdk PUBLIC miller-api)
target_sources(miller-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/miller-sdk.h
)
