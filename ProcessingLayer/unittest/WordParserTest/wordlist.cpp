#include "WordList.h"
#include <iostream>
#include <fstream>



//Default Destructor
WordList::~WordList() {}

//Add words sent by WordListParser to the WordList(holds a list of string words)
void WordList::write(string word){
	cout << word;
}

//Provide word to the StemMaker
string WordList::getword(){
	return ("Good WordList!");
}

//Provide stoplist_word to the StemMaker
string WordList::getstoplist(){
	return ("Good StopList!");
}

//Write words back to the file
void WordList::writeToFile(string path) {
	cout<< "Good WriteToFile";
}

