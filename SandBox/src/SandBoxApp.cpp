#include <SunEngine.h>

class SandBox :public SunEngine::Application {
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

SunEngine::Application* SunEngine::CreateApplication() {
	return new SandBox();
}