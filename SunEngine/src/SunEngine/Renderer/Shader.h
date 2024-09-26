#pragma once
#include "SunEngine/Core/Base.h"
#include <string>
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// ��ɫ��
	/// </summary>
	class Shader {
	public:
		~Shader() = default;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual std::string GetName() const = 0;
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;
		virtual void SetMat3(const std::string& name, const glm::mat3& value) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;

		static Ref<Shader> Create(const std::string& filePath);
		static Ref<Shader> Create(
			const std::string& name,
			const std::string& vertexSrc,
			const std::string& fragmentSrc);
	};

	/// <summary>
	/// ��ɫ����
	/// </summary>
	class ShaderLibrary {
	public:
		/// <summary>
		/// �����ɫ��
		/// </summary>
		/// <param name="shader"></param>
		void Add(const Ref<Shader>& shader);
		
		/// <summary>
		/// �����ɫ��
		/// </summary>
		/// <param name="name">��ɫ����</param>
		/// <param name="shader">��ɫ������</param>
		void Add(const std::string& name, const Ref<Shader>& shader);
		
		/// <summary>
		/// ������ɫ��
		/// </summary>
		/// <param name="filePath">��ɫ���ļ�·��</param>
		/// <returns></returns>
		Ref<Shader> Load(const std::string& filePath);
		
		/// <summary>
		/// ������ɫ��
		/// </summary>
		/// <param name="name">��ɫ����</param>
		/// <param name="vertexSrc">������ɫ��Դ��</param>
		/// <param name="fragments">Ƭ����ɫ��Դ��</param>
		/// <returns></returns>
		Ref<Shader> Load(const std::string& name,
			const std::string& vertexSrc, 
			const std::string& fragments);
		
		/// <summary>
		/// ��ȡ��ɫ��
		/// </summary>
		/// <param name="name">��ɫ����</param>
		/// <returns></returns>
		Ref<Shader> Get(const std::string& name);

		/// <summary>
		/// �Ƿ������ɫ��
		/// </summary>
		/// <param name="name">��ɫ����</param>
		/// <returns></returns>
		bool Exists(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}