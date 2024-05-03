#pragma once

#ifdef VAN_PLATFORM_WINDOWS
	#ifdef VAN_BUILD_DLL
		#define VAN_API __declspec(dllexport)
	#else
		#define VAN_API __declspec(dllimport)
	#endif
#else
	#error VanEngine only support Windows!
#endif // VAN_PLATFORM_WINDOWS
