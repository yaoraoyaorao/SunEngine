#include "sunpch.h"
#include "WinInput.h"

#include "SunEngine/Application.h"

#include <GLFW/glfw3.h>

namespace SunEngine{

	Input* Input::m_Instance = new WinInput();

	bool SunEngine::WinInput::IsKeyPressedImpl(int keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WinInput::IsMouseButtonPressedImpl(int button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	float WinInput::GetMouseXImpl()
	{
		return GetMousePositionImpl().first;
	}

	float WinInput::GetMouseYImpl()
	{
		return GetMousePositionImpl().second;
	}
	std::pair<float, float> WinInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { (float)x, (float)y };
	}
}