#include "pch.h"
#include "Application.h"
#include "Slurp/Events/ApplicationEvent.h"
#include "Slurp/Log.h"


namespace Slurp {

	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SL_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SL_TRACE(e);
		}

		while (true);
	}
}
