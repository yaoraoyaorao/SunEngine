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

		void SetZoomLevel(float level) { m_ZoomLevel = level; }
		float GetZoomLevel() const { return m_ZoomLevel; }
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

		float m_CameraTranslationSpeed = 5.0f;
		float m_CameraRotationSpeed = 180.0f;

		float lastX = 0.0f;
		float lastY = 0.0f;
	};

}

