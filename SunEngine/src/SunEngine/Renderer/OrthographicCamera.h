#pragma once
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// 正交摄像机
	/// </summary>
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bootom, float top);
		
		/// <summary>
		/// 设置投影
		/// </summary>
		/// <param name="left"></param>
		/// <param name="right"></param>
		/// <param name="bottom"></param>
		/// <param name="top"></param>
		void SetProjection(float left, float right, float bottom, float top);

		/// <summary>
		/// 获取摄像机位置
		/// </summary>
		/// <returns></returns>
		const glm::vec3& GetPosition() const { return m_Position; }
		
		/// <summary>
		/// 设置摄像机位置
		/// </summary>
		/// <param name="position"></param>
		void SetPosition(const glm::vec3& position) {
			m_Position = position; 
			RecalculateViewMatrix();
		}

		/// <summary>
		/// 获取摄像机旋转角度
		/// </summary>
		/// <returns></returns>
		const float GetRotation() const { return m_Rotation; }
		
		/// <summary>
		/// 设置摄像机旋转角度
		/// </summary>
		/// <param name="rotation"></param>
		void SetRotation(float rotation) {
			m_Rotation = rotation; 
			RecalculateViewMatrix(); 
		}

		const glm::mat4& GetProjectionMatrix()const { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix()const { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix()const { return m_ViewProjectionMatrix; }
	private:
		void RecalculateViewMatrix();
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };

		//正交摄像机 旋转只会考虑z轴
		float m_Rotation = 0.0f;
	};
}


