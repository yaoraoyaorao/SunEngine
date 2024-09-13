#pragma once

#ifdef SUN_PLATFORM_WINDOWS
	#ifdef SUN_BUILD_DLL
		#define SUN_API __declspec(dllexport)
	#else
		#define SUN_API __declspec(dllimport)
	#endif
#else
	#error Sun Engine only supports Windows!
#endif

#ifdef SUN_ENABLE_ASSERTS
	#define SUN_ASSERT(x, ...) { if(!(x)) { SUN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SUN_CORE_ASSERT(x, ...) { if(!(x)) { SUN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SUN_ASSERT(x, ...)
	#define SUN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)