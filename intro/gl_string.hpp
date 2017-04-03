#ifndef AOPENGL_STRING_HPP
#define AOPENGL_STRING_HPP

#include <string>
#include <astring_view.hpp>
#include "gl_headers.hpp"

namespace aopengl
{
	using string = std::basic_string<GLchar>;
	using string_view = astd::basic_string_view<GLchar>;
}

#endif //!GL_STRING_HPP