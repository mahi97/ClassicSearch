//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "ProblemSolver.h"

ProblemSolver::ProblemSolver(const char *problem, const char *search, char* argv[]) {
	setSearch(search, argv);
	setProblem(problem);
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
	if (strcmp(_search ,"BFS") == 0) {
		search = new SearchBFS(isGraph);
	} else if (strcmp(_search ,"DFS") == 0) {
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
	} else if (strcmp(_search ,"UCS") == 0) {
		search = new SearchUCS(isGraph);
		
	} else if (strcmp(_search ,"BID") == 0) {
		search = new SearchBidirect(isGraph);
		
	} else if (strcmp(_search ,"A*") == 0) {
		search = new SearchAStar(isGraph);
		
	}
}

void ProblemSolver::setProblem(const char *_problem) {
	if (strcmp(_problem ,"Nav") == 0) {
		problem = new ProblemNavigation;
	} else if (strcmp(_problem, "Water") == 0) {
		problem = new ProblemWater;
	} else if (strcmp(_problem,"Puzzle") == 0) {
		problem = new ProblemPuzzle;
	}
}
