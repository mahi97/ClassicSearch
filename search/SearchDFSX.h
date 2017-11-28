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
	void setDepth(int depth);
protected:
	void search();
	void search(State* par, int depth);
	int depth;
	
};


#endif //SEARCH_PROJECT_SEARCHDFSX_H
