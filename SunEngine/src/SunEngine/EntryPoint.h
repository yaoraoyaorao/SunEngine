#pragma once
/*
	���������
*/
#ifdef SUN_PLATFORM_WINDOWS

extern SunEngine::Application* SunEngine::CreateApplication();

int main(int argc,char** argv) {

	SunEngine::Log::Init();

	SUN_CORE_INFO("��ʼ����־�ɹ�!");
	
	auto app = SunEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif // SUN_PLATFORM_WINDOWS
