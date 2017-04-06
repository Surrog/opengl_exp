#ifndef AOPENGL_COLOR_HPP
#define AOPENGL_COLOR_HPP

#include <array>
#include "gl_headers.hpp"

namespace aopengl
{
	struct color
	{
		color() : _data({ 0.f, 0.f, 0.f, 0.f }) {}
		color(const std::array<GLfloat, 4>& col) : _data(col) {}
		color(const color&) = default;
		color(color&&) = default;
		color& operator=(const color&) = default;
		color& operator=(color&&) noexcept = default;		
		const GLfloat* data() const { return _data.data(); }
	private:
		std::array<GLfloat, 4> _data;
	};
}

#endif //!AOPENGL_COLOR_HPP

