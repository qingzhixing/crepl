#pragma once
#ifndef RUNTIME_REGISTERAR_HPP
#define RUNTIME_REGISTRAR_HPP

#include <string>
#include <iostream>
#include <utility>
#include <unistd.h>
#include <cstdlib>

class RuntimeRegistrar
{
public:
	/**
	 * @brief 处理输入的代码行，判断是函数定义还是表达式，并进行相应的注册
	 * @param input_line
	 */
	static void ProcessLine(const std::string &input_line)
	{
		// Generate unique temp file
		char file_name[] = "/tmp/crepl-XXXXXX.cpp";
		int fd = mkstemps(file_name, 4);
		if (fd == -1)
		{
			std::cerr << "Error creating temporary file\n";
			return;
		}

		// Check whether it's a function or an expression
		bool is_function = input_line.starts_with("int ");
		std::string expression_func_name;

		// write the content
		std::string code_content;
		if (is_function)
		{
			// A Function
			code_content = input_line + "\n";
		}
		else
		{
			// An Expression
			static int expression_counter = 0;
			expression_func_name = std::format("__expr_{}", expression_counter++);
			code_content = std::format("int {}() {{ return {}; }}\n", expression_func_name, input_line);
		}
		write(fd, code_content.c_str(), code_content.size());

		// Compile and load
		// TODO: Uncompleted

		close(fd);
	}
};

#endif //! RUNTIME_REGISTRAR_HPP
