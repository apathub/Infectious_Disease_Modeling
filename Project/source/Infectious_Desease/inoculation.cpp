#include "Project_head.h"

void population_inoculation(){
	int npeople; //Calls for population size and creates a class with a vector of people
	float perVaccinated; //Transfer the % of people vaccinated to the population class	
	float perTransfer; //Transfers the % chance to transfer the disease to the population class
	// User Input
	cout << "Please, enter the size of the population? ";
	cin >> npeople;
	cout << "Please, enter the percentage (0<p<1) of vaccinated people: ";
	cin >> perVaccinated;
	cout << "Please, enter the change (0<c<1) of disease transfer: ";
	cin >> perTransfer;
	// create a test population object
	Population population(npeople,perTransfer,perVaccinated);

	srand(time(NULL)); // the seed
	population.run_simulation(1); // run simulation
}
