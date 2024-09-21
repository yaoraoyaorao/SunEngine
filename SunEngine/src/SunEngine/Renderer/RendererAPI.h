#pragma once
#include <glm/glm.hpp>
#include "VertexArray.h"
namespace SunEngine {
	/// <summary>
	/// ��Ⱦ�ӿ�
	/// </summary>
	class RendererAPI {
	public:
		enum class API {
			None = 0, OpenGL = 1
		};
	public:
		
		/// <summary>
		/// ��ʼ��
		/// </summary>
		virtual void Init() = 0;
		
		/// <summary>
		/// ���������ɫ
		/// </summary>
		/// <param name="color"></param>
		virtual void SetClearColor(const glm::vec4& color) = 0;
		
		/// <summary>
		/// ���
		/// </summary>
		virtual void Clear() = 0;
		
		/// <summary>
		/// ����
		/// </summary>
		/// <param name="vertexArray"></param>
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;
		
		/// <summary>
		/// ��ȡ��ǰʹ��API
		/// </summary>
		/// <returns></returns>
		inline static API GetAPI() { return m_API; }
	private:
		static API m_API;
	};
}