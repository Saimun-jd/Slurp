#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Slurp/Events/ApplicationEvent.h"
#include "Window.h"

namespace Slurp {

	class SLURP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e) noexcept;

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	private:
		static Application* s_Instance;
	};
	
	//To be defined in a client
	Application* CreateApplication();
}
