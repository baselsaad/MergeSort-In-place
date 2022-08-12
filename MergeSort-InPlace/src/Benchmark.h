#pragma once
#ifndef BENCHMARK
#define BENCHMARK


namespace Classic
{
	void Merge(int* unsortedArray, int* leftArray, int* rightArray, unsigned int sizeLeft, unsigned int sizeRight);
	void MergeSort(int* unsortedArray, unsigned int size);
}

namespace NoHeap
{
	void Merge(int* unsortedArray, int* leftArray, int* rightArray, unsigned int sizeLeft, unsigned int sizeRight);
	void MergeSort(int* unsortedArray, unsigned int size);
}

#endif
