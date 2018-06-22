#include "FreqList.h"

using namespace std;

FreqList::FreqList() {
	_current_item = 0;
}

FreqList::~FreqList() {}

int FreqList::read(string path) {
	return 0;
}

void FreqList::write(string path) {
	ofstream output;
	output.open(path + ".txt", std::ios_base::app);
	_current_item = 0;
	while (_current_item < getSize())
	{
		output << "Word: " << freqList.at(_current_item)->getWord() << "   Count: " << freqList.at(_current_item)->getCount() << endl;
		_current_item++;
	}
}


WordCount* FreqList::getFirst() {
	int temp = _current_item;
	_current_item = 0;
	if (freqList.size() > 0){
		WordCount* wc = freqList.at(0);
		_current_item = temp;
		return wc;
	}
	else {
		_current_item = temp;
		return 0;
	}
}

WordCount* FreqList::getNext() {
	if (freqList.size() <= 0)
		return 0;
	_current_item++;
	return freqList.at(_current_item - 1);
}

WordCount* FreqList::getLast() {
	int temp = _current_item;
	_current_item = freqList.size() - 1;
	if (freqList.size() > 0) {
		WordCount* wc = freqList.at(freqList.size() - 1);
		_current_item = temp;
		return wc;
	}
	else {
		_current_item = temp;
		return 0;
	}
}

int FreqList::getSize() {
	return freqList.size();
}

void FreqList::sortbycount() {
	
}
void FreqList::addinlist(WordCount* wc) {
	freqList.push_back(wc);
}

void FreqList::topn(int index) {

}
void FreqList::setCurrentItem(int index)
{
	if (index >= 0 && index < getSize())
	{
		_current_item = index;
	}
}