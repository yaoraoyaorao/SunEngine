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

		inline static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
			m_RendererAPI->SetViewport(x, y, width, height);
		}

		/// <summary>
		/// ����ָ��
		/// </summary>
		/// <param name="vertexArray"></param>
		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray,uint32_t indexCount = 0) {
			m_RendererAPI->DrawIndexed(vertexArray, indexCount);
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