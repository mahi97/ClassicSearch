//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHDFSX_H
#define SEARCH_PROJECT_SEARCHDFSX_H


#include "SearchDFS.h"

class SearchDFSX : public SearchDFS{
public:
	SearchDFSX(bool isGraph, unsigned int depth);
	virtual void execute();

private:
	unsigned int depth;
};


#endif //SEARCH_PROJECT_SEARCHDFSX_H
