#pragma once
#ifndef RUNTIME_REGISTERAR_HPP
#define RUNTIME_REGISTRAR_HPP

#include <string>
#include <iostream>

class RuntimeRegistrar
{
public:
	static void ProcessLine(const std::string &input_line)
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
