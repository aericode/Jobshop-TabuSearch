#include "task.h"
#include "assignment.h"
#include "tuple.h"
#include "search.h"
#include <iostream>

int main(){
	
	Search* search = new Search("./input/default.csv");

	search->do_search();

}