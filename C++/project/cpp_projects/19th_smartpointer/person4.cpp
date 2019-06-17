
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person {

public:

	Person() {
		cout <<"Pserson()"<<endl;
	}


	~Person()
	{
		cout << "~Person()"<<endl;
	}
	void printInfo(void)
	{
		cout<<"just a test function"<<endl;
	}
};

class sp {
private:
	Person *p;

public:
	sp() : p(0) {}
	
	sp(Person *other)
	{
		cout<<"sp(const Person *other)"<<endl;
		p = other;
	}

/* add_by_szx: �������캯�� ��Ҫ���ڸ�ֵ����
����Ϊ��ʽ�������
*/
	sp(sp &other)
	{
		cout<<"sp(const Person *other)"<<endl;
		p = other.p;
	}

	~sp()
	{
		cout<<"~sp()"<<endl;
		if (p)
			delete p;
	}

	Person *operator->()
	{
		return p;
	}
	
};

void test_func(sp &other)
{
	sp s = other;

	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
	//delete p;

	
}

int main(int argc, char **argv)
{	
	int i;

	/* �൱��:
	 * 1. Person *p = new Person();
	 * 2. sp tmp(p);  ==> sp(Person *other)
	 * 3.
	 * 3.1 sp other(tmp);  ==> sp(sp &other2)
	       ��������: sp &other2 = tmp; 
	       			 // �����﷨����Ϊһ������û�취ָ��һ����ʱ������һ����ʱ��sp����û�취ת����һ��sp����
	                 const sp& other2 = tmp; //ok
	 * ��
	 * 3.2 sp other(tmp ==> Person*);  ==>sp(Person *other)
	 * // û�취��һ��sp������ʽת��Ϊһ��Person*ָ��
	 */
	
	sp other = new Person();

	for (i = 0; i < 2; i++)
		test_func(other);
	return 0;
}

