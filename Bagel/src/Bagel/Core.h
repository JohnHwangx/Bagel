#pragma once
#include <memory>

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
#endif //  BG_PLATFORM_WINDOWS

#ifdef BG_DEBUG
	#define BG_ENABLE_ASSERTS
#endif

#ifdef BG_ENABLE_ASSERTS
	#define BG_ASSERT(x, ...) { if(!(x)) { BG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BG_CORE_ASSERT(x, ...)  { if(!(x)) { BG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BG_ASSERT(x, ...)
	#define BG_CORE_ASSERT(x, ...)
#endif // BG_ENABLE_ASSERTS


#define BAGEL_NAMESPACE_BEGIN namespace Bagel {
#define BAGEL_NAMESPACE_END }

#define BIT(x) (1 << x)

#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Bagel {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}