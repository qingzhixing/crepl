#include <iostream>
#include <argument_handler.hpp>
#include <project_info.hpp>
#include <input_handler.hpp>
#include <testkit.h>

int main(int argc, char *argv[])
{
	auto argument = ArgumentHandler::HandleArguments(argc, argv);
	if (argument.show_help)
	{
		ProjectInfo::PrintHelp();
		return 0;
	}
	if (argument.show_version)
	{
		ProjectInfo::PrintVersion();
		return 0;
	}

	// 不在开启测试的环境下进行交互
	if (IsTestkitEnabled())
	{
		std::cout << "Running tests...\n";
		return 0;
	}

	InputHandler::HandleInput();
	return 0;
}