#include "pch.h"
#include "CppUnitTest.h"
#include "../KNPO_6/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace errorSearchUnitTest
{
	TEST_CLASS(errorSearchUnitTest)
	{
	public:
		
		/*TEST_METHOD(tooBigValue)
		{
			//std::string* in = new std::string;
			std::string input = { "11111199999999999999999999999" };
			int error = 0;
			error = errorSearch(input);
			Assert::AreEqual(1, error);
		}*/

		TEST_METHOD(correctValue)
		{
			std::string input = { "24332" };
			int error = 0;
			std::string* in = &input;
			error = errorSearch(input);
			Assert::AreEqual(0, error);
		}

		TEST_METHOD(correctValueButWithLetters)
		{
			std::string input = { "41g21f11" };
			int error = 0;
			std::string* in = &input;
			error = errorSearch(input);
			Assert::AreEqual(0, error);
		}

		TEST_METHOD(fullOfLettersValue)
		{
			std::string input = { "oncepromisedto" };
			int error = 0;
			std::string* in = &input;
			error = errorSearch(input);
			Assert::AreEqual(0, error);
		}
	};
}
