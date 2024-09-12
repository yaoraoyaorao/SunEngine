#pragma once
/*
	程序主入口
*/
#ifdef SUN_PLATFORM_WINDOWS

extern SunEngine::Application* SunEngine::CreateApplication();

int main(int argc,char** argv) {

	SunEngine::Log::Init();

	SUN_CORE_INFO("初始化日志成功!");
	
	auto app = SunEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // SUN_PLATFORM_WINDOWS
