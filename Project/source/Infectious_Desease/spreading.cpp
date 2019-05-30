#include "Project_head.h" //include the headerfile

void population_spreading(){
	int npeople; //Calls for population size and creates a class with a vector of people
	float perVaccinated; //Transfers the % of people vaccinated to the population class
	float perTransfer; //Transfers the % chance to transfer the disease to the population class
	int pEncountered; //Sets the amount of people someone encounters per day in the pop. class

	cout << "Please, enter the size of the population? ";
	cin >> npeople;
	cout << "Please, enter the percentage (0<p<1) of people who are vaccinated: ";
	cin >> perVaccinated;
	cout << "Please, enter the change (0<c<1) of disease transfer: ";
	cin >> perTransfer;
	cout << "Please, enter how many people the sick person encounters: ";
	cin >> pEncountered;
	Population population(npeople,perTransfer,perVaccinated,pEncountered);

	srand(time(NULL)); //the seed
	population.run_simulation(2);
};
