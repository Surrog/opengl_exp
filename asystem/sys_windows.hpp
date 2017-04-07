#ifndef ASYSTEM_WINDOWS_HPP
#define ASYSTEM_WINDOWS_HPP

#include <cassert>
#include "astring_view.hpp"
#include <string>
#include "GLFW/glfw3.h"

namespace asystem
{
	struct windows
	{
		windows() = default;

		windows(const windows&) = delete;
		windows& operator=(const windows&) = delete;

		windows(windows&& orig)
		{
			if (this != &orig)
			{
				info = orig.info;
				id = orig.id;
				orig.id = nullptr;
			}
		}
		windows& operator=(windows&& orig) noexcept
		{
			if (this != &orig)
			{
				info = orig.info;
				id = orig.id;
				orig.id = nullptr;
			}
			return *this;
		}

		~windows()
		{
			if (id != nullptr)
			{
				glfwDestroyWindow(id);
			}
		}

		void start_window()
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, info.version_major);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, info.version_minor);
			glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, info.debug ? GL_TRUE : GL_FALSE);
			if (info.robust)
			{
				glfwWindowHint(GLFW_CONTEXT_ROBUSTNESS, GLFW_LOSE_CONTEXT_ON_RESET);
			}
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
			glfwWindowHint(GLFW_SAMPLES, info.samples);
			glfwWindowHint(GLFW_STEREO, info.stereo ? GL_TRUE : GL_FALSE);

			id = glfwCreateWindow(info.width, info.height, info.title.data(), info.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
			assert(id != nullptr);
			glfwMakeContextCurrent(id);
		}

		void swapBuffers()
		{
			glfwSwapBuffers(id);
		}

		void pollEvent()
		{
			glfwPollEvents();
		}

		struct
		{
			std::string title = "default title";
			int width = 800;
			int height = 600;
			int version_major = 4;
			int version_minor = 3;
			int samples = 1;

			bool fullscreen = false;
			bool vsync = false;
			bool cursor = true;
			bool stereo = false;
			bool debug =
#ifdef _DEBUG
				true;
#else //!_DEBUG
				false;
#endif //_DEBUG
			bool robust = false;
		} info;

	private:
		GLFWwindow* id = nullptr;
	};
}

#endif //!ASYSTEM_WINDOWS_HPP