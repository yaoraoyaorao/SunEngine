#include "sunpch.h"
#include "WinWindow.h"

#include "SunEngine/Events/KeyEvent.h"
#include "SunEngine/Events/MouseEvent.h"
#include "SunEngine/Events/ApplicationEvent.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
namespace SunEngine {
	static bool m_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description) {
		SUN_CORE_ERROR("GLFW���� ({0}): {1}", error, description);
	}

	Scope<Window> Window::Create(const WindowProps& props) {
		return CreateScope<WinWindow>(props);
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

		SUN_CORE_INFO("�������� {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!m_GLFWInitialized)
		{
			int success = glfwInit();
			SUN_CORE_ASSERT(success, "GLFW��ʼ��ʧ��!");
			glfwSetErrorCallback(GLFWErrorCallback);
			m_GLFWInitialized = true;
		}

		//�������ڣ�����OpenGL������
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		
		m_Context = new OpenGLContext(m_Window);
		m_Context->Init(); 
		
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		/*
			����GLFW�ص�,����GLFW�Ļص���������������Զ����¼�
		*/

		//���ڳߴ�ı�ص�
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height) {
			
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizeEvent event(width, height);
			data.EventCallback(event);
		});

		//���ڹرջص�
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowCloseEvent event;
			data.EventCallback(event);
		});

		//���̻ص�
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
			}
		});

		//��갴���ص�
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			}
		});

		//�����ֻص�
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		//����ƶ��ص�
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});
	}

	void WinWindow::Shutdown() {

		SUN_PROFILE_FUNCTION();
		glfwDestroyWindow(m_Window);
	}

	void WinWindow::OnUpdate() {
		glfwPollEvents();
		m_Context->SwapBuffers();
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