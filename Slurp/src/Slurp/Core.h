#pragma once

#ifdef SL_PLATFORM_WINDOWS
	#ifdef SL_BUILD_DLL
		#define SLURP_API __declspec(dllexport)
	#else
		#define SLURP_API __declspec(dllimport)
	#endif
#else
	#error Slurp only supports Windows!
#endif

#define BIT(x) (1 << x)