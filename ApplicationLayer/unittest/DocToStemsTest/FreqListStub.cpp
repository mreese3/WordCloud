#include "FreqList.h"

using namespace std;

FreqList::FreqList() {
	//cout << "Default constructor creation\n";
	_current_item = 0;
}

FreqList::~FreqList() {}

int FreqList::read(string path) {
	_current_item = 0;
	ifstream file_input;
	file_input.open(path);
	if (file_input.fail()) {
		cout << "The requested file does not exists\n";
		return 0;
	}
	else if (!file_input.fail()) {
		try{
			// FreqList doesn't have anything to do with
			//while (getline(file_input, path)) {
			//	MapItem map_item = MapItem();
			//	map_item.fromString(path);
			//	for (int i = 0; i < freqList.size(); i++) {
			//		if ((freqList.at(i)->getWord()) == map_item.getWord()) {
			//		}
			//		else {
			//			string word = map_item.getWord();
			//			int count = map_item.getFontSize();
			//			freqList.push_back(new WordCount(word, count));
			//		}
			//	}
			//}
			//file_input.close();
			//return 1;
			//cout << "The requested file has been read\n";
			//file_input.close();
			//return 1;
		}
		catch (exception e){
			cout << "The requested file cannot be read\n";
			return 0;
		}
	}
	return 0;
}


int FreqList::write(string path) {
	ifstream file_input;
	if (ifstream(path)) {
		//append if already file exists
		cout << "The requested file already exists\n";
		return 1;
	}
	else {
		ofstream output;
		output.open(path);
		try {
			for (int i = 0; i < freqList.size(); i++) {
				string word = freqList.at(i)->getWord();
				int count = freqList.at(i)->getCount();
				string sc = ";";
				string mapstring = word + to_string(count) + sc + to_string(count) + sc + to_string(count) + sc
					+ to_string(count) + sc + to_string(count) + sc;
				output << mapstring;
			}
			cout << "The requested file has been created\n";
			output.close();
			return 1;
		}
		catch (exception e) {
			cout << "The requested file cannot be opened\n";
			return 0;
		}
	}
}


WordCount* FreqList::getFirst() {
	_current_item = 0;
	//cout << "This will return the first element\n";
	if (freqList.size()>0){
		WordCount* wc = freqList.at(0);
		return wc;
	}
	else {
		//cout << "No elements in the list";
		return 0;
	}
}

WordCount* FreqList::getNext() {
	if (freqList.size() <= 0)
		return 0;
	_current_item++;
	return freqList.at(_current_item);
}


WordCount* FreqList::getLast() {
	//cout << "This will return the last element\n";
	_current_item = freqList.size() - 1;
	if (freqList.size()>0) {
		WordCount* wc = freqList.at(freqList.size() - 1);
		return wc;
	}
	else {
		//cout << "No elements in the list";
		return 0;
	}
}

int FreqList::getSize() {
	//cout << "Specify the list item number for getting the size\n";
	return freqList.size();
}

void FreqList::sortbycount() {
	//cout << "Your list is now sorted\n";
	for (int i = 0; i < freqList.size(); i++) {
		for (int j = 0; j < freqList.size() - 1; j++) {
			if (freqList.at(j)->getCount() > freqList.at(j + 1)->getCount()) {
				WordCount* atj = freqList.at(j);
				freqList.at(j) = freqList.at(j + 1);
				freqList.at(j + 1) = atj;
			}
		}
	}
}

void FreqList::addinlist(WordCount* wc) {
	cout << "Added the desired element\n";
	freqList.push_back(wc);
}

/*
WordCount FreqList::removefromlist() {
WordCount wc("Test", 5);
cout << "This will remove an item from list\n";
return wc;
}
*/

/*
void FreqList::updatelist(int count) {
cout << "The list is updated\n";
}
*/

// don't expose the implementation
//vector<WordCount*> FreqList::getlist() {
//	return freqList;
//}

void FreqList::topn(int index) {
	cout << "The Top" << index << "list is being displayed\n";
	sortbycount();
	if (index > freqList.size()) {
		cout << "The index value has exceeded the maximum size limit of the list";
	}
	else{
		for (int i = index; i < freqList.size(); i++) {
			freqList.erase(start + i);
		}
	}
	//return freqList; don't return the list-- this exposes your implementation
}
