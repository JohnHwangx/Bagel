#include "bgpch.h"

#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Bagel {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:
			BG_CORE_ASSERT(false, "RendererAPI:None is currently not supported!");
			return nullptr;

		case RendererAPI::API::OpenGL:
			return std::make_shared<OpenGLVertexArray>();
		}

		BG_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}