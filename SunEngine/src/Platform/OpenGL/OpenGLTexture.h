#pragma once
#include "SunEngine/Renderer/Texture.h"
namespace SunEngine {
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& path);
		~OpenGLTexture2D();
		inline virtual uint32_t GetWidth() const override { return m_Height; }
		inline virtual uint32_t GetHeight() const override { return m_Width; }
		virtual void Bind(uint32_t slot = 0) const override;
	private:
		std::string m_Path;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
	};

}

