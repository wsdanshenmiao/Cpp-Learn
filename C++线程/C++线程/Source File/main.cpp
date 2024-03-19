#include <thread>
#include <iostream>

static bool s_Finished = false;

void DoWork()
{
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		using namespace std::literals::chrono_literals;
		std::cout << "Working" << std::endl;
		std::this_thread::sleep_for(1s);
	}	
}

int main()
{
	std::thread worker(DoWork);	//���������߳�

	std::cin.get();
	s_Finished = true;

	worker.join();	//�ȴ��̼߳���
	std::cout << "Finished" << std::endl;

	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	std::cin.get();
}