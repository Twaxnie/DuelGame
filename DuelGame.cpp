#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

//rand()%100+1
//system("cls");


enum wears {
	head,
	body,
	legs,
	boots
};
enum hands {
	leftArm,
	rightArm
};
enum itemsinfo {
	iId,
	slot,
	secondSlot,
	iHP,
	iDamage,
	iHit,
	iProtect,
	iParry
};

enum invType {
	weapon,
	wear,
	belt
};

enum Stat {
	hp,
	dmg,
	hit,
	prot,
	parry
};


//Предметы

string ItemName[] = {
	"Пусто",          //0
	"Маска Паука",    //1
	"Катаны Дэдпула", //2
	"Щит Кэпа",       //3
	"Броня Старка",   //4
	"Камень разума",  //5
	"Камень силы"     //6
};

int Items[][8] = {
	//id		slot		sSlot		iHP			iDMG		iHit		iProt		iParry
//	{,			,			,			,			,			,			,			 }
	{0,			0,			0,			0,			0,			0,			0,			0},
	{1,			wear,		head,	   50,			0,			2,			-1,			0},
	{2,			weapon,		leftArm,	0,			0,			0,			-3,			5},
	{3,			weapon,		rightArm,	0,			0,			0,			7,			0},
	{4,			wear,		body,		0,			0,			-5,			9,			1},
	{5,			belt,		   0,		0,			0,			0,			3,			1},
	{6,			belt,		   0,		0,			0,			0,			1,			1}
};



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
	int display_level = 0;
	int inventory[3][4] = { {0, 0, 0, 0}, 
							{0, 0, 0, 0}, 
							{0, 0, 0, 0}};
	int chance_to_drop = 30;


	void save() {
		ofstream File;
		File.open("profile.txt");
		File << name << endl\
			<< exp << endl\
			<< level << endl\
			<< damage << endl\
			<< chance_to_hit << endl\
			<< chance_of_protection << endl\
			<< chance_to_parry << endl\
			<< number_of_duels << endl\
			<< display_level << endl\
			<< inventory[weapon][0] << endl\
			<< inventory[weapon][1] << endl\
			<< inventory[wear][0] << endl\
			<< inventory[wear][1] << endl\
			<< inventory[wear][2] << endl\
			<< inventory[wear][3] << endl\
			<< inventory[belt][0] << endl\
			<< inventory[belt][1] << endl\
			<< inventory[belt][2] << endl\
			<< inventory[belt][3] << endl\
			<< chance_to_drop;
			File.close();
	}

	void load() {
		ifstream Load;
		Load.open("profile.txt");
		Load >> name\
			>> exp\
			>> level\
			>> damage\
			>> chance_to_hit\
			>> chance_of_protection\
			>> chance_to_parry\
			>> number_of_duels\
			>> display_level\
			>> inventory[weapon][0]\
			>> inventory[weapon][1]\
			>> inventory[wear][0]\
			>> inventory[wear][1]\
			>> inventory[wear][2]\
			>> inventory[wear][3]\
			>> inventory[belt][0]\
			>> inventory[belt][1]\
			>> inventory[belt][2]\
			>> inventory[belt][3]\
			>> chance_to_drop;
		Load.close();
	}

	int feature(int feature) {
		Game player;
		player.load();
		int add_hp = 0;
		int add_dmg = 0;
		int add_hit = 0;
		int add_prot = 0;
		int add_parry = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				add_hp += Items[inventory[i][j]][3];
				add_dmg += Items[inventory[i][j]][4];
				add_hit += Items[inventory[i][j]][5];
				add_prot += Items[inventory[i][j]][6];
				add_parry += Items[inventory[i][j]][7];
			}
		}
		if (feature == hp) {
			return add_hp + player.health;
		}
		if (feature == dmg) {
			return add_dmg + player.damage;
		}
		if (feature == hit) {
			return add_hit + player.chance_to_hit;
		}
		if (feature == prot) {
			return add_prot + player.chance_of_protection;
		}
		if (feature == parry) {
			return add_parry + player.chance_to_parry;
		}

	}

	void stat() {
		Game player;
		player.load();
		system("cls");
		system("color 2");
		
		cout << "___________Статистика___________" << endl;
		cout << "Имя - " << player.name << endl;
		cout << "Опыт - " << player.exp << endl;
		cout << "Урон - " << player.damage << endl;
		cout << "----------" << endl;
		cout << "Шанс атаки - " << player.chance_to_hit << endl;
		cout << "Шанс защиты - " << player.chance_of_protection << endl;
		cout << "Шанс парировать - " << player.chance_to_parry << endl;
		cout << "----------" << endl;
		cout << "Количество побед: " << player.number_of_duels << endl;
		cout << "Уровень: " << player.display_level;
		cout << endl;
		cout << endl;
		cout << "Вернуться в меню: ";
		char b;
		cin >> b;
		
	}
};












