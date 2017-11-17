//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHBFS_H
#define SEARCH_PROJECT_SEARCHBFS_H


#include <Search.h>
#include <queue>
#include <list>

class SearchBFS : public Search {
public:
	SearchBFS(bool isGraph);
	virtual void execute();

protected:
	virtual void searchG();
	virtual void search();
	
private:
	std::list<State*>  f;
	std::vector<State*> e;
	
};


#endif //SEARCH_PROJECT_SEARCHBFS_H
