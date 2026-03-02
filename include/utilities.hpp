#pragma once
#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <string>
std::string Trim(const std::string &str)
{
	const std::string whitespace = " \n\r\t\f\v";
	size_t start = str.find_first_not_of(whitespace);
	size_t end = str.find_last_not_of(whitespace);
	if (start == std::string::npos || end == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}
#endif //! UTILITIES_HPP