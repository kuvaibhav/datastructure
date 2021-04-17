#include <LLQueue.hpp>

int main()
{
	LLQueue<int> a;
    a.enqueue(3);
    LLQueue<int> b(a);
    return 0;
}

