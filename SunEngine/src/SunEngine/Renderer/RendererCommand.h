#pragma once
#include "RendererAPI.h"
namespace SunEngine {
	/// <summary>
	/// 渲染指令
	/// </summary>
	class RendererCommand {
	public:
		/// <summary>
		/// 初始化
		/// </summary>
		inline static void Init() {
			m_RendererAPI->Init();
		}

		/// <summary>
		/// 绘制指令
		/// </summary>
		/// <param name="vertexArray"></param>
		inline static void DrawIndexed(const Ref<VertexArray>& vertexArray) {
			m_RendererAPI->DrawIndexed(vertexArray);
		}
		
		/// <summary>
		/// 设置清屏颜色
		/// </summary>
		/// <param name="color"></param>
		inline static void SetClearColor(const glm::vec4& color) {
			m_RendererAPI->SetClearColor(color);
		}
		
		/// <summary>
		/// 清除
		/// </summary>
		inline static void Clear() {
			m_RendererAPI->Clear();
		}
	private:
		static RendererAPI* m_RendererAPI;
	};
}