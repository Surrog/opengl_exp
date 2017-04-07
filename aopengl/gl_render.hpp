#ifndef AOPENGL_RENDER_HPP
#define AOPENGL_RENDER_HPP

#include "gl_headers.hpp"
#include "gl_color.hpp"
#include "gl_program.hpp"
#include "gl_shader.hpp"
#include "gl_primitive.hpp"

namespace aopengl
{
	struct render
	{
		static void clear(const color& col)
		{
			glClearBufferfv(GL_COLOR, 0, col.data());
		}

		static void set_program(const program& prog)
		{
			glUseProgram(prog.id);
		}

		static void draw_arrays(const primitive& prim, std::size_t start, std::size_t size)
		{
			glDrawArrays(static_cast<GLenum>(prim), start, size);
		}
	};
}


#endif //!AOPENGL_RENDER_HPP