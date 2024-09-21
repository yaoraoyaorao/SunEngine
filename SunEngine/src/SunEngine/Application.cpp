#include "sunpch.h"

#include "Log.h"
#include "Input.h"
#include "Application.h"
#include "SunEngine/Renderer/Renderer.h"
#include <GLFW/glfw3.h>

namespace SunEngine {
	Application* Application::m_Instance = nullptr;

	Application::Application()
	{
		
		SUN_CORE_ASSERT(!m_Instance, "Applicationֻ�ܴ���һ��");
		m_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	
		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application() {

	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
		
		//�����¼���Layer��
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			if(e.Handled())
				break;
			(*--it)->OnEvent(e);
		}
	}

	void Application::Run() {
		while (m_Running)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			//�߼�����
			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate(timestep);
			}

			//��Ⱦ����
			m_ImGuiLayer->OnBegin();
			for (Layer* layer : m_LayerStack)
			{
				layer->OnImGuiRender();
			}
			m_ImGuiLayer->OnEnd();

			//���ڸ���
			m_Window->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer) {
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}
}