#ifndef ASYSTEM_APPLICATION_HPP
#define ASYSTEM_APPLICATION_HPP

#include <cassert>
#include "GLFW/glfw3.h"

namespace asystem
{
	struct application
	{
		application()
		{
			initialization_ok = glfwInit();
		}

		~application()
		{
			if (valid())
				glfwTerminate();
		}

		application(const application&) = delete;
		application& operator=(const application&) = delete;

		application(application&& orig)
		{
			if (this != &orig)
			{
				initialization_ok = orig.initialization_ok;
				orig.initialization_ok = -1;
			}
		}
		application& operator=(application&& orig)
		{
			if (this != &orig)
			{
				initialization_ok = orig.initialization_ok;
				orig.initialization_ok = -1;
			}
			return *this;
		}

		bool valid() const
		{
			return initialization_ok == 0;
		}

	private:
		int initialization_ok = -1;
	};

}

#endif //!ASYSTEM_APPLICATION_HPP
