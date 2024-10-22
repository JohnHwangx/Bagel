#include "bgpch.h"
#include "RenderCommand.h"

namespace Bagel {
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}