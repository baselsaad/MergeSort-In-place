#pragma once


/*
* Basic Memory Allocation Tracker
*/
class AllocationTracker
{
public:
	AllocationTracker(const AllocationTracker&) = delete;

public:
	static AllocationTracker& Get();

	inline size_t GetCurrentUsage() { return Usage; };

	inline size_t GetTotalAllocated() { return TotalAllocated; };

	inline size_t GetTotalFreed() { return TotalFreed; };

	void Increase(size_t size);

	void PrintMemoryUsage() const;

	void Reset();

	void Del(size_t size);

	void DeleteArray(void* memoryAddress, size_t size);

private:
	AllocationTracker();
	static AllocationTracker s_Instance;

private:
	size_t TotalAllocated = 0;
	size_t Usage = 0;
	size_t TotalFreed = 0;
	size_t TotalAllocationsCount = 0;
};

#define AT_DELETE(PTR,SIZE) AllocationTracker::Get().DeleteArray(PTR,SIZE)



