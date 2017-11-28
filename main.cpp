#include <iostream>
#include <ctime>
#include "ProblemSolver.h"

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout << "Too few Argument";
		return 1;
	}
	ProblemSolver problemSolver{argv[1], argv[2], (argv + 3)};
	clock_t b = clock();
	problemSolver.run();
	clock_t e = clock();
	Result r = problemSolver.getResult();
	std::cout << "\t\tThe Resualt\n";
	if (r.answer != nullptr) std::cout << "Answer Found !\n";
	else std::cout << "Answer Not Found !\n";
	std::cout << "Path : ";
	for (auto& p : r.path) std::cout << p << " - "; std::cout << std::endl;
	std::cout << "Node Expanded : " << r.nodeExpand << std::endl;
	std::cout << "Node Seen     : " << r.nodeSeen   << std::endl;
	std::cout << "Time    : "       <<  (double)(e - b)/CLOCKS_PER_SEC  << std::endl;
	std::cout << "Path Cost     : " << r.pathCost << std::endl;
	if (r.maxMemoryUsage > 1024*1024) std::cout << "MaxMemory Use : " << r.maxMemoryUsage/(1024*1024) << "MB" << std::endl;
	else if (r.maxMemoryUsage > 1023) std::cout << "MaxMemory Use : " << r.maxMemoryUsage/1024.0 << "KB" << std::endl;
	else std::cout << "MaxMemory Use : " << r.maxMemoryUsage << "B" << std::endl;
	
	return 0;
}