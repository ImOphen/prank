#include <iostream>
#include <fstream>
#include <unistd.h>
#include <signal.h>

std::string generate_random_word(int length) {
	void *tmp = malloc(1);
	srand((long) tmp + time(NULL));
	std::string word;
	for (int i = 0; i < length; i++) {
		word += (char)('a' + rand() % 26);
	}
	return word;
}

void signal_handler(int sig) {
	return ;
}
int main()
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTERM, signal_handler);
	while(1)
	{
		std::cout << generate_random_word(15) << std::endl;
		std::ofstream file("~/Desktop/" + generate_random_word(15));
		file.close();
		usleep(1);
	}
	return 0;
}