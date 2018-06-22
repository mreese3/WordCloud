#include "wordlist.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//constructor
wordlist::wordlist()
{
	words.clear();
	it = words.begin();
}

//deconstructor
wordlist::~wordlist() {
}

int wordlist::getSize()
{
	return words.size();
}
//append words in wordlist
void wordlist::addWord(string word){

	words.push_back(word);

	//i= words.begin();

}
//get the first word in wordlist
string wordlist::first(){
	it = words.begin();
	if (it == words.end())
		return 0;
	else
		return words.front();

}
//get the next word in wordlist
string wordlist::getnext(){
	it++;
	if (it == words.end())
		return "";
	else
		return *it;
}


//check if a word exist in wordlist
bool wordlist::isWordinlist(string word){

	list<string>::iterator iter;
	iter = words.begin();
	for (int i = 1; i < words.size(); i++)
	{
		string wordFromList = *iter;
		if (word == wordFromList)
			return true;
		iter++;
	}
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