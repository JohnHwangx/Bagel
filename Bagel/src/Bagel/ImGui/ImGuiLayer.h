#pragma once

#include "Bagel/Layer.h"

BAGEL_NAMESPACE_BEGIN

class ImGuiLayer :public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	void OnAttach();
	void OnDetach();
	void OnUpdate();
	void OnEvent(Event& event);

private:
	float m_Time = 0.0f;
};

BAGEL_NAMESPACE_END