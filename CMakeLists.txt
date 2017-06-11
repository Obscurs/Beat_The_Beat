cmake_minimum_required(VERSION 3.5)
project(Beat_The_Beat)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")
set(EXECUTABLE_NAME "Beat_The_Beat")

include_directories(inc)
add_executable(${EXECUTABLE_NAME}
	src/AnimatedSprite.cpp
	src/Animation.cpp
	src/Conductor.cpp
	src/Game.cpp
	src/GameObject.cpp
	src/InputManager.cpp
	src/JoystickInputManager.cpp
	src/KeyboardInputManager.cpp
	src/MagicView.cpp
	src/MenuScene.cpp
	src/Note.cpp
	src/Player.cpp
	src/Quote.cpp
	src/Resources.cpp
	src/Scene.cpp
	src/Stave.cpp
	src/StaveParser.cpp
	src/TestScene.cpp
	src/TextParticle.cpp
	src/main.cpp
)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()
