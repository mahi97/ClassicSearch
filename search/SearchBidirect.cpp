//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "SearchBidirect.h"

SearchBidirect::SearchBidirect(bool isGraph) : Search(isGraph) {
	found[0] = found[1] = false;
}

void SearchBidirect::execute() {
	f.push_back(problem->initialState());
	f2.push_back(problem->initialStateR());
	search();
	result.maxMemoryUsage = (result.nodeSeen - result.nodeExpand)* sizeof(int) * 9;
	resultR.maxMemoryUsage = (result.nodeSeen - result.nodeExpand)* sizeof(int) * 9;
	if (result.path.size())
		result.path.pop_back();
	if (resultR.path.size())
		resultR.path.pop_back();
	result.pathCost = problem->pathCost(result.path);
	resultR.pathCost = problem->pathCost(resultR.path);
	result.answer = problem->initialStateR();
	result.maxMemoryUsage += resultR.maxMemoryUsage;
	result.pathCost += resultR.pathCost;
	result.nodeSeen += resultR.nodeSeen;
	result.nodeExpand += resultR.nodeExpand;
	result.path.reverse();
	for (auto& a : resultR.path) result.path.push_back(a);
}

void SearchBidirect::search() {
	
	State *s1 = nullptr;
	State *s2 = nullptr;
	while (! f.empty()  || ! f2.empty()) {
		
		if (!f.empty() && !found[0]) {
			s1 = f.front();
			f.pop_front();
			result.nodeExpand++;
			if (problem->goalTestBidirect(s1)) {
				const State* temp = s1;
				result.answer = s1;
				while (temp != nullptr) {
					result.path.push_back(temp->act);
					temp = temp->par;
				}
				found[0] = true;
			}
			
			for (auto &action : problem->actions(s1)) {
				result.nodeSeen++;
				if (isGraph) {
					bool temp = false;
					for (auto node : e) {
						if (*node == *problem->nextState(s1, action)) {
							temp = true;
							break;
						}
					}
					if (temp) continue;
				}
				f.push_back(problem->nextState(s1, action));
			}
			e.push_back(s1);
			if (found[0]) f.clear();
		}
		
		if (! f2.empty() && !found[1]) {
			s2 = f2.front();
			f2.pop_front();
			resultR.nodeExpand++;
			if (problem->goalTestBidirect(s2)) {
				resultR.answer = s2;
				const State* temp = s2;
				while (temp != nullptr) {
					resultR.path.push_back(3 - temp->act);
					temp = temp->par;
				}
				found[1] = true;
			}
			
			
			for (auto& action : problem->actions(s2)) {
				resultR.nodeSeen++;
				if (isGraph) {
					bool temp = false;
					for (auto node : e2) {
						if (*node == *problem->nextStateR(s2, action)) {
							temp = true;
							break;
						}
					}
					if (temp) continue;
				}
				f2.push_back(problem->nextStateR(s2, action));
			}
			e2.push_back(s2);
			if (found[1]) f2.clear();
		}
		
	}
	
}
