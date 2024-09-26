#include "sunpch.h"
#include "SunEngine/Core/Base.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
namespace SunEngine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SUN_CORE_ASSERT(windowHandle, "GLFWwindow为空");
	}
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		
		//初始化Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SUN_CORE_ASSERT(status, "无法初始化Glad!");

		SUN_CORE_INFO("渲染API:OpenGL");
		SUN_CORE_INFO(" 供应商:{0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		SUN_CORE_INFO(" 渲染:{0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		SUN_CORE_INFO(" 版本:{0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}