#pragma once
#include "SunEngine/Core.h"
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