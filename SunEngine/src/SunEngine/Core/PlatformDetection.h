#ifdef _WIN32
	#ifdef  _WIN64
		#define SUN_PLATFORM_WINDOWS 
	#else
		#error "不支持32位构建"
#endif //  _WIN64

//IOS平台检测
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS设备不支持"
	#elif TARGET_OS_IPHONE == 1
		#define SUN_PLATFORM_IOS
		#error "IOS设备不支持"
	#elif TARGET_OS_MAC == 1
		#define SUN_PLATFORM_MAC
		#error "MAC设备不支持"
	#else
		#error "未知的苹果平台"
#endif

//Android平台检测
#elif defined(__ANDROID__)
	#define SUN_PLATFORM_ANDROID
#error "安卓平台不支持"

//Linux平台检测
#elif defined(__linux__)
	#define SUN_PLATFORM_LINUX
	#error "Linux平台不支持"
#else
	#error "未知的平台"
#endif