#pragma once
#include "OrthographicCamera.h"
#include "SunEngine/Core/TimeStep.h"
#include "SunEngine/Events/MouseEvent.h"
#include "SunEngine/Events/ApplicationEvent.h"

#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// 正交摄像机控制
	/// </summary>
	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRotaion,bool rotation = false);
		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);
		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }
	private:
		bool OnMouseScrolled(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		float m_CameraRotation = 0.0f;
		glm::vec3 m_CmeraPosition = { 0.0f, 0.0f, 0.0f };

		float m_CameraTranslationSpeed = 10.0f;
		float m_CameraRotationSpeed = 180.0f;
	};

}

