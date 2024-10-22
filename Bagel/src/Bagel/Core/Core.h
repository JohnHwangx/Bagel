#pragma once
#include <memory>

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

#define BG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Bagel {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}