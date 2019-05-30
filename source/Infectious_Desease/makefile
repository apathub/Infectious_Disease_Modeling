info:
        @echo "You can compile everything or each Excercise seperately: 'make CompAll' or 'make CompE#' (#=1:5)."
        @echo "You may also use the script to remove the binaries 'RemoveBin'."

RemoveBin:
        rm -f Project_lib.o instance.o population.o inoculation.o spreading.o transmition_probability.o main.o

Test:
        g++ -c Project_lib.cpp
        g++ -c instance.cpp
        g++ -c population.cpp
        g++ -c inoculation.cpp
        g++ -c spreading.cpp
        g++ -c transmition_probability.cpp
        g++ -c main.cpp
        g++ -o program Project_lib.o instance.o population.o inoculation.o spreading.o transmition_probability.o main.o



