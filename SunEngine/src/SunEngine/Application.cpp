#include "sunpch.h"
#include "Application.h"
#include "SunEngine/Event/ApplicationEvent.h"
#include "SunEngine/Log.h"
namespace SunEngine {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		
		while (true);
	}
}