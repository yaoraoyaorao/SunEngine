#ifdef _WIN32
	#ifdef  _WIN64
		#define SUN_PLATFORM_WINDOWS 
	#else
		#error "��֧��32λ����"
#endif //  _WIN64

//IOSƽ̨���
#elif defined(__APPLE__) || defined(__MACH__)
	#include <TargetConditionals.h>
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS�豸��֧��"
	#elif TARGET_OS_IPHONE == 1
		#define SUN_PLATFORM_IOS
		#error "IOS�豸��֧��"
	#elif TARGET_OS_MAC == 1
		#define SUN_PLATFORM_MAC
		#error "MAC�豸��֧��"
	#else
		#error "δ֪��ƻ��ƽ̨"
#endif

//Androidƽ̨���
#elif defined(__ANDROID__)
	#define SUN_PLATFORM_ANDROID
#error "��׿ƽ̨��֧��"

//Linuxƽ̨���
#elif defined(__linux__)
	#define SUN_PLATFORM_LINUX
	#error "Linuxƽ̨��֧��"
#else
	#error "δ֪��ƽ̨"
#endif