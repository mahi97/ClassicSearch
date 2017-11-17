//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_PROBLEMSOLVER_H
#define SEARCH_PROJECT_PROBLEMSOLVER_H

#include <problems.h>
#include <searches.h>
#include <string>



class ProblemSolver {
public:
	ProblemSolver(const char* problem, const char* search, char* argv[]);
	virtual ~ProblemSolver();
	void run();
	Result getResult();
private:
	Problem *problem;
	Search  *search;
	
	void setProblem(const char* _problem);
	void setSearch(const char* _search, char* argv[]);
};

#endif //SEARCH_PROJECT_PROBLEMSOLVER_H
