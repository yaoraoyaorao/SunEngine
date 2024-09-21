#include "sunpch.h"
#include "OrthographicCamera.h"
#include <glm/gtc/matrix_transform.hpp>
namespace SunEngine {
	
	OrthographicCamera::OrthographicCamera(float left, float right, float bootom, float top)
		:m_ProjectionMatrix(glm::ortho(left, right, bootom, top, -1.0f, 1.0f)) ,
		m_ViewMatrix(1.0f)
	{
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
	
	void OrthographicCamera::RecalculateViewMatrix()
	{
		// ����任������ƽ������ת
		glm::mat4 transform = 
			glm::translate(glm::mat4(1.0f), m_Position) * //ƽ�Ƶ������λ��
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1)); //��z����ת�����
		
		// ������ͼ���󣺱任����������
		m_ViewMatrix = glm::inverse(transform);

		// ������ͼͶӰ����ͶӰ���� * ��ͼ����
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}