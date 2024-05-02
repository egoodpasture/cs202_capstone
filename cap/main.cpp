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
int main() {
	srand(time(0));
	ifstream fin;
	string line;

	fin.open("ascii_sprites.txt");

	if (!fin.is_open()) {
		cout << "Could not open file." << endl;
		return 1;
	}
	
	vector<string> sprites;
	vector<string> names;
	string ints[4] = {"attack", "defend", "heal", "buff"};
	int identifier; //used to determine current sprite and enemy name
	string currSprite, name;
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
	
	Enemy * en1 = new Enemy(50, 2, false);
	identifier = roll(0,2);
	currSprite = sprites[identifier];
	name = names[identifier];

	cout << currSprite << endl;
	cout << "Name: " << name << endl;
	cout << "Health: " << en1->getHealth() << endl;
	//cout << "Test default roll: " << roll() << endl;
	//cout << "Test roll 3-7: " << roll(6, 7) << endl;
	int intention = roll(1,3);
	cout << "Enemy will " << ints[intention - 1] << ".\n";
	cout << "Enemy performs " << ints[intention- 1] << " for: " << en1->perform_intention(roll(), intention, identifier) << endl;
	
	return 0;
}
