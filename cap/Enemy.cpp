#include "Enemy.h"
#include<random>
#include<string>

using namespace std;

Enemy::Enemy(int h, int prof, bool status) {
	health = h;
	proficiency = prof;
	boss = status;
}
/*
Enemy::~Enemy{
	delete *this;
}*/

int Enemy::getHealth() {
	return health;
}

void Enemy::damage(int val) {
	health -= val;
}

int Enemy::getProf() {
	return proficiency;
}

int Enemy::perform_intention(int roll, int intention, int id) {
	
	if(intention == 1)
		return (roll + proficiency);
	if(intention == 2)
		return ((roll % 10) + proficiency);
	if(intention == 3) {
		int val = (roll % 10) + proficiency;
		if (val > 0)
			health += val;
		else
			val = 0;
		return val;
	}
	if(intention == 4) {
		boss_buff(id);
		return 0;
	}
	else{
		return -1;
	}

}

string Enemy::boss_buff(int boss) {
	
	if(boss) {
		//switch statements depending which boss
		//performs corresponding buff
	}
	return "DEBUG: enemy is not a boss";
}
