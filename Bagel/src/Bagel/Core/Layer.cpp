#include "bgpch.h"
#include "Layer.h"

BAGEL_NAMESPACE_BEGIN

Layer::Layer(const std::string& debugName)
	: m_DebugName(debugName)
{
}

Layer::~Layer()
{
}

BAGEL_NAMESPACE_END