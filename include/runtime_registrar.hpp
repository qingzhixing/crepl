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
		if (IsLineAFunction(input_line))
		{
			auto success = RegisterFunction(input_line);

			if (!success)
			{
				std::cout << "❌ Compile Error" << std::endl;
			}
		}
		else
		{
			auto [success, result] = RegisterRunExpression(input_line);

			if (!result)
			{
				std::cout << "❌ Compile Error" << std::endl;
			}
			else
			{
				std::cout << "✅ Result: " << result << std::endl;
			}
		}
	}

	/**
	 * @brief 注册函数定义
	 *
	 * @param input_line
	 */
	static bool RegisterFunction(const std::string &input_line)
	{
		auto [fd, file_name] = GenerateOpenUniqueCpp();
		if (fd < 0)
		{
			return false;
		}
		auto success = write(fd, input_line.c_str(), sizeof(input_line.c_str()));
	}

	/**
	 * @brief 注册表达式并运行它
	 *
	 * @param input_line
	 * @return std::pair<bool, int> 第一个元素表示编译运行是否成功，第二个元素表示表达式的结果（如果编译运行成功）
	 */
	static std::pair<bool, int> RegisterRunExpression(const std::string &input_line)
	{
		auto [fd, file_name] = GenerateOpenUniqueCpp();
		if (fd < 0)
		{
			return {false, 0};
		}
	}

	static bool IsLineAFunction(const std::string &input_line)
	{
		return input_line.starts_with("int ");
	}

	/**
	 * @brief 生成一个唯一的Cpp文件并返回其文件描述符
	 *
	 * @return int 唯一Cpp文件的文件描述符
	 */
	static std::pair<int, std::string> GenerateOpenUniqueCpp()
	{
		char file_name[] = "/tmp/crepl-XXXXXX.cpp";
		int fd = mkstemps(file_name, 4); // 4 是 ".cpp" 的长度
		if (fd < 0)
		{
			perror("mkstemps");
		}
		std::string file_name_str = file_name;
		return {fd, file_name_str};
	}
};

#endif //! RUNTIME_REGISTRAR_HPP
