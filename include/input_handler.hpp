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
			std::string input_line;
			std::getline(std::cin, input_line);

			// 优先判断输入结束
			if (std::cin.fail() || std::cin.eof())
			{
				std::cout << "\n🤩 Input error or EOF detected. Exiting...\n";
				continue_flag = false;
				continue;
			}

			input_line = Trim(input_line);
			if (input_line.empty())
			{
				continue;
			}
		}
	}

private:
	void HandleInputLine(const std::string &input_line)
	{
	}

	bool IsFunctionValid(const std::string &input_line)
	{
	}

	bool IsExpressionValid(const std::string &input_line)
	{
	}

	void IsLineAFunction(const std::string &input_line)
	{
	}
};
#endif //! INPUT_HANDLER_HPP