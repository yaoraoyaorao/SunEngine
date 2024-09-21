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
		// 计算变换矩阵，先平移再旋转
		glm::mat4 transform = 
			glm::translate(glm::mat4(1.0f), m_Position) * //平移到摄像机位置
			glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1)); //绕z轴旋转摄像机
		
		// 计算视图矩阵：变换矩阵的逆矩阵
		m_ViewMatrix = glm::inverse(transform);

		// 计算视图投影矩阵：投影矩阵 * 视图矩阵
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}