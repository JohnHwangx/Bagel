#pragma once

#ifdef BG_PLATFORM_WINDOWS
	#ifdef BG_BUILD_DLL
		#define BAGEL_API __declspec(dllexport)
	#else
		#define BAGEL_API __declspec(dllimport)
	#endif
#else
	#error Bagel only supports Windows!
#endif