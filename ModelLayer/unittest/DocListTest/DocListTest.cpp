#include "DocList.h"

int main()
{
	DocList* f = new DocList("freqlist.txt");
	cout<<"First: "<<f->getFirst()->getWord()<<", "<<f->getFirst()->getCount()<<endl;
	cout << "Last: " << f->getLast()->getWord() << ", " << f->getLast()->getCount() << endl;
	cout << "Size: " << f->getSize() << endl;

	system("pause");
	return 0;
}