#pragma once

#include "sunpch.h"
#include "SunEngine/Core/Base.h"
#include "SunEngine/Events/Event.h"
/*
	抽象窗口类：平台无关
*/
namespace SunEngine {
	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Sun Engine",unsigned int width = 1280,unsigned int height = 720):
			Title(title), Width(width), Height(height) {}
	};

	class Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		
		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};
}