#pragma once
#include "SunEngine/Renderer/Buffer.h"
namespace SunEngine {

	/// <summary>
	/// OpenGL顶点缓冲实现
	/// </summary>
	class OpenGLVertexBuffer:public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void SetLayout(const BufferLayout& layout) override { m_BufferLayout = layout; }
		virtual const BufferLayout& GetLayout() const override { return m_BufferLayout; }
	private:
		uint32_t m_RendererID;
		BufferLayout m_BufferLayout;
	};

	/// <summary>
	/// OpenGL索引缓冲实现
	/// </summary>
	class OpenGLIndexBuffer :public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual uint32_t GetCount()const {
			return m_Count;
		}

		virtual void Bind() const override;
		virtual void UnBind() const override;
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}



