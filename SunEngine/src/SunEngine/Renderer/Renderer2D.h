#pragma once
#include "OrthographicCamera.h"
#include "Texture.h"
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// 2D��Ⱦ
	/// </summary>
	class Renderer2D {
	public:
		/// <summary>
		/// ��ʼ��
		/// </summary>
		static void Init();

		/// <summary>
		/// �ر�
		/// </summary>
		static void Shutdown();

		/// <summary>
		/// ˢ��
		/// </summary>
		static void Flush();
		
		/// <summary>
		/// ��ʼ����
		/// </summary>
		/// <param name="camera"></param>
		static void BeginScene(const OrthographicCamera& camera);

		/// <summary>
		/// ��������
		/// </summary>
		static void EndScene();

		/// <summary>
		/// ������ɫ�ı���
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="color"></param>
		static void DrawQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			const glm::vec4& color);

		/// <summary>
		/// ������ɫ�ı���
		/// </summary>
		/// <param name="position"></param>
		/// <param name="size"></param>
		/// <param name="color"></param>
		static void DrawQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			const glm::vec4& color);

		/// <summary>
		/// ���������ı���
		/// </summary>
		/// <param name="position">2Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="texture">����</param>
		/// <param name="tilingFactor">ƽ������</param>
		/// <param name="tintColor"ɫ����ɫ</param>
		static void DrawQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// ���������ı���
		/// </summary>
		/// <param name="position">3Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="texture">����</param>
		/// <param name="tilingFactor">ƽ������</param>
		/// <param name="tintColor"ɫ����ɫ</param>
		static void DrawQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// ������Ⱦ�ı���
		/// </summary>
		/// <param name="position">2Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="rotation">��ת�Ƕ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawRotatedQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			float rotation,
			const glm::vec4& color);

		/// <summary>
		/// ������Ⱦ�ı���
		/// </summary>
		/// <param name="position">3Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="rotation">��ת�Ƕ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawRotatedQuad(
			const glm::vec3& position,
			const glm::vec2& size,
			float rotation,
			const glm::vec4& color);

		/// <summary>
		/// ���������ı���
		/// </summary>
		/// <param name="position">2Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="rotation">��ת�Ƕ�</param>
		/// <param name="color">��ɫ</param>
		static void DrawRotatedQuad(
			const glm::vec2& position,
			const glm::vec2& size,
			float rotation,
			const Ref<Texture2D>& texture,
			float tilingFactor = 1.0f,
			glm::vec4& tintColor = glm::vec4(1.0f));

		/// <summary>
		/// ���������ı���
		/// </summary>
		/// <param name="position">3Dλ��</param>
		/// <param name="size">�ߴ�</param>
		/// <param name="rotation">��ת�Ƕ�</param>
		/// <param name="color">��ɫ</param>
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