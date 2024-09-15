#include <SunEngine.h>

class TestLayer :public SunEngine::Layer {
public:
	TestLayer()
		:Layer("Test")
	{
	}

	void OnUpdate() override
	{
		if (SunEngine::Input::IsKeyPressed(SUN_KEY_W))
		{
			SUN_INFO("Key Pressed");
		}
	}

	void OnEvent(SunEngine::Event& event) override
	{

	}

};

class SandBox :public SunEngine::Application {
public:
	SandBox()
	{
		PushLayer(new TestLayer());
		//PushLayer(new SunEngine::ImGuiLayer());
	}

	~SandBox()
	{
		
	}
};

SunEngine::Application* SunEngine::CreateApplication() {
	return new SandBox();
}