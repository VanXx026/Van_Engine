#pragma once

#include "Core.h"

namespace Van
{
	class VAN_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
	};

	// TO be defined in Client
	Application* CreateApplication();
}


