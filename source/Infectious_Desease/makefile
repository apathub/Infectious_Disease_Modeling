info:
	@echo "You can compile everything or each Excercise seperately: 'make CompAll' or 'make CompE#' (#=1:5)."
	@echo "You may also use the script to remove the binaries 'RemoveBin'."

CompAll: CompE1 CompE2 CompE3 CompE4 CompE5

CompE1: instance.cc Project_lib.o
	icpc -o CompE1 instance.cc Project_lib.o

CompE2: population.cc Project_lib.o
	icpc -o CompE2 population.cc Project_lib.o

CompE3: inoculation.cc Project_lib.o
	icpc -o CompE3 inoculation.cc Project_lib.o

CompE4: spreading.cc Project_lib.o
	icpc -o CompE4 spreading.cc Project_lib.o

CompE5: transmition_probability.cc Project_lib.o
	icpc -o CompE5 transmition_probability.cc Project_lib.o

CompE6: main.cc Project_lib.o
	icpc -o CompE5 main.cc Project_lib.o

Project_lib.o:
	icpc -c Project_lib.cc
	
RemoveBin:
	rm -f Project_lib.o CompE1 CompE2 CompE3 CompE4 CompE5 CompE6
