#include "task.h"
#include <string>

Task::Task(){};

Task::Task(std::string tag,int duration, int deadline){
	this->tag = tag;

	this->duration = duration;
	this->deadline = deadline;
}

Task::Task(const Task& other){
	this->tag      = other.tag;
	this->duration = other.duration;
	this->deadline = other.deadline;
}