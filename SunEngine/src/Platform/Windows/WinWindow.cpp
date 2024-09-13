#include "sunpch.h"
#include "WinWindow.h"
namespace SunEngine {
	static bool m_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WinWindow(props);
	}

	WinWindow::WinWindow(const WindowProps& props) {
		Init(props);
	}

	WinWindow::~WinWindow() {
		
	}

	void WinWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SUN_CORE_INFO("创建窗口 {0} ({1}, {2})", props.Title, props.Width, props.Height);
	
		if (!m_GLFWInitialized)
		{
			int success = glfwInit();
			SUN_CORE_ASSERT(success, "GLFW初始化失败!");
			m_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WinWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WinWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WinWindow::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

	bool WinWindow::IsVSync() const {
		return m_Data.VSync;
	}
}