#include "PEngine.h"

class Sandbox : public PEngine::Application
{
	public:
		Sandbox()
		{
		}
		~Sandbox()
		{
		}
};

PEngine::Application* PEngine::CreateApplication()
{
	return new Sandbox();
}
