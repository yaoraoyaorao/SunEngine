#include "sunpch.h"
#include "Texture.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"
namespace SunEngine {
	
	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone����������ʧ��");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(width, height);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ���������ʧ��");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone����������ʧ��");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLTexture2D>(path);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ���������ʧ��");
		return nullptr;
	}
}