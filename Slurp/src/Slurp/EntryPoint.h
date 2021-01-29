#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern Slurp::Application* Slurp::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Slurp::CreateApplication();
	app->Run();
	delete app;
}

#endif