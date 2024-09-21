#pragma once
#include "SunEngine/Renderer/GraphicsContext.h"
struct GLFWwindow;
namespace SunEngine {
	/// <summary>
	/// OpenGL������
	/// </summary>
	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* windowHandle);
		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};
}