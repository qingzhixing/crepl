#include <iostream>
#include <argument_handler.hpp>
#include <project_info.hpp>

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

	std::cout << "Welcome to " << ProjectInfo::project_name << "!" << std::endl;
	return 0;
}