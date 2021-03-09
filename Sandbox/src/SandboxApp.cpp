#include<Slurp.h>

class Sandbox : public Slurp::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{
		
	}
};

Slurp::Application* Slurp::CreateApplication()
{
	return new Sandbox();
}