#include "QuickMergeAlgorithms.h"

void Merging(std::vector<int> &vet, std::vector<int> &vetAux, int left, int right) {
	int vetSize = (right - left) + 1;
	int middle = (left + right) / 2;
	int x = left, y = middle + 1;
	vetAux = vet;
	for(int i = left; i < right + 1; i++) {
		if(x <= middle && (y > right || vetAux[x] < vetAux[y])) {
			vet[i] = vetAux[x];
			x++;
		}
		else {
			vet[i] = vetAux[y];
			y++;
		}
	}

}

/**
*Vector to be sorted
*Vector auxiliary to merge the vectors
*The first element to be sorted
*the last element (included, so don't pass the array size)
*/
void SplitMerge(std::vector<int> &vet, std::vector<int> &vetAux, int left, int right) {
	if(right - left < 1) return;
	int middle = (right + left) / 2;
	SplitMerge(vet, vetAux, left, middle);
	SplitMerge(vet, vetAux, middle + 1, right);
	Merging(vet, vetAux, left, right);
}

void MergeSort(std::vector<int> &vet) {
	std::vector<int> vetAux;
	SplitMerge(vet, vetAux, 0, vet.size() - 1);
}


void QuickSort(std::vector<int> &vet, int left, int right) {
	int i, j, x;
	i = left;
	j = right;
	x = vet[(left + right) / 2];

	while(i <= j) {
		while(vet[i] < x && i < right)i++;
		while(vet[j] > x && j > left)j--;
		if(i <= j) {
			std::swap(vet[i], vet[j]);
			i++;
			j--;
		}
	}
	if(j > left) QuickSort(vet, left, j);
	if(i < right) QuickSort(vet, i, right);
}