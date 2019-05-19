#include <iostream>
#include <string.h>
#include <unistd.h>
/* add_by_szx: ��̬�Ķ��壺����ʹ�ò�ͬ�Ķ������ͬһ������������ݶ���ȥ���������治ͬ�ĺ����� 
   ����ͨ���麯������ʵ�ֵģ������������ĵ�����ʧ�ܵģ�����һ���ļ���
*/
using namespace std;

class Human {
public:
	void eating(void) { cout<<"use hand to eat"<<endl; }
};

class Englishman : public Human {
public:
	void eating(void) { cout<<"use knife to eat"<<endl; }
};


class Chinese : public Human {
public:
	void eating(void) { cout<<"use chopsticks to eat"<<endl; }
};

void test_eating(Human& h)
{
	h.eating();
}

int main(int argc, char **argv)
{
	Human h;
	Englishman e;
	Chinese c;

	test_eating(h);
	test_eating(e);
	test_eating(c);

	return 0;
}


