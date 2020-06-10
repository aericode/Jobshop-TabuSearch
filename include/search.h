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

	void sort_neighborhood();

	bool is_tuple_same(Tuple, Tuple);

	static bool compare_assignment_ptr(Assignment*, Assignment*);

	struct pointer_compare {
      bool operator()(const Assignment* l, const Assignment* r) {
        return *l < *r;
      }
    };
};


#endif