#include "task.h"
#include "assignment.h"
#include "tuple.h"
#include "search.h"
#include <iostream>

int main(){

	std::vector<Task*> all_tasks;
	//TAG, DURATION, DEADLINE
	Task A ("Alberto",1,3);
	Task B ("Bruna",1,2);
	Task C ("Carmen",1,1);
	Task D ("Dani",1,4);
	Task E ("Eduardo",1,5);

	
	Assignment assignment;

	assignment.add_task(A);
	assignment.add_task(B);
	assignment.add_task(C);
	assignment.add_task(D);
	assignment.add_task(E);


	assignment.update_task_timing();
	assignment.calc_score();


	Search* search = new Search(assignment,7,5);

	search->do_search();
	
	/*
	Assignment* b = new Assignment(assignment);

	b->swap(0,4);
	assignment.show();
	b->show();

	search.current_candidate = assignment;
	search.make_neighborhood();

	search.sort_neighborhood();
	search.show_neighborhood();
	*/

	/*
	std::cout<<assignment.delay_score<<std::endl;

	assignment.swap(0,2);
	assignment.update_task_timing();
	assignment.calc_score();

	assignment.show();
	std::cout<<assignment.delay_score<<std::endl;
	*/

}