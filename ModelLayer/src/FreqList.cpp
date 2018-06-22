#include "FreqList.h"

using namespace std;

FreqList::FreqList() {
	cout << "Default FreqList constructor creation\n";
}

FreqList::~FreqList() {}

int FreqList::read(string path) {
	ifstream file_input;
	file_input.open(path);
	if (file_input.fail()) {
		cout << "The requested file does not exists\n";
		return 0;
	}
	else if (!file_input.fail()) {
		try{
			string temp;
			while (getline(file_input, temp)) {
				WordCount *wordcount;
				wordcount = new WordCount(temp);
				int test = 0;
				for (int i = 0; i < (int)freqList.size(); i++) {
					if (freqList.at(i)->getWord() == wordcount->getWord()) {
						test++;
					}
				}
				if (test == 0)
					freqList.push_back(wordcount);
			}
			cout << "The requested file has been read\n";
			file_input.close();
			return 1;
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
	//if (ifstream(path)) 
	//{
	//	//append if already file exists--To be added
	//	cout << "The requested file already exists\n";
	//	return 1;
	//}
	//else 
	{
		ofstream output;
		output.open(path, ofstream::out | ofstream::app);
		try {
			for (int i = 0; i < (int)freqList.size(); i++) {
				string wc_string = freqList.at(i)->asString();
				output << wc_string;
				output << endl;
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
	//cout << "This will return the first element\n";
	if (freqList.size()>0) {
		return freqList.front();
	}
	else {
		cout << "No elements in the list\n";
	}
}

WordCount* FreqList::getLast() {
	//cout << "This will return the last element\n";
	if (freqList.size()>0) {
		return freqList.back();
	}
	else {
		cout << "No elements in the list\n";
	}
}

WordCount* FreqList::getNext() {
	/*if (freqList.size() > 0 && !done )
	{
		position = freqList.begin();
		done = true;
	}
	if (position != freqList.end() - 1)
		position++;*/
	try
	{
		if (freqList.size() > 0 && !done)
		{
			position = freqList.begin();
			done = true;
		}
		if (position != freqList.end() - 1)
			position++;
		else
			position = ++freqList.begin();
		return *position;
	}
	catch (exception e)
	{
		position = freqList.begin();
		position++;
		return *position;
	}
	return *position;
}

int FreqList::getSize() {
	//cout << "This would return the size of the list:\n";
	return freqList.size();
}

void FreqList::sortbycount() {
	cout << "Your list is now sorted\n";
	/*for (int i = 0; i < freqList.size(); i++) {
		for (int j = 0; j < freqList.size() - 1; j++) {
		if (freqList.at(j)->getCount() > freqList.at(i)->getCount()) {
		WordCount* atj = freqList.at(j);
		freqList.at(j) = freqList.at(j + 1);
		freqList.at(j + 1) = atj;
		}
		}
		}*/
	int j = 0;
	int swapped = true;
	while (swapped) {
		swapped = false;
		j++;
		for (int i = 0; i < freqList.size() - j; i++)
		{
			if (freqList.at(i)->getCount() < freqList.at(i + 1)->getCount()) {
				WordCount* atj = freqList.at(i);
				freqList.at(i) = freqList.at(i + 1);
				freqList.at(i + 1) = atj;
				swapped = true;
			}
		}
	}
}

void FreqList::addinlist(WordCount* wc) {
	//cout << "Added the desired element\n";
	freqList.push_back(wc);
	//if (freqList.size() == 1)
	//Resetting the position of the iterator will avoid the comparison of two different iterators (an issue presented by StemmedList) and iterator invalidation!
		position = freqList.begin();
}

WordCount* FreqList::remove() {
	//cout << "Pop out the elements from the back one by one";
	WordCount *wc;
	if (freqList.size() > 0) {
		wc = freqList.at(freqList.size() - 1);
		freqList.pop_back();
		position--;
		return wc;
	}
	else {
		cout << "The list is empty";
	}
}

void FreqList::removeall() {
	cout << "Remove all the elements from the Freqlist\n";
	freqList.clear();
}

vector<WordCount*> FreqList::getlist() {
	cout << "Return the reference to the FreqList\n";
	return freqList;
}

vector<WordCount*> FreqList::Topn(int index) {
	cout << "The Top" << index << "list is being displayed\n";
	sortbycount();
	if (index > freqList.size()) {
		cout << "The index value has exceeded the maximum size limit of the list";
	}
	else{
		for (int i = index; i < freqList.size(); i++) {
			position = freqList.begin();
			freqList.erase(position + i);
		}
	}
	return freqList;
}
