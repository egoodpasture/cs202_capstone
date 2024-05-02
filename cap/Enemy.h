#ifndef ENEMY_H
#define ENEMY_H
#include<string>

class Enemy {

	public:
		Enemy(int = 0, int = 0, bool = false); // default constructor, parameters are health, proficiency, and boss status
		Enemy(const Enemy &); // copy constructor
		~Enemy();
		int getHealth();
		void damage(int);
		int getProf();
		int perform_intention(int, int, int);
		//string display();
		std::string boss_buff(int); 
		
	private:
		int health;
		int proficiency; // flat number added to all rolls
		bool boss;

};

#endif
