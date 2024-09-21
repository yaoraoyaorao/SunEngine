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
				SUN_CORE_ASSERT(false, "äÖÈ¾APIÑ¡ÔñÎªNone£º¶¥µã»º³åÉèÖÃÊ§°Ü");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return new OpenGLVertexBuffer(vertices, size);
		}

		SUN_CORE_ASSERT(false, "äÖÈ¾APIÎª¿Õ£º¶¥µã»º³åÉèÖÃÊ§°Ü");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:
				SUN_CORE_ASSERT(false, "äÖÈ¾APIÑ¡ÔñÎªNone£ºË÷Òı»º³åÉèÖÃÊ§°Ü");
				return nullptr;
			case RendererAPI::API::OpenGL:
				return new OpenGLIndexBuffer(indices, count);
		}

		SUN_CORE_ASSERT(false, "äÖÈ¾APIÎª¿Õ£ºË÷Òı»º³åÉèÖÃÊ§°Ü");
		return nullptr;
	}

}