#include <Bagel.h>

class ExampleLayer :public Bagel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{}

	void OnUpdate() override
	{
		BG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Bagel::Event& event) override
	{
		BG_TRACE("{0}", event.ToString());
	}
};

class Sandbox :public Bagel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Bagel::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Bagel::Application* Bagel::CreateApplication()
{
	return new Sandbox();
}