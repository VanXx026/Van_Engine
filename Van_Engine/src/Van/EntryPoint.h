// ������������ڵ��Ŀ����Ϊ�˽���ʼ��Ӧ�ö˵��߼���������ˣ���������Ӧ�ö�ȥ����ʼ��
#pragma once

#ifdef VAN_PLATFORM_WINDOWS

extern Van::Application* Van::CreateApplication();
// Van::Application* Van::CreateApplication(); 
// Ŀǰ�������Ӳ���extern�����ԣ���Ϊ���ͷ�ļ��������Ҫ�ŵ�SandboxApp����ģ�Ԥ����׶������������ֱ�Ӹ��Ƶ�SandboxApp��

int main(int argc, char** argv)
{
	auto app = Van::CreateApplication();
	app->Run();
	delete app;
}

#else
	#error VanEngine only support Windows!
#endif // VAN_PLATFORM_WINDOWS
