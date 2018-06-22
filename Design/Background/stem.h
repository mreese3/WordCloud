#include <string>;
using namespace std;

class stem
{
public:
	stem();
	~stem();
	virtual string stemTerm(string s);
	virtual void setTerm(string s);
	virtual string getTerm();
	virtual void add(char ch);
	virtual void add(char[] w, int wLen);
	virtual override string ToString();
	virtual int getResultLength();
	virtual char[] getResultBuffer();
	virtual bool cons(int i);
	
private:
	int m();
	virtual bool vowelinstem();
	virtual bool doublec(int j);
	virtual bool cvc(int i);
	virtual bool ends(string s);
	virtual void setto(string s);
	virtual void r(string s);
	virtual void step1();
	virtual void step2();
	virtual void step3();
	virtual void step4();
	virtual void step5();
	virtual void step6();
	virtual void stem();
};