// PEAp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Matrix.h"
#include "BruteForce.h"
#include "BranchAndBound.h"
using namespace std;

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}

int main()
{
	int wybor;
	bool work = true;
	LARGE_INTEGER performanceCountStart, performanceCountEnd;

	BruteForce *algo = new BruteForce();
	algo->loadMatrix("karol.txt");
	algo->createNeighborhoodMatrix();
	do {

		cout << "Co chcesz zrobic?" << endl;
		cout << "1.Wyswietlic macierz kosztow" << endl;
		cout << "2.Wyswietlic macierz sasiedztwa" << endl;
		cout << "3.Rozwiazac problem Brute Force" << endl;
		cout << "4.Zakonczyc dzialanie programu" << endl;
		cin >> wybor;

		switch(wybor)
		{ 
		case 1: 
		{
			algo->displayMatrix(); break;
		}

		case 2:
		{
			algo->displayNeighborhoodMatrix(); break;
		}

		case 3:
		{
			performanceCountStart = startTimer();
		algo->TSP(0);
		performanceCountEnd = endTimer();
		double tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
		cout << endl << "Time:" << tm << endl;
		cout << endl << "Droga: ";
		algo->displayRoute();
		cout << endl <<"Koszt: "<< algo->getCost() << endl<<endl; break;
		}

		case 4:
		{
			work = false; break;
		}
		
		default: cout << "Błędny numer" << endl; break;
		
		}





	} while (work);


	
	
	

	//tablica->loadMatrix("karol.txt");
	//tablica->displayMatrix();
	//tablica->getSize();
	//tablica->createNeighborhoodMatrix();
	//tablica->displayNeighborhoodMatrix();
	//algo->displayMatrix();
	
	//algo->displayNeighborhoodMatrix();
	
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
