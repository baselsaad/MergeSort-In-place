#pragma once
#include <random>

int RandomRange(const int& minInclusive, const int& maxExclusive)
{
	int min = minInclusive;
	int max = maxExclusive;

	//if max < min, then swap 
	if (min > max) {
		int temp = min;
		min = max;
		max = temp;
	}

	int size = std::abs(max - min);
	//to avoid dividing by zero
	if (size == 0) {
		return min;
	}

	return min + (rand() % (size));
}

void RandomArrayGenerator(int* ptrArray, unsigned int size)
{
	srand(time(0));
	for (unsigned int i = 0; i < size; i++)
		ptrArray[i] = RandomRange(0, size);
}

bool CheckIfSorted(int* ptrArray, int size) {
	for (int i = 0; i < size - 1; i++)
	{
		if (ptrArray[i] > ptrArray[i + 1])
			return false;
	}

	return true;
}