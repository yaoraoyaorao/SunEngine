#include "sunpch.h"
#include "OpenGLTexture.h"
#include "SunEngine/Core.h"
#include "SunEngine/Log.h"
#include <stb_image.h>
#include <glad/glad.h>
namespace SunEngine {
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		:m_Path(path)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		SUN_CORE_ASSERT(data, "加载图片失败");

		m_Width = width;
		m_Height = height;

		GLenum internalForm = 0, dataFormat = 0;
		
		if (channels == 4){
			internalForm = GL_RGBA8; 
			dataFormat = GL_RGBA;
		}
		else if(channels == 3) {
			internalForm = GL_RGB8;
			dataFormat = GL_RGB;
		}

		SUN_CORE_ASSERT(internalForm & dataFormat, "不支持加载此格式");

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, internalForm, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		
		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

		SUN_CORE_INFO("图片加载成功 宽:{0} 高:{1} 通道:{2} 渲染ID:{3}", 
			width, height,
			channels,
			m_RendererID);

		stbi_image_free(data);
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}

}