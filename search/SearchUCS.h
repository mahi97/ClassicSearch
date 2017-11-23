//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHUCS_H
#define SEARCH_PROJECT_SEARCHUCS_H


#include <Search.h>

class SearchUCS : public Search{
public:
	SearchUCS(bool isGraph);
	virtual void execute();

protected:
	void search();
	std::list<State*>  f;
	std::list<State*>  e;
	
	
};


#endif //SEARCH_PROJECT_SEARCHUCS_H
