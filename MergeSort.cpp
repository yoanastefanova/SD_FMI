// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


///
///	Слива съдържанието на двата сортирани масива pA и pB
///	в масива pResult.
///
///	Масивът получен при сливането също е сортиран.
///	В pResult трябва да има поне sizeA + sizeB елемента,
///	за да може да побере в себе си резултата от сливането.
///
template <class T>
void Merge(T* pA, size_t sizeA, T* pB, size_t sizeB, T* pResult)
{
	size_t i = 0;
	size_t ia = 0;
	size_t ib = 0;

	while (ia < sizeA && ib < sizeB)
		pResult[i++] = (pA[ia] < pB[ib] ? pA[ia++] : pB[ib++]);

	while (ia < sizeA)
		pResult[i++] = pA[ia++];

	while (ib < sizeB)
		pResult[i++] = pB[ib++];
}

template <class T>
void MergeSortStep(T* pArr, size_t Size, T* pBuffer)
{
	if (Size <= 1)
		return;

	size_t middle = Size / 2;

	MergeSortStep(pArr, middle, pBuffer);
	std::cout << "size: " << Size << '\n';// << "mid: " << middle << '\n';

	/*
	for (int i = 0; i < Size; ++i)
	{
		std::cout << pArr[i];
	}
	*/

	/*
	MergeSortStep(pArr + middle, Size - middle, pBuffer + middle);

	Merge(pArr, middle, pArr + middle, Size - middle, pBuffer);

	for (size_t i = 0; i < Size; i++)
		pArr[i] = pBuffer[i];
		*/
}


template <class T>
void MergeSort(T* pArr, size_t Size)
{
	if (!pArr || Size == 0)
		return;

	T* pBuffer = new T[Size];

	MergeSortStep(pArr, Size, pBuffer);

	delete[]  pBuffer;
}


int main()
{
	int arr[] = { 2,7,1,4,3,8,1,5 };
	MergeSort<int>(arr, 8);
	
	/*
	for (int i = 0; i < 8; i++)
	{
		std::cout << arr[i];
	}
	*/
	

   return 0; 
}
