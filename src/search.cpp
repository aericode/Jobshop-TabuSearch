#include "search.h"
#include <iostream>
#include <algorithm>

Search::Search(){}

bool Search::is_tuple_same(Tuple a, Tuple b){
	if(a.t1 == b.t1 && a.t2 == b.t2){
		return true;
	}else if(a.t1 == b.t2 && a.t2 == b.t1){
		return true;
	}else{
		return false;
	}
}

void Search::make_neighborhood(){
	neighborhood.clear();
	Assignment* to_add;
	int size = current_candidate.task_list.size();
	for(int i = 0;i < (size-1); i++){
		for(int j = i+1; j < size;j++){
			to_add = new Assignment(current_candidate);
			to_add->swap(i,j);
			to_add->update_task_timing();
			to_add->calc_score();
			neighborhood.push_back(to_add);
		}
	}
}

void Search::show_neighborhood(){
	int size = neighborhood.size();
	for(int i = 0; i < size;i++){
		std::cout<<neighborhood[i]->swapped_elements.t1<<' '<<neighborhood[i]->swapped_elements.t2<<' ';
		neighborhood[i]->show();
		std::cout<<"Delay: "<<neighborhood[i]->delay_score<<std::endl;
	}
}

void Search::sort_neighborhood(){
	std::sort(neighborhood.begin(),neighborhood.end(), pointer_compare());
}