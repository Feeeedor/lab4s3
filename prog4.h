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
Student(std::string, int num, int*scr);
~Student();
void setFamily(std::string fam);
std::string getFamily();
int getNumber_score();
int *getArr_score();
};
class Old_student : public Student{
private:
std::string yir;
std::string place_yir;
int yir_score;
public:
Old_student();
Old_student(std::string, int num, int*scr, std::string y, std::string py, int sc);
std::string getYir();
std::string getPlace_yir();
int getYir_score();
};
