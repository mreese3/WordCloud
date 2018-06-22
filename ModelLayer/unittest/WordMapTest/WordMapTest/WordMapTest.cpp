// Testing WordMap(w/MapItem,Point,Size)

#include "WordMap.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Creating WordMap object...\n";
	WordMap wordMap = WordMap();

	cout << "Creating Initial files: inputA and inputB" << endl;
	if (wordMap.write("inputA") && wordMap.write("inputB")) {
		cout << "Inital file writes succeeded!" << endl;
		}
	else {
		cout << "Inital file writes failed!" << endl;
		cout << "Critical ERROR!" << endl;
		return 1;
		}

	cout << "\n=====================================================\n" << endl;

	cout << "File A\n";

	cout << "Testing 'file not found'...\n";
	if (!(wordMap.read("nothing"))) {
		}
	else {
		cout << "That's weird, we suceeded." << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing read() on 'inputA'...\n";
	if (wordMap.read("inputA")) {
		cout << "Read succeeded!" << endl;
		}
	else {
		cout << "Read failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing write() on 'outputA'...\n";
	if (wordMap.write("outputA")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing multiple writes on 'outputA'...\n";
	if (wordMap.write("outputA")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}
	if (wordMap.write("outputA")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}
	if (wordMap.write("outputA")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}


	cout << "Testing sizeSort()...\n";
	wordMap.sizeSort();
	if (wordMap.write("outputA-sizeSort")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing randomize()...\n";
	wordMap.randomize();
	if (wordMap.write("outputA-randomize")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}



	cout << "\n=====================================================\n" << endl;

	cout << "File B\n";
	cout << "Creating WordMap object...\n";
	WordMap wordMap2 = WordMap();

	cout << "Testing 'file not found'...\n";
	if (!(wordMap2.read("nothing"))) {
		}
	else {
		cout << "That's weird, we suceeded." << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing read() on 'inputB'...\n";
	if (wordMap2.read("inputB")) {
		cout << "Read succeeded!" << endl;
		}
	else {
		cout << "Read failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing write() on 'outputB'...\n";
	if (wordMap.write("outputB")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}


	cout << "Testing multiple writes on 'outputB'...\n";
	if (wordMap.write("outputB")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}
	if (wordMap.write("outputB")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}
	if (wordMap.write("outputB")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}



	cout << "Testing sizeSort()...\n";
	wordMap2.sizeSort();
	if (wordMap2.write("outputB-sorted")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "Testing randomize()...\n";
	wordMap2.randomize();
	if (wordMap2.write("outputB-random")) {
		cout << "Write succeeded!" << endl;
		}
	else {
		cout << "Write failed!" << endl;
		cout << "ERROR!" << endl;
		}

	cout << "\n=====================================================\n" << endl;

	cout << "Cleaning up with \"del output*\" and \"del input*\"" << endl;
	system("del input*");
	system("del output*");

	cout << "\n=====================================================\n" << endl;

	WordMap map = WordMap();
	cout << "Testing input and output" << endl;
	MapItem item = MapItem();
	item.fromString("Rick;3;1555;356;386;2444;");
	cout << "Trying to add an item" << endl;
	map.append(item);
	cout << "Expecting Rick;3;1555;356;386;2444;" << endl;
	cout << "map.peekNext(); = " << (map.peekNext()).toString() << endl;

	cout << "Trying popNext()" << endl;
	cout << "map.popNext() = " << (map.popNext()).toString() << endl;

	cout << "The map should be empty. Is it?" << endl;
	if (map.isEmpty()) {
		cout << "Yes! Success!" << endl;
		}
	else {
		cout << "The map either still has contents, or isEmpty is wrong" << endl;
		cout << "ERROR!" << endl;
		}

	system("pause");
	return 0;
}