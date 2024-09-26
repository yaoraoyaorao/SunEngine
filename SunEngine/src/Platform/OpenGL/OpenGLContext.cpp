#include "sunpch.h"
#include "SunEngine/Core/Base.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
namespace SunEngine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SUN_CORE_ASSERT(windowHandle, "GLFWwindowΪ��");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		
		//��ʼ��Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SUN_CORE_ASSERT(status, "�޷���ʼ��Glad!");

		SUN_CORE_INFO("��ȾAPI:OpenGL");
		SUN_CORE_INFO(" ��Ӧ��:{0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		SUN_CORE_INFO(" ��Ⱦ:{0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		SUN_CORE_INFO(" �汾:{0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}