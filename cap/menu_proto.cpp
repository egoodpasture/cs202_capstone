#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main() {

	
    int lvlCount = 1;
    int attack, block, attprof, blkprof, healing, turn = 1, actions = 0, playerHealth = 0, enemyHealth = 100;
    string start, classPage, cont;
    bool dead = false, ready = false, settings = false, play = false;

    while (play == false) {
        lvlCount = 1;
        playerHealth = 0;
        ready = false;
        dead = false;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "                                                   Capstone Final                                 ";
        cout << "\n------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n                                                                                  ";
        cout << "\nType start or quit > ";
        cin >> start;
        if (start == "quit" || start == "Quit" || start == "q" || start == "Q") {
            play = true;
            cout << "\nThanks for playing!" << endl;
            return 0;
        }
        while (ready == false) {
            settings = false;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "                                                 Choose Your Warrior                             ";
            cout << "\n------------------------------------------------------------------------------------------------------------------------------";
            cout << "\n(1) Brute \n(2) Shinobi \n(3) Mage";
            cout << "\nWhich class do you want [type 's' for settings] > ";
            cin >> classPage;
            cout << endl;
            if (classPage == "S" || classPage == "s") {
                while (settings == false) {

                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << "                                                      Settings                                        ";
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
                attprof = 10;
				blkprof = 5;
                healing = 5;
                playerHealth = 100;
				actions = 1;
                ready = true;
            }
            if (classPage == "2") {
                attprof = 3;
				blkprof = 2;
                healing = 8;
                playerHealth = 75;
				actions = 2;
                ready = true;
            }
            if (classPage == "3") {
                attprof = 5;
				blkprof = 3;
                healing = 12; 
                playerHealth = 50;
				actions = 1;
                ready = true;
            }

        } // ready bool

		if (turn % 2 == 1 && (enemyHealth != 0 || playerHealth != 0)) {
			cout << "\n------------------------------------------------------------------------------------------------------------------------------";
			cout << "\nEnemy Health: " << enemyHealth << "                                          >                                                Player Health: " << playerHealth << endl;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // place sprites in here
			cout << "\nActions: \n(1) Attack \n(2) Heal \n(3) Block \n";
			cout << " > ";
			cin >> cont;
			cout << endl;
			turn++;
		} // Player Turn
	} // Play bool
}
