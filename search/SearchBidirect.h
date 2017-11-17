//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHBIDIRECT_H
#define SEARCH_PROJECT_SEARCHBIDIRECT_H


#include <Search.h>

class SearchBidirect : public Search {
public:
	SearchBidirect(bool isGraph);
	virtual void execute();

protected:
	void search();
	
};


#endif //SEARCH_PROJECT_SEARCHBIDIRECT_H
