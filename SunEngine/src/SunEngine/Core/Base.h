#pragma once
#include <memory>

#include "PlatformDetection.h"

//#ifdef SUN_DEBUG
//	#define SUN_ENABLE_ASSERTS
//#endif

#ifdef SUN_ENABLE_ASSERTS
	#define SUN_ASSERT(x, ...) { if(!(x)) { SUN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SUN_CORE_ASSERT(x, ...) { if(!(x)) { SUN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SUN_ASSERT(x, ...)
	#define SUN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x,this,std::placeholders::_1)

namespace SunEngine {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T,typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
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

