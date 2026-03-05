#pragma once
#ifndef GPP_INVOKER_HPP
#define GPP_INVOKER_HPP

#include <string>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/wait.h>

/**
 * @brief 调用g++ 编译代码成动态链接库
 *
 * g++ -shared -fPIC -Wno-implicit-function-declaration -o <临时.so> <临时.cpp>
 */
class GppInvoker
{
public:
	static bool CompileFile(const std::string &source_file, const std::string &output_file)
	{
		char *const exec_argv[] = {
			"g++",
			"-shared",
			"-fPIC",
			"-Wno-implicit-function-declaration",
			"-o",
			strdup(output_file.c_str()),
			strdup(source_file.c_str()),
			nullptr,
		};
		char *exec_envp[] = {
			strdup("PATH=/bin"),
			NULL,
		};

		int pid = fork();
		if (pid < 0)
		{
			perror("fork");
			return false;
		}
		if (pid == 0)
		{
			// Child Process
			execve("/usr/bin/g++", exec_argv, exec_envp);
			perror("execve");
			std::cerr << "❌ 子进程调用g++失败, 可能是你的系统中未安装g++工具." << std::endl;
		}
		// Parent Process
		int status;
		int result = waitpid(pid, &status, 0);
		if (result < 0)
		{
			perror("waitpid");
			return false;
		}
		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				std::cerr << "❌ g++ 编译失败, 退出状态码: " << exit_status << std::endl;
				return false;
			}
		}
		else
		{
			std::cerr << "❌ g++ 编译失败, 子进程异常退出." << std::endl;
			return false;
		}

		return true;
	}
};

#endif //! GPP_INVOKER_HPP