#ifndef assignment_h
#define assignment_h

#include <list>
#include "tuple.h"
#include "task.h"
#include <algorithm>
#include <vector>

class Assignment{
public:

	Tuple swapped_elements;

	std::vector<Task*> task_list;

	int delay_score;
	void calc_score();

	//Atenção!: Não calcula ao adicionar tarefa
	void add_task(Task);

	void update_task_timing();

	void show();

	void swap(int, int);

	Assignment();
	Assignment(const Assignment&);
	~Assignment();

	bool operator> (const Assignment &other) const {
    	return delay_score > other.delay_score;
	}
}; 

#endif