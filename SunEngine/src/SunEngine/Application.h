#pragma once
#include "Core.h"

#include "Window.h"
#include "SunEngine/LayerStack.h"
#include "SunEngine/Events/ApplicationEvent.h"
namespace SunEngine {
	class SUN_API Application
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
		bool m_Running = true;
		std::unique_ptr<Window> m_Window;
		LayerStack m_LayerStack;
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		static Application* m_Instance;
	};

	Application* CreateApplication();
}