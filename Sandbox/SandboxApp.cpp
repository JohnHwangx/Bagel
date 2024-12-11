#include <Bagel.h>
#include <Core/EnterPoint.h>

#include "Sandbox2D.h"
#include "ExampleLayer.h"

class Sandbox :public Bagel::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		//PushLayer(new Bagel::ImGuiLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Bagel::Application* Bagel::CreateApplication()
{
	return new Sandbox();
}