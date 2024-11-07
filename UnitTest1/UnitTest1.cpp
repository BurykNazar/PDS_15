#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab15\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestSmallBoardNoSolution)
		{
			N = 2;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			solutions.clear();

			solveUtility(0, 0, 0, 0);

			Assert::IsTrue(solutions.empty());
		}

		TEST_METHOD(TestSmallBoardSingleSolution)
		{
			N = 1;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			solutions.clear();

			solveUtility(0, 0, 0, 0);

			Assert::AreEqual((size_t)1, solutions.size());
			Assert::AreEqual(1, solutions[0][0][0]);
		}

		TEST_METHOD(Test4x4Board)
		{
			N = 4;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			solutions.clear();

			solveUtility(0, 0, 0, 0);

			Assert::AreEqual((size_t)2, solutions.size());
		}

		TEST_METHOD(Test8x8Board)
		{
			N = 8;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			solutions.clear();

			solveUtility(0, 0, 0, 0);

			Assert::AreEqual((size_t)92, solutions.size());
		}

		TEST_METHOD(TestCanPlaceQueenTrue)
		{
			N = 4;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			board[0][1] = 1;

			Assert::IsTrue(canPlaceQueen(1, 3));
		}

		TEST_METHOD(TestCanPlaceQueenFalse)
		{
			N = 4;
			board = vector<vector<int>>(N, vector<int>(N, 0));
			board[0][1] = 1;

			Assert::IsFalse(canPlaceQueen(1, 1));
		}
	};
}
