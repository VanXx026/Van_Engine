// 在引擎端添加入口点的目的是为了将初始化应用端的逻辑放在引擎端，而不是让应用端去做初始化
#pragma once

#ifdef VAN_PLATFORM_WINDOWS

extern Van::Application* Van::CreateApplication();
// Van::Application* Van::CreateApplication(); 
// 目前看下来加不加extern都可以，因为这个头文件本身就是要放到SandboxApp里面的，预处理阶段里面的内容是直接复制到SandboxApp里

int main(int argc, char** argv)
{
	Van::Log::Init();
	VAN_CORE_ERROR("Initialized Log!");
	int a = 5;
	VAN_INFO("Hello! Var = {0}", a);

	auto app = Van::CreateApplication();
	app->Run();
	delete app;
}

#endif // VAN_PLATFORM_WINDOWS
