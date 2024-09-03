#include "bgpch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Bagel {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}