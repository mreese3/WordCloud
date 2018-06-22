#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include<string>
#include<iostream>

using namespace std;

class WordCount
{
	 
public:
	WordCount(string temp);
	WordCount(string temp,int number);
	virtual ~WordCount();
	virtual void resetCount();
	//virtual void addToCount(int offset);
	//virtual void setWord(string word);
	virtual void print();
	virtual string getWord();
	virtual void setCount(int count);
	virtual int getCount();
	virtual string asString();
	virtual void fromString(string value);
	
private:
	string word;
	int count=0;
};

#endif