#include "bgpch.h"

#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Bagel {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI()) {
		case RendererAPI::None: BG_CORE_ASSERT(false, "RendererAPI:None is currently not supported!"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}
		BG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}