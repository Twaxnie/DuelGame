#include <iostream>
#include <fstream>
#include <stdio.h>
#include <windows.h>
using namespace std;

//rand()%100+1
//system("cls");

void print(string text) {
	cout << text << endl;
}

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
	"Empty",              //0
	"Spider Mask",        //1
	"Deadpool's Katana",  //2
	"Cap's Shield",       //3
	"Stark Armor",        //4
	"Mind Stone",         //5
	"Power Stone"         //6
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

string Bot_Name[] = { "Ironclad", "Strong", "Parryman", "Giant", "Default" };

//                      id     hp      dmg    hit    prot   parry
int Bot_Stat[5][6] = {  {0,    110,    10,    50,    65,    15},
						{1,    100,    15,    60,    45,    20},
						{2,    100,    10,    30,    40,    40},
						{3,    150,    20,    30,    30,    10},
						{4,    100,    10,    50,    50,    15} };


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
	float money = 0;

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
			<< chance_to_drop << endl\
			<< money;
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
			>> chance_to_drop\
			>> money;
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
		system("color 5");
		print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
		print("::::::::::::::::::::::::::::::::::::'######::'########::::'###::::'########::'######::::::::::::::::::::::::::::::::::::");
		print("::::::::::::::::::::::::::::::::::::'##... ##:... ##..::::'## ##:::... ##..::'##... ##::::::::::::::::::::::::::::::::::");
		print(":::::::::::::::::::::::::::::::::::: ##:::..::::: ##:::::'##:. ##::::: ##:::: ##:::..:::::::::::::::::::::::::::::::::::");
		print("::::::::::::::::::::::::::::::::::::. ######::::: ##::::'##:::. ##:::: ##::::. ######:::::::::::::::::::::::::::::::::::");
		print(":::::::::::::::::::::::::::::::::::::..... ##:::: ##:::: #########:::: ##:::::..... ##::::::::::::::::::::::::::::::::::");
		print("::::::::::::::::::::::::::::::::::::'##::: ##:::: ##:::: ##.... ##:::: ##::::'##::: ##::::::::::::::::::::::::::::::::::");
		print("::::::::::::::::::::::::::::::::::::. ######::::: ##:::: ##:::: ##:::: ##::::. ######:::::::::::::::::::::::::::::::::::");
		print(":::::::::::::::::::::::::::::::::::::......::::::..:::::..:::::..:::::..::::::......::::::::::::::::::::::::::::::::::::");
		
		cout << "Name - " << player.name << endl;
		cout << "EXP - " << player.exp << endl;
		cout << "Damage - " << player.damage << endl;
		cout << "----------" << endl;
		cout << "Attack chance - " << player.chance_to_hit << endl;
		cout << "Defense chance - " << player.chance_of_protection << endl;
		cout << "Chance to parry - " << player.chance_to_parry << endl;
		cout << "----------" << endl;
		cout << "Number of wins: " << player.number_of_duels << endl;
		cout << "LVL: " << player.display_level;
		cout << endl;
		cout << "----------" << endl;
		cout << "Money: " << player.money << endl;
		cout << endl;
		cout << "Back to menu: ";
		char b;
		cin >> b;
		
	}
};

/* void roulette() {
	Game player;
	cout << "Your balance: " << player.money << endl;
	cout << "Bet: ";
	float bet = 0;
	char Char_String[4] = {'*', '$', '#', '_'};
	cin >> bet;
	player.money -= bet;
	char choice1 = rand() % 4;
	char choice2 = rand() % 4;
	char choice3 = rand() % 4;
	int won_money = 0;
	if (choice1 == 0) {
		if ((choice2 == 0 and choice3 != 0) or (choice2 != 0 and choice3 == 0)) {
			player.money += bet * 1.5;
			won_money = bet * 1.5;
		}
		if (choice2 == 0 and choice3 == 0) {
			player.money += bet * 2;
			won_money = bet * 2;
		}
	}
	if (choice1 == 1) {
		if (choice2 == 1 and choice3 == 1) {
			player.money += bet * 10;
			won_money = bet * 10;
		}
	}
	if (choice1 == 2) {
		if ((choice2 == 2 and choice3 != 2) or (choice2 != 2 and choice3 == 2)) {
			player.money += bet * 1.25;
			won_money = bet * 1.25;
		}
		if (choice2 == 2 and choice3 == 2) {
			player.money += bet * 1.5;
			won_money = bet * 1.5;
		}
	}
	system("cls");
	for (int i = 0; i < 10; i++) {
		print("::::::::::::::::::::::::");
		cout << ":   " << Char_String[rand() % 4] << "   :   " << Char_String[rand() % 4] << "   :   " << Char_String[rand() % 4] << "   :" << endl;
		print("::::::::::::::::::::::::");
		Sleep(1000);
		system("cls");
		
	}
	system("cls");
	print("::::::::::::::::::::::::");
	cout << ":   " << Char_String[choice1] << "   :   " << Char_String[choice2] << "   :   " << Char_String[choice3] << "   :" << endl;
	print("::::::::::::::::::::::::");
	cout << "You won: " << won_money << " coins" << endl;
	cout << "1| Back to menu" << endl;
	cout << "2| Try again" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		return;
	}
	if (choice == 2) {
		roulette();
	}
}
*/



