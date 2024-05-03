#include <Van.h>

class Sandbox : public Van::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Van::Application* Van::CreateApplication()
{
	return new Sandbox();
}