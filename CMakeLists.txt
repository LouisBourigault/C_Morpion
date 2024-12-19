# créer le 19/12/24 
# nom / prénom créateur : Joyez Baptiste 
# création d'un ficheir cmake pour le projet morpion en c
# CMake configuration for the Morpion project
# Created on 19/12/24 by Joyez Baptiste

cmake_minimum_required(VERSION 3.10)
project(MorpionProject VERSION 1.0 LANGUAGES C)

# Define the CONFIG_TEXTUI preprocessor macro
add_definitions(-DCONFIG_TEXTUI)

# Set the C standard to C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the source files
add_executable(MorpionProject main.c)

# Include directories (if any)
# target_include_directories(MorpionProject PRIVATE include)

# Link libraries (if any)
# target_link_libraries(MorpionProject PRIVATE some_library)

# Enable compiler warnings
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(MorpionProject PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Installation rules (optional)
# install(TARGETS MorpionProject DESTINATION bin)