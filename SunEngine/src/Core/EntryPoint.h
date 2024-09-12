#pragma once

#ifdef SUN_PLATFORM_WINDOWS

#include "Application.h"

extern SunEngine::Application* SunEngine::CreateApplication();

int main(int argc,char** argv) {
	auto app = SunEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // SUN_PLATFORM_WINDOWS
