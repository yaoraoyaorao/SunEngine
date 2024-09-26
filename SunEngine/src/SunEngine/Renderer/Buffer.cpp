#include "sunpch.h"

#include "Buffer.h"
#include "Renderer.h"

#include "SunEngine/Core/Base.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#pragma once
namespace SunEngine {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				SUN_CORE_ASSERT(false, "äÖÈ¾APIÑ¡ÔñÎªNone£º¶¥µã»º³åÉèÖÃÊ§°Ü");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		SUN_CORE_ASSERT(false, "äÖÈ¾APIÎª¿Õ£º¶¥µã»º³åÉèÖÃÊ§°Ü");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			SUN_CORE_ASSERT(false, "äÖÈ¾APIÑ¡ÔñÎªNone£º¶¥µã»º³åÉèÖÃÊ§°Ü");
			return nullptr;
		case RendererAPI::API::OpenGL:
			return CreateRef<OpenGLVertexBuffer>(size);
		}

		SUN_CORE_ASSERT(false, "äÖÈ¾APIÎª¿Õ£º¶¥µã»º³åÉèÖÃÊ§°Ü");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				SUN_CORE_ASSERT(false, "äÖÈ¾APIÑ¡ÔñÎªNone£ºË÷Òı»º³åÉèÖÃÊ§°Ü");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLIndexBuffer>(indices, count);
		}

		SUN_CORE_ASSERT(false, "äÖÈ¾APIÎª¿Õ£ºË÷Òı»º³åÉèÖÃÊ§°Ü");
		return nullptr;
	}

}