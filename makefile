info:
	@echo "You can compile everything or each Excercise seperately: 'make CompAll' or 'make CompE#' (#=1:5)."
	@echo "You may also use the script to remove the binaries 'RemoveBin'."

CompAll: CompE1 CompE2 CompE3 CompE4 CompE5

CompE1: Ex39_1.cc Project_lib.o
	g++ -o CompE1 Ex39_1.cc Project_lib.o

CompE2: Ex39_2.cc Project_lib.o
	g++ -o CompE2 Ex39_2.cc Project_lib.o

CompE3: Ex39_3.cc Project_lib.o
	g++ -o CompE3 Ex39_3.cc Project_lib.o

CompE4: Ex39_4.cc Project_lib.o
	g++ -o CompE4 Ex39_4.cc Project_lib.o

CompE5: Ex39_5.cc Project_lib.o
	g++ -o CompE5 Ex39_5.cc Project_lib.o

Project_lib.o:
	g++ -c Project_lib.cc
	
RemoveBin:
	rm -f Project_lib.o CompE1 CompE2 CompE3 CompE4 CompE5
