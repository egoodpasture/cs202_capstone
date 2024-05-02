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

	switch(chosenClass) {
		case 0: 
			health = 100;
			numAttack = 1;
			prof = 10;
			heal = 5;
			break;
		case 1:
			health = 75;
			numAttack = 2;
			prof = 3;
			heal = 8;
			break;
		case 2:
			health = 50;
			numAttack = 1;
			prof = 5;
			heal = 12;
			break;
		default: return "";
	}

	//meow
	
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
					cout << "Welcome to our Capstone Final Project. This project was inspired by early text based RNG\n";
					cout << "dungeon games. In this game, you play as a young warrior that will go through a dungeon\n";
					cout << "untold amounts of enemies; will you be able to make it to the end to clear the cave of the";
					cout << " monstrocities?\n"
					cout << "We shall see.....\n";
					cout << "\n\nPress any button to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "2") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "In this game, there are multiple crucial elements that every warrior must know in order";
					cout << "\nto effectivly and safely survive the dungeon.";
					cout << "\nFirstly, lets talk about who you are as a player in the dungeon. You as play can customize\n";
					cout << "yourself into three different classes: 'Brute', 'Shinobi', or 'Mage', and you can pick the\n";
					cout << "best class to fit your play style on how you want to fight (and live). Another important part\n";
					cout << "of the dungeon is how you will fight. When you see and opputunity to strike, you will be\n";
					cout << "given three options on what to do: 'Attack', 'Block', or 'Heal'. The fight will respond to\n";
					cout << "how you pick. If you pick attack, you will deal a random damage amount to the enemy, if you\n";
					cout << "block, you will negate a certain amount of damage the enemy will do onto you (or even all of\n";
					cout << "it if you're good enough), and if you heal, you will regenerate some of your health based\n";
					cout << "on your healing factor. Now there is one more thing to discuss, your proficiency, this is\n";
					cout << "a additive to your block and attack damage that will aide you in battle.\n"
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
