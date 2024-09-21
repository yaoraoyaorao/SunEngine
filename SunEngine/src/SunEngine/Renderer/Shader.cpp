#include "sunpch.h"
#include "Shader.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"
namespace SunEngine {
	
	Ref<Shader> Shader::Create(const std::string& filePath)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "渲染API选择为None：着色器设置失败");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(filePath);
		}

		SUN_CORE_ASSERT(false, "渲染API为空：着色器设置失败");
		return nullptr;
	}

	Ref<Shader> Shader::Create(
		const std::string& name,
		const std::string& vertexSrc, 
		const std::string& fragmentSrc)
    {
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "渲染API选择为None：着色器设置失败");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		SUN_CORE_ASSERT(false, "渲染API为空：着色器设置失败");
		return nullptr;
    }

	//////////////////////////////////着色器库////////////////////////////////////////
	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		SUN_CORE_ASSERT(!Exists(name), "着色器:{0}已存在!", name);
		m_Shaders[name] = shader;
	}
	
	Ref<Shader> ShaderLibrary::Load(const std::string& filePath)
	{
		auto shader = Shader::Create(filePath);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Load(const std::string& name, const std::string& vertexSrc, const std::string& fragments)
	{
		auto shader = Shader::Create(name, vertexSrc, fragments);
		Add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		SUN_CORE_ASSERT(Exists(name), "着色器:{0}不存在!", name);

		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name)
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}