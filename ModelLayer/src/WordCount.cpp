#include "WordCount.h"

using namespace std;

WordCount::WordCount(string temp,int number) { 
	resetCount();
	word = temp;
	count = number;
}

WordCount::WordCount(string line) {
	fromString(line);
}

WordCount::~WordCount() {}

void WordCount::resetCount() {
	count = 0;
}

void WordCount::print() {

	cout << word<<endl;
	cout << count<<"\n";

}

//void WordCount::addToCount(int offset) {}

//void WordCount::setWord(string word) {}

string WordCount::getWord() { return word; }

void WordCount::setCount(int c) { count = c; }

int WordCount::getCount() {	return count;}

string WordCount::asString() {
	string word_string = getWord();
	int count_string = getCount();
	string wcstring = word_string + ";" + to_string(count_string);
	return wcstring;
}

void WordCount::fromString(string line) {
	int i = 0;
	string temp;
	while (true) {
		if(line[i] != ';'){
			temp = line[i];
			word.append(temp);
			i++;
		}
		else if (line[i] == ';') {
		break;
		}
	}
	i++;
	string count_string;
	for (int j = i; j < line.length(); j++) {
		count_string = count_string + line[j];
	}
	count = atoi(count_string.c_str());

}


