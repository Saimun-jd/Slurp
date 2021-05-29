#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern Slurp::Application* Slurp::CreateApplication();

int main(int argc, char** argv)
{
	Slurp::Log::Init();

	SL_CORE_TRACE("Core succefully created");

	auto app = Slurp::CreateApplication();
	app->Run();
	delete app;
}

#endif