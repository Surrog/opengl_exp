#ifndef AOPENGL_PRIMITIVE_HPP
#define AOPENGL_PRIMITIVE_HPP

#include "gl_headers.hpp"

namespace aopengl
{
	enum class primitive : GLenum
	{
		Point = GL_POINT
		, Line = GL_LINE
		, Triangle = GL_TRIANGLES
	};
}


#endif //!AOPENGL_PRIMITIVE_HPP