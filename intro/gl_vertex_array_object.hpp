#ifndef AOPENGL_VERTEX_ARRAY_OBJECT
#define AOPENGL_VERTEX_ARRAY_OBJECT

#include "gl_headers.hpp"

namespace aopengl
{
	struct vertex_array
	{
		GLuint id;

		vertex_array()
		{
			glCreateVertexArrays(1, &id);
		}

		vertex_array(const vertex_array&) = delete;
		vertex_array& operator=(const vertex_array&) = delete;

		vertex_array(vertex_array&& orig) { id = orig.id; orig.id = 0; }
		vertex_array& operator=(vertex_array&& orig) { id = orig.id; orig.id = 0; return *this; }


		~vertex_array()
		{
			glDeleteVertexArrays(1, &id);
		}
	};

	void bind(const vertex_array& arr)
	{
		glBindVertexArray(arr.id);
	}
}

#endif //!AOPENGL_VERTEX_ARRAY_OBJECT
