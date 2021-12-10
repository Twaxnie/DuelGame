#include <iostream>
#include <fstream>
using namespace std;

//rand()%100+1
//system("cls");


int settings[8];


class Game{
public:
	string name = "Player";
	int health = 100;
	int exp = 0;
	int level = 0;
	int damage = 10;
	int chance_to_hit = 50;
	int chance_of_protection = 50;
	int chance_to_parry = 15;
	int number_of_duels = 0;

	void save() {
		ofstream File;
		File.open("profile.txt");
		File<< name << endl\
			<< health << endl\
			<< exp << endl\
			<< level << endl\
			<< damage << endl\
			<< chance_to_hit << endl\
			<< chance_of_protection << endl\
			<< chance_to_parry << endl\
			<< number_of_duels << endl;
			File.close();
	}

	void load() {
		ifstream Load;
		Load.open("profile.txt");
		Load >> name\
			>> health\
			>> exp\
			>> level\
			>> damage\
			>> chance_to_hit\
			>> chance_of_protection\
			>> chance_to_parry\
			>> number_of_duels;
		Load.close();
	}

	void stat() {
		Game player;
		player.load();
		system("cls");
		cout << "___________Статистика___________" << endl;
		cout << "Имя - " << player.name << endl;
		cout << "Опыт - " << player.exp << endl;
		cout << "Урон - " << player.damage << endl;
		cout << "----------" << endl;
		cout << "Шанс атаки - " << player.chance_to_hit << endl;
		cout << "Шанс защиты - " << player.chance_of_protection << endl;
		cout << "Шанс парировать - " << player.chance_to_parry << endl;
		cout << "----------" << endl;
		cout << "Количество побед: " << player.number_of_duels;
		cout << endl;
		cout << endl;
		cout << "Вернуться в меню: ";
		char b;
		cin >> b;
		
	}
};

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

void game() {
	Game player, bot;
	player.load();
	while (player.health > 0 or bot.health > 0) {
		if (player.health <= 0 or bot.health <= 0) {
			break;
		}
		cout << "ХП Игрока: " << player.health << endl;
		cout << "ХП Бота: " << bot.health << endl;
		cout << endl;
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
				if (try_to_hit(player.chance_to_hit) == true) {
					if (try_to_parry(bot.chance_to_parry) == true) {
						player.health -= player.damage;
						cout << "Противник парировал урон" << endl;
						cout << endl;
					}
					else{
						if (try_to_protect(bot.chance_of_protection) == true) {
							cout << "Противник смог защититься" << endl;
							cout << endl;
						}
						else {
							bot.health -= player.damage;
							cout << "Противник не смог защититься" << endl;
							cout << endl;
						}
					}

				}
				else {
					cout << "Вам не удалось нанести урон" << endl;
					cout << endl;
					
				}
			}
			if (bot_act == 'A') {
				cout << "Вы атакуете" << endl;
				cout << "Противник атакует" << endl;
				cout << endl;
				if (try_to_hit(player.chance_to_hit) == true) {
					bot.health -= player.damage;
					cout << "Вы нанесли урон" << endl;
					cout << endl;
						
					
				}
				else {
					cout << "Вам не удалось нанести урон" << endl;
					cout << endl;
					
				}
				if (try_to_hit(bot.chance_to_hit) == true) {
					player.health -= bot.damage;
					cout << "Вам нанесли урон" << endl;
					cout << endl;	
				}
				else {
					cout << "Противник не нанес урон" << endl;
					cout << endl;
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
				if (try_to_hit(bot.chance_to_hit) == true) {
					if (try_to_parry(player.chance_to_parry) == true) {
						bot.health -= bot.damage;
						cout << "Вы парировали урон" << endl;
						cout << endl;
					}
					else {
						player.health -= bot.damage;
						cout << "Противник нанес вам урон" << endl;
						cout << endl;
					}
				}
				else {
					cout << "Противник не смог нанести урон" << endl;
					cout << endl;
					
				}
			}
		}
	}
	if (bot.health == 0 and player.health != 0) {
		cout << "Вы победили!" << endl;
		player.exp += 10;
		cout << player.exp << "(+10)";
	}
	if (player.health == 0 and bot.health != 0) {
		cout << "Вы проиграли" << endl;
		player.exp -= 5;
		cout << player.exp << "(-5)";
	}
	if (bot.health == 0 and player.health == 0) {
		cout << "Ничья" << endl;
		player.exp += 5;
		cout << player.exp << "(+5)";
	}
}

void BeforeStart() {
	Game player;
	ifstream check("profile.txt");
	cout << "|1 - Начать игру с новым профилем" << endl;
	cout << ((!check.is_open()) ? "" : "|2 - Начать игру с существующем профилем") << endl;
	int check_num;
	while (true){
		cin >> check_num;
		if (check_num == 1) {
			system("cls");
			cout << "Введите имя: ";
			cin >> player.name;
			player.save();
			system("cls");
			game();
		}
		if (check.is_open()) {
			if (check_num == 2) {
				system("cls");
				game();
			}
		}
	}
	

}

void menu() {
	Game player;
	system("cls");
	cout << "|``````````````````````|\n"\
		<< "|       Играть (p)     |\n"\
		<< "|     Статистика (s)   |\n"\
		<< "|     Инвентарь (i)    |\n"\
		<< "|,,,,,,,,,,,,,,,,,,,,,,|" << endl;
	char Start;
	while (true) {
		cin >> Start;
		if (Start == 'p') {
			system("cls");
			BeforeStart();
		}
		if (Start == 's') {
			player.stat();
			menu();
		}
		if (Start == 'i') {

		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "|``````````````````````|\n"\
		<< "|       Welcome        |\n"\
		<< "|         To           |\n"\
		<< "|        Du3l          |\n"\
		<< "|,,,,,,,,,,,,,,,,,,,,,,|" << endl;
		char Start;
		while (true){
			cout << "Print S to Start" << endl;
			cin >> Start;
			if (Start == 'S') {
				menu();
				break;
			}
		}
		
}

