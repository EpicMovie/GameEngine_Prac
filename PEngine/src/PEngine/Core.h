#pragma once

#ifdef PE_PLATFORM_WINDOWS
	#ifdef PE_BUILD_DLL
		#define PEngine_API __declspec(dllexport)
	#else 
		#define PEngine_API __declspec(dllimport)
	#endif 
#else
	#error Only Support Windows!
#endif 

#define BIT(x) (1 << x)
