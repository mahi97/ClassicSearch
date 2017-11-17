//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "SearchDFSX.h"

SearchDFSX::SearchDFSX(bool isGraph, unsigned int depth) : SearchDFS(isGraph) {
		this->depth = depth;
}

void SearchDFSX::execute() {
	SearchDFS::execute();
}
