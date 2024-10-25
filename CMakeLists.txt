cmake_minimum_required(VERSION 3.28)
project(miller-sdk VERSION 0.0.1
                   DESCRIPTION "An SDK for Sonic Forces"
                   LANGUAGES CXX ASM_MASM)

# Temporary workaround for bug, see
# - https://discourse.cmake.org/t/building-lib-file-from-asm-cmake-bug/1959
# - https://gitlab.kitware.com/cmake/cmake/-/issues/18889
set(CMAKE_ASM_MASM_CREATE_STATIC_LIBRARY "<CMAKE_AR> /OUT:<TARGET> <LINK_FLAGS> <OBJECTS>")

add_library(miller-sdk STATIC)
target_compile_features(miller-sdk PUBLIC cxx_std_17)

if(DEFINED MILLER_SDK_CUSTOM_EIGEN_TARGET)
    target_link_libraries(miller-sdk PUBLIC ${MILLER_SDK_CUSTOM_EIGEN_TARGET})
else()
    target_link_libraries(miller-sdk PUBLIC eigen)
endif()

target_include_directories(miller-sdk PUBLIC miller-api)
target_sources(miller-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/miller-sdk.h
)

add_subdirectory(vendor EXCLUDE_FROM_ALL)
