#pragma once

#include "Core/Layer.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"

BAGEL_NAMESPACE_BEGIN

class ImGuiLayer :public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void Begin();
	void End();

private:
	float m_Time = 0.0f;
};

BAGEL_NAMESPACE_END