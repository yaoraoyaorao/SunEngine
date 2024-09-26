#pragma once
#include "SunEngine/Core/Base.h"
#include <string>
#include <glm/glm.hpp>
namespace SunEngine {
	/// <summary>
	/// 着色器
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
	/// 着色器库
	/// </summary>
	class ShaderLibrary {
	public:
		/// <summary>
		/// 添加着色器
		/// </summary>
		/// <param name="shader"></param>
		void Add(const Ref<Shader>& shader);
		
		/// <summary>
		/// 添加着色器
		/// </summary>
		/// <param name="name">着色器名</param>
		/// <param name="shader">着色器引用</param>
		void Add(const std::string& name, const Ref<Shader>& shader);
		
		/// <summary>
		/// 加载着色器
		/// </summary>
		/// <param name="filePath">着色器文件路径</param>
		/// <returns></returns>
		Ref<Shader> Load(const std::string& filePath);
		
		/// <summary>
		/// 加载着色器
		/// </summary>
		/// <param name="name">着色器名</param>
		/// <param name="vertexSrc">顶点着色器源码</param>
		/// <param name="fragments">片段着色器源码</param>
		/// <returns></returns>
		Ref<Shader> Load(const std::string& name,
			const std::string& vertexSrc, 
			const std::string& fragments);
		
		/// <summary>
		/// 获取着色器
		/// </summary>
		/// <param name="name">着色器名</param>
		/// <returns></returns>
		Ref<Shader> Get(const std::string& name);

		/// <summary>
		/// 是否存在着色器
		/// </summary>
		/// <param name="name">着色器名</param>
		/// <returns></returns>
		bool Exists(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}