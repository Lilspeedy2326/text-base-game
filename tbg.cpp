#include<iostream>
using namespace std; 

//Global Variable
int affinity = 0;
int LokiHealth = 100;
int VillainGen();
string inventory[5] = { " ", " ", " ", " ", " " }; int gold = 100;


//functions variable
void PetGen();
void shop(); 
void ItemDropper();
void BattleSystem();
void BossBattle();

int main() {
	for (int i = 0; i < 5; i++)//prints inventory
		inventory[i] = " ";

	cout << "WELCOME TO SAKAAR LOKI!!!!!" << endl; 
	cout << "You see a Cocker Spaniel following you, you look at the name tag and its name is Bubbles, Bubbles is also white." << endl;
	cout << "You are stuck in the grandmaster Tower try to espace!!!!!!! " << endl;
	int room = 1;
	char input = 'a';
	bool chests[5] = { 0,0,0,0,0 };
	bool hasWon = false;


	while (input != 'q' && hasWon == false && LokiHealth > 0) { //OMG GAME LOOP!!!

		cout << "your inventory:" << endl;
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " ";
		cout << endl;

		switch (room) {
		case 1:
			PetGen();
			cout << "you're in Hulk's room, you can go (e)ast to head to the kitchen. " << endl;
			cout << "Bubbles wants you to (P)et him or (B)ellyrub him." << endl;
			cout << "you see a (c)hest in the corner." << endl;
			if (inventory[0] != "key")
				cout << "you see a shiny (k)ey on the floot" << endl;
			cin >> input;
			if (input == 'c') {
				if (chests[0] == 0) {
					cout << "you open the chest!" << endl;
					ItemDropper();
				}
				else {
					cout << "the chest is empty!" << endl;
				}
			}
			if (input == 'e' || input == 'E')
				room = 2;
			if (input == 'p' || input == 'P')
				cout << "Bubbles licks you for petting him" << endl;
			else if (input == 'b' || input == 'B')
				cout << "Bubbles has a smile because you gave him belly rubs" << endl;
			
			if (input == 'k')
				inventory[0] = "key";
			break;
		case 2:
			BattleSystem();
			PetGen();
			cout << "you're in the Kitchen, you can go (w)est back to Hulk's room or (s)outh to a storage room." << endl;
			
			cout << "Bubbles grabs a ball from the corner of the room (T)hrow the ball or make him (S)it for the ball" << endl;
			cin >> input;
			if (input == 'w' || input == 'E')
				room = 1;
			if (input == 't' || input == 'T')
				cout << "You throwed the ball and Bubbles chased it." << endl;
			else if (input == 's' || input == 'S')
				cout << "Bubbles sat so you threw the ball for him and he went to go chase it." << endl;
			if (input == 's' || input == 'S')
				if (inventory[0] == "key") {
					cout << "you unlock the door with the key!" << endl;
					inventory[0] = " ";
					room = 3;

				}
				else
					cout << "the door is locked, You need a key to open the door." << endl;
			break;
		case 3:
			PetGen();
			BattleSystem();
			cout << "you're in the storage room , you can go (n)orth back to Kitchen or go (e)ast to a Empty room." << endl;
			cout << "There's a sho(p) in the coner" << endl;
			cout << "You find Bubbles squeaky toy in the corner of the room, (S)queak the toy or (G)ive him the squeaky toy." << endl;
			cout << "you see a (c)hest in the corner." << endl;
			cin >> input;
			if (input == 'c') {
				if (chests[0] == 0) {
					cout << "you open the chest!" << endl;
					ItemDropper();
				}
				else {
					cout << "the chest is empty!" << endl;
				}
			}
			if (input == 'p' || input == 'P')
				shop();
			if (input == 'n' || input == 'N')
				room = 2;
			else if (input == 'e' || input == 'E')
				room = 4;
			if (input == 's' || input == 'S')
				cout << "You Squeak the toy so he barks for the toy." << endl;
			else if (input == 'g' || input == 'G')
				cout << "You give him the squeaky toy so he starts squeaking it none stop." << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
	    case 4:
			PetGen();
			BattleSystem();
			cout << "you're in the empty room, you can go (w)est to storage room or (s)outh to Cafeteria." << endl;
			cout << "Bubbles brings you his favorit bone, (T)hrow the bonbe or (M)ake him do tricks for the bone." << endl;
			cin >> input;
			if (input == 'w' || input == 'W')
				room = 3;
			else if (input == 's' || input == 'S')
				room = 5;
			if (input == 't' || input == 'T')
				cout << "Bubbles runs after the bone when you threw it." << endl;
			else if (input == 'm' || input == 'M')
				cout << "Bubbles start doing tricks for the bone." << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
		case 5:
			PetGen();
			BattleSystem();
			cout << "you're in the Cafeteria, you can go (n)orth back to the empty room or (s)outh to training room for battle." << endl;
			cout << "Make Bubbles (S)it or (R)ull over or (H)owl." << endl;
			cout << "you see a (c)hest in the corner." << endl;
			cin >> input;
			if (input == 'c') {
				if (chests[0] == 0) {
					cout << "you open the chest!" << endl;
					ItemDropper();
				}
				else {
					cout << "the chest is empty!" << endl;
				}
			}
			if (input == 'n' || input == 'N')
				room = 4;
			else if (input == 's' || input == 'S')
				room = 6;
			if (input == 'S' || input == 'S')
				cout << "Bubbles sat with a big smile." << endl;
			else if (input == 'r' || input == 'R')
				cout << "Bubbles rulled over while wagging his tail" << endl;
			else if (input == 'h' || input == 'H')
				cout << "Bubbles starts howling." << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
		case 6:
			PetGen();
			BattleSystem();
			cout << "you're in The training room for battle, you can go (n)orth bacl to the Cafeteria or (e)ast to the Gym." << endl;
			cout << "(F)eed bubbles with his food in the room in the Corner or give him (W)ater " << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 5;
			else if (input == 'e' || input == 'E')
				room = 7;
			if (input == 'f' || input == 'F')
				cout << "Food wags his tail while eating." << endl;
			else if (input == 'w' || input == 'W')
				cout << "Bubbles wags his tail while drinking water." << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
		case 7:
			PetGen();
			BattleSystem();
			cout << "you're in the gym, you can go (w)est back to Training room or (s)outh to the Armor room." << endl;
			cout << "Grab Bubbles (B)lanket and put it over him so he can take a nap, give Bubbles his stuff (A)nimals so he can sleep with it." << endl;
			cout << "you see a (c)hest in the corner." << endl;
			cin >> input;
			if (input == 'c') {
				if (chests[0] == 0) {
					cout << "you open the chest!" << endl;
					ItemDropper();
				}
				else {
					cout << "the chest is empty!" << endl;
				}
			}
		case 8:
			PetGen();
			BattleSystem();
			cout << "you're in the Armor room, you can go (n)orth back to the gym or (e)ast to the weapon room." << endl;
			cout << "Bubbles brings his (R)ope to play tuggle war, Bubbles makes you (C)hase" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 7;
			else if (input == 'e' || input == 'E')
				room = 9;
			if (input == 'r' || input == 'R')
				cout << "You are playing tuggle war with Bubbles." << endl;
			else if (input == 'c' || input == 'C')
				cout << "" << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
		case 9:
			PetGen();
			BattleSystem();
			cout << "you're in the Weapon room, you can go (w)est back to the armor room or (s)outh to the Grand Arena." << endl;
			cout << "Bubbles brings you his frisbee, You (T)hrow it or throw to his (M)outh so he can catch it with his mouth" << endl;
			cout << "" << endl;
			cin >> input;
			if (input == 'w' || input == 'W')
				room = 8;
			else if (input == 's' || input == 'S')
				room = 10;
			if (input == 't' || input == 'T')
				cout << "" << endl;
			else if (input == 'w' || input == 'W')
				cout << "" << endl;
			else
				cout << "sorry, I don't understand" << endl;
			break;
		case 10:
			PetGen();
			BossBattle();
			cout << "You are in Grand Arena, you can go (n)orth back to the weapon room." << endl;
			cout << "" << endl;
			cin >> input;
			if (input == 'n' || input == 'N')
				room = 9;
			if (input == 'n' || input == 'N')
				cout << "" << endl;
			else if (input == 'n' || input == 'N')
				cout << "" << endl;

			else
				cout << "sorry, I don't understand" << endl;
			break;
			cout << "You made it to the last room and you defeatd the boss batlle so. YOU ESCAPED THE GRAND MASTER TOWER AS WELL!!!!!!" << endl;
			hasWon = true; // cause game loop tp quit
			break;
		}


	}//end of game loop

	if (hasWon == true) {
		cout << "The text base game has ended!" << endl;
		cout << "Thanks for playig, YOU WIN!" << endl;

	}
	//you can add more messages here

}//end of main 



