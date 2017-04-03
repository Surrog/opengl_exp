#ifndef AOPENGL_PROGRAM_HPP
#define AOPENGL_PROGRAM_HPP

#include "gl_headers.hpp"

namespace aopengl
{
	struct program
	{
		GLint id;

		program() : id(0) {}

		template <typename CONTAINER>
		program(const CONTAINER& container_shader)
		{
			id = glCreateProgram();

			for (auto& sha : container_shader)
			{
				glAttachShader(id, sha.id);
			}

			glLinkProgram(id);
		}

		program(const program&) = delete;
		program& operator=(const program&) = delete;

		program(program&& orig)
		{
			id = orig.id;
			orig.id = 0;
		}
		program& operator=(program&& orig)
		{
			if (this != &orig)
			{
				id = orig.id;
				orig.id = 0;
			}
			return *this;
		}

		~program()
		{
			if (id != 0)
			{
				glDeleteProgram(id);
			}
		}
	};
}

#endif //!AOPENGL_PROGRAM_HPP