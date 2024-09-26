#pragma once
/*
	程序主入口
*/
#ifdef SUN_PLATFORM_WINDOWS

extern SunEngine::Application* SunEngine::CreateApplication();

int main(int argc,char** argv) {

	SunEngine::Log::Init();
	auto app = SunEngine::CreateApplication();
	app->Run();

	delete app;
}
#endif // SUN_PLATFORM_WINDOWS
