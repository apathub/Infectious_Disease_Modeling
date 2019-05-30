#include <iostream> //input output
#include <string>
#include <stdlib.h> //general functions
#include <sstream> // string stream
#include <time.h>
#include <iomanip> //parametric manipulators
#include <math.h>
#include <fstream> //input output file stresm
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::setw;
using std::string;
using std::ostringstream;
using std::vector;

void instance();
void population();
void population_spreading();
void population_inoculation();
void population_transmition_probability();
void menu();
void mainMenu();

class Person{
private:
	int health_state;
	int npeople_Infected;
	int npeople_Innoculated;
	int npeople_Recovered;
	int npeople_Susceptible;
public:
	Person();
	void infect(int n);
	void infect(int n, int& npeople_Infected, int& npeople_Susceptible);
	bool is_stable();
	int num_people_internal;
	string status_string();
	string status_string(bool narrative);
	void update();
	void update(int& npeople_Recovered,int& npeople_Infected);
	void vaccinate(int& npeople_Innoculated,int& npeople_Susceptible);
};

class Population{
private:
	int population_size;
	vector<Person> people;
	float per_vaccinated_internal;
	float prob_of_transfer;
	int people_Encountered;
	int npeople_Infected;
	int npeople_Susceptible;
	int npeople_Recovered;
	int npeople_Innoculated;
public:
	// initialize input in case user doesn't provide any values
	Population(int npeople,float Probability_Transfer = 0.0,
			float perVaccinated = 0.0,int pEncountered = 0);
	void count_infected();
	void random_vaccinations();
	void random_infection();
	void update();
	void people_display();
	void infect_people(bool randomEncounters = false);
	void run_simulation(int caseN);	
	void write_csv_summary(int inp_0=0, float inp_1 = 0.0, float inp_2 = 0.0, int inp_3=0, int inp_4=0, int inp_5=0, int inp_6=0, int inp_7=0);
};
