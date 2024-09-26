#include "Sandbox2D.h"
#include <SunEngine.h>
#include <SunEngine/Core/EntryPoint.h>
class SandBox :public SunEngine::Application {
public:
	SandBox()
	{
		PushLayer(new Sandbox2D());
	}

	~SandBox()
	{
		
	}
};

SunEngine::Application* SunEngine::CreateApplication() {
	return new SandBox();
}