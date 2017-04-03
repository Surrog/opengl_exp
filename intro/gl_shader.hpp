#ifndef AOPENGL_SHADER_HPP
#define AOPENGL_SHADER_HPP

#include "gl_string.hpp"
#include <gl\glcorearb.h>
#include <gl\GL.h>
#include "GL\gl3w.h"

namespace aopengl
{
	struct shader 
	{
		enum SHADER_TYPE : GLenum
		{
			VERTEX = GL_VERTEX_SHADER
			, FRAGMENT = GL_FRAGMENT_SHADER
		};

		GLuint id;

		shader() : id(0) {}

		shader(const shader&) = delete;
		shader& operator=(const shader&) = delete;

		shader(shader&& orig)
		{
			id = orig.id;
			orig.id = 0;
		}
		shader& operator=(shader&& orig)
		{
			id = orig.id;
			orig.id = 0;
		}

		shader(gl_string_view value, const SHADER_TYPE& type)
		{
			id = glCreateShader(type);
			assert(id != 0);
			GLint size = static_cast<GLint>(value.size());
			glShaderSource(id, 1, &value.data(), &size);
			glCompileShader(id);
		}

		~shader()
		{
			if (id != 0)
			{
				glDeleteShader(id);
			}
		}
	};
}

#endif //!AOPENGL_SHADER_HPP