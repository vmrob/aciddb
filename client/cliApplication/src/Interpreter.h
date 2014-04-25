#pragma once
#include "CLI.h"

class Interpreter : public CLI::Observer {
private:
	std::shared_ptr<CLI> _cli;

public:

	Interpreter(std::shared_ptr<CLI> cli) : _cli(cli) {}

<<<<<<< HEAD
	void newInput(std::string line);
=======
	void newInput(std::string line) {
		_cli->writeLine("echo: " + line);
		// TODO: process line
	}
>>>>>>> 219aec36dd2adc53d3f05020977d37ab0f8732f9
};