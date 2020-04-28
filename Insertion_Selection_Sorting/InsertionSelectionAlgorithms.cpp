#include "InsertionSelectionAlgorithms.h"

Results InsertionSort(std::vector<int> &vet) {
	//std::ofstream results("resultadosInsertion.txt",std::ofstream::out); // arquivo de saida dos vetores ordenados e dos dados da ordenação
	//int comparasions=0,swaps=0, j;
	//clock_t timeTotal; // Variavel que sera usada para contar quantos ticks o processador levou no total
	//timeTotal = clock();
	int SIZE = vet.size();
	int aux;
	Results result;
	for (int i = 0; i < SIZE - 1; i++) {
		aux = i;
		for (int j = i + 1; j<SIZE; j++) {
			if(vet.at(j) < vet.at(aux)) {
				aux = j;
			}
			result.comparison++;
		}
		std::swap(vet[i], vet[aux]);
		result.swaps++;
	}
	return result;
}

void SelectionSort(std::vector<int> &vet) {
	int i, j;
	int SIZE = vet.size();
	for (j = 0; j < SIZE - 1; j++) {
		int minor = j;
		for (i = j + 1; i < SIZE; i++) {
			if (vet[i] < vet[minor]) {
				minor = i;
			}
		}
		if (minor != j) {
			std::swap(vet[j], vet[minor]);
		}
	}
}

