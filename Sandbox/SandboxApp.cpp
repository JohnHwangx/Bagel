#include <Bagel.h>
#include "imgui.h"

class ExampleLayer :public Bagel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		if (Bagel::Input::IsKeyPressed(HZ_KEY_TAB))
			BG_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Bagel::Event& event) override
	{
		if (event.GetEventType() == Bagel::EventType::KeyPressed)
		{
			Bagel::KeyPressedEvent& e = (Bagel::KeyPressedEvent&)event;
			if (e.GetKeyCode() == HZ_KEY_TAB)
				BG_TRACE("Tab key is pressed (event)!");
			BG_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox :public Bagel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		//PushLayer(new Bagel::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Bagel::Application* Bagel::CreateApplication()
{
	return new Sandbox();
}