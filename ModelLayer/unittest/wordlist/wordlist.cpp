#include "wordlist.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//constructor
wordlist::wordlist()
{
}

//deconstructor
wordlist::~wordlist() {
}
//append words in wordlist
void wordlist::addWord(string word){

	words.push_back(word);

	i= words.begin();

}
//get the first word in wordlist
string wordlist::first(){
	return words.front();

}
//get the next word in wordlist
string wordlist::getnext(){
	return words.back();
}


//check if a word exist in wordlist
bool wordlist::isWordinlist(string word){

	if (word == (words.front()))
		return true;
	
	else if (word == (words.back()))
		return true;
	else
		return false;
}



	//read from file
void wordlist::readfile(string filename){
	ifstream readfile;

	string word;
	readfile.open(filename);
	if (readfile.is_open())
	{
		getline(readfile, word);
		if (word != "")
		{
			words.push_back(word);
		}
	}
	
	readfile.close();
}

//write to a file
void wordlist::writeToFile(string filename){

	ofstream myfile;
	if (!myfile.is_open())
	{
		cout << "file dose not exist" << endl;
		
	}
	myfile.open(filename);
	myfile << "write to a file";
	myfile.close();
}


















