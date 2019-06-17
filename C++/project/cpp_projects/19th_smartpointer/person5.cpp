
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
		cout<<"sp(Person *other)"<<endl;
		p = other;
	}

	sp(const sp &other)
	{
		cout<<"sp(const sp &other)"<<endl;
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

	sp other = new Person();

	for (i = 0; i < 2; i++)
		test_func(other);
/* add_by_szx: 	���������������ü����ĸ��� 
�ڵ�һ�ε���test_funcʱ��other.pָ������new���������ĵ�ַ
��ʱtest_func�е�s.p��main�е�other.pָ��ͬһ���ַ
��test_func���ý���ʱ������s���ͷ�s.p��
Ȼ����ʱmian�е�other����Ҫ���p���ͷ�֮������һ�ε���test_funcʱ�����other���p����δֵ֪
�����˴���ķ�����

Ϊ�ˣ�����������ָ������������ĸ��
*/
	return 0;
}

