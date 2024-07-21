#pragma once

#ifdef BG_PLATFORM_WINDOWS

extern Bagel::Application* Bagel::CreateApplication();

int main() {
	auto app = Bagel::CreateApplication();
}

#endif // BG_PLATFORM_WINDOWS