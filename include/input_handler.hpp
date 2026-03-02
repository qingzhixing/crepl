#pragma once
#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include <iostream>
#include <format>
#include <project_info.hpp>
#include <utilities.hpp>

class InputHandler
{
public:
	static void HandleInput()
	{
		bool continue_flag = true;
		while (continue_flag)
		{
			std::cout << std::format("\n✨{}> ", ProjectInfo::project_name);
			std::string input;
			std::getline(std::cin, input);
			input = Trim(input);
			if (input.empty())
			{
				continue;
			}
			if (std::cin.fail())
			{
				continue_flag = false;
				continue;
			}
			std::cout << std::format("read: {}\n", input);
		}
	}
};
#endif //! INPUT_HANDLER_HPP