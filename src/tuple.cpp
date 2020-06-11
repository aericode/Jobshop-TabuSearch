#include "tuple.h"

Tuple::Tuple(){}

Tuple::Tuple(int t1, int t2){
	this->t1 = t1;
	this->t2 = t2;
}

Tuple::Tuple(const Tuple& other){
	this->t1 = other.t1;
	this->t2 = other.t2;
}