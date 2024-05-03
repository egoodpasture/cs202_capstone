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

int fight (int c, double m, int fightNum, int phealth, int numAtt, int pprof, int loop, vector<string> sprites, vector<string> names);

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
			health = 100;numAttack = 1;prof = 10;heal = 10;
			break;
		case 1:
			health = 60;numAttack = 2;prof = 4;heal = 10;
			break;
		case 2:
			health = 50;numAttack = 1;prof = 8;heal = 10;
			break;
		default:
			cout << "Invalid class selection" << endl;
			exit(1);
			break;
	}
	// end player set up
	
	bool endless = false, valid = false;
	string end;
	string con;
	int loops = 1, playMaxHealth = health;
	double mult = 1;

	do {
		for (int i = 1 ; i < 4 ; i++) {
			health = fight(chosenClass, mult, i, health, numAttack, prof, loops, sprites, names);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
			if (health > 0 && i == 1) {
				cout << "You've healed slightly.\nYou've slain your foe. Yet, another challenge awaits you. Enter any key to continue: ";
				cin >> con;
			}
			else if (health > 0 && i == 2){
				cout << "You've healed slightly.\nYou've triumphed again. Enter any key to challenge the boss: ";
				cin >> con;
			}
			else if (health > 0 && i == 3) {
				cout << "Congratulations. You've escaped the Ascii Dungeon.\n";
				cout << "You can now play Endless Mode. In Endless, \nthe enemies and bosses scale based on the number of loops completed.\nYou will be fully healed before you begin.\nWould you like to quit (q) or play Endless Mode (e)? ";
				do {
					cin >> end;
					if (end.at(0) == 'q' || end.at(0) == 'Q')
						return 0;
					else if (end.at(0) == 'e' || end.at(0) == 'E') {
						valid = true;
						loops++;
						health = playMaxHealth;
						mult += (.5*(loops-1));
						endless = true;
					}
					else {
						cout << "\nPlease enter 'q' to quit or 'e' to play Endless Mode: ";
					}
				} while (valid != true);
			}
			else {
				cout << "You were slain.\n";
				return 0;
			}
			health += heal;
		}
	}while (endless == true);

	return 0;
}

