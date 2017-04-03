#ifndef AOPENGL_STRING_HPP
#define AOPENGL_STRING_HPP

#include <string>
#include <astring_view.hpp>
#include <GL\glcorearb.h>

namespace aopengl
{
	using gl_string = std::basic_string<GLchar>;
	using gl_string_view = astd::basic_string_view<GLchar>;
}

#endif //!GL_STRING_HPP