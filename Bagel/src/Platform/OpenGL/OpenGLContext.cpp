#include "bgpch.h"

#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Bagel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		BG_CORE_ASSERT(windowHandle, "window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BG_CORE_ASSERT(status, "Failed to initialize Glad!");

		BG_CORE_INFO("OpenGL 信息:");
		BG_CORE_INFO("	Vendor：{0}", (const char*)glGetString(GL_VENDOR));
		BG_CORE_INFO("	显卡名：{0}", (const char*)glGetString(GL_RENDERER));
		BG_CORE_INFO("	版本：{0}", (const char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}