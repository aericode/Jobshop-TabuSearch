#ifndef tuple_h
#define tuple_h

class Tuple{
public:
	int t1;
	int t2;

	Tuple();
	Tuple(int, int);
	Tuple(const Tuple&);
};

#endif