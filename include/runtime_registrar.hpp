#pragma once
#ifndef RUNTIME_REGISTERAR_HPP
#define RUNTIME_REGISTRAR_HPP

#include <string>
#include <iostream>
#include <utility>
#include <unistd.h>
#include <cstdlib>
#include <gcc_invoker.hpp>

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
		char file_name[] = "/tmp/crepl-XXXXXX.c";
		int fd = mkstemps(file_name, 2);
		if (fd == -1)
		{
			std::cerr << "Error creating temporary file\n";
			return;
		}
		std::string file_name_str = file_name;
		auto file_name_without_sfx = file_name_str.substr(0, file_name_str.size() - 2);
		std::cout << std::format("📃Created File: {}\n📎Generating: {}.so",
								 file_name_str, file_name_without_sfx)
				  << std::endl;

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

		// Compile
		auto compile_result = GccInvoker::CompileFile(file_name_str, file_name_without_sfx + ".so");
		if (!compile_result)
		{
			std::cerr << "❌ 编译失败, 无法注册函数/表达式." << std::endl;
			close(fd);
			return;
		}

		close(fd);
	}
};

#endif //! RUNTIME_REGISTRAR_HPP
