#include "pch.h"
#include "CppUnitTest.h"
#include "../АиСД. Лабораторная работа 2/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestlab2)
	{
	public:
		
		TEST_METHOD(QuickSortTest)
		{
			const int test = 5;
			int* array = new int[test];
			int start = 0; int end = test - 1;
			qSort(array, start, end);
			for (int i = 0; i < test - 1; i++) 
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[]array;
		}
		TEST_METHOD(BogoSortTest)
		{
			const int test = 10;
			int* array = new int[test];
			bogoSort(array, test);
			for (int i = 0; i < test - 1; i++) 
			{
				Assert::IsTrue(array[i] <= array[i + 1]);
			}
			delete[]array;
		}
		TEST_METHOD(CountingSortTest)
		{
			const int test_size = 3;
			char* test_array = new char[test_size];
			test_array[0] = 'c';
			test_array[1] = 'b';
			test_array[2] = 'a';
			countingSort(test_array, test_size);
			Assert::IsTrue(test_array[0] == 'a');
			Assert::IsTrue(test_array[1] == 'b');
			Assert::IsTrue(test_array[2] == 'c');

			delete[]test_array;
		}

		TEST_METHOD(InsertionSortTest)
		{
			const int test = 10;
			int* array = new int[test];
			insertionSort(array, test);
			for (int i = 0; i < test-1; i)
			{
				Assert::IsTrue(array[i] <= array[i]);
			}
			delete[]array;

		}
		TEST_METHOD(BinarySortTest)
		{
			int testsize = 8;
			int* array = new int[testsize];
			for (int i = 0; i < testsize - 1; i++) {
				array[i] = i;
			}
			for (int i = 0; i < testsize - 1; i++) {
				Assert::IsTrue(binarySearch(array, i, testsize) == i);
			}
			try {
				binarySearch(array, testsize*3, testsize);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is no such element in the array", error.what());
			}
		}

	};
}