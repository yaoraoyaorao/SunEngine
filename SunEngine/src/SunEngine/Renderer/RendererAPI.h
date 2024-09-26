#pragma once
#include <glm/glm.hpp>
#include "VertexArray.h"
namespace SunEngine {
	/// <summary>
	/// 渲染接口
	/// </summary>
	class RendererAPI {
	public:
		enum class API {
			None = 0, OpenGL = 1
		};
	public:
		
		/// <summary>
		/// 初始化
		/// </summary>
		virtual void Init() = 0;
		
		/// <summary>
		/// 设置视口
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="width"></param>
		/// <param name="height"></param>
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		/// <summary>
		/// 设置清除颜色
		/// </summary>
		/// <param name="color"></param>
		virtual void SetClearColor(const glm::vec4& color) = 0;
		
		/// <summary>
		/// 清除
		/// </summary>
		virtual void Clear() = 0;
		
		/// <summary>
		/// 绘制
		/// </summary>
		/// <param name="vertexArray"></param>
		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray,uint32_t indexCount = 0) = 0;
		
		/// <summary>
		/// 获取当前使用API
		/// </summary>
		/// <returns></returns>
		inline static API GetAPI() { return m_API; }
	private:
		static API m_API;
	};
}