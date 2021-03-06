cmake_minimum_required(VERSION 3.5)
project(Beat_The_Beat)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(SOURCE_FILES Main.cpp Game.cpp Game.h Inputs.cpp Inputs.h  MagicView.cpp MagicView.h Note.cpp Note.h Stave.cpp Stave.h GameObject.cpp GameObject.h Conductor.cpp Conductor.h NoteTextEvent.cpp NoteTextEvent.h Resources.cpp Resources.h Scene.cpp Scene.h Entity.cpp Entity.h Actor.cpp Actor.h entities/Quote.cpp entities/Quote.h entities/Box.cpp entities/Box.h actors/Quote1Actor.cpp actors/Quote1Actor.h entities/Particle.cpp entities/Particle.h actors/Ballos1Actor.cpp actors/Ballos1Actor.h)
set(EXECUTABLE_NAME "Beat_The_Beat")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