void shop() {
	cout << "Welcome to the shop" << endl;
	int input = 2;
	while (input != 0) {
		cout << "What would you like to buy?" << endl;
		cout << "1) cupcake: $5" << endl;
		cout << "2) dirty sock: $10" << endl;
		cout << "3) key: $50" << endl;
		cout << "enter 1, 2, 3, 0 to quit." << endl;
		for (int i = 0; i < 5; i++)
			cout << inventory[i] << " ";
		cout << endl<<endl;

		cout << "what would you like to purchase?" << endl;
		cin >> input;

		if (input == 1) {
			if (gold >= 5) {
				cout << "you bought the cupcake!" << endl;
				inventory[1] = "cupcake";
				gold -= 5;
			}
			else
				cout << "you don't have enough gold!" << endl;
		
		}
		else if (input == 2) {
			if (gold >= 10) {
				cout << "you bought the sock!" << endl;
				inventory[2] = "sock";
				gold -= 10;
			}
			else
				cout << "you don't have enough gold!" << endl;
		}
		else if (input == 3) {
			if (gold >= 50) {
				cout << "you bought the key!" << endl;
				inventory[0] = "key";
				gold -= 50;
			}
			else
				cout << "you don't have enough gold!" << endl;
		}
		else {
			cout << "that's not an option, dummy" << endl;
		}
	}
}


