cmake_minimum_required (VERSION 3.7)

include (xtsslib/utility.cmake)

project (opengl_exp)

#compiler requirement
set (CMAKE_CXX_STANDARD 14)

if (${UNIX} OR ${APPLE})
	find_package(glfw REQUIRED)
else ()
	set(GLFW_ROOT ${PROJECT_SOURCE_DIR} CACHE STRING "The root directory of glfw")
	set(GLFW_ROOT_BIN ${PROJECT_SOURCE_DIR} CACHE STRING "The root directory of glfw binary")
	assert_exists("${GLFW_ROOT}/include") 
	assert_exists("${GLFW_ROOT_BIN}/src")
	set (Glfw_LIBRARIES 
	debug "${GLFW_ROOT_BIN}/src/Debug/glfw3.lib" 
	optimized "${GLFW_ROOT_BIN}/src/Release/glfw3.lib")
endif()

include_directories("${GLFW_ROOT}/include")

set (INTRO_PROJECT_SOURCES
		${PROJECT_SOURCE_DIR}/intro/main.cpp
		)
		
add_executable(intro ${INTRO_PROJECT_SOURCES})
target_link_libraries(intro ${Glfw_LIBRARIES})