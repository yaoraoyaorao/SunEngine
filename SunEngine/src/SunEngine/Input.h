#pragma once

#include "SunEngine/Core.h"
namespace SunEngine {
	class SUN_API Input{
	public:
		static bool IsKeyPressed(int keycode) { return m_Instance->IsKeyPressedImpl(keycode); }
		static bool IsMouseButtonPressed(int button) { return m_Instance->IsMouseButtonPressedImpl(button); }
		
		static std::pair<float, float> GetMousePosition() { return m_Instance->GetMousePositionImpl(); }
		static float GetMouseX() { return m_Instance->GetMouseXImpl(); }
		static float GetMouseY() { return m_Instance->GetMouseYImpl(); }
	
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float,float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	public:
		static Input* m_Instance;
	};
}