#include "gtest/gtest.h"
#include "LLQueue.hpp"


namespace{


// NOTE:  these are not intended as exhaustive tests.
	// This should get you started testing.
	// You should make your own additional tests for the queue
	// VERY IMPORTANT:  if your LLQueue is not templated, or if 
	//		it is not linked-list based, your score for this project
	//		will be zero.  Be sure your LLQueue compiles and runs 
	// 		with non-numeric data types. 
	//		(recall that 'char' in C++ is numeric, but std::string is not)

TEST(QueueTest, QueueTest1)
{
	LLQueue<int> a;
	a.enqueue(5);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, Only_Enqueue_Int)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	EXPECT_TRUE( a.front() == 5 );
}

TEST(QueueTest, Only_Enqueue_Strings)
{
	LLQueue<std::string> a;
	a.enqueue("x");
	a.enqueue("y");
	EXPECT_TRUE( a.front() == "x" );
}

TEST(QueueTest, Only_Enqueue_One_String)
{
	LLQueue<std::string> a;
	a.enqueue("xyz");
	EXPECT_TRUE( a.front() == "xyz" );
}

TEST(QueueTest, QueueTest3)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.front() == 3 );
}

TEST(QueueTest, Dequeue_When_Queue_is_Empty)
{
	LLQueue<int> a;
	EXPECT_THROW( a.dequeue(), QueueEmptyException);
}

TEST(QueueTest, Front_When_Queue_is_Empty)
{
	LLQueue<int> a;
	EXPECT_THROW( a.front(), QueueEmptyException);
}

TEST(QueueTest, isEmpty_When_Queue_is_Empty)
{
	LLQueue<int> a;
	EXPECT_TRUE( a.isEmpty() == true);
}

TEST(QueueTest, isEmpty_When_Queue_is_not_Empty)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_FALSE( a.isEmpty() == true );
}

TEST(QueueTest, Size_When_Queue_is_not_Empty)
{
	LLQueue<int> a;
	a.enqueue(5);
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.size() == 1 );
}

TEST(QueueTest, Size_When_Queue_is_Empty)
{
	LLQueue<int> a;
	a.enqueue(3);
	a.dequeue();
	EXPECT_TRUE( a.size() == 0 );
}

TEST(QueueTest, CopyConstructorString)
{
	LLQueue<std::string> a;
	a.enqueue("first");
	a.enqueue("second");
	a.dequeue();
	LLQueue<std::string> b(a);
	a.enqueue("third");
	a.enqueue("fourth");
	a.dequeue();
	b.front();
	EXPECT_TRUE( b.front() == "second");
}

TEST(QueueTest, CopyConstructorInteger)
{
	LLQueue<int> a;
	a.enqueue(1);
	a.enqueue(2);
	a.dequeue();
	LLQueue<int> b(a);
	a.enqueue(3);
	a.enqueue(4);
	a.dequeue();
	b.front();
	EXPECT_TRUE( b.front() == 2);
}

TEST(QueueTest, AssignmentInteger)
{
	LLQueue<int> a;
	a.enqueue(1);
	a.enqueue(2);
	a.dequeue();
	LLQueue<int> b = a;
	a.enqueue(3);
	a.enqueue(4);
	a.dequeue();
	b.front();
	EXPECT_TRUE( b.front() == 2);
}

TEST(QueueTest, AssignmentNonEmptySize)
{
	LLQueue<int> a;
	LLQueue<int> b;
	a.enqueue(1);
	b.enqueue(2);
	a.enqueue(3);
	b.enqueue(4);
	a.enqueue(5);
	b.enqueue(6);
	a = b;

	EXPECT_FALSE( a.size() == 6);
}

TEST(QueueTest, AssignmentIntegerNonEmpty)
{
	LLQueue<int> a;
	LLQueue<int> b;
	a.enqueue(1);
	b.enqueue(2);
	a.enqueue(3);
	b.enqueue(4);
	a.enqueue(5);
	b.enqueue(6);
	a = b;

	EXPECT_TRUE( a.front() == 2);
}

TEST(QueueTest, AssignmentIntegerNonEmptyTwo)
{
	LLQueue<int> a;
	LLQueue<int> b;
	a.enqueue(1);
	b.enqueue(2);
	a.enqueue(3);
	b.enqueue(4);
	a.enqueue(5);
	b.enqueue(6);
	a = b;

	EXPECT_FALSE( a.front() == 1);
}

TEST(QueueTest, AssignmentIntegerNonEmptySizeTwo)
{
	LLQueue<int> a;
	LLQueue<int> b;
	a.enqueue(1);
	b.enqueue(2);
	a.enqueue(3);
	b.enqueue(4);
	a.enqueue(5);
	b.enqueue(6);
	a = b;

	EXPECT_TRUE( a.size() == 3);
}

TEST(QueueTest, SimpleSizeTest)
{
	LLQueue<std::string> a;
	a.enqueue("abc");
	a.enqueue("def");
	a.enqueue("ghi");
	a.enqueue("jkl");
	a.enqueue("mno");
	a.enqueue("pqr");
	a.dequeue();
	a.dequeue();
	a.enqueue("stu");

	EXPECT_TRUE( a.size() == 5);
}

TEST(QueueTest, AssignmentAndDequeue)
{
	LLQueue<float> a;
	a.enqueue(1.234);
	a.enqueue(2.456);
	a.enqueue(3.4543);
	LLQueue<float> b;
	b.enqueue(12.456);
	b = a;
	b.dequeue();
	b.dequeue();
	b.dequeue();

	EXPECT_TRUE(b.isEmpty() == true);
	EXPECT_FALSE(a.isEmpty() == true);
}

}
