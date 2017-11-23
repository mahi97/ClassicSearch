//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHASTAR_H
#define SEARCH_PROJECT_SEARCHASTAR_H


#include <Search.h>

class SearchAStar : public Search{
public:
	SearchAStar(bool isGraph);
	virtual void execute();

protected:
	void search();
	std::list<State*> f;
	std::list<State*> e;
	
	
};


#endif //SEARCH_PROJECT_SEARCHASTAR_H
