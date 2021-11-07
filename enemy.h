#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class monster{
	public:
		int HP;
		void Enemy()
		{
			if(HP < 0)
			{
				HP = 0;
			}
			cout<<"\t\tName\t: "<<"Slime"<<endl;//header lain
			cout<<"\t\tLevel\t: "<<level<<endl;//header lain
			cout<<"\t\tHP\t: "<<HP;
			
		}
		
		void Enemy_Starter(int lvl=0){
			
			HP = (lvl*10) + 100;
			if(lvl == 0)
			{
				lvl = 1;
			}
			level = lvl;
		}
		
		int Enemy_HP(int damage=0)
		{
			HP = HP - damage;
			return HP;
		}
		
		int Enemy_Attack()
		{
			int a = 0;
			int Attack ;
			srand(time(0));
			a = (rand()% 5);
			if(a > 2)
			{
				Attack = 6 + a;
			}
			else
			{
				Attack = 0;
			}
			return Attack;
		}
		
	private:
		int level;
	
	public:
		string nama;
};
