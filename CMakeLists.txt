cmake_minimum_required (VERSION 3.7)

include (xtsslib/utility.cmake)

project (opengl_exp)

#compiler requirement
set (CMAKE_CXX_STANDARD 17)

if (UNIX OR APPLE)
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

find_package(OpenGl REQUIRED)

if (WIN32)
add_compile_options( /std:c++latest )
endif (WIN32)

include_directories("${GLFW_ROOT}/include")
include_directories("${PROJECT_SOURCE_DIR}/gl3w/include")
include_directories("${PROJECT_SOURCE_DIR}/xtsslib")
include_directories(${OPENGL_INCLUDE_DIR})


set (INTRO_PROJECT_SOURCES
		${PROJECT_SOURCE_DIR}/intro/gl_headers.hpp
		${PROJECT_SOURCE_DIR}/intro/gl_program.hpp
		${PROJECT_SOURCE_DIR}/intro/gl_shader.hpp
		${PROJECT_SOURCE_DIR}/intro/gl_string.hpp
		${PROJECT_SOURCE_DIR}/intro/gl_vertex_array_object.hpp
		${PROJECT_SOURCE_DIR}/intro/main.cpp
		)

set (GLEW_SOURCES
		${PROJECT_SOURCE_DIR}/gl3w/src/gl3w.c
		)
		
add_executable(intro ${INTRO_PROJECT_SOURCES} ${GLEW_SOURCES})
target_link_libraries(intro ${Glfw_LIBRARIES} ${OPENGL_LIBRARIES})
