#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#define VERSION "0.0.1"

// comment the source of this block
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

class CLI {
public:
	class Observer {
	public:
		virtual void newInput(std::string line) = 0;
	};

	void writeLine(std::string data) {
		std::cout << data << std::endl;
	}

	void subscribe(std::shared_ptr<Observer> obs) {
		_observers.push_back(obs);
	}

	bool hasInput() {
		return inputAvailable();
	}

	void awaitInput(){
		std::cout << "> ";
		std::cout.flush();
	}

	void processInput() {
		std::string line;
		std::getline(std::cin, line);

		for (auto&& e : _observers) {
			e->newInput(line);
		}
	}

	void header() {
		std::cout << "AcidDB CLI v" VERSION << std::endl;
		std::cout << "connecting to localhost" << std::endl;
	}

private:
	std::vector<std::shared_ptr<Observer>> _observers;
};