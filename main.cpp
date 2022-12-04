#include "Heap.h"
#include "Sort.h"
#include "FileManipulation.h"
using namespace std;


int main()
{
	//Number of Sketch File
	int numberofFiles = 500;

	//Number of Element in each Sketch File
	int numberofElements = 6000;

	//Name of the file to be sorted
	string inputFile;
	inputFile = "Books_rating.csv";

	//Name of the Result File
	string outputFile;
	outputFile = "sorted_books_rating.csv";

	externalSort(inputFile, outputFile, numberofElements, numberofFiles);
	
	return 0;
}
