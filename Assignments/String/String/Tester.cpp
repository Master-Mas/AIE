////////////////////////////////////////////////////////////
// Author:			Sam Murphy
// Date Modified:	2016-02-19
// Brief:			A Unit Test for the String class that I created.
////////////////////////////////////////////////////////////

#include "Tester.h"
#include "String.h"
#include <iostream>
#include <fstream>
#include <time.h>

void main() 
{
	std::ofstream file;
	file.open("UnitTestOutput.txt", std::ios_base::_Nocreate | std::ios_base::app);

	if (file.is_open())
	{
		int testNumber = 0;

		file << "----------------------------------------\n" << "Unit Test Run - Time: " << time(NULL) << "\n\n";

		bool test0 = TestDefaultConstructor();
		file << "Test " << testNumber++ << "\tDefault Constructor\t" << (test0 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tDefault Constructor\t" << (test0 ? "Successful\n" : "Failed\n");

		bool test1 = TestCharOnlyConstructor();
		file << "Test " << testNumber++ << "\tConstructor Char Only\t" << (test1 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tConstructor Char Only\t" << (test1 ? "Successful\n" : "Failed\n");

		bool test2 = TestCharArrayConstructor();
		file << "Test " << testNumber++ << "\tConstructor Char Array\t" << (test2 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tConstructor Char Array\t" << (test2 ? "Successful\n" : "Failed\n");

		bool test3 = TestHeapDefaultConstructor();
		file << "Test " << testNumber++ << "\tDefault Heap Constructor\t" << (test3 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tDefault Heap Constructor\t" << (test3 ? "Successful\n" : "Failed\n");

		bool test4 = TestHeapCharOnlyConstructor();
		file << "Test " << testNumber++ << "\tConstructor Heap Char Only\t" << (test4 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tConstructor Heap Char Only\t" << (test4 ? "Successful\n" : "Failed\n");

		bool test5 = TestHeapCharArrayConstructor();
		file << "Test " << testNumber++ << "\tConstructor Heap Char Array\t" << (test5 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tConstructor Heap Char Array\t" << (test5 ? "Successful\n" : "Failed\n");

		bool test21 = TestCopyConstructor();
		file << "Test " << testNumber++ << "\tCopy Constructor\t" << (test21 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tCopy Constructor\t" << (test21 ? "Successful\n" : "Failed\n");

		bool test6 = TestGetLength();
		file << "Test " << testNumber++ << "\tGetLength\t" << (test6 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tGetLength\t" << (test6 ? "Successful\n" : "Failed\n");

		bool test7 = TestEquals();
		file << "Test " << testNumber++ << "\tEquals\t" << (test7 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tEquals\t" << (test7 ? "Successful\n" : "Failed\n");

		bool test8 = TestAppend();
		file << "Test " << testNumber++ << "\tAppend\t" << (test8 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tAppend\t" << (test8 ? "Successful\n" : "Failed\n");

		bool test9 = TestPrepend();
		file << "Test " << testNumber++ << "\tPrepend\t" << (test9 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tPrepend\t" << (test9 ? "Successful\n" : "Failed\n");

		bool test10 = TestAt();
		file << "Test " << testNumber++ << "\tAt\t" << (test10 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tAt\t" << (test10 ? "Successful\n" : "Failed\n");

		bool test11 = TestSet();
		file << "Test " << testNumber++ << "\tSet\t" << (test11 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tSet\t" << (test11 ? "Successful\n" : "Failed\n");

		bool test12 = TestToUpperCase();
		file << "Test " << testNumber++ << "\tToUpperCase\t" << (test12 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tToUpperCase\t" << (test12 ? "Successful\n" : "Failed\n");

		bool test13 = TestToLowerCase();
		file << "Test " << testNumber++ << "\tToLowerCase\t" << (test13 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tToLowerCase\t" << (test13 ? "Successful\n" : "Failed\n");

		bool test14 = TestGetRaw();
		file << "Test " << testNumber++ << "\tGetRaw\t" << (test14 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tGetRaw\t" << (test14 ? "Successful\n" : "Failed\n");

		bool test15 = TestFind();
		file << "Test " << testNumber++ << "\tFind\t" << (test15 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tFind\t" << (test15 ? "Successful\n" : "Failed\n");

		bool test16 = TestFindFromIndex();
		file << "Test " << testNumber++ << "\tFind(int startIndex, String * neddle)\t" << (test16 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tFind(int startIndex, String * neddle)\t" << (test16 ? "Successful\n" : "Failed\n");

		bool test17 = TestReplace();
		file << "Test " << testNumber++ << "\tReplace\t" << (test17 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tReplace\t" << (test17 ? "Successful\n" : "Failed\n");

		bool test18 = TestEqualsOperator();
		file << "Test " << testNumber++ << "\t=\t" << (test18 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\t=\t" << (test18 ? "Successful\n" : "Failed\n");

		bool test19 = TestCout();
		file << "Test " << testNumber++ << "\tCout\t" << (test19 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tCout\t" << (test19 ? "Successful\n" : "Failed\n");

		bool test20 = TestCin();
		file << "Test " << testNumber++ << "\tCin\t" << (test20 ? "Successful\n" : "Failed\n");
		std::cout << "Test " << testNumber << "\tCin\t" << (test20 ? "Successful\n" : "Failed\n");

		float total = test0 + test1 + test2 + test3 + test4 + test5 + test6 + test7 + test8 + test9 +
			test10 + test11 + test12 + test13 + test14 + test15 + test16 + test17 + test18 +
			test19 + test20 + test21;

		float percentage = (total / testNumber) * 100;

		file << "Success Rate: " << percentage << "%\n";
		std::cout << "Success Rate: " << percentage << "%\n";

	}
	else
	{
		std::cout << "File Not Open!" << std::endl;
	}

	file.close();

	system("pause");
}

bool TestDefaultConstructor()
{
	String testing = String();
	return testing.GetLength() == 0;
}

bool TestCharOnlyConstructor()
{
	String testing = String('a');
	if (testing.GetLength() == 1) 
	{
		if (testing.At(0) == 'a') 
		{
			return true;
		}
	}
	return false;
}

bool TestCharArrayConstructor()
{
	String testing = String("abc");
	if (testing.GetLength() == 3)
	{
		if (testing.At(0) == 'a' && testing.At(1) == 'b' && testing.At(2) == 'c')
		{
			return true;
		}
	}
	return false;
}

bool TestHeapDefaultConstructor()
{
	String* testing = new String();
	bool answer = testing->GetLength() == 0;
	delete testing;
	return answer;
}

bool TestHeapCharOnlyConstructor()
{
	String* testing = new String('a');
	bool answer;
	if (testing->GetLength() == 1) 
	{
		if (testing->At(0) == 'a')
		{
			answer = 1;
		}
		else
		{
			answer = 0;
		}
	}
	else
	{
		answer = 0;
	}
	delete testing;
	return answer;
}

bool TestHeapCharArrayConstructor()
{
	String* testing = new String("abc");
	bool answer;
	if (testing->GetLength() == 3)
	{
		if (testing->At(0) == 'a' && testing->At(1) == 'b' && testing->At(2) == 'c')
		{
			answer = 1;
		}
		else
		{
			answer = 0;
		}
	}
	else
	{
		answer = 0;
	}
	delete testing;
	return answer;
}

bool TestCopyConstructor()
{
	String temp = String("abc");
	String testing = String(&temp);
	if (testing.GetLength() == 3)
	{
		if (testing.At(0) == 'a' && testing.At(1) == 'b' && testing.At(2) == 'c')
		{
			return true;
		}
	}

	return false;
}

bool TestGetLength()
{
	String testing = String("abc");
	return testing.GetLength() == 3;
}

bool TestEquals()
{
	String testing = String("abc");
	return testing.Equals(&String("abc"));
}

bool TestAppend()
{
	String testing = String("abc");
	testing.Append(&String("def"));
	return testing.Equals(&String("abcdef"));
}

bool TestPrepend()
{
	String testing = String("def");
	testing.Prepend(&String("abc"));
	return testing.Equals(&String("abcdef"));
}

bool TestAt()
{
	String testing = String("abc");
	if (testing.At(0) == 'a' && testing.At(1) == 'b' && testing.At(2) == 'c')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool TestSet()
{
	String testing = String("abc");
	testing.Set("def");
	return testing.Equals(&String("def"));
}

bool TestToUpperCase()
{
	String testing = String("abc");
	String* upper = testing.ToUpperCase();
	return upper->Equals(&String("ABC"));
}

bool TestToLowerCase()
{
	String testing = String("ABC");
	String* lower = testing.ToLowerCase();
	return lower->Equals(&String("abc"));
}

bool TestGetRaw()
{
	String testing = String("abc");
	const char* raw = testing.GetCStyleString();

	if (testing.At(0) == raw[0] && testing.At(1) == raw[1] && testing.At(2) == raw[2])
	{
		delete[] raw;
		return true;
	}
	delete[] raw;
	return false;
}

bool TestFind()
{
	String testing = String("Hello World!");
	int index = testing.Find(&String("Wo"));
	if (index == 6) 
	{
		index = testing.Find(&String("ad"));
		if (index == -1)
		{
			return true;
		}
	}

	return false;
}

bool TestFindFromIndex()
{
	String testing = String("Hello World! Good Morning");
	int index = testing.Find(13, &String("or"));
	if (index == 19)
	{
		index = testing.Find(13, &String("lo"));
		if (index == -1)
		{
			return true;
		}
	}

	return false;
}

bool TestReplace()
{
	String testing = String("Hello World!");
	if (testing.Replace(&String("World"), &String("People")))
	{
		if (testing.Equals(&String("Hello People!")))
		{
			if (!testing.Replace(&String("World"), &String("This Shouldn't Work")))
			{
				if (testing.Equals(&String("Hello People!")))
				{
					if (testing.Replace(&String("!"), &String(" Extending Out")))
					{
						if (testing.Equals(&String("Hello People Extending Out")))
						{
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}

bool TestEqualsOperator()
{
	String testing = "abc";
	if (testing.GetLength() == 3)
	{
		if (testing.At(0) == 'a' && testing.At(1) == 'b' && testing.At(2) == 'c')
		{
			return true;
		}
	}
	return false;
}

bool TestCout()
{
	String testing = String("Testing Cout");
	std::cout << std::endl << &testing << std::endl << std::endl;
	return true;
}

bool TestCin()
{
	String testing = String();
	std::cout << std::endl << "Please Write Something: "; 
	std::cin >> &testing;
	std::cout << &testing << std::endl << "Is this what you wrote. Write 1 for yes and 0 for no: ";
	std::cin >> &testing;
	std::cout << std::endl;

	return testing.Equals(&String("1"));
}