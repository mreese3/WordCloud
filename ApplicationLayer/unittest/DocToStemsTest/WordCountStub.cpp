#include "WordCount.h"

WordCount::WordCount(string temp, int number) {
	resetCount();
	word = temp;
	count = number;
}

WordCount::~WordCount() {}

void WordCount::resetCount() {
	count = 0;
}

void WordCount::addToCount(int offset) {}

void WordCount::setWord(string word) {}

string WordCount::getWord() { return word; }

void WordCount::setCount(int c) { count = c; }

int WordCount::getCount() { return count; }

string WordCount::getAsString() { return "Good work!"; }

void WordCount::setFromString(string value) {}


