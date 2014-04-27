#include "CLI.h"

// source site:
// http://stackoverflow.com/questions/717572/how-do-you-do-non-blocking-console-i-o-on-linux-in-c
bool inputAvailable() {
	struct timeval tv;
	fd_set fds;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fds);
	FD_SET(STDIN_FILENO,&fds);
	select(STDIN_FILENO+1, &fds, NULL, NULL,&tv);
	return (FD_ISSET(0,&fds));
}

void CLI::writeLine(std::string data) {
	std::cout << data << std::endl;
}

void CLI::subscribe(std::shared_ptr<Observer> obs) {
	_observers.push_back(obs);
}

bool CLI::hasInput(){
	return inputAvailable();
}

void CLI::awaitInput(){
	std::cout << "> ";
	std::cout.flush();
}

void CLI::processInput(){
	std::string line;
	std::getline(std::cin, line);

	for (auto&& e : _observers) {
		e->newInput(line);
	}
}

void CLI::header() {
	std::cout << "AcidDB CLI v" ACIDDB_CLI_VERSION << std::endl;
	std::cout << "connecting to localhost" << std::endl;
}