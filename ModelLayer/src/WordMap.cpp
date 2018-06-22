#include "WordMap.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Used to determine which font size is greater
struct WordMap::font_greater_than
{
    inline bool operator() (MapItem& item1, MapItem& item2)
    {
        return (item1.getFontSize() > item2.getFontSize());
    }
};

WordMap::WordMap() {

	}

// Test if the WordMap is empty. If this is true, and you call
// peek or pop, the result is undefined. So don't do that.
bool WordMap::isEmpty() {
	return (list.empty());
	}

// Will return the latest MapItem to the Caller, but not remove
// the list.
MapItem WordMap::peekNext() {
	return list.back();
	}

// Returns the rearmost element, and removes it.
// This reduces wordmap size by 1.
MapItem WordMap::popNext() {
	MapItem item = list.back();
	list.pop_back();
	return item;
	}

// Adds an item to the back of the list.
void WordMap::append(MapItem item) {
	list.push_back(item);
	}

// Reads from a file to add MapItems to the list
bool WordMap::read(std::string str) {
	bool success = true;
	ifstream input;
	input.open(str);
	if (input.fail()) {
		cerr << "File not found" << endl;
		return (!success);
		}
	try {
		string strFromFile;
		while (getline(input, strFromFile)) {
			MapItem newItem = MapItem();
			newItem.fromString(strFromFile);
			list.push_back(newItem);
			}
		input.close();
		return success;
		}
	catch (ifstream::failure e) {
		cerr << "Error in WordMap::read(): File opened but could not be written to" << endl;
		return (!success);
		}
	}

// Traverses the list and writes the items to a file
bool WordMap::write(std::string str) {
	bool success = true;
	int copy = 1;
	string newStr = str;

	while (ifstream(newStr)) // while another file still exists
	{
		newStr.assign(str);
		// TODO: HANDLE FILE EXTENSION?
		newStr.append(" (" + to_string((long long)copy) + ")");
		copy++;
	}

	ofstream output;
	output.open(newStr);

	// [if|of]stream.fail() will fail if one of about 30 conditions are true.
	// Some programs would care about the exact reason for failure, but we don't
	// It doesn't matter if it dies because of aliens or the apocalypse. It's all the same
	if (output.fail()) {
		return (!success);
		}

	try {
		for (int i = 0; i < (int)list.size(); i++) {
			output << list.at(i).toString() << "\n";
			}
		output.close();
		return success;
		}
	catch (ifstream::failure e) {
		cerr << "Unable to open output file! Nothing written." << endl;
		return (!success);
		}
	
	}

// Ascending order
void WordMap::sizeSort(void)
{
	sort(list.begin(), list.end(), font_greater_than());
}

// Shuffles randomly
void WordMap::randomize(void)
{
	random_shuffle(list.begin(), list.end());
}

WordMap::~WordMap()
{
	
}
