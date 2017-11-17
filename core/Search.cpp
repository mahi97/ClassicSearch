//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "Search.h"

void Search::setProblem(Problem *_problem) {
	problem = _problem;
}

Search::Search(bool isGraph) {
	this->isGraph = isGraph;
}
