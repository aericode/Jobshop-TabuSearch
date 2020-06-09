#include "task.h"
#include "assignment.h"
#include "tuple.h"
#include "search.h"
#include <iostream>

int main(){

	std::vector<Task*> all_tasks;
	//TAG, DURATION, DEADLINE
	Task A ("Alberto",1,1);
	Task B ("Bruna",1,1);
	Task C ("Carmen",7,1);
	Task D ("Dani",1,1);
	Task E ("Eduardo",1,1);

	

	Search search;
	Assignment assignment;

	assignment.add_task(A);
	assignment.add_task(B);
	assignment.add_task(C);
	assignment.add_task(D);
	assignment.add_task(E);


	assignment.update_task_timing();
	assignment.calc_score();

	

	Assignment* b = new Assignment(assignment);

	b->swap(0,4);
	assignment.show();
	b->show();

	search.current_candidate = assignment;
	search.make_neighborhood();
	search.show_neighborhood();
	/*
	std::cout<<assignment.delay_score<<std::endl;

	assignment.swap(0,2);
	assignment.update_task_timing();
	assignment.calc_score();

	assignment.show();
	std::cout<<assignment.delay_score<<std::endl;
	*/

}