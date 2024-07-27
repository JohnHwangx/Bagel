#include "bgpch.h"
#include "Application.h"

#include "Bagel/Log.h"
#include "Events/ApplicationEvent.h"
//#include "Events/KeyEvent.h"
#include <iostream>

namespace Bagel {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		//std::cout << e << std::endl;
		BG_TRACE(e.ToString());

		while (true);
	}
}