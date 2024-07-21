#include <Bagel.h>
#include <iostream>

class Sandbox :public Bagel::Application
{
public:
	Sandbox()
	{
		std::cout << "Hello Sandbox\n";
	}

	~Sandbox()
	{

	}
};

Bagel::Application* Bagel::CreateApplication()
{
	return new Sandbox();
}