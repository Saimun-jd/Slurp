#include "pch.h"
#include "Application.h"

#include <GLFW/glfw3.h>


namespace Slurp {
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		SL_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(
			[&](Event& e)
			{
				EventDispatcher dispatcher(e);
				dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
				SL_CORE_TRACE("{0}", e); 
			}
			);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
	bool Application::OnWindowClose(WindowCloseEvent& e) noexcept
	{
		m_Running = false;
		return true;
	}
}
