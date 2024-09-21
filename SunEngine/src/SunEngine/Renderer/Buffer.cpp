#include "sunpch.h"

#include "Buffer.h"
#include "Renderer.h"

#include "SunEngine/Core.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#pragma once
namespace SunEngine {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone�����㻺������ʧ��");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ����㻺������ʧ��");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				SUN_CORE_ASSERT(false, "��ȾAPIѡ��ΪNone��������������ʧ��");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return new OpenGLIndexBuffer(indices, count);
		}

		SUN_CORE_ASSERT(false, "��ȾAPIΪ�գ�������������ʧ��");
		return nullptr;
	}

}