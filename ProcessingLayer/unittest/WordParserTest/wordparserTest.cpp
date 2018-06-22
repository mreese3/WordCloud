#include "wordlistparser.h"
using namespace std;

int main(){
	string file;
	file = "testtxt.txt";
	WordListParser wordlist(file);
	cout << "Done!";
	system("Pause");
	return 0;
}