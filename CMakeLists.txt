cmake_minimum_required(VERSION 3.5)

Project(FireRescueSimulation) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

file(GLOB APP "app.cpp")
file(GLOB POINT_WGS "src/PointWGS/*.cpp")
file(GLOB FIRE_ENGINE "src/FireEngine/*.cpp")
file(GLOB FIRE_RESCUE_UNIT "src/FireRescueUnit/*.cpp")
file(GLOB CENTRAL_UNIT "src/CentralUnit/*.cpp")
file(GLOB FIRE_ENGINE_OBSERVER "src/Observer/*.cpp")
file(GLOB SIMULATION "src/Simulation/*.cpp")
file(GLOB ACCIDENT "src/Accident/*.cpp")

add_executable(
    ${PROJECT_NAME} 
    ${APP} 
    ${POINT_WGS}
    ${FIRE_ENGINE}
    ${FIRE_RESCUE_UNIT}
    ${FIRE_ENGINE_OBSERVER}
    ${ACCIDENT}
    ${CENTRAL_UNIT}
    ${SIMULATION}
)

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    src/PointWGS
    src/FireRescueUnit
    src/FireEngine
    src/Accident
    src/CentralUnit
    src/State
    src/Observer
    src/Simulation
    src/Strategy
    src/Container
)
