#pragma once
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// ���������
	/// </summary>
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bootom, float top);
		
		/// <summary>
		/// ����ͶӰ
		/// </summary>
		/// <param name="left"></param>
		/// <param name="right"></param>
		/// <param name="bottom"></param>
		/// <param name="top"></param>
		void SetProjection(float left, float right, float bottom, float top);

		/// <summary>
		/// ��ȡ�����λ��
		/// </summary>
		/// <returns></returns>
		const glm::vec3& GetPosition() const { return m_Position; }
		
		/// <summary>
		/// ���������λ��
		/// </summary>
		/// <param name="position"></param>
		void SetPosition(const glm::vec3& position) {
			m_Position = position; 
			RecalculateViewMatrix();
		}

		/// <summary>
		/// ��ȡ�������ת�Ƕ�
		/// </summary>
		/// <returns></returns>
		const float GetRotation() const { return m_Rotation; }
		
		/// <summary>
		/// �����������ת�Ƕ�
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

		//��������� ��תֻ�ῼ��z��
		float m_Rotation = 0.0f;
	};
}


