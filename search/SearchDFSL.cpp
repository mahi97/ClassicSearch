//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include <iostream>
#include "SearchDFSL.h"

SearchDFSL::SearchDFSL(bool isGraph) : SearchDFSX(isGraph, 0) {}

void SearchDFSL::execute() {
	int depth = 1;
	while (result.answer == nullptr) {
		setDepth(depth++);
		SearchDFSX::execute();
		e.clear();
	}
}
