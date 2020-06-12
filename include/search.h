#ifndef search_h
#define search_h

#include "tuple.h"
#include "task.h"
#include "assignment.h"
#include <vector>


class Search{
public:

	int iteration_limit;
	int iteration_count;

	//melhor encontrado até agora
	Assignment record_best;

	//melhor score encontrado até agora
	int best_score;

	Assignment current_candidate;

	//tuples with 
	std::vector<Tuple*> tabu_list;

	//tamanho da lista tabu
	int tabu_tenure;

	std::vector<Assignment*> neighborhood;

	Search();

	Search(Assignment, int, int);

	void make_neighborhood();

	void show_neighborhood();

	void sort_neighborhood();

	bool is_tuple_same(Tuple, Tuple);

	static bool compare_assignment_ptr(Assignment*, Assignment*);

	//invertido para fazer sort reverso
	struct pointer_compare {
      bool operator()(const Assignment* l, const Assignment* r) {
        return *r > *l;
      }
    };

    bool is_tabu(Assignment*);

    void get_next_chosen();

    void do_search();

    void show_tabu_list();

    bool is_aspiration_valid(Assignment*);
};


#endif