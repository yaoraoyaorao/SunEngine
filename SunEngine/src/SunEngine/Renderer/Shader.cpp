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
			SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone����ɫ������ʧ��");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(filePath);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ���ɫ������ʧ��");
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
			SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone����ɫ������ʧ��");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLShader>(name, vertexSrc, fragmentSrc);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ���ɫ������ʧ��");
		return nullptr;
    }

	//////////////////////////////////��ɫ����////////////////////////////////////////
	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto& name = shader->GetName();
		Add(name, shader);
	}

	void ShaderLibrary::Add(const std::string& name, const Ref<Shader>& shader)
	{
		SUN_CORE_ASSERT(!Exists(name), "��ɫ��:{0}�Ѵ���!", name);
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
		SUN_CORE_ASSERT(Exists(name), "��ɫ��:{0}������!", name);

		return m_Shaders[name];
	}

	bool ShaderLibrary::Exists(const std::string& name)
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}