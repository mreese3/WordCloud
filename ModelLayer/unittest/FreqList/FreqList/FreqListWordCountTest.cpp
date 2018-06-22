#include "WordCount.h"
#include "FreqList.h"
#include <iostream>

using namespace std;

int main() {
	
	string filepath = "FileC.txt";
	
	vector<WordCount*> freqList;
	FreqList * freqlist = new FreqList();
	
	for (int i = 0; i < 20; i++)
	{
		int wordLength = rand() % 5 + 5;
		string word;
		for (int i = 0; i < wordLength; i++)
		{
			word += (rand() % 57 + 65);
		}
		WordCount *newWord = new WordCount(word, rand() % 100 + 14);
		freqlist->addinlist(newWord);
	}

	freqList = freqlist->getlist();

	for (int i = 0; i < 20; i++) {
		(freqList.at(i))->print();
	}

	freqlist->getFirst()->print();
	freqlist->getLast()->print();

	cout << "Now we are using the getNext function";
	for (int i = 0; i < 20; i++) {
		freqlist->getNext()->print();
	}
	/*
	cout << "\n2: Read File or path"<<"\n";
	if (freqlist->read(filepath)) {
		cout << "Successful File read\n";
	}else if (!freqlist->read(filepath)) {
		cout << "Unsuccessful File read\n";
	}
	
	*/
	
	/*
	cout<<"\n3: Testing the File write method for file"<< "'" << filepath<< "'" << "\n";
	if (freqlist->write(filepath)) {
		cout << "Successful File write\n";
	}else if (!freqlist->write(filepath)) {
		cout << "Unsuccessful File read\n";
	}
	cout << "\n4: Testing the File write method again for existing file" << "'" << filepath << "'" << "\n";
	if (freqlist->write(filepath)) {
		cout << "Successful File write\n";
	}else if (!freqlist->write(filepath)) {
		cout << "Unsuccessful File write\n";
	}
	cout << "\n5: Testing the File read method again for existing file" << "'" << filepath << "'" << "\n";
	if (freqlist->read(filepath)) {
		cout << "Successful File read\n";
	}else if (!freqlist->read(filepath)) {
		cout << "Unsuccessful File read\n";
	}
	
	cout << "\n6: Testing the getFirst()";
	freqlist->getFirst();

	cout << "\n7: Testing the getLast()\n";
	freqlist->getLast();

	cout << "\n8: Testing the getSize()\n";
	freqlist->getSize();

	cout << "\n9: Testing the sortbycount()\n";
	//freqlist->sortbycount();

	cout << "\n10: Testing the addinlist()\n";
	//freqlist->addinlist(WordCount("Group", 12));

	cout << "\n11: Testing the removefromlist()\n";
	//freqlist->removefromlist();
	
	cout << "\n12: Testing the updatelist()\n";
	
	*/
	//freqlist->updatelist(12);

	//cout << "\n13: Testing the getlist()\n"; 
	//freqlist->getlist();  // method removed

	/*
	cout << "\n14: Testing the TopN()\n";
	//freqlist->Topn(10);

	cout << "\n////////////////////////////////////////////////////////////////////////////////////\n\n";


	cout << "\n/////////////////////////////Testing the WordCount object///////////////////////////\n";
	cout << "Testing the WordCount object\n";
	//Testing the setters setWord() and setCount() methods
	cout << "Testing the setters setWord() and setCount() methods\n";
	//wc->setCount(12);
	//wc->setWord("Group_six");

	//Testing the getters getWord() and getCount() methods
	cout << "Testing the getters getWord() and GetCount() methods\n";
	cout << "Word value: "<<wc->getWord() << "\n";
	cout << "Count value: "<<wc->getCount() << "\n";
	
	//Testing the resetCount() method
	wc->resetCount();
	cout<<"Count value after resetCount():"<<wc->getCount()<<"\n";
	cout << "\n////////////////////////////////////////////////////////////////////////////////////\n\n";


	*/
	







	system("pause");
	return 0;
}