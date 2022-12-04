#pragma once
#include "String.h"

vector <string> split(string line, string separator)
{
	vector<string> result;

	int startPos = 0;
	size_t foundPos = line.find(separator, startPos);

	if (foundPos != string::npos)
	{
		string token = line.substr(startPos, foundPos);
		result.push_back(token);
	}

	startPos = foundPos + separator.size();

	string token = line.substr(startPos, line.size() - startPos);
	result.push_back(token);

	return result;
}