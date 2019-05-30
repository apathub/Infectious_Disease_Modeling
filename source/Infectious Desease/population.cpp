#include "Project_head.h"

void population(){
	int npeople;
	// User Input
	cout << "Please, enter the size of the population? ";
	cin >> npeople;
	// create a test population object
	Population population(npeople);

	srand(time(NULL)); //the seed for rand
	population.run_simulation(0);//run simulation
};
