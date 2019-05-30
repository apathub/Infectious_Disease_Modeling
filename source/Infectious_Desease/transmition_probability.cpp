#include "Project_head.h"

void population_transmition_probability(){
	int npeople; //Calls for population size and creates a class with a vector of people
	float perTransfer; //Transfers the % chance to transfer the disease to the population class
	// User Input
	cout << "Please, enter the size of the population? ";
	cin >> npeople;
	cout << "Please enter the change (0<c<1) of disease transfer: ";
	cin >> perTransfer;
	// create a test population object
	Population population(npeople,perTransfer);

	srand(time(NULL)); //the seed for rand
	population.run_simulation(1); // run simulation incorporate contagion
}
