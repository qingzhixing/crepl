#pragma once
#ifndef PROJECT_INFO_HPP
#define PROJECT_INFO_HPP

#include <string>
#include <format>
#include <iostream>

class ProjectInfo
{
public:
	static const inline std::string project_name = "crepl";
	static const inline std::string description = "C++ 实现的交互式的shell";
	static inline const std::string ascii_art =
		R"()";
	static inline const std::string author = "qingzhixing";
	static inline const std::string mail = "qzsqqmail@qq.com";
	static inline const std::string license = "MIT License";
	static inline const std::string github_link = "https://github.com/qingzhixing/crepl";

public:
	static void PrintVersion()
	{
		std::cout << ascii_art << std::endl;
		std::cout << std::format("🎃 {}: {}\n", project_name, description);
		std::cout << std::format("⌨️ Author: {}\n", author);
		std::cout << std::format("💌 Mail: {}\n", mail);
		std::cout << std::format("👾 License: {}\n", license);
		std::cout << std::format("📎 GitHub: {}\n", github_link);
	}

	static void PrintHelp()
	{
	}
};

#endif //! PROJECT_INFO_HPP