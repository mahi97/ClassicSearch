#include <iostream>

#include "ProblemSolver.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Too few Argument";
		return 1;
	}
	
	ProblemSolver problemSolver{argv[1], argv[2], (argv + 3)};
	problemSolver.run();
	problemSolver.getResult();
	return 0;
}