#include<Slurp.h>


class ExampleLayer : public Slurp::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Slurp::Event& event) override
	{
		SL_TRACE("{0}", event);
	}

};

class Sandbox : public Slurp::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
		
	}
};

Slurp::Application* Slurp::CreateApplication()
{
	return new Sandbox();
}