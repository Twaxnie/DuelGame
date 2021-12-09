#include <iostream>
#include <fstream>
// #include <>
using namespace std;


//rand()%100+1
//system("cls");


int settings[8];

int player_health = 100;
int player_exp = 0;
int player_level = 0;
int player_damage = 10;
int player_chance_to_hit = 50;
int player_chance_of_protection = 50;
int player_chance_to_parry = 15;
int number_of_duels = 1;


int bot_health = 100;
int bot_level = 0;
int bot_damage = 10;
int bot_chance_to_hit = 60;
int bot_chance_of_protection = 50;
int bot_chance_to_parry = 15;

int try_to_hit(int hit) {
	if (rand() % 100 + 1 <= hit) {
		return true;
	}
	else {
		return false;
	}
}

int try_to_protect(int prot) {
	if (rand() % 100 + 1 <= prot) {
		return true;
	}
	else {
		return false;
	}
}

int try_to_parry(int parry) {
	if (rand() % 100 + 1 <= parry) {
		return true;
	}
	else {
		return false;
	}
}

char bot_action() {
	if (rand() % 2 == 0) {
		return 'A';
	}
	else{
		return 'D';
	}
}

void health() {
	cout << "ХП Игрока: " << player_health << endl;
	cout << "ХП Бота: " << bot_health << endl;
	cout << endl;
}

void game() {
	while (player_health > 0 or bot_health > 0) {
		if (player_health <= 0 or bot_health <= 0) {
			break;
		}
		char player_action;
		cout << "Выберите действие(A - атака, D - защита): ";
		cin >> player_action;
		system("cls");
		char bot_act = bot_action();
		if (player_action == 'A') {
			if (bot_act == 'D') {
				cout << "Вы атакуете" << endl;
				cout << "Противник пытается защититься" << endl;
				cout << endl;
				if (try_to_hit(player_chance_to_hit) == true) {
					if (try_to_parry(bot_chance_to_parry) == true) {
						player_health -= player_damage;
						cout << "Противник парировал урон" << endl;
						cout << endl;
						health();
					}
					else{
						if (try_to_protect(bot_chance_of_protection) == true) {
							cout << "Противник смог защититься" << endl;
							cout << endl;
							health();
						}
						else {
							bot_health -= player_damage;
							cout << "Противник не смог защититься" << endl;
							cout << endl;
							health();
						}
					}
				}
				else {
					cout << "Вам не удалось нанести урон" << endl;
					cout << endl;
					health();
				}

			}
			if (bot_act == 'A') {
				cout << "Вы атакуете" << endl;
				cout << "Противник атакует" << endl;
				cout << endl;
				if (try_to_hit(player_chance_to_hit) == true) {
					if (try_to_parry(bot_chance_to_parry) == true) {
						player_health -= player_damage;
						cout << "Противник парировал урон" << endl;
						cout << endl;
						health();
					}
					else {
						bot_health -= player_damage;
						cout << "Вы нанесли урон" << endl;
						cout << endl;
						health();
					}
				}
				else {
					cout << "Вам не удалось нанести урон" << endl;
					cout << endl;
					health();
				}
				if (try_to_hit(bot_chance_to_hit) == true) {
					if (try_to_parry(player_chance_to_parry) == true) {
						bot_health -= bot_damage;
						cout << "Вы парировали урон" << endl;
						cout << endl;
						health();
					}
					else {
						player_health -= bot_damage;
						cout << "Вам нанесли урон" << endl;
						cout << endl;
						health();
					}
				}
				else {
					cout << "Противник не нанес урон" << endl;
					cout << endl;
					health();
				}
			
			}
		}
		if (player_action == 'D') {
			if (bot_act == 'D') {
				cout << "Вы защищаетесь" << endl;
				cout << "Противник защищается" << endl;
				cout << endl;
			}
			if (bot_act == 'A') {
				cout << "Вы защищаетесь" << endl;
				cout << "Противник атакует" << endl;
				cout << endl;
				if (try_to_hit(bot_chance_to_hit) == true) {
					if (try_to_parry(player_chance_to_parry) == true) {
						bot_health -= bot_damage;
						cout << "Вы парировали урон" << endl;
						cout << endl;
						health();
					}
					else {
						player_health -= bot_damage;
						cout << "Противник нанес вам урон" << endl;
						cout << endl;
						health();
					}
				}
				else {
					cout << "Противник не смог нанести урон" << endl;
					cout << endl;
					health();
				}

			}
		}
	}
	if (bot_health == 0 and player_health != 0) {
		cout << "Вы победили!" << endl;
		player_exp += 10;
		cout << player_exp << "(+10)";
	}
	if (player_health == 0 and bot_health != 0) {
		cout << "Вы проиграли" << endl;
		player_exp -= 5;
		cout << player_exp << "(-5)";
	}
	if (bot_health == 0 and player_health == 0) {
		cout << "Ничья" << endl;
		player_exp += 5;
		cout << player_exp << "(+5)";
	}

	
}

void save() {
	ofstream File;
	File.open("profile.txt");
}

void create_profile() {
	ofstream File("profile.txt");
	File << 100 << endl;
	File << 0 << endl;
	File << 0 << endl;
	File << 10 << endl;
	File << 50 << endl;
	File << 50 << endl;
	File << 15 << endl;
	File << 0 << endl;
	File.close();
	ifstream ifFile("profile.txt");
	
	for (int i = 0; i < 8; i++) {
		ifFile >> settings[i];
	}
	
}

int main() {
	//srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	game();
	//int asd;
	//cin >> asd;
	//save();
	//create_profile();
	//for (int i = 0; i < size(settings); i++) {
	//	cout << settings[i] << endl;
	//}
}
