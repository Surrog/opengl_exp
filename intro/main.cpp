
#include <iostream>
#include <string>
#include <cassert>
#include <array>

#include "gl_headers.hpp"

#include "GLFW\glfw3.h"
#include "GLFW\glfw3native.h"

#include "gl_string.hpp"
#include "gl_shader.hpp"
#include "gl_program.hpp"

#include <string_view>

using namespace std::string_literals;

constexpr static const char * basic_vertex_shader_source = R"(
#version 450 core

void main(void)
{
	gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
}
)";

constexpr static const GLchar * basic_fragment_shader_source = R"(
#version 450 core

out vec4 color;
void main(void)
{
	color = vec4(0.0, 0.8, 1.0, 1.0);
}
)";



int main()
{
	std::array<aopengl::shader, 2> shaders{
		aopengl::shader(basic_vertex_shader_source, aopengl::shader::VERTEX)
		, aopengl::shader(basic_fragment_shader_source, aopengl::shader::FRAGMENT)
	};

	aopengl::program prog(shaders);

	return 0;
}