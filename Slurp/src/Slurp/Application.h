#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace Slurp {

	class SLURP_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	
	//To be defined in a client
	Application* CreateApplication();
}
