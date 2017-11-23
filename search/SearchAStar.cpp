//
// Created by Mohammad Mahdi Rahimi on 11/17/17.
//

#include "SearchAStar.h"

SearchAStar::SearchAStar(bool isGraph) : Search(isGraph) {}

void SearchAStar::execute() {
	f.push_back(problem->initialState());
	search();
	result.maxMemoryUsage = (result.nodeSeen - result.nodeExpand)* sizeof(int) * 9;
	result.path.pop_back();
	result.pathCost = problem->pathCost(result.path);
	
}

void SearchAStar::search() {
	while (! f.empty() ) {
		State* s = f.front();
		f.pop_front();
		result.nodeExpand++;
		if (problem->goalTest(s)) {
			result.answer = s;
			const State* temp = s;
			while (temp != nullptr) {
				result.path.push_back(temp->act);
				temp = temp->par;
			}
			return;
		}
		for (auto& action : problem->actions(s)) {
			if (isGraph) {
				bool temp = false;
				for (auto node : e) {
					if (*node == *problem->nextState(s, action)) {
						temp = true;
						break;
					}
				}
				if (temp) continue;
			}
			result.nodeSeen++;
			
			f.push_back(problem->nextState(s, action));
		}
		
		f.sort([&](const void* a, const void* b){
			int g1 = 0,g2 = 0;
			const State* first  = static_cast<const State*>(a);
			const State* second = static_cast<const State*>(b);
			const State* temp = first;
			while(temp) {
				g1++;
				temp = temp->par;
			}
			temp = second;
			while(temp) {
				g2++;
				temp = temp->par;
			}
			return g1 + problem->h(first) >= g2 + problem->h(second);
		});
		
		e.push_back(s);
		
	}
}
