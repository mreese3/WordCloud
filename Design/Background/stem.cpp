#include <iostream>
#include "stem.h"
using namespace std;

stem::stem(){}
stem::~stem(){}

bool stem::ends(string s) 
		{
			int l = s.Length;
			int o = k-l+1;
			if (o < 0)
				return false;
			char[] sc = s.ToCharArray();
			for (int i = 0; i < l; i++)
				if (b[o+i] != sc[i])
					return false;
			j = k-l;
			return true;
		}
void stem::setto(string s) 
		{
			int l = s.Length;
			int o = j+1;
			char[] sc = s.ToCharArray();
			for (int i = 0; i < l; i++)
				b[o+i] = sc[i];
			k = j+l;
		}
bool stem::vowelinstem() 
		{
			int i;
			for (i = 0; i <= j; i++)
				if (! cons(i))
					return true;
			return false;
		}
bool stem::doublec(int j) 
		{
			if (j < 1)
				return false;
			if (b[j] != b[j-1])
				return false;
			return cons(j);
		}
void stem::step1() 
		{
			if (b[k] == 's') 
			{
				if (ends("sses"))
					k -= 2;
				else if (ends("ies"))
					setto("i");
				else if (b[k-1] != 's')
					k--;
			}
			if (ends("eed")) 
			{
				if (m() > 0)
					k--;
			} 
			else if ((ends("ed") || ends("ing")) && vowelinstem()) 
			{
				k = j;
				if (ends("at"))
					setto("ate");
				else if (ends("bl"))
					setto("ble");
				else if (ends("iz"))
					setto("ize");
				else if (doublec(k)) 
				{
					k--;
					int ch = b[k];
					if (ch == 'l' || ch == 's' || ch == 'z')
						k++;
				}
				else if (m() == 1 && cvc(k)) setto("e");
			}
		}
void stem::step2() 
		{
			if (ends("y") && vowelinstem())
				b[k] = 'i';
		}
		/*  step3() maps double suffices to single ones. so -ization ( = -ize plus
		   -ation) maps to -ize etc. note that the string before the suffix must give
		   m() > 0.
        */
		void stem::step3() 
		{
			if (k == 0)
				return;
			
			/* For Bug 1 */
			switch (b[k-1]) 
			{
				case 'a':
					if (ends("ational")) { r("ate"); break; }
					if (ends("tional")) { r("tion"); break; }
					break;
				case 'c':
					if (ends("enci")) { r("ence"); break; }
					if (ends("anci")) { r("ance"); break; }
					break;
				case 'e':
					if (ends("izer")) { r("ize"); break; }
					break;
				case 'l':
					if (ends("bli")) { r("ble"); break; }
					if (ends("alli")) { r("al"); break; }
					if (ends("entli")) { r("ent"); break; }
					if (ends("eli")) { r("e"); break; }
					if (ends("ousli")) { r("ous"); break; }
					break;
				case 'o':
					if (ends("ization")) { r("ize"); break; }
					if (ends("ation")) { r("ate"); break; }
					if (ends("ator")) { r("ate"); break; }
					break;
				case 's':
					if (ends("alism")) { r("al"); break; }
					if (ends("iveness")) { r("ive"); break; }
					if (ends("fulness")) { r("ful"); break; }
					if (ends("ousness")) { r("ous"); break; }
					break;
				case 't':
					if (ends("aliti")) { r("al"); break; }
					if (ends("iviti")) { r("ive"); break; }
					if (ends("biliti")) { r("ble"); break; }
					break;
				case 'g':
					if (ends("logi")) { r("log"); break; }
					break;
				default :
					break;
			}
		}
		/* step4() deals with -ic-, -full, -ness etc. similar strategy to step3. */
		void stem::step4() 
		{
			switch (b[k]) 
			{
				case 'e':
					if (ends("icate")) { r("ic"); break; }
					if (ends("ative")) { r(""); break; }
					if (ends("alize")) { r("al"); break; }
					break;
				case 'i':
					if (ends("iciti")) { r("ic"); break; }
					break;
				case 'l':
					if (ends("ical")) { r("ic"); break; }
					if (ends("ful")) { r(""); break; }
					break;
				case 's':
					if (ends("ness")) { r(""); break; }
					break;
			}
		}
		/* step5() takes off -ant, -ence etc., in context <c>vcvc<v>. */
		void stem::step5() 
		{
			if (k == 0)
				return;
			/* for Bug 1 */
			switch ( b[k-1] ) 
			{
				case 'a':
					if (ends("al")) break; return;
				case 'c':
					if (ends("ance")) break;
					if (ends("ence")) break; return;
				case 'e':
					if (ends("er")) break; return;
				case 'i':
					if (ends("ic")) break; return;
				case 'l':
					if (ends("able")) break;
					if (ends("ible")) break; return;
				case 'n':
					{
					if (ends("ant")) break;
					if (ends("ement")) break;
					if (ends("ment")) break;
					/* element etc. not stripped before the m */
					if (ends("ent")) break; 
				case 'o':
					if (ends("ion") && j >= 0 && (b[j] == 's' || b[j] == 't')) break;
					/* j >= 0 fixes Bug 2 */
					if (ends("ou")) break;
					/* takes care of -ous */
				case 's':
					if (ends("ism")) break;
				case 't':
					if (ends("ate")) break;
					if (ends("iti")) break;
				case 'u':
					if (ends("ous")) break;
				case 'v':
					if (ends("ive")) break;
				case 'z':
					if (ends("ize")) break;
				default:
					return;
			}
			if (m() > 1)
				k = j;
		}
		/* step6() removes a final -e if m() > 1. */
		void stem::step6() 
		{
			j = k;
			
			if (b[k] == 'e') 
			{
				int a = m();
				if (a > 1 || a == 1 && !cvc(k-1))
					k--;
			}
			if (b[k] == 'l' && doublec(k) && m() > 1)
				k--;
		}
		void stem::stem() 
		{
			k = i - 1;
			if (k > 1) 
			{
				step1();
				step2();
				step3();
				step4();
				step5();
				step6();
			}
			i_end = k+1;
			i = 0;
		}