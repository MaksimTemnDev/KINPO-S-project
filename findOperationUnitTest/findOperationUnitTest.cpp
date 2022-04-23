#include "pch.h"
#include "CppUnitTest.h"
#include "../KNPO_6/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace findOperationUnitTest
{
	TEST_CLASS(findOperationUnitTest)
	{
	public:
		
		TEST_METHOD(biggerTestMethod)
		{
			char str[10][10] = {"123",">","22" };
			int strCount = 3;
			int input = 0;
			int output = 1;

			input = findOperation(str, strCount);

			Assert::AreEqual(output, input);
		}

		TEST_METHOD(smallerTestMethod)
		{
			char str[10][10] = { "999","<","9990" };
			int strCount = 3;
			int input = 0;
			int output = 2;

			input = findOperation(str, strCount);

			Assert::AreEqual(output, input);
		}

		TEST_METHOD(biggerOrSameTestMethod)
		{
			char str[10][10] = { "128883",">=","128882" };
			int strCount = 3;
			int input = 0;
			int output = 3;

			input = findOperation(str, strCount);

			Assert::AreEqual(output, input);
		}

		TEST_METHOD(smallerOrSameTestMethod)
		{
			char str[10][10] = { "543101","<=","7770777" };
			int strCount = 3;
			int input = 0;
			int output = 4;

			input = findOperation(str, strCount);

			Assert::AreEqual(output, input);
		}

		TEST_METHOD(invalidOperationTestMethod)
		{
			char str[10][10] = { "123","T","22" };
			int strCount = 3;
			int input = 0;
			int output = -1;

			input = findOperation(str, strCount);

			Assert::AreEqual(output, input);
		}
	};
}
