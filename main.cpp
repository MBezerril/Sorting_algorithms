// SortingAlgorithms.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
// Define to select wich tests run
//#define SELECTION_INSECTION_SORT
#define QUICK_MERGE_SORT
//#define HYBRID_QUICK_SORT
//#define HEAP_SORT

// Define to choose the type of results output
#define VERBOSE_OUTPUT
#define FILE_OUTPUT

// Define the files lines sizes
#define TAM 1000
#define TAM2 10000
#define TAM3 100000

// Standart and custom libraries  
#include <iostream>
#include <list>
#include <string>
#include <time.h>
#include <iomanip>

#include "Utils/FileLoading.h"
#include "Results.h"

#ifdef SELECTION_INSECTION_SORT
#include "Insertion_Selection_Sorting/InsertionSelectionAlgorithms.h"
#endif
#ifdef QUICK_MERGE_SORT
#include "Quick_Merge_Sorting/QuickMergeAlgorithms.h"
#endif

//  -----  Global variables for all tests  ------
//  |-----> Input files
std::string numbers1000_1 = "samples/num.1000.1.in";
std::string numbers1000_2 = "samples/num.1000.2.in";
std::string numbers1000_3 = "samples/num.1000.3.in";
std::string numbers1000_4 = "samples/num.1000.4.in";
std::string numbers10000_1 = "samples/num.10000.1.in";
std::string numbers10000_2 = "samples/num.10000.2.in";
std::string numbers10000_3 = "samples/num.10000.3.in";
std::string numbers10000_4 = "samples/num.10000.4.in";
std::string numbers100000_1 = "samples/num.100000.1.in";
std::string numbers100000_2 = "samples/num.100000.2.in";
std::string numbers100000_3 = "samples/num.100000.3.in";
std::string numbers100000_4 = "samples/num.100000.4.in";

//  |-----> Eviroments variables
bool debug =
#ifdef VERBOSE_OUTPUT
true;
#else
false;
#endif 
bool fileOuputFlag =
#ifdef FILE_OUTPUT
true;
#else
false;
#endif // 
#ifdef SELECTION_INSECTION_SORT
int InsertionSort1000();
int InsertionSort10000();
int InsertionSort100000();
#endif
#ifdef QUICK_MERGE_SORT
int MergeSort1000();
int MergeSort10000();
int MergeSort100000();
int QuickSort1000();
int QuickSort10000();
int QuickSort100000();
#endif

int main()
{
	int sortingResult = 0;
#ifdef SELECTION_INSECTION_SORT
	sortingResult = InsertionSort1000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = InsertionSort10000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = InsertionSort100000();
	if(sortingResult != 0) {
		return sortingResult;
	}
#endif
#ifdef QUICK_MERGE_SORT
	sortingResult = MergeSort1000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = MergeSort10000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = MergeSort100000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = QuickSort1000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = QuickSort10000();
	if(sortingResult != 0) {
		return sortingResult;
	}
	sortingResult = QuickSort100000();
	if(sortingResult != 0) {
		return sortingResult;
	}
#endif
	return 0;
}
#ifdef SELECTION_INSECTION_SORT
int InsertionSort1000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Inserction_Sort_result1000.txt", std::ofstream::out);
	}
	//Sample 1000 - 1
	arraySize = LoadFile(numbers1000_1, numbersArray);
	timeTotal = clock();

	Results result = InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << "Swaps: " << result.swaps << " Comparisons: " << result.comparison << std::endl;
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 2
	arraySize = LoadFile(numbers1000_2, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 3
	arraySize = LoadFile(numbers1000_3, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers1000_4, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}

	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}
int InsertionSort10000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Inserction_Sort_result10000.txt", std::ofstream::out);
	}
	//Sample 1000 - 1
	arraySize = LoadFile(numbers10000_1, numbersArray);
	timeTotal = clock();

	Results result = InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << "Swaps: " << result.swaps << " Comparisons: " << result.comparison << std::endl;
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 2
	arraySize = LoadFile(numbers10000_2, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << "Swaps: " << result.swaps << " Comparisons: " << result.comparison << std::endl;
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 3
	arraySize = LoadFile(numbers10000_3, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << "Swaps: " << result.swaps << " Comparisons: " << result.comparison << std::endl;
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers10000_4, numbersArray);
	timeTotal = clock();

	InsertionSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << "Swaps: " << result.swaps << " Comparisons: " << result.comparison << std::endl;
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}

	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}
