#include "wordlist.h"
#include <iostream>
#include <fstream>
#include <list>

using namespace std;



int main(){

	wordlist word;
	word.addWord("first word");
	word.addWord("next word");
	cout << "the first word is" << "   " << word.first();
	cout << "\n";
	cout << "the seconed word is" << word.getnext();
	cout << "\n";
	cout<< " check to see if the word exist"<< word.isWordinlist("first word");
	cout << "\n";
	word.writeToFile("file.txt");
	word.readfile("file.txt");

	getchar();
	return 0;


}