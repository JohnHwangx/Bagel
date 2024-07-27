#include "bgpch.h"
#include "Application.h"

#include "Bagel/Log.h"
#include "Events/ApplicationEvent.h"
//#include "Events/KeyEvent.h"
#include <iostream>

namespace Bagel {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}