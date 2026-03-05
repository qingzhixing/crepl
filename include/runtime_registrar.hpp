#pragma once
#ifndef RUNTIME_REGISTERAR_HPP
#define RUNTIME_REGISTRAR_HPP

#include <string>
#include <iostream>
#include <utility>

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
	}

	/**
	 * @brief 注册表达式并运行它
	 *
	 * @param input_line
	 * @return std::pair<bool, int> 第一个元素表示编译运行是否成功，第二个元素表示表达式的结果（如果编译运行成功）
	 */
	static std::pair<bool, int> RegisterRunExpression(const std::string &input_line)
	{
	}

	static bool IsFunctionValid(const std::string &input_line)
	{
		return false;
	}

	static bool IsExpressionValid(const std::string &input_line)
	{
		return false;
	}

	static bool IsLineAFunction(const std::string &input_line)
	{
		return false;
	}
};

#endif //! RUNTIME_REGISTRAR_HPP
