#ifndef task_h
#define task_h

#include <string>

class Task{
public:
	std::string tag;

	int duration;
	int deadline;
	int end_time;

	Task();
	Task(std::string, int, int);
	Task(const Task&);
};


#endif