
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father {
private:
	int money;

protected:
	int room_key;
	
public:
	void it_skill(void)
	{
		cout<<"father's it skill"<<endl;
	}

	int getMoney(void)
	{
		return money;
	}

	void setMoney(int money)
	{
		this->money = money;
	}
};

class Son : public Father {
private:
	int toy;
	// ���Ӹ����Ǽ̳еļ��ܣ���Ա������������
	//using Father::it_skill;
public:
	/* ʹ��using�����Ӹ���̳����ĳ�Ա����/������Ȩ�� */
	// �����׵ķ���Կ�׹���
	using Father::room_key;
	// �����׵�˽��Ǯ��������ʧ�ܣ���Ϊ�ó�Ա��Ȩ����private�������Լ���û�취get�������Ա
	//using Father::money;
	
	void play_game(void)
	{
		int m;
		
		cout<<"son paly game"<<endl;

		/* money -= 1; 
		 * ��: ����ֱ���ø��׵�˽��Ǯ
		 */

		/*
		 * ���ǿ�������Ҫ
		 */
		m = getMoney();
		m--;
		setMoney(m);

		room_key = 1; 
	}
};


int main(int argc, char **argv)
{
	Son s;

	s.setMoney(10);
	cout << s.getMoney()<<endl;

	s.it_skill();
	s.play_game();

	s.room_key = 1;
	
	return 0;
}


