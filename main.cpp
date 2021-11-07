#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "enemy.h"
using namespace std;

class player{
	public:
		
		int Player()
		{
			cout<<"\n====================================\n";
			cout<<"Player HP\t: "<<HP_Player()<<endl;
			cout<<"Player Stamina\t: "<<Stamina_Player()<<endl;
			cout<<endl;
		}
		
		int Player_Action(char input)
		{
			if(input == 'a'||input =='A'){
				monster m;
				m.Enemy_HP(10);
				cout<<"Player Attack : "<<Player_Attack()<<endl;
				//cout<<"damage terima : "<<m.Enemy_HP(20);
				Player_Attack();
			}
			else if(input == 'p'||input =='P')
			{
				Player_Status();
			}	
		}
		
		void Player_Status()
		{
			system("cls");
			cout<<"Attack Player\t: "<<Player_Attack()<<endl;
			cout<<"Defenf Player\t: "<<Defend<<endl;
			cout<<"EVA Player\t: "<<Eva<<endl;
		}
		
		int starter(int hp, int st){
			HP = hp;
			Stamina = st;
		}
		
		int Player_Attack(int critical=0, int equitmen=0)
		{
			if(critical > 6)
			{
				critical = 4;
			}
			Attack = 10;//defaul damagenya
			//citical didpt dari random ()
			if(equitmen == 0 && critical >= 3)
			{
				Attack = Attack + critical;
			}
			else if(equitmen == 0 && critical > 1 && critical <= 2)
			{
			}
			else if(critical == 0)
			{
				Attack = 0;
			}
			return Attack;
		}
		
		int Stamina_Player(int lelah=0){
			Stamina -= lelah;				
			return Stamina;
		}
		
		int HP_Player(int damage=0)
		{
			HP -= damage;
			return HP;
		}	
/////////DEKLARASI///////////////////		
	private:
		int Eva;
		int Attack;
		int Defend;
			
	public:
		int HP;
		int Stamina;
};

void Player_UI(){
	//UI player
	cout<<"(a) Attack\n";
	cout<<"(d) Defend\n";
	cout<<"(i) Inventory\n";
	cout<<"(p) Player Status\n";
}

int random()
{
	srand(time(0));
	int a;
//	for(int i=1; i<5; i++)
//	{
//		cout<<1+(rand()% 6)<<endl;
//	}
	a = (rand()% 4);
	return a;
}

int turn_combat(int turn)
{
	int o;
	if(turn % 2 == 0)
	{
		o = 0;
	}
	else
	{
		o = 1;
	}
	return o;
}

main()
{
	player p;
	monster m;
	char input;
	int stage = 1;// + turn combat
	p.starter(100,100);
	m.Enemy_Starter();
	do{
		m.Enemy();
		p.Player();
		if(turn_combat(stage) == 1)
		{
			Player_UI();
			cin>>input;
		}
		cout<<"\nBattle Log :";
		
		//player turn/////
		if(turn_combat(stage) == 1)
		{
			if(input == 'a')
			{
				p.Stamina_Player(5);
				if(p.Stamina <= 0)
				{
					cout<<"\nCapek Cuyy!!!";
					p.Stamina = 0;
				}
				else if(p.Stamina > 0)
				{
					m.Enemy_HP(p.Player_Attack(random()));
					if(random() < 1)
					{
						cout<<"\nAttack MISSS";
					}
					else
					{
						cout<<"\nHIT "<<p.Player_Attack(random())<<endl;
					}
				}
			}
			else if(input == 'p')
			{
				p.Player_Status();
				getch();
				system("cls");
			}
			else
			{
				cout<<"no action";
			}
		}
		//enemy turn
		if(turn_combat(stage) == 0)
		{
			p.HP_Player(m.Enemy_Attack());
			if(m.Enemy_Attack() <= 0)
			{
				cout<<"\nEnemy Attack MISSS ";
			}
			else
			{
				cout<<"\nEnemy Attack "<<m.Enemy_Attack();
			}
		}
		getch();
		system("cls");
		cout<<"Stage : "<<stage;
		cout<<"\n/////////////////////////////////////\n";
		string turn;
		if(turn_combat(stage) == 0)
		{
			turn = "You Turn\n";
		}
		else
		{
			turn = "Enemy Turn\n";
		}
		cout<<"turn : "<<turn<<endl;//turn
		stage += 1;
		
	}
	while(m.HP >= 0);
	getch();
	m.Enemy();
	cout<<"\nSlime Dikalahkan!!!";
}