void inv() {
	Game player;
	player.load();
	player.inventory;
	cout << "            #######" << endl;
	cout << "           ##@###@##" << endl;
	cout << "           #########" << endl;
	cout << "            ##---##" << endl;
	cout << "               #" << endl;
	cout << "              ###" << endl;
	cout << "             # # #" << endl;
	cout << "            #  #  # " << endl;
	cout << "               # " << endl;
	cout << "               # " << endl;
	cout << "              # #" << endl;
	cout << "             #   #" << endl;
	cout << "            #     #" << endl;
	cout << "_________Броня_________" << endl;
	cout << "Голова: " << "[" << ItemName[player.inventory[wear][head]] << "]" << endl;
	cout << "Тело: " << "[" << ItemName[player.inventory[wear][body]] << "]" << endl;
	cout << "Руки: " << "[" << ItemName[player.inventory[wear][legs]] << "]" << endl;
	cout << "Ноги: " << "[" << ItemName[player.inventory[wear][boots]] << "]" << endl;
	cout << endl;
	cout << "_________Оружие_________" << endl;
	cout << "Правая рука: " << "[" << ItemName[player.inventory[weapon][rightArm]] << "]" << endl;
	cout << "Левая рука: " << "[" << ItemName[player.inventory[weapon][leftArm]] << "]" << endl;
	cout << endl;
	cout << "_________Пояс_________" << endl;
	cout << "1 слот: " << "[" << ItemName[player.inventory[belt][0]] << "]" << endl;
	cout << "2 слот: " << "[" << ItemName[player.inventory[belt][1]] << "]" << endl;
	cout << "3 слот: " << "[" << ItemName[player.inventory[belt][2]] << "]" << endl;
	cout << "4 слот: " << "[" << ItemName[player.inventory[belt][3]] << "]" << endl;

	char choice;
	cin >> choice;
}



 

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

int bot_skill() {
	int choice = rand() % 100 + 1;
	if (choice <= 33) {
		return 1;
	}
	if (choice > 33 and choice <= 66) {
		return 2;
	}
	if (choice > 66) {
		return 3;
	}
}

void drop() {
	Game player;
	player.load();
	if (rand() % 100 + 1 <= player.chance_to_drop) {
		int drop = rand() % (size(Items) - 1) + 1;
		cout << "Новый предмет: " << ItemName[drop] << endl;
		if (Items[drop][1] == wear) {
			cout << "В этом слоту " << ItemName[player.inventory[Items[drop][1]][Items[drop][2]]] << endl;
			cout << "Надеть или заменить предмет? (y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y') {
				player.inventory[Items[drop][1]][Items[drop][2]] = drop;
				player.chance_to_drop = 30;
				player.save();
			}
			else {
				return;
			}
		}
	


		if (Items[drop][1] == weapon) {
			cout << "В слоту " << player.inventory[Items[drop][1]][Items[drop][2]] << endl;
			cout << "Надеть или заменить предмет? (y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y') {
				player.inventory[Items[drop][1]][Items[drop][2]] = drop;
				player.chance_to_drop = 30;
				player.save();
			}
			else {
				return;
			}
			

		}
		if (Items[drop][1] == belt) {
			cout << "_________Пояс_________" << endl;
			cout << "1 слот: " << "[" << ItemName[player.inventory[belt][0]] << "]" << endl;
			cout << "2 слот: " << "[" << ItemName[player.inventory[belt][1]] << "]" << endl;
			cout << "3 слот: " << "[" << ItemName[player.inventory[belt][2]] << "]" << endl;
			cout << "4 слот: " << "[" << ItemName[player.inventory[belt][3]] << "]" << endl;
			cout << endl;
			cout << "Выберите слот в который хотите поместить предмет или заменить старый: ";
			int slot;
			cin >> slot;
			cout << "Надеть или заменить предмет? (y/n): ";
			char choice;
			cin >> choice;
			if (choice == 'y') {
				player.inventory[Items[drop][1]][Items[drop][2]] = drop;
				player.chance_to_drop = 30;
				player.save();
			}
			else {
				return;
			}
		}
	}
		else {
			player.chance_to_drop += 5;
			player.save();
			return;
		}
}



