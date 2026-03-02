#pragma once
#ifndef ARGUMENT_HANDLER_H
#define ARGUMENT_HANDLER_H
#include <getopt.h>
#include <iostream>

struct ProgramOption
{
	bool show_help = false;
	bool show_version = false;
};

class ArgumentHandler
{
public:
	static ProgramOption HandleArguments(int argc, char *argv[])
	{
		ProgramOption option;
		int opt;
		while ((opt = getopt(argc, argv, "hv")) != -1)
		{
			switch (opt)
			{
			case 'h':
				option.show_help = true;
				break;
			case 'v':
				option.show_version = true;
				break;
			default:
				option.show_help = true;
				break;
			}
		}
		return option;
	}
};
#endif //! ARGUMENT_HANDLER_H