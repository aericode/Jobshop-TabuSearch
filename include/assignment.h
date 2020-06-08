#ifndef assignment_h
#define assignment_h

#include <list>
#include "task.h"
#include <vector>

class Assignment{
public:

	std::vector<Task*> task_list;

	int delay_score;
	void calc_score();

	//Atenção!: Não calcula ao adicionar tarefa
	void add_task(Task);

	void update_task_timing();

	void show();

	void swap(int, int);

	Assignment();
};


#endif