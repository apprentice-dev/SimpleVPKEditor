#do the actual work of building the executable

cmake_minimum_required(VERSION 3.23)
project(SimpleVPKExtractor)

include(./toolchain.cmake)


set(ENV{this_exec_prefix} ${CMAKE_SOURCE_DIR}/build/wxwidgets) #important: set library path as wx-config makes use of exec_prefix somehow, which is weird...

#logic to find the right wx-config
set(wxconfigfilename "")



if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(wxconfigfilename "msw-unicode")
else()
    set(wxconfigfilename "gtk3-unicode")
endif()

if(NOT wxBUILD_SHARED)
    set(wxconfigfilename ${wxconfigfilename}"-static")
endif()
set(wxconfigfilename ${wxconfigfilename}"-3.3")

#set(ENV{WX_CONFIG} ${CMAKE_SOURCE_DIR}/build/wxwidgets/lib/wx/config/msw-unicode-3.3)

set(wxWidgets_FIND_STYLE "unix")

include(custom_findwxwidgets.cmake)
