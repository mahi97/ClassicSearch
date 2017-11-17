//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_SEARCHDFS_H
#define SEARCH_PROJECT_SEARCHDFS_H


#include "SearchDFSX.h"

class SearchDFS : public SearchDFSX {
public:
	SearchDFS(bool isGraph);
	virtual void execute();
protected:
	void search();
	void search(State* par);
};


#endif //SEARCH_PROJECT_SEARCHDFS_H
