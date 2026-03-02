#pragma once
#ifndef GPP_INVOKER_HPP
#define GPP_INVOKER_HPP

/**
 * @brief 调用g++ 编译代码成动态链接库
 *
 * g++ -shared -fPIC -Wno-implicit-function-declaration -o <临时.so> <临时.cpp>
 */
class GppInvoker
{
};

#endif //! GPP_INVOKER_HPP