int fight (int c, double m, int fightNum, int phealth, int numAtt, int pprof, int loop, vector<string> sprites, vector<string> names) {
	// universal enemy set up
	Enemy * enemy;
	string ints[4] = {"attack", "defend", "heal", "buff"};
	int identifier; //used to determine current sprite and enemy name
	string currSprite, name;
	// end universal enemy set up
	
	//based on fight number, roll identifier for sprite belonging to enemy level (i.e 0 or 1 for fight 1)
	switch(fightNum) {
		case 1:
			identifier = roll(0,1);
			enemy = new Enemy(50*m, 4*m, false);	
			break;
		case 2:
			identifier = roll(2,3);
			enemy = new Enemy(80*m, 6*m, false);	
			break;
		case 3:
			identifier = roll(4,5);
			enemy = new Enemy(105*m, 9*m, true);	
			break;
		default:
			cout << "Invalid fight number" << endl;
			exit(1);
			break;
	}

	currSprite = sprites[identifier];
	name = names[identifier];
	int enemyMove, count = 0, playPrev, enPrev, playDam = 0, enDam = 0, playNum = 0;
	char playMove;

	do {
		int intention;
		bool valid = false;

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
		//cout << "DEBUG: mult: " << m << endl;
		if (loop > 1)
			cout << "LOOP " << loop << ", FIGHT " << fightNum << "\n_______________\n\n";
		else
			cout << "FIGHT " << fightNum << "\n_______\n\n";
		cout << name << endl;
		cout << "Health: ";
		for (int i = 0 ; i < (enemy->getHealth()+1)/2 ; i++) 
			cout << "[]" ;
		//cout << "DEBUG: Health: " << enemy->getHealth();
		cout << endl << endl;

		cout << currSprite << endl << endl;
		if (count > 0)
			cout << "You " << ints[playPrev] <<"ed for " << playNum << ". " << name << " " << ints[enPrev-1] << "ed for " << enemyMove << ". \nYou received " << playDam << " damage and dealt " << enDam << " damage.\n";
		do {
			intention = roll(1,3);
		} while (intention == enPrev);
		enPrev = intention;
		enemyMove = enemy->perform_intention(roll(), intention, identifier);

		if (roll(1,3) > 1) {
			if (intention == 1) {
				cout << endl << name << " is planning to " << ints[intention-1] << " for " << enemyMove << " damage.";
				playDam = enemyMove;
			}
			else if (intention  > 1)
				cout << endl << name << " is planning to " << ints[intention-1];
		}
		else{
			cout << endl << name << "'s intentions are unknown.";
			if (intention == 1)
				playDam = enemyMove;
		}
		cout << "\nYour health: ";
		for (int i = 0 ; i < (phealth+1)/2 ; i++) 
			cout << "[]" ;
		//cout << "DEBUG: Health: " << phealth;

		do {
			cout << "\n\nWhat will you do? Attack (a) or defend (d)? ";
			cin >> playMove;

			if(playMove == 'a' || playMove == 'A'){
				valid = true;
				playPrev = 0;
				enDam = 0;
				playNum = 0;

				for (int i = 0 ; i < numAtt ; i++)
					playNum += roll() + pprof;
				enDam = playNum;

				if(intention == 1) {
					enemy->damage(enDam);
					phealth -= playDam;
				}
				else if(intention == 2) {
					playDam = 0;
					enDam -= enemyMove;
					if (enDam > 0)
						enemy->damage(enDam);
					else 
						enDam = 0;
				}
				else {
					enemy->damage(enDam);
					playDam = 0;
				}
			}
			else if(playMove == 'd' || playMove == 'D'){
				valid = true;
				playPrev = 1;
				enDam = 0;
				playNum = 0;
				
				if (c != 2)
					playNum = roll();
				else // if player is mage add proficiency to block
					playNum = roll() + pprof;
				
				
				if(intention == 1) {
					playDam -= playNum;
					if (playDam > 0)
						phealth -= playDam;
					else 
						playDam = 0;
				}
			}
			else {
				cout << "\n\nPlease enter a valid action: ";
			}
		} while (valid == false);

		count++;
	} while (phealth > 0 && enemy->getHealth() > 0); 
	
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

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
	cout << "                                                   Ascii Dungeon                                 ";
	cout << "\n------------------------------------------------------------------------------------------------------------------------------";
	cout << "\n                                                                                  ";
	cout << "\nType start or quit > ";
	cin >> start;
	
	while (ready == false) {
		settings = false;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
		cout << "                                                 Choose Your Warrior                             ";
		cout << "\n------------------------------------------------------------------------------------------------------------------------------";
		cout << "\n(1) Brute [Very high health, 10 proficiency, medium healing][Perk: extra high health]";
		cout << "\n(2) Shinobi [Medium health, 4 proficiency, medium healing][Perk: two attack rolls]";
		cout << "\n(3) Mage [Low Health, 8 proficiency, medium healing][Perk: proficiency is added to both attack and defense rolls]";
		cout << "\n\nWhich class do you want [type 'i' for info] > ";
		cin >> classPage;
		cout << endl;
		if (classPage == "i" || classPage == "i") {
			while (settings == false) {

				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
				cout << "                                                      Info                                        ";
				cout << "\n------------------------------------------------------------------------------------------------------------------------------";
				cout << "\n(1) What is this game? \n(2) How to play?";
				cout << "\n\nType 'Back' to go back > ";
				cin >> classPage;
				cout << endl;
				if (classPage == "b" || classPage == "B" || classPage == "Back" || classPage == "back") settings = true;
				if (classPage == "1") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
					cout << "This is our Capstone Final Project for Cosc 202 Spring 2024. This game was inspired by Slay The Spire and early text\n";
					cout << "based RPGs. In this game, you will travserse a dungeon filled with ASCII monsters.\n";
					cout << "Will you be able to make it to make it out of the dungeon alive? Try your hardest...";
					cout << "\n\nEnter any key to go back > ";
					cin >> classPage;
					cout << endl;
				}
				if (classPage == "2") {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; 
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
					cout << "a additive to your block and attack damage that will aide you in battle.\n";
					cout << "\nWell now you are fully prepared to take on the adventure ahead of you. I'm counting that";
					cout << " you will win!";
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
			return 2;
		}

	} // ready bool

	return -1;
}
