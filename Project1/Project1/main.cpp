#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;


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


struct Player
{
	int Mine_level = 0;
	int ore_mined = 0;
	int exp_points = 0;
	int supermine = 0;
	bool has_supermine = 0;

	void lvlMath()
	{
		int level_limiter = 100;
		exp_points = floor(ore_mined / 3); // 3 is just test number but in future every ore will have own exp number
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
	Player ronnie;

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


		if (answer == "mine")
		{
			cout << endl << "Mined " << ores << " " << chance(time(0)) << endl;
			ronnie.ore_mined += ores;
			ronnie.lvlMath();
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
				}
				ronnie.supermine--;
			}
			else cout << "You do not have supermine" << endl;
			ronnie.lvlMath();
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