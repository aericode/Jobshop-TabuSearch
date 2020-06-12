#include "task.h"
#include "assignment.h"
#include "tuple.h"
#include "search.h"
#include <iostream>

int main(){

	std::vector<Task*> all_tasks;
	//TAG, DURATION, DEADLINE
	Task A ("Alberto",2,3);
	Task B ("Bruna",4,7);
	Task C ("Carmen",3,6);
	Task D ("Dani",3,4);
	Task E ("Eduardo",2,5);

	
	Assignment assignment;

	assignment.add_task(A);
	assignment.add_task(D);
	assignment.add_task(E);
	assignment.add_task(C);
	assignment.add_task(B);


	assignment.update_task_timing();
	assignment.calc_score();


	Search* search = new Search(assignment,6,1000);
	//search->make_neighborhood();
	//search->sort_neighborhood();
	//search->show_neighborhood();


	search->do_search();
	
	
	/*
	Assignment* b = new Assignment(assignment);
	Assignment* c = new Assignment(assignment);

	b->swap(3,0);
	c->swap(0,3);
	
	if(search->is_tuple_same(b->swapped_elements,c->swapped_elements)){
		std::cout<<"é igual"<<std::endl;
	}else{
		std::cout<<"não é igual"<<std::endl;
	}
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