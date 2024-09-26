#include "sunpch.h"
#include "SunEngine/Core/Base.h"
#include "SunEngine/Core/Input.h"
#include "SunEngine/Core/KeyCodes.h"
#include "SunEngine/Core/MouseButtonCodes.h"
#include "SunEngine/Events/Event.h"
#include "OrthographicCameraController.h"
namespace SunEngine {

	OrthographicCameraController::OrthographicCameraController(float aspectRotaion, bool rotation):
		m_AspectRatio(aspectRotaion),
		m_Camera(-m_AspectRatio * m_ZoomLevel,
				  m_AspectRatio * m_ZoomLevel,
				 -m_ZoomLevel, m_ZoomLevel),
		m_Rotation(rotation)
	{
		lastX = Input::GetMouseX();
		lastY = Input::GetMouseY();
	}

	void OrthographicCameraController::OnUpdate(Timestep ts)
	{
		//Top
		if (Input::IsKeyPressed(SUN_KEY_W))
		{
			m_CmeraPosition.y += m_CameraTranslationSpeed * ts;
		}
		//Left
		if (Input::IsKeyPressed(SUN_KEY_A))
		{
			m_CmeraPosition.x -= m_CameraTranslationSpeed * ts;
		}
		//Bottom
		if (Input::IsKeyPressed(SUN_KEY_S))
		{
			m_CmeraPosition.y -= m_CameraTranslationSpeed * ts;
		}
		//Right
		if (Input::IsKeyPressed(SUN_KEY_D))
		{
			m_CmeraPosition.x += m_CameraTranslationSpeed * ts;
		}

		if (m_Rotation)
		{
			//Left Rotation
			if (Input::IsKeyPressed(SUN_KEY_Q))
			{
				m_CameraRotation += m_CameraRotationSpeed * ts;
			}

			//Right Rotation
			if (Input::IsKeyPressed(SUN_KEY_E))
			{
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			}

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CmeraPosition);

		m_CameraRotationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
	{
		m_ZoomLevel -= e.GetYOffset()* 0.5f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection
		(
			-m_AspectRatio * m_ZoomLevel,
			 m_AspectRatio * m_ZoomLevel,
			-m_ZoomLevel, m_ZoomLevel
		);

		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
	{
		m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		m_Camera.SetProjection
		(
			-m_AspectRatio * m_ZoomLevel,
			 m_AspectRatio * m_ZoomLevel,
			-m_ZoomLevel, m_ZoomLevel
		);
		return false;
	}

}