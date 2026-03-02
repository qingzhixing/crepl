#include <runtime_registrar.hpp>
#include <testkit.h>

UnitTest(Test_IsLineAFunction)
{
	assert(RuntimeRegistrar::IsLineAFunction("int func() { return 0; }"));
	assert(!RuntimeRegistrar::IsLineAFunction("gcd(114,514);"));
}

UnitTest(Test_IsExpressionValid)
{
	assert(RuntimeRegistrar::IsExpressionValid("gcd(114,514);"));
	assert(!RuntimeRegistrar::IsExpressionValid("114 + int + 514"));
}

UnitTest(Test_IsFunctionValid)
{
	assert(RuntimeRegistrar::IsFunctionValid("int func() { return 0; }"));
	assert(!RuntimeRegistrar::IsFunctionValid("int func() { return 0; }}"));
	assert(!RuntimeRegistrar::IsFunctionValid("int func() { return 0; "));
	assert(!RuntimeRegistrar::IsFunctionValid("int func()  return 0;} "));
}