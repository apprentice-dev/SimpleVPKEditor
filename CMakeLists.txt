cmake_minimum_required(VERSION 3.23)

project(SimpleVPKExtractor)

set(SOURCE_FILES "main.cpp")

add_executable(main)

target_sources(main PRIVATE ${SOURCE_FILES})


