#include "AllocationTracker.h"

#include <iostream>

AllocationTracker AllocationTracker::s_Instance;

AllocationTracker::AllocationTracker()
	: TotalAllocated(0), TotalFreed(0)
{
}

void AllocationTracker::Increase(size_t size)
{
	TotalAllocationsCount++;
	TotalAllocated += size;
	Usage += size;
}

void AllocationTracker::Del(size_t size)
{
	TotalFreed += size;
	Usage -= size;
}

void AllocationTracker::PrintMemoryUsage() const
{
	std::cout << "\n-----------------------------------------------------------------------------\n";
	std::cout << "\nCurrent Memory Usage: " << AllocationTracker::Get().GetCurrentUsage() / 1000000 << " MB\n";
	std::cout << "\nTotal Memory Allocated: " << AllocationTracker::Get().GetTotalAllocated() / 1000000 << " MB\n";
	std::cout << "\nTotal Memory Freed: " << AllocationTracker::Get().GetTotalFreed() / 1000000 << " MB\n";
	std::cout << "\nTotal Allocations Count: " << AllocationTracker::Get().TotalAllocationsCount << "\n";
	std::cout << "\n-----------------------------------------------------------------------------\n";
}

void AllocationTracker::Reset()
{
	TotalAllocated = 0;
	TotalFreed = 0;
	Usage = 0;
	TotalAllocationsCount = 0;
}

/*
* Simple Method to releace Memory of a Array (to track memory allocation)
*/
void AllocationTracker::DeleteArray(void* memoryAddress, size_t size)
{
	AllocationTracker::Get().Del(size * 4);
	delete[](int*)memoryAddress;
}

AllocationTracker& AllocationTracker::Get()
{
	return s_Instance;
}

void* operator new(std::size_t size)
{
	AllocationTracker::Get().Increase(size);
	return malloc(size);
}

void operator delete(void* memoryAdrress, std::size_t size)
{
	AllocationTracker::Get().Del(size);
	free(memoryAdrress);
}


