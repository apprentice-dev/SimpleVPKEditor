#do the actual work of building the executable

cmake_minimum_required(VERSION 3.23)
project(SimpleVPKExtractor)

include(./toolchain.cmake)


set(ENV{this_exec_prefix} ${CMAKE_SOURCE_DIR}/build) #important: set library path as wx-config makes use of exec_prefix somehow, which is weird...
set(ENV{this_prefix} ${CMAKE_SOURCE_DIR}/wxwidgets)

#logic to find the right wx-config
set(wxconfigfilename "")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(wxconfigfilename msw-unicode)
else()
    set(wxconfigfilename gtk3-unicode)
endif()

if(NOT wxBUILD_SHARED)
    set(wxconfigfilename ${wxconfigfilename}-static)
endif()
set(wxconfigfilename ${wxconfigfilename}-3.3)

message("using config " ${wxconfigfilename})


#set(ENV{WX_CONFIG} ${CMAKE_S\OURCE_DIR}/build//lib/wx/config/msw-unicode-3.3)
set(ENV{WX_CONFIG} ${CMAKE_SOURCE_DIR}/build/lib/wx/config/${wxconfigfilename})

set(wxWidgets_FIND_STYLE "unix")

include(custom_findwxwidgets.cmake)

add_executable(test)

target_include_directories(test PUBLIC ${wxWidgets_INCLUDE_DIRS})

target_link_libraries(test PRIVATE ${wxWidgets_LIBRARIES})

target_sources(test PRIVATE ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/windows/mainwindow.cpp PUBLIC FILE_SET HEADERS FILES ${CMAKE_SOURCE_DIR}/src/windows/mainwindow.hpp)

#target_link_options(test PUBLIC ${wxWidgets_LIBRARIES})



#[[


target_link_directories(test PUBLIC ${wxWidgets_LIBRARY_DIRS})

target_include_directories(test PUBLIC ${wxWidgets_INCLUDE_DIRS})
]]
