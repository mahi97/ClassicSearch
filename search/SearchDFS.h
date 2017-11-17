//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHDFS_H
#define SEARCH_PROJECT_SEARCHDFS_H


#include <Search.h>

class SearchDFS : public Search {
public:
	SearchDFS(bool isGraph);
	virtual void execute();

protected:
	void search();
};


#endif //SEARCH_PROJECT_SEARCHDFS_H
