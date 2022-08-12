#include "Benchmark.h"
#include "Timer.h"
#include "TestingTools.h"
#include "AllocationTracker.h"

void TestClassic(const int& size, const int& i)
{
	printf("(%d)%12d", i + 1, size);
	Timer timer;

	int* numbers = new int[size];
	RandomArrayGenerator(numbers, size);

	AllocationTracker::Get().Reset();
	timer.StartTimer();
	Classic::MergeSort(numbers, size);
	timer.StopTimer();

	
	timer.PrintResults("Classic", CheckIfSorted(numbers, size));
	size_t totalAllocated = AllocationTracker::Get().GetTotalAllocated();
	printf(", %8lu MB, %8lu GB (Total Allocated!)\n", totalAllocated / 1000000, totalAllocated / 1000000000);

	AT_DELETE(numbers, size);
}

void TestNoHeap(const int& size, const int& i)
{
	printf("(%d)%12d", i + 1, size);
	Timer timer;

	int* numbers = new int[size];
	RandomArrayGenerator(numbers, size);

	AllocationTracker::Get().Reset();
	timer.StartTimer();
	NoHeap::MergeSort(numbers, size);
	timer.StopTimer();

	timer.PrintResults("Classic", CheckIfSorted(numbers, size));
	size_t totalAllocated = AllocationTracker::Get().GetTotalAllocated();
	printf(", %5lu MB, %5lu GB (Total Allocated!)\n", totalAllocated / 1000000, totalAllocated / 1000000000);

	AT_DELETE(numbers, size);
}


int main()
{
	int numbersCount[5] = { 100000 ,1000000,10000000,100000000,1000000000 };

	
	//Classic 
	{
		std::cout << "Classic MergeSort Benchmark";
		std::cout << "\n-------------------------------------------------------------------------------\n";
		for (int i = 0; i < 5; i++)
		{
			TestClassic(numbersCount[i], i);
		}
		std::cout << "\n-------------------------------------------------------------------------------\n";
	}


	// Without Heap Allocations
	{
		std::cout << "(In Place) MergeSort Benchmark";
		std::cout << "\n-------------------------------------------------------------------------------\n";
		for (int i = 0; i < 5; i++)
		{
			TestNoHeap(numbersCount[i], i);
		}
		std::cout << "\n-------------------------------------------------------------------------------\n";
	}

	std::cin.get();
}
