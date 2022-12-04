#pragma once
#include "FileManipulation.h"
using namespace std;
ifstream openFiletoRead(string inputFile)
{
	ifstream result;
	result.open(inputFile);

	if (!result.is_open())
	{
		cout << "Cannot open file to read!" << endl;
	}
	return result;
}

ofstream openFiletoWrite(string outputFile)
{
	ofstream result;
	result.open(outputFile);

	if (!result.is_open())
	{
		cout << "Cannot open file to write!" << endl;
	}
	return result;
}

//After read one line in the Input File, this function separate the infomation and store it in new Book
Book readBook(string line)
{
	vector <string> newBook = split(line, ",");

	Book result;
	result.id = newBook[0];
	result.other_info = newBook[1];

	return result;
}

//Merge Sketch Files into the Result File
void mergeFiles(string outputFile, int n, int numberofFiles)
{
	//Create an array of file pointers to open the Sketch Files to read
	ifstream* ifs = new ifstream[numberofFiles];
	for (int i = 0; i < numberofFiles; ++i)
	{
		//Respectively create the Sketch Files named: "1.txt","2.txt",.....
		string name = to_string(i);

		stringstream builder;

		builder << name << ".txt";

		string file = builder.str();
		ifs[i] = openFiletoRead(file);
	}

	//Open the Result File to write the last result
	ofstream ofs(outputFile);

	//Create the same amount of HeapNode as the number of Sketch Files to store the first element of every Sketch File
	HeapNode* arr = new HeapNode[numberofFiles];
	int i = 0;

	//Read the first element of Sketch Files into [numofFiles] HeapNode
	for (; i < numberofFiles; ++i)
	{
		string line;
		getline(ifs[i], line);

		Book a = readBook(line);
		arr[i] = createHeapNode(a, i);
	}

	//Create a min-heap 

	MinHeap heap(arr, i);

	//cnt is the number of Sketch Files that have read fully
	int cnt = 0;
	//End while if every Sketch File was read fully
	while (cnt != i)
	{
		//Write the smallest element of Min-Heap into the Result File
		HeapNode root = heap.getMin();
		printNodetoFile(ofs, root);
		//Check whether the file containing the smallest element was read fully or not
		string line;
		getline(ifs[root.index], line);
		if (line == "")
		{
		//If done remove root as it going to the last index of Min-Heap
			root.element.id = INT_MAX;
		//Mark one file done
			++cnt;
		}
		else
		{
		//Read new element to the Min-Heap
			Book a = readBook(line);
			root = createHeapNode(a, root.index);
		}
		//Reorganize Min-Heap after the insertion
		heap.replaceMin(root);
	}
	cout << endl;
	
	//Close all files after reading and writing
	for (int i = 0; i < numberofFiles; ++i)
	{
		ifs[i].close();
	}

	ofs.close();
}

void createRun(string inputFile, int size, int numberofFiles)
{
	//Open the file to be sorted
	ifstream ifs = openFiletoRead(inputFile);

	//Skip the first line of file as it was : "Id,Title,Price,User_id,profileName,review/helpfulness,review/score,review/time,review/summary,review/text"
	string line;
	getline(ifs, line);

	//Open the Sketch Files to start reading
	ofstream* ofs = new ofstream[numberofFiles];


	for (int i = 0; i < numberofFiles; ++i)
	{
		stringstream builder;

		builder << to_string(i) << ".txt";

		string file = builder.str();

		ofs[i] = openFiletoWrite(file);
	}

	//Create one temp array to store the same amount of elements as the number of elements to be put in one Sketch File
	Book* bookRun = new Book[size];

	bool stillread = true;
	//Index of Sketch File
	int current = 0;

	int i;
	while (current < numberofFiles)
	{
		for (i = 0; i < size; ++i)
		{
			string line;
			//If already reach the end of Input File, stop reading
			getline(ifs, line);
			if (line == "")
			{
				stillread = false;
				break;
			}
			else
			{
			//Else continue reading
				bookRun[i] = readBook(line);
			}
		}
		//Sort the temp array by Quick Sort
		quickSort(bookRun, 0, i - 1);

		//Write the elements into Sketch Files
		for (int j = 0; j < i; ++j)
		{
			ofs[current] << bookRun[j].id << "," << bookRun[j].other_info << endl;
		}

		++current;
	}

	//Close all the files after reading and writing
	for (int i = 0; i < numberofFiles; ++i)
	{
		ofs[i].close();
	}
}

void externalSort(string inputFile, string outputFile, int size, int numberofFiles)
{
	createRun(inputFile, size, numberofFiles);

	mergeFiles(outputFile, size, numberofFiles);
}
