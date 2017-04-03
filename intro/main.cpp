
#include <iostream>
#include <string>
#include <cassert>


#include <Windows.h>
#include <gl\GL.h>
#include <gl\GLU.h>

#include "GL\gl3w.h"

#include "GLFW\glfw3.h"
#include "GLFW\glfw3native.h"

#include "gl_string.hpp"
#include "gl_shader.hpp"

using namespace std::string_literals;

constexpr static char * basic_vertex_shader_source = R"(
#version 450 core

void main(void)
{
	gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
}
)";

constexpr static const GLchar const * basic_fragment_shader_source = R"(
#version 450 core

out vec4 color;
void main(void)
{
	color = vec4(0.0, 0.8, 1.0, 1.0);
}
)";



int main()
{
	std::cout << "hello world" << std::endl;

	return 0;
}