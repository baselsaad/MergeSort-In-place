#include "Benchmark.h"

namespace NoHeap {

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
		int* leftArray = &unsortedArray[0];

		//right Array
		int rightSize = size - leftSize;
		int* rightArray = &unsortedArray[leftSize]; // beginn with last index from right

		//sort
		MergeSort(leftArray, leftSize);
		MergeSort(rightArray, rightSize);

		//int* sortedArray = merge(leftSorted, rightSorted, leftSize, rightSize);
		Merge(unsortedArray, leftArray, rightArray, leftSize, rightSize);

	}

}


