#pragma once
#include "Core.h"
namespace SunEngine {
	class SUN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();
}


