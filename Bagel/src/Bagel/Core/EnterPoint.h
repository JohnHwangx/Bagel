#pragma once
#include "Core/Core.h"

#ifdef BG_PLATFORM_WINDOWS

extern Bagel::Application* Bagel::CreateApplication();

int main() {

	std::cout << "Core::main" << std::endl;

	Bagel::Log::Init();

	BG_PROFILE_BEGIN_SESSION("Startup", "BagelProfile-Startup.json");
	auto app = Bagel::CreateApplication();
	BG_PROFILE_END_SESSION();
	BG_PROFILE_BEGIN_SESSION("Runtime", "BagelProfile-Runtime.json");
	app->Run();
	BG_PROFILE_END_SESSION();
	BG_PROFILE_BEGIN_SESSION("Startup", "BagelProfile-Shutdown.json");
	delete app;
	BG_PROFILE_END_SESSION();
}

#endif // BG_PLATFORM_WINDOWS