#include<iostream>
using namespace std;
//��һЩ���������
class People {
	string Name;
	double Speed;
public:
	People(){}
	People(int  inputAttack, int inputHealth) { 
		Health = inputHealth; 
		Attack = inputAttack;
	}
	int Attack = 0;
	int Health = 100;
};

class HighVictory :  People {
	int WinTime;
public:
	HighVictory() {}
	static int HighNumber;
	People& Fight(People&){  }
	
	// ��������ʵ��  ͨ���������� ��ʼ�����ĳЩ���� 
	HighVictory(int inputHealth , int inputAttack) {
		Attack = inputAttack;
		Health = inputHealth;
		++HighNumber;
	}
};
  int HighVictory::HighNumber  = 0;

class Low : People {
	int LoseTime;
	
public:
	bool bIsDead;
	Low(){}
	Low(int inputHealth , int inputAttack) {
		Health = inputHealth;
		Attack = inputAttack;
		++LowNumber;
	}

	static int LowNumber;
	void AttackOther( Low& otherLow ){  
		otherLow.Health = otherLow.Health - Attack;
		if (otherLow.Health <=0 )
		{
			otherLow.bIsDead = true;
			otherLow.Health = 0;
		}
		if (otherLow.bIsDead)
		{
			cout << "�н�ɫ����" << endl;
		}
	}
};
 int Low::LowNumber = 0;

int main() {

	HighVictory* GSL = new HighVictory(100 ,   50);
	Low * LJL = new Low(50,  25);
	Low * LHC = new Low(60 , 24);
	Low * Bear = new Low( 70, 40);
	cout << Low::LowNumber << endl;
	cout << HighVictory::HighNumber << endl;

	//������һЩ���ҵ���   vector
	while ( Low::LowNumber > 1 )
	{
		Bear->AttackOther( *LJL);
		if (LJL->bIsDead)
		{
			delete LJL;
			LJL = nullptr;
		}   
		if (LJL)
		{
			LJL->AttackOther(*LHC);
			if (LHC->bIsDead)
			{
				delete LHC;
				LHC = nullptr;
			}
		}
		
		if (LHC)
		{
			LHC->AttackOther(*Bear);
			if (Bear->bIsDead)
			{
				delete Bear;
				Bear = nullptr;
			}
		}
		
	}
	system("pause");
	return 066;
}