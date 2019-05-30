#include "Project_head.h"

void instance(){
	Person joe;
	for(int step = 0;;step++){
		joe.update();
		float bad_luck = (float) rand()/(float) RAND_MAX;
		if (bad_luck > 0.95) {
			joe.infect(5);
		}
		cout << "On day " << setw(2) << step << ", Joe is " << joe.status_string() << endl;
		if (joe.is_stable()){
			break;
		}
	}
}