int InsertionSort100000() {
	return 0;
}
#endif

//--------------------------------------------------
int MergeSort1000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Merge_Sort_result1000.txt", std::ofstream::out);
	}
	//Sample 1000 - 1
	arraySize = LoadFile(numbers1000_1, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 2
	arraySize = LoadFile(numbers1000_2, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 3
	arraySize = LoadFile(numbers1000_3, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers1000_4, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}

//--------------------------------------------------
int MergeSort10000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Merge_Sort_result10000.txt", std::ofstream::out);
	}
	//Sample 10000 - 1
	arraySize = LoadFile(numbers10000_1, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 2
	arraySize = LoadFile(numbers10000_2, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 3
	arraySize = LoadFile(numbers10000_3, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers10000_4, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}

//--------------------------------------------------
int MergeSort100000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Merge_Sort_result100000.txt", std::ofstream::out);
	}
	//Sample 10000 - 1
	arraySize = LoadFile(numbers100000_1, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 2
	arraySize = LoadFile(numbers100000_2, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 3
	arraySize = LoadFile(numbers100000_3, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers100000_4, numbersArray);
	timeTotal = clock();

	MergeSort(numbersArray);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}

//--------------------------------------------------
int QuickSort1000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Quick_Sort_result1000.txt", std::ofstream::out);
	}
	//Sample 1000 - 1
	arraySize = LoadFile(numbers1000_1, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << std::setprecision(5) << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 2
	arraySize = LoadFile(numbers1000_2, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 3
	arraySize = LoadFile(numbers1000_3, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers1000_4, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}

//--------------------------------------------------
int QuickSort10000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Quick_Sort_result10000.txt", std::ofstream::out);
	}
	//Sample 10000 - 1
	arraySize = LoadFile(numbers10000_1, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 2
	arraySize = LoadFile(numbers10000_2, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 3
	arraySize = LoadFile(numbers10000_3, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers10000_4, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((float)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((float)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}

//--------------------------------------------------
int QuickSort100000() {
	std::ofstream file_output;
	clock_t timeTotal;
	double med = 0;
	std::vector<int> numbersArray;
	int arraySize;

	if(fileOuputFlag) {
		file_output.open("Quick_Sort_result100000.txt", std::ofstream::out);
	}
	//Sample 10000 - 1
	arraySize = LoadFile(numbers100000_1, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) {
			std::cout << i;
			return -1;
		}
	}
	if(fileOuputFlag) {
		file_output << "1: ";
		file_output << ((double)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((double)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 2
	arraySize = LoadFile(numbers100000_2, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "2: ";
		file_output << ((double)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((double)timeTotal) / CLOCKS_PER_SEC;

	//Sample 10000 - 3
	arraySize = LoadFile(numbers100000_3, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "3: ";
		file_output << ((double)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((double)timeTotal) / CLOCKS_PER_SEC;

	//Sample 1000 - 4
	arraySize = LoadFile(numbers100000_4, numbersArray);
	timeTotal = clock();

	//SORTING TIME!
	QuickSort(numbersArray, 0, arraySize-1);

	timeTotal = clock() - timeTotal;
	// Verify if the sorting alrogritm made all correct
	for(int i = 0; i < TAM - 1; i++) {
		if(numbersArray[i] > numbersArray[i + 1]) return -1;
	}
	if(fileOuputFlag) {
		file_output << "4: ";
		file_output << ((double)timeTotal) / CLOCKS_PER_SEC << std::endl;
	}
	med += ((double)timeTotal) / CLOCKS_PER_SEC;

	if(fileOuputFlag) {
		file_output << "average: ";
		file_output << med / 4.0f << std::endl;
	}
	file_output.close();
	std::cout << "media de tempo:" << med / 4.0f << std::endl;
	return 0;
}