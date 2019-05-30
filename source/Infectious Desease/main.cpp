#include "Project_head.h"

int choice1 = 0;
int choice2 = 3;

int main(int argc, char** argv) {
	menu();
	return 0;
}

void menu() {
	do {
		choice2 = 0;
		mainMenu();
		system("CLS");
		switch (choice1) {
		case 1:
			instance();
			break;
		case 2:
			population();
			break;
		case 3:
			population_transmition_probability();
			break;
		case 4:
			population_inoculation();
			break;
		case 5:
			//system("CLS");
			population_spreading();
			break;
		case 6:
			cout << "You chose to quit the program \n";
			break;
		}
		system("pause");
		system("CLS");
	} while (choice1 != 6);
}

void mainMenu(void) {
	cout << "Main Menu\n";
	cout << "1 - Infection Instance\n";
	cout << "2 - Population Infection\n";
	cout << "3 - Transmition probablity\n";
	cout << "4 - With Inoculation\n";
	cout << "5 - Infection Spreading\n";
	cout << "6 - Quit\n";
	cout << "Please choose: ";
	cin >> choice1;
}

