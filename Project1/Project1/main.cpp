#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// Ore rarity system
string chance(int a)
{
	srand(a);
	int oreChance = (rand() % 21) + 1;
	if (oreChance > 0 && oreChance < 9)
	{
		return "coal";
	}
	else if (oreChance > 8 && oreChance < 14)
	{
		return "iron";
	}
	else if (oreChance > 13 && oreChance < 18)
	{
		return "gold";
	}
	else if (oreChance > 17 && oreChance < 21)
	{
		return "diamond";
	}
	else if (oreChance > 20 && oreChance < 22)
	{
		return "unknown object";
	}
}


struct Ores
{
	double exp_given = 0;


	double expCount(string a)
	{
		if (a == "coal")
		{
			exp_given = .3;
		}
		else if (a == "iron")
		{
			exp_given = .5;
		}
		else if (a == "gold")
		{
			exp_given = 1;
		}
		else if (a == "diamond")
		{
			exp_given = 1.5;
		}
		else if (a == "unknown object")
		{
			exp_given = 1.7;
		} return exp_given;
	}
};

struct Player
{
	int Mine_level = 0;
	int ore_mined = 0;
	int exp_points = 0;
	int supermine = 0;
	bool has_supermine = 0;

	void lvlMath(double a,int b)
	{
		int level_limiter = 100;
		exp_points += floor(b * a); 
		Mine_level = floor(exp_points / level_limiter);
	}

	int superMine(int a)
	{
			int mineStorage = 0;
			srand(a);
			int oreMine = (rand() % 10) + 1;
			mineStorage += oreMine;
			ore_mined += mineStorage;
			return mineStorage;
			
			
	}

	void supermine_charge(int a)
	{
		srand(a);
		int charge = rand() % 10;
		if (charge == 6)
		{
			cout << "+1 Supermine[type 'supermine' to use]" << endl;
			supermine++;
		}

	}
};




int main()
{
	//variable declaration
	Player ronnie;
	Ores ore;
	double oreEXP;
	int StotalOre;



	//start of game
	cout << "-> ";
	string answer;
	cin >> answer;

	bool GameOn = true;
	while (GameOn)
	{

		srand(time(0));
		int ores = (rand() % 6) + 1;

		if (ronnie.supermine <= 0)
		{
			ronnie.has_supermine = false;
		}
		else ronnie.has_supermine = true;


		double mathOre = 0;
		if (answer == "mine")
		{
			cout << endl << "Mined " << ores << " " << chance(time(0)) << endl;
			oreEXP = ore.expCount(chance(time(0)));
			ronnie.ore_mined += ores;
			ronnie.lvlMath(oreEXP,ores);
			ronnie.supermine_charge(time(0));
			cout << "-> ";
			cin >> answer;
		}
		else if (answer == "inventory")
		{
			cout << endl << "You have " << ronnie.ore_mined << " ores" << endl;
			cout << "-> ";
			cin >> answer;

		}
		else if (answer == "exp")
		{
			cout << "Exp points: " << ronnie.exp_points << endl;
			cout << "-> ";
			cin >> answer;
		}
		else if (answer == "level")
		{
			cout << "You are LEVEL " << ronnie.Mine_level << endl;
			cout << "-> ";
			cin >> answer;
		}
		else if (answer == "supermine")
		{
			if (ronnie.has_supermine) {
				for (int i = 0; i < 5; i++)
				{
					cout << "You mined " << ronnie.superMine(time(0) + i) << " " << chance(time(0) + i) << endl;
					StotalOre = ronnie.superMine(time(0) + i);
					oreEXP = ore.expCount(chance(time(0) + i));
					ronnie.lvlMath(oreEXP,StotalOre);
				}
				ronnie.supermine--;
			}
			else cout << "You do not have supermine" << endl;
			cout << "-> ";
			cin >> answer;
		}

		else if (answer == "status")
		{
			cout << "Ores: " << ronnie.ore_mined << endl <<
				"Supermine: " << ronnie.supermine << endl <<
				"Level: " << ronnie.Mine_level << endl <<
				"Exp: " << ronnie.exp_points << endl;
			cout << "-> ";
			cin >> answer;
		}
		else if (answer == "stop")
		{
			break;
		}
		else
		{
			cout << "Invalid command" << endl << "-> ";
			cin >> answer;
		}
		
		
	}
}