//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#ifndef SEARCH_PROJECT_STATE_H
#define SEARCH_PROJECT_STATE_H


class State {
public:
	State();
	~State();
	virtual bool operator==(const State&) const = 0;
	const State* par;
	int act;
};


#endif //SEARCH_PROJECT_STATE_H
