#include "task.h"
#include "assignment.h"
#include <iostream>

int main(){

	std::vector<Task*> all_tasks;
	//TAG, DURATION, DEADLINE
	Task A ("Alberto",1,1);
	Task B ("Bruna",1,1);
	Task C ("Carmen",7,1);
	Task D ("Dani",1,1);
	Task E ("Eduardo",1,1);

	all_tasks.push_back(&A);
	all_tasks.push_back(&B);
	all_tasks.push_back(&C);
	all_tasks.push_back(&D);
	all_tasks.push_back(&E);

	
	Assignment assignment;
	assignment.task_list = all_tasks;

	assignment.update_task_timing();
	assignment.calc_score();

	assignment.show();
	std::cout<<assignment.delay_score<<std::endl;

	assignment.swap(0,2);
	assignment.update_task_timing();
	assignment.calc_score();

	assignment.show();
	std::cout<<assignment.delay_score<<std::endl;

}