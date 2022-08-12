#include "Benchmark.h"
#include "AllocationTracker.h"


namespace Classic
{
	void Merge(int* unsortedArray, int* leftArray, int* rightArray, unsigned int sizeLeft, unsigned int sizeRight)
	{
		//leftPointerIndex, rightPointerIndex
		unsigned int pLeft = 0;
		unsigned int pRight = 0;
		unsigned int index = 0;

		while (pLeft < sizeLeft && pRight < sizeRight) {
			if (leftArray[pLeft] <= rightArray[pRight])
			{
				//Left is smaller than Right => copy the left value into unsortedArray and increase "pLeft" by one 
				unsortedArray[index] = leftArray[pLeft];
				pLeft++;
			}
			else
			{
				//Right is smaller than Left => copy the Right value into unsortedArray and increase "pRight" by one
				unsortedArray[index] = rightArray[pRight];
				pRight++;
			}
			index++;
		}

		//Copy the remaining values from the left array
		while (pLeft < sizeLeft)
		{
			unsortedArray[index] = leftArray[pLeft];
			pLeft++;
			index++;
		}

		//Copy the remaining of the values from the right array
		while (pRight < sizeRight)
		{
			unsortedArray[index] = rightArray[pRight];
			pRight++;
			index++;
		}

		
	}

	void MergeSort(int* unsortedArray, unsigned int size)
	{
		if (size <= 1)
		{
			return;
		}

		//left Array
		int leftSize = size / 2;
		int* leftArray = new int[leftSize];
		for (int i = 0; i < leftSize; i++)
		{
			leftArray[i] = unsortedArray[i];
		}

		//right Array
		int rightSize = size - leftSize;
		int* rightArray = new int[rightSize];
		for (int i = 0; i < rightSize; i++)
		{
			rightArray[i] = unsortedArray[i + leftSize];
		}

		//sort
		MergeSort(leftArray, leftSize);
		MergeSort(rightArray, rightSize);

		Merge(unsortedArray, leftArray, rightArray, leftSize, rightSize);

		//delete the Arrays after copying them 
		AT_DELETE(leftArray, leftSize);
		AT_DELETE(rightArray, rightSize);
		//--------Track Memory Allocations--------
	}

}