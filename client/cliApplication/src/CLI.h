#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "version.h"

class CLI {
public:
	class Observer {
	public:
		virtual void newInput(std::string line) = 0;
	};

	void writeLine(std::string data);

	void subscribe(std::shared_ptr<Observer> obs);

	bool hasInput();

	void awaitInput();

	void processInput();

	void header();

private:
	std::vector<std::shared_ptr<Observer>> _observers;
};