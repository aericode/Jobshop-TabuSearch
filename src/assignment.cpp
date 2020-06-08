#include "assignment.h"
#include <vector>
#include <iostream>
#include <algorithm>

Assignment::Assignment(){
	delay_score = 0;
}

void Assignment::calc_score(){
	delay_score = 0;
	int delta;
	for (std::vector<Task*>::iterator it=task_list.begin(); it != task_list.end(); ++it){
		delta = (*it)->end_time - (*it)->deadline;
		delay_score += std::max(0, delta);
	}

	std::cout<< delay_score;
}

void Assignment::add_task(Task task){
	Task* to_add = new Task(task);
	task_list.push_back(to_add);
}

void Assignment::update_task_timing(){
	for (std::vector<Task*>::iterator it=task_list.begin(); it != task_list.end(); ++it){
		if(it == task_list.begin()){
			//o primeiro acaba na sua própria duração
			(*it)->end_time = (*it)->duration;
		}else{
			//atualiza a hora em que terminou
			//somando sua própria duração ao anterior
			(*it)->end_time = (*std::prev(it))->end_time + (*it)->duration;
		}
	}
}

void Assignment::show(){
	std::cout << "[ ";
	for (std::vector<Task*>::iterator it=task_list.begin(); it != task_list.end(); it++){
		std::cout << (*it)->tag;
		if(it != task_list.end() )std::cout<<" ";
	}
	std::cout << ']' << std::endl;
}

void Assignment::swap(int a, int b){
	Task* aux;

	aux = task_list[a];
	task_list[a] = task_list[b];
	task_list[b] = aux;

}