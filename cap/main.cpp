#include "Enemy.h"
#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include<time.h>

using namespace std;

int roll(int begin = 0, int end = 20) {
	int num = rand() % (end+ 1 - begin);
	return begin + num;
}

int menu();

vector<vector<string>> load_sprites();

int fight (int fightNum, int phealth, int numAtt, int pprof, int pheal, vector<string> sprites, vector<string> names);

int boss_fight (int phealth, int numAtt, int pprof, int pheal, vector<string> sprites, vector<string> names);

int main() {
	srand(time(0));
	vector<vector<string>> vec;

	vec = load_sprites();
	vector<string> sprites = vec[0];
	vector<string> names = vec[1];

	// player set up
	int health, numAttack, prof, heal;
	int chosenClass = menu();

	// implement switch statement for classes
	// set player stats
	
	// end player set up

	/*
	cout << currSprite << endl;
	cout << "Name: " << name << endl;
	cout << "Health: " << en1->getHealth() << endl;
	//cout << "Test default roll: " << roll() << endl;
	//cout << "Test roll 3-7: " << roll(6, 7) << endl;
	int intention = roll(1,3);
	cout << "Enemy will " << ints[intention - 1] << ".\n";
	cout << "Enemy performs " << ints[intention- 1] << " for: " << en1->perform_intention(roll(), intention, identifier) << endl;
	*/

	return 0;
}

int fight (int fightNum, int phealth, int numAtt, int pprof, int pheal, vector<string> sprites, vector<string> names) {
	
	// universal enemy set up
	string ints[4] = {"attack", "defend", "heal", "buff"};
	int identifier; //used to determine current sprite and enemy name
	string currSprite, name;
	// end universal enemy set up
	
	//based on fight number, roll identifier for sprite belonging to enemy level (i.e 0 or 1 for fight 1)
	//identifier = roll(0,1);
	
	currSprite = sprites[identifier];
	name = names[identifier];
	//Enemy * en1 = new Enemy(50, 2, false);
	
	return phealth;
}

vector<vector<string>> load_sprites() {
	ifstream fin;
	string line;
	vector<vector<string>> vec;
	vector<string> sprites;
	vector<string> names;

	fin.open("ascii_sprites.txt");

	if (!fin.is_open()) {
		cout << "Could not open sprites." << endl;
		exit(1);
	}
	
	int i = 0;
	int oldi = -1;
	sprites.push_back("");
	
	while (getline(fin, line)) {
		
		//cout << line << endl;
		if (line == "~") {
			i++;
			sprites.push_back("");
		}
		else if (oldi != i) {
			names.push_back(line);
			oldi = i;
		}
		else {
			//cout << "pushing back...\n";
			sprites[i] += line + "\n";
			//cout << "success\n";
		}

	}
	fin.close();

	vec.push_back(sprites);
	vec.push_back(names);

	return vec;
}

int menu() {

	bool settings = false, ready = false;
	string start, classPage;

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                                                   Capstone Final                                 ";
	cout << "\n------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n                                                                                  ";
	cout << "\nType start or quit > ";
	cin >> start;
	
	while (ready == false) {
		settings = false;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "                                                 Choose Your Warrior                             ";
		cout << "\n------------------------------------------------------------------------------------------------------------------------------";
		cout << "\n(1) Brute \n(2) Shinobi \n(3) Mage";
		cout << "\nWhich class do you want [type 'i' for info] > ";
		cin >> classPage;
		cout << endl;
		if (classPage == "i" || classPage == "i") {
			while (settings == false) {

				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cout << "                                                      Info                                        ";
				cout << "\n------------------------------------------------------------------------------------------------------------------------------";
				cout << "\n(1) What is this game? \n(2) How to play? \n(3) Brute Class \n(4) Shinobi Class \n(5) Mage Class";
				cout << "\nType 'Back' to go back > ";
				cin >> classPage;
				cout << endl;
				if (classPage == "b" || classPage == "B" || classPage == "Back" || classPage == "back") settings = true;
				if (classPage == "1") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "Welcome to Dungeon Slayer. This is a role-playing game inspired by D&D. In this game you";
					cout << "\nwill explore multiple levels of a dungeon and having to defeat three major bosses";
					cout << "\nthroughout the way. In this game, you will have to combine all your strategy and luck in";
					cout << "\norder to complete all the stages presented before you. Do YOU have what it takes young";
					cout << " warrior? We shall see...";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "2") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "In this game, there are multiple crucial elements that every warrior must know in order";
					cout << "\nto effectivly and safely survive the dungeon.";
					cout << "\nFirstly we must talk about your turns. Each fight sequence is broken up into 2 turns, the";
					cout << "\nplayer and the enemy. The player will have 2 possible chances to perform an action on";
					cout << "\ntheir turn. If the action the player chooses succeeded, the second action is forfieted";
					cout << "\nand the enemy will have their turn.";
					cout << "\nNow lets talk about what actions you can take. There are two main actions you can choose";
					cout << "\nfrom in any class: Attack and Defend. When you choose to attack, a 'dice' is rolled to";
					cout << "\ndetermine if your attack was successful and rolls it against the enemies defence [and";
					cout << "\nvice-versa]. If an attack is successful, another dice is rolled to see if you rolled a";
					cout << "\ncritical hit which will deal more damage. If you choose defence as your action, then a";
					cout << "\n'dice' will roll to see if you blocking will be successful. If the block is successful";
					cout << "\nit will decrease the chance of your enemy's attack working by and will give you 5 - 15 HP";
					cout << "\nback. There are also classes that can buff your base stats and give you an edge based on";
					cout << "\nyour prefered playing style";
					cout << "\nWell now you are fully prepared to take on the adventure ahead of you. I'm counting that";
					cout << " you will win!";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "3") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "This is the Brute Class. This class is able to take punches to the face without \nflinching";
					cout << "; however, he isn't very bright and heals extremely slow.";
					cout << "\n\nHealth = 100 \nAttacks per turn = 1 \nProficiency = 10 \nHealing Factor = 5";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "4") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "This is the Shinobi Class. When you use this class you turn into a very agile and quick";
					cout << " ninja able to land\nmultiple strikes sequentially. \nHowever, this comes at a cost of a";
					cout << " mediocre health and healing factor";
					cout << "\n\nHealth = 75 \nAttacks per turn = 2 \nProficiency = 3 \nHealing Factor = 8";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "5") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "This is the Mage Class. In this class you turn into a wise mage able to cast spells with";
					cout << " great affect to\nboth attack the enemy and heal yourself. \nHowever it comes at the cost";
					cout << " of you being physically weak to an enemy's attack.";
					cout << "\n\nHealth = 50 \nAttacks per turn = 1 \nProficiency = 5 \nHealing Factor = 12";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
			} // settings while

		} // settings if statement
		if (classPage == "1") {
			ready = true;
			return 0;
		}
		if (classPage == "2") {
			ready = true;
			return 1;
		}
		if (classPage == "3") {
			ready = true;
			return 3;
		}

	} // ready bool

	return -1;
}
