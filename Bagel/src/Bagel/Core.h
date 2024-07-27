#pragma once

#ifdef BG_PLATFORM_WINDOWS
	#ifdef BG_DYNAMIC_LINK
		#ifdef BG_BUILD_DLL
			#define BAGEL_API __declspec(dllexport)
		#else
			#define BAGEL_API __declspec(dllimport)
		#endif
	#else
		#define BAGEL_API 
	#endif // BG_DYNAMIC_LINK

	
#else
	#error Bagel only supports Windows!
#endif

#define BIT(x) (1 << x)