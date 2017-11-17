//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemSolver.h"

ProblemSolver::ProblemSolver(const char *problem, const char *search, char* argv[]) {
	setProblem(problem);
	setSearch(search, argv);
}

ProblemSolver::~ProblemSolver() {
	delete search;
	delete problem;
}

void ProblemSolver::run() {
	search->setProblem(problem);
	search->execute();
}

Result ProblemSolver::getResult() {
	return search->result;
}

void ProblemSolver::setSearch(const char *_search, char* argv[]) {
	bool isGraph = (*argv[0] == 'G' || *argv[0] == 'g');
	if (_search == "BFS") {
		search = new SearchBFS(isGraph);
	} else if (_search == "DFS") {
		switch (atoi(argv[1])) {
			case -1:
				search = new SearchDFS(isGraph);
				break;
			case 0:
				search = new SearchDFS(isGraph);
				break;
			default:
				search = new SearchDFSX(isGraph, (unsigned int) atoi(argv[1]));
				break;
		}
	} else if (_search == "UCS") {
		search = new SearchUCS(isGraph);
		
	} else if (_search == "BID") {
		search = new SearchBidirect(isGraph);
		
	} else if (_search == "A*") {
		search = new SearchAStar(isGraph);
		
	}
}

void ProblemSolver::setProblem(const char *_problem) {
	if (_problem == "Nav") {
		problem = new ProblemNavigation;
	} else if (_problem == "Water") {
		problem = new ProblemWater;
	} else if (_problem == "Puzzle") {
		problem = new ProblemPuzzle;
	}
}
