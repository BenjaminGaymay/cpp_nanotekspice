//
// EPITECH PROJECT, 2018
// cpp_nanotekspice
// File description:
// Signal
//

#include <signal.h>
#include "Signal.hpp"
#include <iostream>

static bool g_quitLoop = false;

void quitLoop(int empty)
{
	(void)empty;
	g_quitLoop = true;
}

int loop(const std::string &cmd, std::map<std::string, nts::Component *> cList)
{
	(void)cmd;
	while (! g_quitLoop) {
		if (simulate(cmd, cList) == 84)
			return 84;
		usleep(500);
	}
	return 0;
}

int createSignal()
{
	struct sigaction sigIntHandler;

	sigIntHandler.sa_handler = quitLoop;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
	g_quitLoop = false;
	return 0;
}
