#pragma once
#include "RendererAPI.h"
namespace SunEngine {
	/// <summary>
	/// ��Ⱦָ��
	/// </summary>
	class RendererCommand {
	public:
		/// <summary>
		/// ��ʼ��
		/// </summary>
		inline static void Init() {
			m_RendererAPI->Init();
		}

		/// <summary>
		/// ����ָ��
		/// </summary>
		/// <param name="vertexArray"></param>
		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray) {
			m_RendererAPI->DrawIndexed(vertexArray);
		}
		
		/// <summary>
		/// ����������ɫ
		/// </summary>
		/// <param name="color"></param>
		inline static void SetClearColor(const glm::vec4& color) {
			m_RendererAPI->SetClearColor(color);
		}
		
		/// <summary>
		/// ���
		/// </summary>
		inline static void Clear() {
			m_RendererAPI->Clear();
		}
	private:
		static RendererAPI* m_RendererAPI;
	};
}