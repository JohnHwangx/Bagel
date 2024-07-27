#include "bgpch.h"
#include "WindowsWindow.h"
#include "Bagel/Log.h"

BAGEL_NAMESPACE_BEGIN

static bool is_GLFWInitialized = false;

Window* Window::Create(const WindowProps& props)
{
	return new WindowsWindow(props);
}

WindowsWindow::WindowsWindow(const WindowProps& props)
{
	Init(props);
}

WindowsWindow::~WindowsWindow()
{
	Shutdown();
}

void WindowsWindow::OnUpdate()
{
	glfwPollEvents();
	glfwSwapBuffers(m_Window);
}

void WindowsWindow::SetVSync(bool enabled)
{
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	m_Data.VSync = enabled;
}

bool WindowsWindow::IsVSync() const
{
	return false;
}

void WindowsWindow::Init(const WindowProps& props)
{
	m_Data.Title = props.Title;
	m_Data.Width = props.Width;
	m_Data.Height = props.Height;

	BG_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

	if (!is_GLFWInitialized)
	{
		int success = glfwInit();
		BG_CORE_ASSERT(success, "Could not initialize GLFW!");

		is_GLFWInitialized = true;
	}

	m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_Window);
	glfwSetWindowUserPointer(m_Window, &m_Data);
	SetVSync(true);

}

void WindowsWindow::Shutdown()
{
	glfwDestroyWindow(m_Window);
}

BAGEL_NAMESPACE_END