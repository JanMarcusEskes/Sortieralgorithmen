// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <chrono>
#include <iostream>

#pragma region Quicksort

int getPivot(int piBegin, int piEnd, std::vector<int> &pcoiData)
{
	int i = piBegin;
	int j = piEnd - 1;
	int liPivot = pcoiData[piEnd];

	do
	{
		while (pcoiData[i] < liPivot && i < piEnd - 1)
		{
			i++;
		}

		while (pcoiData[j] >= liPivot && j > piBegin)
		{
			j--;
		}

		if (i < j)
		{
			int liTemp = pcoiData[i];
			pcoiData[i] = pcoiData[j];
			pcoiData[j] = liTemp;
		}

	} while (i < j);

	if (pcoiData[i] >= liPivot)
	{
		int liTemp = pcoiData[i];
		pcoiData[i] = pcoiData[piEnd];
		pcoiData[piEnd] = liTemp;
		return i;
	}
	else
	{
		return piEnd;
	}
}

void quicksort(int piBegin, int piEnd, std::vector<int> &pcoiData)
{
	if (piBegin < piEnd)
	{
		int liPivot = getPivot(piBegin, piEnd, pcoiData);
		quicksort(piBegin, liPivot - 1, pcoiData);
		quicksort(liPivot + 1, piEnd, pcoiData);
	}
}
#pragma endregion

#pragma region Bubblesort

void bubblesort(std::vector<int> &pcoiData)
{
	for (int &liValue1 : pcoiData)
	{
		for (int &liValue2 : pcoiData)
		{
			if (liValue1 < liValue2)
			{
				int liTemp = liValue1;
				liValue1 = liValue2;
				liValue2 = liTemp;
			}
		}
	}
}

#pragma endregion

#pragma region Selectionsort

void selectionsort(std::vector<int> &pcoiData) {
	for (int i = 0; i < pcoiData.size(); i++) {
		int liMinValue = INT32_MAX;
		int liMinIndex = 0;;

		for (int j = i; j < pcoiData.size(); j++)
		{
			int liValue2 = pcoiData[j];

			if (liValue2 < liMinValue) {
				liMinIndex = j;
				liMinValue = liValue2;
			}
		}

		int liTemp = pcoiData[i];
		pcoiData[i] = pcoiData[liMinIndex];
		pcoiData[liMinIndex] = liTemp;
	}
}

#pragma endregion


int main()
{
	std::chrono::steady_clock::time_point lkStart;
	std::chrono::steady_clock::time_point lkEnd;
	std::chrono::high_resolution_clock timer;
	std::vector<std::chrono::milliseconds> lcokTimes;



	std::vector<int> lcoiInts;

	for (int i = 0; i < 100000; i++) {
		lcoiInts.push_back(rand() % 1000000);
	}

	std::vector<int> lcoiInts2(lcoiInts);
	std::vector<int> lcoiInts3(lcoiInts);


	lkStart = timer.now();
	quicksort(0, lcoiInts.size() - 1, lcoiInts);
	lkEnd = timer.now();
	lcokTimes.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(lkEnd - lkStart));

	lkStart = timer.now();
	bubblesort(lcoiInts2);
	lkEnd = timer.now();
	lcokTimes.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(lkEnd - lkStart));

	lkStart = timer.now();
	selectionsort(lcoiInts3);
	lkEnd = timer.now();
	lcokTimes.push_back(std::chrono::duration_cast<std::chrono::milliseconds>(lkEnd - lkStart));

	for (auto &x : lcokTimes)
	{
		std::cout << "(in ms): " << x.count() << "\n";
	}
	system("pause");

	return 0;
}

