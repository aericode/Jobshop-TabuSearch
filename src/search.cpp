#include "search.h"

Search::Search(){}

bool Search::is_tuple_same(Tuple a, Tuple b){
	if(a.t1 == b.t1 && a.t2 == b.t2){
		return true;
	}else if(a.t1 == b.t2 && a.t2 == b.t1){
		return true;
	}else{
		return false;
	}
}