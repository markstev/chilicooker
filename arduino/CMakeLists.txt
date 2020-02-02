#=============================================================================#
# Author: MarkStevens
# Date:   2019/09/15
#                                                                             #
# Description: Chili Cooking in Berlin                                        #
#                                                                             #
#=============================================================================#

cmake_minimum_required(VERSION 2.8)
#====================================================================#
#  Settings                                                          #
#====================================================================#

set(HOME_DIR /home/mark) # Replace this!!
set(CMAKE_SOURCE_DIR ${HOME_DIR}/chilicooker/arduino) # Source dir. 
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/../arduino-cmake/cmake/ArduinoToolchain.cmake) # Arduino Toolchain
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")

project(ChiliCooker C CXX)
#set(ARDUINO_SDK /usr/share/arduino-1.0.6)
#set(ARDUINO_SDK /usr/share/arduino)
set(ARDUINO_SDK ${HOME_DIR}/Downloads/arduino-1.6.9)
set(FIRMWARE_NAME chili_cooker)


set(${FIRMWARE_NAME}_BOARD nano)               # Arduino Target board
set(${FIRMWARE_NAME}_SRCS  chili_heater.cc)

set(${FIRMWARE_NAME}_PORT /dev/ttyUSB0)            # Serial upload port
link_directories(${CMAKE_SOURCE_DIR})
set(${FIRMWARE_NAME}_NO_AUTOLIBS false)

#====================================================================#
#  Target generation                                                 #
#====================================================================#
generate_arduino_firmware(${FIRMWARE_NAME})