void game() {
	Game player, bot;
	player.load();
	for (int i = 0; i < player.display_level; i++) {   //Рандомно +2 к скиллу бота
		int skill_choice = bot_skill();
		if (skill_choice = 1) {
			bot.chance_to_hit += 2;
		}
		if (skill_choice = 2) {
			bot.chance_of_protection += 2;

		}
		if (skill_choice = 3) {
			bot.chance_to_parry += 2;
		}
	}
	int game_health = player.feature(hp);
	int game_damage = player.feature(dmg);
	int game_hit = player.feature(hit);
	int game_prot = player.feature(prot);
	int game_parry = player.feature(parry);
	while (game_health > 0 or bot.health > 0) {
		if (game_health <= 0 or bot.health <= 0) {
			break;
		}
		cout << "ХП Игрока: " << game_health << endl;
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
				if (try_to_hit(game_hit) == true) {
					if (try_to_parry(bot.chance_to_parry) == true) {
						game_health -= game_damage;
						cout << "Противник парировал урон" << endl;
						cout << endl;
					}
					else{
						if (try_to_protect(bot.chance_of_protection) == true) {
							cout << "Противник смог защититься" << endl;
							cout << endl;
						}
						else {
							bot.health -= game_damage;
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
				if (try_to_hit(game_hit) == true) {
					bot.health -= game_damage;
					cout << "Вы нанесли урон" << endl;
					cout << endl;
						
					
				}
				else {
					cout << "Вам не удалось нанести урон" << endl;
					cout << endl;
					
				}
				if (try_to_hit(bot.chance_to_hit) == true) {
					game_health -= bot.damage;
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
					if (try_to_parry(game_parry) == true) {
						bot.health -= bot.damage;
						cout << "Вы парировали урон" << endl;
						cout << endl;
					}
					else {
						game_health -= bot.damage;
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
	if (bot.health == 0 and game_health != 0) {
		system("cls");
		cout << "___Вы победили!___" << endl;
		player.exp += 10;
		player.number_of_duels += 1;
		cout << "Ваш опыт - " << player.exp << "(+10)";
		cout << endl;
	}
	if (game_health == 0 and bot.health != 0) {
		system("cls");
		cout << "___Вы проиграли___" << endl;
		player.exp -= 5;
		cout << "Ваш опыт - " << player.exp << "(-5)";
		cout << endl;
	}
	if (bot.health == 0 and game_health == 0) {
		system("cls");
		cout << "___Ничья___" << endl;
		player.exp += 5;
		cout << "Ваш опыт - " << player.exp << "(+5)";
		cout << endl;
	}
	
	while (player.exp >= 100) {
		player.exp -= 100;
		player.display_level += 1;
		player.level += 1;
	}
	for (int i = 0; i < player.level; i++) {
		cout << endl;
		cout << "Выберите улучшение: " << endl;
		cout << "|1 - шанс попадания" << endl;
		cout << "|2 - шанс защиты" << endl;
		cout << "|3 - шанс парировать" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			player.chance_to_hit += 2;
			
		}
		if (choice == 2) {
			player.chance_of_protection += 2;
			
		}
		if (choice == 3) {
			player.chance_to_parry += 2;
			
		}
	}
	player.level = 0;
	player.save();
	drop();
	cout << endl;
	cout << "любой символ чтобы вернуться в меню" << endl;
	cout << "n - начать навую игру" << endl;
	char d;
	cin >> d;

	if (d == 'n') {
		system("cls");
		game();
		
	}
	else {
		return;
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
			break;
		}
		if (check.is_open()) {
			if (check_num == 2) {
				system("cls");
				game();
				break;
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
			break;
		}
		if (Start == 's') {
			player.stat();
			menu();
			break;
		}
		if (Start == 'i') {
			system("cls");
			inv();
			break;
		}
	}
	
}

int main() {
	system("color 2");
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	bool flag = false;
	cout << "|``````````````````````|\n"\
		<< "|       Welcome        |\n"\
		<< "|         To           |\n"\
		<< "|        Du3l          |\n"\
		<< "|,,,,,,,,,,,,,,,,,,,,,,|" << endl;
	cout << "Напишите любой символ чтобы начать: ";
	
	char Start;
	cin >> Start;
	while (true) {
		
				system("cls");
				menu();
				
			if (Start == 'S') {
				flag = true;
				system("cls");
				menu();
			}
		}
		
	}	


