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

#define BIT(x) (1 << x)