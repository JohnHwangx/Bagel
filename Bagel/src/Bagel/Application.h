#pragma once

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Bagel {

    class BAGEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run(); 
        void OnEvent(Event& e);

    private:
        bool OnWindowClosed(WindowCloseEvent& e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    Application* CreateApplication();
}