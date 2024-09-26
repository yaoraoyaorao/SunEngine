#pragma once
#include "OrthographicCamera.h"
#include "Texture.h"
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// 2D渲染
	/// </summary>
	class Renderer2D {
	public:
		/// <summary>
		/// 初始化
		/// </summary>
		static void Init();

		/// <summary>
		/// 关闭
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// 刷新
		/// </summary>
		static void Flush();
		
		/// <summary>
		/// 开始场景
		/// </summary>
		/// <param name="camera"></param>
		static void BeginScene(const OrthographicCamera& camera);

		/// <summary>
		/// 结束场景
		/// </summary>
		static void EndScene();

		/// <summary>
		/// 绘制颜色四边形
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="color"></param>
		static void DrawQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			const glm::vec4& color);

		/// <summary>
		/// 绘制颜色四边形
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="color"></param>
		static void DrawQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			const glm::vec4& color);

		/// <summary>
		/// 绘制纹理四边形
		/// </summary>
		/// <param name="position">2D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="texture">纹理</param>
		/// <param name="tilingFactor">平铺因素</param>
		/// <param name="tintColor"色彩颜色</param>
		static void DrawQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// 绘制纹理四边形
		/// </summary>
		/// <param name="position">3D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="texture">纹理</param>
		/// <param name="tilingFactor">平铺因素</param>
		/// <param name="tintColor"色彩颜色</param>
		static void DrawQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// 绘制渲染四边形
		/// </summary>
		/// <param name="position">2D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="rotation">旋转角度</param>
		/// <param name="color">颜色</param>
		static void DrawRotatedQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			float rotation,
			const glm::vec4& color);

		/// <summary>
		/// 绘制渲染四边形
		/// </summary>
		/// <param name="position">3D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="rotation">旋转角度</param>
		/// <param name="color">颜色</param>
		static void DrawRotatedQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			float rotation,
			const glm::vec4& color);

		/// <summary>
		/// 绘制纹理四边形
		/// </summary>
		/// <param name="position">2D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="rotation">旋转角度</param>
		/// <param name="color">颜色</param>
		static void DrawRotatedQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			float rotation,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// 绘制纹理四边形
		/// </summary>
		/// <param name="position">3D位置</param>
		/// <param name="size">尺寸</param>
		/// <param name="rotation">旋转角度</param>
		/// <param name="color">颜色</param>
		static void DrawRotatedQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			float rotation,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));
	private:

	};
}