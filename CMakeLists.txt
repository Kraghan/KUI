# Kickback User Interface project
# Author : Kraghan
# Date   : 2016-12-15
cmake_minimum_required(VERSION 3.6)
project(KUI)

# Files and Directories
set(PROJECT_BIN bin)
set(PROJECT_RES res)
set(PROJECT_CMAKE_CONFIG CMakeConfig.txt)

set(DEBUG_FLAGS "-Wall -g")
set(RELEASE_FLAGS "-O2")
set(COMPILER_FLAGS "-std=c++11")

# Build script

# Platform check
if(WIN32)
    set(PLATEFORM WINDOWS)
elseif(UNIX)
    set(PLATEFORM UNIX)
else()
    set(PLATEFORM NOT_SUPPORTED)
    message(FATAL_ERROR "This plateform is not supported")
endif()

# Project structure check
if(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${PROJECT_BIN}/)
    file(MAKE_DIRECTORY ${PROJECT_BIN})
    message(WARNING "Bin directory created")

elseif(NOT IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${PROJECT_RES}/)
    file(MAKE_DIRECTORY ${PROJECT_RES})
    message(WARNING "Res directory created")
endif()

# CMakeConfig file
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG})
    file(WRITE ${CMAKE_SOURCE_DIR}/${PROJECT_CMAKE_CONFIG} "C://..//SFML | /home/../SFML")
    message(WARNING "CMakeConfig.txt file created, please fill it")
endif()

# Writting default message
message(STATUS "Plateform : ${PLATEFORM}")

# Project settings
set(CMAKE_CXX_FLAGS_DEBUG "${COMPILER_FLAGS} ${DEBUG_FLAGS}" CACHE STRING "debug flags" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${COMPILER_FLAGS} ${RELEASE_FLAGS}" CACHE STRING "release flags" FORCE)

# Getting properties
file(STRINGS "CMakeConfig.txt" SFML_PATH)
message(STATUS "SFML path : ${SFML_PATH}")

# Global useful variables
set(EXENAME_RELEASE KUI)
set(EXENAME_DEBUG KUI_DBG)
set(COMPILATION_MODE RELEASE)
if(NOT COMPILATION_MODE)
    message(STATUS "(Warning) : No argument specified, debug mode activated")
    set(COMPILATION_MODE "DEBUG")
endif()

if(${COMPILATION_MODE} STREQUAL "RELEASE")
    message(STATUS "Compilation mode : release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "compile flags" FORCE)

    if(PLATEFORM STREQUAL "WINDOWS")
        list(APPEND SFML_RELEASE_LIB
                "${SFML_PATH}/lib/libsfml-graphics.a"
                "${SFML_PATH}/lib/libsfml-window.a"
                "${SFML_PATH}/lib/libsfml-system.a"
                "${SFML_PATH}/lib/libsfml-audio.a")

    elseif(PLATEFORM STREQUAL "UNIX")
        list(APPEND SFML_RELEASE_LIB
                "${SFML_PATH}/lib/libsfml-graphics.so"
                "${SFML_PATH}/lib/libsfml-window.so"
                "${SFML_PATH}/lib/libsfml-system.so"
                "${SFML_PATH}/lib/libsfml-audio.so")
    endif()

    set(EXENAME ${EXENAME_RELEASE})
    set(SFML_LIB "${SFML_RELEASE_LIB}")
    message(STATUS "Executable name : ${EXENAME}")

else()
    message(STATUS "Compilation mode : DEBUG MODE")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "compile flags" FORCE)

    if(PLATEFORM STREQUAL "WINDOWS")
        list(APPEND SFML_DEBUG_LIB
                "${SFML_PATH}/lib/libsfml-graphics-d.a"
                "${SFML_PATH}/lib/libsfml-window-d.a"
                "${SFML_PATH}/lib/libsfml-system-d.a"
                "${SFML_PATH}/lib/libsfml-audio-d.a")

    elseif(PLATEFORM STREQUAL "UNIX")
        list(APPEND SFML_DEBUG_LIB
                "${SFML_PATH}/lib/libsfml-graphics.so"
                "${SFML_PATH}/lib/libsfml-window.so"
                "${SFML_PATH}/lib/libsfml-system.so"
                "${SFML_PATH}/lib/libsfml-audio.so")
    endif()

    set(EXENAME ${EXENAME_DEBUG})
    set(SFML_LIB "${SFML_DEBUG_LIB}")
    message(STATUS "Executable name : ${EXENAME}")
endif()

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
message(STATUS "Output  path : ${CMAKE_SOURCE_DIR}/bin")

# include search path
include_directories(
        include
        ${SFML_PATH}/include)

# Adding sub directories
# Sources directories
add_subdirectory(Source)