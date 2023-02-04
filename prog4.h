#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include <vector>

class Student{
    protected:
std::string family;
int number_score;
int *arr_score;
public:
Student();
Student(std::string);
Student(int num, int*scr);
Student(std::string, int num, int*scr);
~Student();
//void print_info();
void setFamily(std::string fam);
std::string getFamily();
int getNumber_score();
int *getArr_score();
};
