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
	/*ifstream ifs = openFiletoRead(inputFile);

	string line;
	getline(ifs, line);
	Book* a = new Book[1000000];

	for (int i = 0; i < 1000000; ++i)
	{
		getline(ifs, line);
		Book temp = readBook(line);
		a[i] = temp;
	}

	ofstream ofs = openFiletoWrite("Books_rating.txt");

	for (int i = 0; i < 1000000; ++i)
	{
		ofs << a[i].id << "," << a[i].other_info << endl;
	}*/
	//Name of the Result File
	string outputFile;
	outputFile = "sorted_books_rating.csv";

	//externalSort(inputFile, outputFile, numberofElements, numberofFiles);
	mergeFiles(outputFile, numberofElements, numberofFiles);

	return 0;
}