void inv() {
	Game player;
	player.load();
	player.inventory;
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::'####:'##::: ##:'##::::'##:'########:'##::: ##:'########::'#######::'########::'##:::'##::::::::::::::::");
	print("::::::::::::::::. ##:: ###:: ##: ##:::: ##: ##.....:: ###:: ##:... ##..::'##.... ##: ##.... ##:. ##:'##:::::::::::::::::");
	print("::::::::::::::::: ##:: ####: ##: ##:::: ##: ##::::::: ####: ##:::: ##:::: ##:::: ##: ##:::: ##::. ####::::::::::::::::::");
	print("::::::::::::::::: ##:: ## ## ##: ##:::: ##: ######::: ## ## ##:::: ##:::: ##:::: ##: ########::::. ##:::::::::::::::::::");
	print("::::::::::::::::: ##:: ##. ####:. ##:: ##:: ##...:::: ##. ####:::: ##:::: ##:::: ##: ##.. ##:::::: ##:::::::::::::::::::");
	print("::::::::::::::::: ##:: ##:. ###::. ## ##::: ##::::::: ##:. ###:::: ##:::: ##:::: ##: ##::. ##::::: ##:::::::::::::::::::");
	print("::::::::::::::::'####: ##::. ##:::. ###:::: ########: ##::. ##:::: ##::::. #######:: ##:::. ##:::: ##:::::::::::::::::::");
	print("::::::::::::::::....::..::::..:::::...:::::........::..::::..:::::..::::::.......:::..:::::..:::::..::::::::::::::::::::");
	cout << endl;
	print(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::Armor::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	cout << "Head: " << "[" << ItemName[player.inventory[wear][head]] << "]" << endl;
	cout << "Body: " << "[" << ItemName[player.inventory[wear][body]] << "]" << endl;
	cout << "Hands: " << "[" << ItemName[player.inventory[wear][legs]] << "]" << endl;
	cout << "Legs: " << "[" << ItemName[player.inventory[wear][boots]] << "]" << endl;
	cout << endl;
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::Weapon::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	cout << "Right Hand: " << "[" << ItemName[player.inventory[weapon][rightArm]] << "]" << endl;
	cout << "Left Hand: " << "[" << ItemName[player.inventory[weapon][leftArm]] << "]" << endl;
	cout << endl;
	print(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::Belt ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	cout << "1 slot: " << "[" << ItemName[player.inventory[belt][0]] << "]" << endl;
	cout << "2 slot: " << "[" << ItemName[player.inventory[belt][1]] << "]" << endl;
	cout << "3 slot: " << "[" << ItemName[player.inventory[belt][2]] << "]" << endl;
	cout << "4 slot: " << "[" << ItemName[player.inventory[belt][3]] << "]" << endl;

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
		cout << "New item: " << ItemName[drop] << endl;
		if (Items[drop][1] == wear) {
			cout << "In this slot " << ItemName[player.inventory[Items[drop][1]][Items[drop][2]]] << endl;
			cout << "Put on or replace an item? (y/n): ";
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
			cout << "In the slot" << player.inventory[Items[drop][1]][Items[drop][2]] << endl;
			cout << "Put on or replace an item? (y/n): ";
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
			cout << "_________Belt_________" << endl;
			cout << "1 slot: " << "[" << ItemName[player.inventory[belt][0]] << "]" << endl;
			cout << "2 slot: " << "[" << ItemName[player.inventory[belt][1]] << "]" << endl;
			cout << "3 slot: " << "[" << ItemName[player.inventory[belt][2]] << "]" << endl;
			cout << "4 slot: " << "[" << ItemName[player.inventory[belt][3]] << "]" << endl;
			cout << endl;
			cout << "Select the slot where you want to place the item or replace the old one: ";
			int slot;
			cin >> slot;
			cout << "Put on or replace an item? (y/n): ";
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

void Give_Money() {
	Game player;
	player.load();
	int give_money = rand() % 20;
	cout << "You've earned " << give_money << "coin" << endl;
	player.money += give_money;
	player.save();
}


void game() {
	Game player, bot;
	player.load();

	//bot_loading
	int rand_type = rand() % 5;
	cout << "Enemy type : " << Bot_Name[rand_type] << endl;
	bot.health = Bot_Stat[rand_type][1];
	bot.damage = Bot_Stat[rand_type][2];
	bot.chance_to_hit = Bot_Stat[rand_type][3];
	bot.chance_of_protection = Bot_Stat[rand_type][4];
	bot.chance_to_parry = Bot_Stat[rand_type][5];

	for (int i = 0; i < player.display_level; i++) {   //Bot skill +2
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

	//player_stats
	int game_health = player.feature(hp);
	int game_damage = player.feature(dmg);
	int game_hit = player.feature(hit);
	int game_prot = player.feature(prot);
	int game_parry = player.feature(parry);

	//game_start

	while (game_health > 0 or bot.health > 0) {
		if (game_health <= 0 or bot.health <= 0) {
			break;
		}
		cout << "HP Player: " << game_health << endl;
		cout << "HP Bot: " << bot.health << endl;
		cout << endl;
		char player_action;
		cout << "Choose an action (A - attack, D - defense): ";
		cin >> player_action;
		system("cls");
		char bot_act = bot_action();
		if (player_action == 'A') {
			if (bot_act == 'D') {
				cout << "You attack" << endl;
				cout << "The enemy tries to defend" << endl;
				cout << endl;
				if (try_to_hit(game_hit) == true) {
					if (try_to_parry(bot.chance_to_parry) == true) {
						game_health -= game_damage;
						cout << "The enemy parried the damage" << endl;
						cout << endl;
					}
					else{
						if (try_to_protect(bot.chance_of_protection) == true) {
							cout << "The enemy was able to defend" << endl;
							cout << endl;
						}
						else {
							bot.health -= game_damage;
							cout << "The enemy was unable to defend" << endl;
							cout << endl;
						}
					}

				}
				else {
					cout << "You failed to deal damage" << endl;
					cout << endl;
					
				}
			}
			if (bot_act == 'A') {
				cout << "You attack" << endl;
				cout << "The enemy attacks" << endl;
				cout << endl;
				if (try_to_hit(game_hit) == true) {
					bot.health -= game_damage;
					cout << "You have done damage" << endl;
					cout << endl;
						
					
				}
				else {
					cout << "You failed to deal damage" << endl;
					cout << endl;
					
				}
				if (try_to_hit(bot.chance_to_hit) == true) {
					game_health -= bot.damage;
					cout << "You have been damaged" << endl;
					cout << endl;	
				}
				else {
					cout << "The enemy did not damage" << endl;
					cout << endl;
				}
			}
		}
		if (player_action == 'D') {
			if (bot_act == 'D') {
				cout << "You defend" << endl;
				cout << "The enemy is defending" << endl;
				cout << endl;
			}
			if (bot_act == 'A') {
				cout << "You defend" << endl;
				cout << "The enemy attacks" << endl;
				cout << endl;
				if (try_to_hit(bot.chance_to_hit) == true) {
					if (try_to_parry(game_parry) == true) {
						bot.health -= bot.damage;
						cout << "You parried the damage" << endl;
						cout << endl;
					}
					else {
						game_health -= bot.damage;
						cout << "The enemy has damaged you" << endl;
						cout << endl;
					}
				}
				else {
					cout << "The enemy was unable to inflict damage" << endl;
					cout << endl;
					
				}
			}
		}
	}
	if (bot.health == 0 and game_health != 0) {
		system("cls");
		cout << "___You won!___" << endl;
		player.exp += 10;
		player.number_of_duels += 1;
		cout << "Your experience - " << player.exp << "(+10)";
		cout << endl;
	}
	if (game_health == 0 and bot.health != 0) {
		system("cls");
		cout << "___You lost___" << endl;
		player.exp -= 5;
		cout << "Your experience - " << player.exp << "(-5)";
		cout << endl;
	}
	if (bot.health == 0 and game_health == 0) {
		system("cls");
		cout << "___dead heat___" << endl;
		player.exp += 5;
		cout << "Your experience - " << player.exp << "(+5)";
		cout << endl;
	}
	
	//exp_add

	while (player.exp >= 100) {
		player.exp -= 100;
		player.display_level += 1;
		player.level += 1;
	}
	for (int i = 0; i < player.level; i++) {
		cout << endl;
		cout << "Select an upgrade: " << endl;
		cout << "|1 - hit chance" << endl;
		cout << "|2 - chance of defense" << endl;
		cout << "|3 - chance to parry" << endl;
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
	Give_Money();
	drop();
	cout << endl;
	cout << "any character to return to the menu" << endl;
	cout << "n - start a new game" << endl;
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
	cout << "|1 - Start the game with a new profile" << endl;
	cout << ((!check.is_open()) ? "" : "|2 - Start game with existing profile") << endl;
	int check_num;
	while (true){
		cin >> check_num;
		if (check_num == 1) {
			system("cls");
			cout << "Enter your name: ";
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
	system("color 2");
	cout << "|``````````````````````|\n"\
		<< "|         Play (p)     |\n"\
		<< "|         Stat (s)     |\n"\
		<< "|       Inventory (i)  |\n"\
		<< "|       Roulette(r)    |\n"\
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
		/*if (Start == 'r') {
			system("cls");
			roulette();
			break;
		}*/
	}
	
}

int main() {
	system("color 0");
	srand(time(NULL));
	//setlocale(LC_ALL, "Russian");
	bool flag = false;

	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print(":::::::::'########::'##::::'##:'########:'##::::::::::::::::::::::::::'######::::::'###::::'##::::'##:'########:::::::::");
	print("::::::::: ##.... ##: ##:::: ##: ##.....:: ##:::::::::::::::::::::::::'##... ##::::'## ##::: ###::'###: ##.....::::::::::");
	print("::::::::: ##:::: ##: ##:::: ##: ##::::::: ##::::::::::::::::::::::::: ##:::..::::'##:. ##:: ####'####: ##:::::::::::::::");
	print("::::::::: ##:::: ##: ##:::: ##: ######::: ##::::::::::::::::::::::::: ##::'####:'##:::. ##: ## ### ##: ######:::::::::::");
	print("::::::::: ##:::: ##: ##:::: ##: ##...:::: ##::::::::::::::::::::::::: ##::: ##:: #########: ##. #: ##: ##...::::::::::::");
	print("::::::::: ##:::: ##: ##:::: ##: ##::::::: ##::::::::::::::::::::::::: ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::::::::::");
	print("::::::::: ########::. #######:: ########: ########:::::::::::::::::::. ######::: ##:::: ##: ##:::: ##: ########:::::::::");
	print(":::::::::........::::.......:::........::........:::::::::::::::::::::......::::..:::::..::..:::::..::........::::::::::");
	print(":::::::::::::::::::::::::::::::::::::::::::::::::'######::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::'##... ##:::'##:::::'##:::::::::::::::::::::::::::::::::::::::::::::::::");
	print(":::::::::::::::::::::::::::::::::::::::::::::::: ##:::..:::: ##::::: ##:::::::::::::::::::::::::::::::::::::::::::::::::");
	print(":::::::::::::::::::::::::::::::::::::::::::::::: ##:::::::'######:'######:::::::::::::::::::::::::::::::::::::::::::::::");
	print(":::::::::::::::::::::::::::::::::::::::::::::::: ##:::::::.. ##.::.. ##.::::::::::::::::::::::::::::::::::::::::::::::::");
	print(":::::::::::::::::::::::::::::::::::::::::::::::: ##::: ##::: ##::::: ##:::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::. ######::::..::::::..::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	print("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");

	
	
	
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


