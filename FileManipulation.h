#include "Heap.h"
#include "Sort.h"
#include <sstream>

ifstream openFiletoRead(string inputFile);
ofstream openFiletoWrite(string inputFile);
Book readBook(string line);
void mergeFiles(string outputFile, int n, int numberofFiles);
void createRun(string inputFile, int size, int numberofFiles);
void externalSort(string inputFile, string outputFile, int size, int numberofFiles);