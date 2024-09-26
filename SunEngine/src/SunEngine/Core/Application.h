#pragma once
#include "Base.h"
#include "Window.h"

#include "SunEngine/Core/LayerStack.h"
#include "SunEngine/Core/TimeStep.h"
#include "SunEngine/ImGui/ImGuiLayer.h"
#include "SunEngine/Events/ApplicationEvent.h"
namespace SunEngine {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Instance() { return *m_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowReasize(WindowResizeEvent& e);
	private:
		bool m_Running = true;
		bool m_Minimized = false;
		std::unique_ptr<Window> m_Window;
		Timestep m_TimeStep;
		ImGuiLayer* m_ImGuiLayer;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* m_Instance;
	};

	Application* CreateApplication();
}