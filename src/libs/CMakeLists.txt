cmake_minimum_required(VERSION 3.23)
project(SimpleVPKLib #[[VERSION 1.0]]) #library will not be tracked versions unless the main one starts getting tracked idk what am i doing but yeah im just yapping

add_library(SimpleVPKLib OBJECT)

target_sources(SimpleVPKLib PRIVATE vpklib/main.cpp)

#end



