#pragma once

#include "Core/Input.h"

BAGEL_NAMESPACE_BEGIN

class WindowsInput :public Input
{
protected:
	virtual bool IsKeyPressedImpl(int keycode) override;

	virtual bool IsMouseButtonPressedImpl(int button) override;
	virtual std::pair<float, float> GetMousePositionImpl() override;
	virtual float GetMouseXImpl() override;
	virtual float GetMouseYImpl() override;
};

BAGEL_NAMESPACE_END