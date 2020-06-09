#ifndef search_h
#define search_h

#include "tuple.h"
#include "task.h"
#include "assignment.h"
#include <vector>


class Search{
public:

	int iteration_count;

	//melhor encontrado até agora
	Assignment record_best;

	//melhor score encontrado até agora
	int best_score;

	Assignment current_candidate;

	//tuples with 
	std::vector<Tuple> tabu_list;

	//tamanho da lista tabu
	int tabu_tenure;

	std::vector<Assignment*> neighborhood;

	Search();

	void make_neighborhood();

	void show_neighborhood();

	bool is_tuple_same(Tuple, Tuple);
};


#endif