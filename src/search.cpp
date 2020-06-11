#define INT_MIN -2147483648
#define DEFAULT_TENURE 3;

#include "search.h"
#include <iostream>
#include <algorithm>

Search::Search(){
	best_score = INT_MIN;
	tabu_tenure = DEFAULT_TENURE;

	iteration_count = 0;
}

Search::Search(Assignment initial, int tabu_tenure_, int iteration_limit_){
	current_candidate = initial;
	tabu_tenure       = tabu_tenure_;
	iteration_limit   = iteration_limit_;

	iteration_count = 0;
}

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

bool Search::is_tabu(Assignment* assignment){
	for(int i = 0; i < tabu_list.size(); i++){
		if(is_tuple_same(assignment->swapped_elements, *tabu_list[i] ) ){
			return true;
		}
	}
	return false;
}


void Search::get_next_chosen(){
	for(int i = 0; i < neighborhood.size();i++){
		//se o elemento não é tabu
		if(!is_tabu(neighborhood[i]) ){
			//ele agora é o próximo candidato
			current_candidate = *neighborhood[i];
			//atualiza a lista tabu
			Tuple * next_tabu = new Tuple(current_candidate.swapped_elements);
			tabu_list.push_back(next_tabu);
			if(tabu_list.size() > tabu_tenure){
				int last = tabu_list.size() - 1;
				Tuple * aux = tabu_list[last];
				tabu_list.pop_back();
				//todo delete aux;
			}
			//verifica scores
			if (current_candidate.delay_score > best_score){
				record_best = current_candidate;
				best_score  = current_candidate.delay_score;
			}

			return;
		}
	}
}

void Search::do_search(){
	tabu_list.clear();
	std::cout<<tabu_list.size()<<std::endl;
	while(iteration_count < iteration_limit){
		make_neighborhood();
		sort_neighborhood();
		get_next_chosen();
		iteration_count++;
		current_candidate.show();
		show_tabu_list();
	}

	std::cout<<"melhor encontrado ";
	current_candidate.show();
}

void Search::show_tabu_list(){
	for(int i = 0; i < tabu_list.size();i++){
		std::cout<<tabu_list[i]->t1<<" "<<tabu_list[i]->t2<<'\n';
	}
}