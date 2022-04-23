#include "pch.h"
#include "CppUnitTest.h"
#include "../KNPO_6/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace findOperandsUnitTest
{
	TEST_CLASS(findOperandsUnitTest)
	{
	public:
		
		TEST_METHOD(oneStringArgumentsTestMethod)
		{
			struct Accoplishment tested;
			char inputStrings[10][10] = { "ac",">","b" };
			char firstArgure[10][10] = { "ac" };
			char secondArgue[10][10] = {"b"};

			operandsCopy(&tested, inputStrings, 3);

			for (int i = 0; i < 1; i++)
			{
				for (int j = 0; j < 10; ++j)
				{
					Assert::AreEqual(firstArgure[i][j], tested.operandOne[i][j]);
					Assert::AreEqual(secondArgue[i][j], tested.operandTwo[i][j]);
				}
			}
		}

		TEST_METHOD(manyStringsArgumentsTestMethod)
		{
			struct Accoplishment tested;
			char inputStrings[10][10] = { "ac","iop","+","<=","b","yuyt","wow","-","/" };
			char firstArgure[10][10] = { "ac" };
			char secondArgue[10][10] = { "b" };

			operandsCopy(&tested, inputStrings, 3);

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 10; ++j)
				{
					Assert::AreEqual(firstArgure[i][j], tested.operandOne[i][j]);
					Assert::AreEqual(secondArgue[i][j], tested.operandTwo[i][j]);
				}
			}
		}
	};
}
