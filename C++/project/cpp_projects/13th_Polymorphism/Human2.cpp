#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
/* add_by_szx: �������麯���ĸ��� */
/*
���ƣ�
	��̬���ࣺ���麯�����ڱ���ʱȷ���õ��õĺ�����
	��̬���ࣺ�麯��
		��������ָ�룬ָ���麯����
		����ʱ��ͨ��ָ�룬�ҵ������ö�Ӧ���麯����
*/
class Human {
private:
	int a;
public:
	virtual void eating(void) { cout<<"use hand to eat"<<endl; }
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
/* add_by_szx: ��֤�麯��ʵ�ֻ��ƣ����Ƿ�ȷʵ�����һ�������ָ�� 
   ������֤ȷʵ�����12�ֽڵ�ָ�롣
*/
	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(Englishman) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;

	return 0;
}


