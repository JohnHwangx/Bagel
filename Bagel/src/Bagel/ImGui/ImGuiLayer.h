#pragma once

#include "Bagel/Layer.h"
#include "Bagel/Events/ApplicationEvent.h"
#include "Bagel/Events/MouseEvent.h"
#include "Bagel/Events/KeyEvent.h"

BAGEL_NAMESPACE_BEGIN

class ImGuiLayer :public Layer
{
public:
	ImGuiLayer();
	~ImGuiLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnImGuiRender() override;

	void Begin();
	void End();

private:
	float m_Time = 0.0f;
};

BAGEL_NAMESPACE_END