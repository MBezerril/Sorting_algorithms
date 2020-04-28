#include "FileLoading.h"

/*  Loads a file with only one number per line and
	put in the target array.
	Returns the size of the array build from the file if its a valid file.
	Returns -1 if the file isn't open and -2 if there isn't more than one line.
*/
int LoadFile(std::string fileName, std::vector<int> &target) {
	std::ifstream inputFile;
	std::string fileLine;
	std::vector<int> *temp;

	inputFile.open(fileName, std::fstream::in);
	if(!inputFile.is_open()) return -1;
	int linesCount = std::count(std::istreambuf_iterator<char>(inputFile), std::istreambuf_iterator<char>(), '\n');
	inputFile.clear();
	inputFile.seekg(0);
	//Resize the vector to speed up the insertion
	if(target.size()>0)
	{
		target.clear();
	}
	if(linesCount < 1) return -2;
	try {
		for(int i = 0; i < linesCount; i++) {
			inputFile >> fileLine;
			std::stringstream t(fileLine);
			int aux = 0;
			t >> aux;
			target.push_back(std::atoi(fileLine.data()));
		}
	}
	catch(std::exception e) {
		return -3;
	}
	//if(!target) {
		//delete [] target;
		//target = nullptr;
	//}
	return linesCount;
}