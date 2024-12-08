cmake_minimum_required(VERSION 3.5)

Project(FireRescueManager) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB APP "app.cpp")
file(GLOB POINT_WGS "src/PointWGS/*.cpp")
file(GLOB FIRE_ENGINE "src/FireEngine/*.cpp")
file(GLOB FIRE_RESCUE_UNIT "src/FireRescueUnit/*.cpp")

add_executable(
    ${PROJECT_NAME} 
    ${APP} 
    ${POINT_WGS}
    ${FIRE_ENGINE}
    ${FIRE_RESCUE_UNIT}
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    src/PointWGS
    src/FireRescueUnit
    src/FireEngine
    src/Accident
    src/State
    src/CentralUnit
)
