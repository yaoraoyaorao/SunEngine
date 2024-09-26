#include "sunpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace SunEngine {

	Ref<VertexArray> VertexArray::Create() {
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone��������������ʧ��");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ�������������ʧ��");
		return nullptr;
	}
}