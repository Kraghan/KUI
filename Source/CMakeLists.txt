# Kickback User Interface project
# Author : Kraghan
# Date   : 2016-12-15
cmake_minimum_required(VERSION 3.6)

# Getting sources
file(GLOB_RECURSE SOURCE_FILE *)

# Creating main executable
# Should be only the main file
add_executable(${EXENAME} ${SOURCE_FILE})

# Linking all static libraries
target_link_libraries(${EXENAME} ${SFML_LIB})