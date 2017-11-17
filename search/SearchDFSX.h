//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHDFSX_H
#define SEARCH_PROJECT_SEARCHDFSX_H


#include <list>
#include <Search.h>

class SearchDFSX : public Search {
public:
	SearchDFSX(bool isGraph, unsigned int depth);
	virtual void execute();

protected:
	void search();
	void search(const State* par, int depth);
	unsigned int depth;
	
};


#endif //SEARCH_PROJECT_SEARCHDFSX_H
