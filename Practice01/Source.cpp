#include<iostream>
using namespace std;
//做一些有意义的事
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
	
	// 我这里想实现  通过两个整数 初始化类的某些属性 
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
			cout << "有角色挂了" << endl;
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

	//发生了一些不幸的事   vector
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