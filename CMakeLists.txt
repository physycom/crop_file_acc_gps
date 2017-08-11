cmake_minimum_required (VERSION 3.1)
project (crop_file_acc_gps)
set (CMAKE_CXX_STANDARD 11)

if(MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(crop_file_acc_gps ${CMAKE_SOURCE_DIR}/src/crop_file.cpp)
target_link_libraries(crop_file_acc_gps ${Boost_LIBRARIES}) 

install (TARGETS 
	crop_file_acc_gps  
	DESTINATION ${CMAKE_SOURCE_DIR}/bin/
)

