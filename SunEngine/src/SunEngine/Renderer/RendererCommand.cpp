#include "sunpch.h"
#include "RendererCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"
namespace SunEngine {
	RendererAPI* RendererCommand::m_RendererAPI = new OpenGLRendererAPI();
}