#build the lib library

cmake_minimum_required(VERSION 3.23)

project(SimpleVPKExtractor_build) #we are making a utility cmake script to build the libs first.. its not our project.


if(NOT DISABLE_CROSS_COMPILE)
set(HEHE_TOOLCHAIN_PREFIX x86_64-w64-mingw32)

set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_CXX_COMPILER /usr/bin/${HEHE_TOOLCHAIN_PREFIX}-g++)
set(CMAKE_C_COMPILER   /usr/bin/${HEHE_TOOLCHAIN_PREFIX}-gcc)

set(CMAKE_FIND_ROOT_PATH /usr/${HEHE_TOOLCHAIN_PREFIX})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
endif()




add_subdirectory(../wxwidgets .)

#[[
include(ProcessorCount)

ProcessorCount(NUM_LOGICAL_CORES)

math(EXPR NUM_HALF_LOGICAL_CORES "${NUM_LOGICAL_CORES} / 2")



if(DEFINED USE_LOGICAL_CORES)
	message("generator concluded. Now running makefile with ${USE_LOGICAL_CORES}")
	execute_process(COMMAND make "-j${USE_LOGICAL_CORES}" WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
else()
	message("generator concluded. Now running makefile with ${NUM_HALF_LOGICAL_CORES}")
	execute_process(COMMAND make "-j${NUM_HALF_LOGICAL_CORES}" WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
]]


##message(${wxWidgets_INCLUDE_DIRS})


##message(${CMAKE_HOST_SYSTEM_NAME})

##add_subdirectory(./wxwidgets)


##set(SOURCE_FILES "main.cpp")

##add_executable(main)


##target_sources(main PRIVATE ${SOURCE_FILES})


