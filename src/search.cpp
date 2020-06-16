#define INT_MAX 2147483648
#define DEFAULT_TENURE 3

#include "search.h"
#include <iostream>
#include <fstream>
#include <algorithm>

Search::Search(){
	best_score = INT_MAX;
	tabu_tenure = DEFAULT_TENURE;

	iteration_count = 0;
}

Search::Search(Assignment initial, int tabu_tenure_, int iteration_limit_){
	current_candidate = initial;
	tabu_tenure       = tabu_tenure_;
	iteration_limit   = iteration_limit_;

	iteration_count = 0;

	current_candidate.update_task_timing();
	current_candidate.calc_score();
	best_score = current_candidate.delay_score;
	record_best = current_candidate;

}

Search::Search(std::string file_location){
	
	Assignment assignment;
	Task* next_task;

	std::string tag;
	std::string duration;
	std::string deadline;

	int conv_duration;
	int conv_deadline;

	std::string tabu_tenure_;
	std::string iteration_limit_;

	std::ifstream input(file_location);

	if(!input.is_open()) std::cout << "Error during file reading" << std::endl;

	getline(input, tabu_tenure_, ',');
	getline(input, iteration_limit_, '\n');

	this->tabu_tenure     = std::stoi(tabu_tenure_);
	this->iteration_limit = std::stoi(iteration_limit_);

	while(input.good()){
		getline(input, tag, ',');
		getline(input, duration, ',');
		getline(input, deadline, '\n');

		conv_duration = std::stoi(duration);
		conv_deadline = std::stoi(deadline);

		next_task = new Task(tag, conv_duration, conv_deadline);

		assignment.add_task(next_task);
	}

	current_candidate = assignment;
	current_candidate.update_task_timing();
	current_candidate.calc_score();
	best_score = current_candidate.delay_score;
	record_best = current_candidate;

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
		if(!is_tabu(neighborhood[i]) || is_aspiration_valid(neighborhood[i])){
			//ele agora é o próximo candidato
			current_candidate = *neighborhood[i];
			//atualiza a lista tabu
			Tuple * next_tabu = new Tuple(current_candidate.swapped_elements);
			tabu_list.insert(tabu_list.begin(), next_tabu);
			if(tabu_list.size() > tabu_tenure){
				int last = tabu_list.size() - 1;
				Tuple * aux = tabu_list[last];
				tabu_list.pop_back();
				delete aux;
			}
			//verifica scores
			if (current_candidate.delay_score < best_score){
				record_best = current_candidate;
				best_score  = current_candidate.delay_score;
			}

			return;
		}
	}
}

void Search::do_search(){
	tabu_list.clear();
	while(iteration_count < iteration_limit){
		make_neighborhood();
		sort_neighborhood();
		get_next_chosen();
		iteration_count++;
	}

	std::cout<<"melhor encontrado ";
	record_best.show();
}

void Search::show_tabu_list(){
	for(int i = 0; i < tabu_list.size();i++){
		std::cout<<tabu_list[i]->t1<<" "<<tabu_list[i]->t2<<'\n';
	}
}

bool Search::is_aspiration_valid(Assignment* assignment){
	return assignment->delay_score < best_score;
}