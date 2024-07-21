#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern Bagel::Application* Bagel::CreateApplication();

int main() {

	std::cout << "Core::main" << std::endl;

	Bagel::Log::Init();
	BG_CORE_WARN("initialize log");
	int a = 5;
	BG_INFO("hello Var={0}", a);

	auto app = Bagel::CreateApplication();
	app->Run();
	delete app;
}

#endif // BG_PLATFORM_WINDOWS