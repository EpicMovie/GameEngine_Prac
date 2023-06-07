#pragma once

#include "Core.h"

namespace PEngine
{
	class PEngine_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	// To be defined in Client 
	Application* CreateApplication();
}