void ItemDropper() {
	int num = rand() % 100;
	if (num < 20) {
		cout << "you got a  Lævateinn!! " << endl;
		inventory[2] = " Lævateinn ";
	}
	else if (num < 50) {
		cout << "you got a Dagger!!!" << endl;
		inventory[3] = "Dagger!!!";
	}
	else if (num < 75) {
		cout << "you got the Scepter" << endl;
		inventory[4] = "Scepter";
	}
	else {
		cout << "you get nothing!" << endl;

	}
}

int VillainGen() {
	int num = rand() % 100;
	if (num < 5) {
		cout << "Venom appeard" << endl;
		return 10;
	}
	else if (num < 55) {
		cout << "Surtur appeared" << endl;
		return 15;
	}
	else if (num < 75) {
		cout << "Agatha Harkness appeared" << endl;
		return 20;
	}
	else if (num < 100) {
		cout << "Hela appeared" << endl;
		return 25;
	}
	else {
		cout << "Not a option" << endl;
		return 0;
	}
}
void BattleSystem() {
	cout << "Batlle commencing!" << endl;
	int Villain = VillainGen(); //the Villain variable holds onto the number VillainGen() returns!
	int VillainHealth = 20;
	int Villaindmg;
	int Lokidmg;

	//set different health and dmg for Villains
	if (Villain == 10) {//Venom
		Villaindmg = rand() % 20 + 20;
	}
	else if (Villain == 15) {//Surtur
		Villaindmg = rand() % 30 + 20;
	}
	else if (Villain == 20) {//Agatha Harkness 
		Villaindmg = rand() % 30 + 30;
	}
	else if (Villain == 25) {//Hela
		Villaindmg = rand() % 40 + 30;
	}
	else if (Villain == 0) {
		VillainHealth = 0;
		Villaindmg = 0;
	}

	char input;
	while (LokiHealth > 0 && VillainHealth > 0) { //battle system game loop


		if (Villain == 10) {//Venom
			Villaindmg = rand() % 20 + 20;
		}
		else if (Villain == 15) {//Surtur
			Villaindmg = rand() % 30 + 20;
		}
		else if (Villain == 20) {//Agatha Harkness 
			Villaindmg = rand() % 30 + 30;
		}
		else if (Villain == 25) {//Hela 
			Villaindmg = rand() % 40 + 30;
		}
		//monster attacks player
		Villaindmg = rand() % 10; //0-9dmg
		LokiHealth -= Villaindmg;
		cout << endl << endl << "The Villain hits you for" << Villaindmg << " damage." << endl;
		//player attacks monster
		Lokidmg = rand() % 50 + 50; //10-19dmg
		VillainHealth -= Lokidmg;
		cout << "You hit the Villain for" << Villaindmg << " damage." << endl;
		cout << "Your health is" << LokiHealth << ", and the monster's is " << VillainHealth << endl;
	}//end of loop
	
}



void PetGen() {
	int num = rand() % 100;
	if (num < 5)
		cout << "Buddy wags his tail" << endl;
	else if (num < 55)
		cout << "Buddy Barks!!" << endl;
	else if (num < 75)
		cout << "Buddy runs around the room" << endl;
	else if (num < 100)\
		cout << "Buddy takes a nap" << endl;
	else
		cout << "Not a option" << endl;
}

void BossBattle() {
	int GalactusHealth = 100;
	int num;
	cout << "Let the Final Battle commence." << endl;
	while (LokiHealth > 0 && GalactusHealth > 0)
		//Boss attacks loki
		num = rand() % 10; //0-9dmg
	LokiHealth -= num;
	cout << "The Boss bites you for" << num << "damge." << endl;
	//player attacks monster
	num = rand() % 50 + 50; //10-19dmg
	GalactusHealth -= num;
	cout << "You hit the boss for" << num << " damage." << endl;
	cout << "Your health is" << LokiHealth << ", and the Boss's is " << GalactusHealth << endl;
}//end of loo`
