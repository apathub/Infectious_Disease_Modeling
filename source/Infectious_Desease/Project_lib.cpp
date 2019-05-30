#include "Project_head.h"

Person::Person(){
	health_state = 0;// by default every person is susceptible
}

// Method which infects a person with the diseaese to run for n days (polymorphism)
void Person::infect(int n) {
	if (health_state == 0) {
	health_state = n;
	}
};

void Person::infect(int n,int& npeople_Infected,int& npeople_Susceptible){
	if (health_state == 0){
	health_state = n;
	npeople_Infected++;
	npeople_Susceptible--;
	}
};
// Reports whether the peson has been sick and is recovered (polymorphism)
bool Person::is_stable() {
	if (status_string() == "recovered.") {
		return true;
	} else {
		return false;
	}
};
// status_string method (polymorphism - two cases depending on the input)
string Person::status_string() {
	if (health_state == 0) { return "susceptible."; }
	else if (health_state == -1) { return "recovered."; }
	else if (health_state == -2) { return "inocculated."; }
	else {
		ostringstream sickDaysString;
		sickDaysString << "sick (" << health_state << " to go)";
		return sickDaysString.str();
	}
};
string Person::status_string(bool narrative) {
	if (narrative == false) {
		if (health_state == 0) { return " ? "; }
		else if (health_state == -1) { return " - "; }
		else if (health_state == -2) { return " x "; }
		else { return " + "; }
	}
};

// The method update(), updates the disease status (polymorphism)
void Person::update() { // without inputs
	if (health_state > 1) {
		health_state--;
	}
	else if (health_state == 1) {
		health_state = -1;
	}
};
void Person::update(int& npeople_Recovered, int& npeople_Infected) { // with inputs
	if (health_state > 1) {
		health_state--;
	}
	else if (health_state == 1) {
		health_state = -1;
		npeople_Recovered++;
		npeople_Infected--;
	}
};
// Method which changes the health state
void Person::vaccinate(int& npeople_Innoculated, int& npeople_Susceptible) {
	health_state = -2;
	npeople_Innoculated++;
	npeople_Susceptible--;
};

// constructor for the Population class
Population::Population(int npeople,float Probability_Transfer,float perVaccinated,int pEncountered){
	population_size = npeople;
	prob_of_transfer = Probability_Transfer;
	per_vaccinated_internal = perVaccinated;
	people_Encountered = pEncountered;
	// initialize the state counters
	npeople_Infected = 0;
	npeople_Susceptible = npeople;
	npeople_Recovered = 0;
	npeople_Innoculated = 0;
	people = vector<Person>(npeople); //store the vector
};
// This methodcounts how many peole are infected
void Population::count_infected() {
	npeople_Infected = 0;
	for (int p = 0; p < population_size; p++) {
		if (people[p].status_string(false) == " + ") {//if sick
			npeople_Infected++;
		}
	}
};
// infect random people in the population
void Population::infect_people(bool randomEncounters) {
	vector<Person> peopleCopy = people;
	for (int p = 0; p < population_size; p++) {// for every person in the population
		if (peopleCopy[p].status_string(false) == " + ") {//if sick
			if (randomEncounters == true) {// if disease is transmitted from sick person to others (incorporate spreading EX39_5)
				for (int j = 0; j < people_Encountered; j++) {
					if ((float)rand() / (float)RAND_MAX < prob_of_transfer) {
						people[rand() % population_size].infect(5,
							npeople_Infected, npeople_Susceptible);
					}
				}
			}
			else {
				if ((float)rand() / (float)RAND_MAX < prob_of_transfer) {
					if (p - 1 >= 0) {
						people[p - 1].infect(5, npeople_Infected, npeople_Susceptible);
					}
				}
				if ((float)rand() / (float)RAND_MAX < prob_of_transfer) {
					if (p + 1 <= population_size - 1) {
						people[p + 1].infect(5, npeople_Infected, npeople_Susceptible);
					}
				}
			}
		}
	}
};

// This method displays the infection status of the whole population
void Population::people_display() {
	for (int p = 0; p < population_size; p++) {
		cout << people[p].status_string(false);
	}
};
// This method infects a random person of the population
void Population::random_infection() {
	if (per_vaccinated_internal < 1) {
		while (true) {
			int randPerson = rand() % population_size;
			if (people[randPerson].status_string(false) == " ? ") {
				people[randPerson].infect(5, npeople_Infected, npeople_Susceptible);
				break;
			}
		}
	}
};
void Population::random_vaccinations(){
	int number_vaccinated = population_size * per_vaccinated_internal;
	for (int p = 0; p < number_vaccinated;){
		int randPerson = rand() % population_size;
		if (people[randPerson].status_string(false) == " ? "){
			people[randPerson].vaccinate(npeople_Innoculated,npeople_Susceptible);
			p++;
		}
	}
};
// Run the Simulations 
void Population::run_simulation(int caseN) {
	int npeopleLength = log10(population_size) + 2;
	bool infectionActive = true;
	int step = 1;
	random_vaccinations();
	random_infection();
	if (population_size > 20) {
		cout << "The selected population is too large (>20). A summary of each state is presented:" << endl;
	}
	while (infectionActive) {
		if (population_size <= 20) {
			cout << "In step " << setw(npeopleLength) << step
				<< " #sick: " << setw(npeopleLength) << npeople_Infected << ":";
			people_display();
			cout << endl;
		}
		else {
			cout << "In step " << setw(npeopleLength) << step << "   #sick: "
				<< setw(npeopleLength) << npeople_Infected << "   #susceptible: "
				<< setw(npeopleLength) << npeople_Susceptible << "   #recovered: "
				<< setw(npeopleLength) << npeople_Recovered << "   #innoculated: "
				<< npeople_Innoculated << endl;
		}
		if (npeople_Infected == 0) {
			infectionActive = false;
		}
		update();
		if (caseN == 1) {
			infect_people(); // incorporate contagion 
		}
		else if (caseN == 2) {
			infect_people(true);  // incorporate spreading 
		}
		step++;
	}
	// export a summary of the simulation in a csv file
	write_csv_summary(step, prob_of_transfer, per_vaccinated_internal, people_Encountered, population_size, npeople_Infected, npeople_Susceptible, npeople_Recovered);
};

// update the status of each person on the population
void Population::update(){
	for (int p = 0; p < population_size; p++){
		people[p].update(npeople_Recovered,npeople_Infected);
	}
};

void Population::write_csv_summary(int inp_0,float inp_1, float inp_2, int inp_3, int inp_4, int inp_5, int inp_6, int inp_7) {
	std::fstream myfile;
	myfile.open("summary.csv", std::fstream::app);
	myfile <<inp_0<<","<< inp_1<<","<< inp_2<<","<<inp_3<<","<< inp_4<<","<< inp_5<<","<< inp_6<<","<< inp_7<<endl;
	myfile.close();
}


