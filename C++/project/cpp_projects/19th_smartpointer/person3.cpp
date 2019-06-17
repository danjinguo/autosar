
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

/* add_by_szx: �����Լ�д������ָ���� 
ͨ���������ָ�룬������������ʵ��������ʱ���ͷ������ڹ����ʱ�����������ڴ��ַ��
*/
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

void test_func(void)
{
	sp s = new Person();
/* add_by_szx: ����ʵ����->�����أ��Ӷ�����ͨ��`sp`��������person������ķ��� 
�����->�������е�ϸ�ڣ���ϸ�ɲο� https://blog.csdn.net/custa/article/details/5674434
�����Ч����Ϊ���->�����������һ�����ʵ������������s->printInfo�ȼ���s.operator->()->printInfo;
*/
	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
/* add_by_szx: 	����������delete�ͻ�����ڴ�й¶ */
	//delete p;

	
}

int main(int argc, char **argv)
{	
	int i;

	for (i = 0; i < 2; i++)
		test_func();
	return 0;
}

