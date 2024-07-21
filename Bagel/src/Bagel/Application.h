#pragma once

#include "Core.h"

namespace Bagel{

    class BAGEL_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application* CreateApplication();
}