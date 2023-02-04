#include "prog4.h"

Student::Student()
{
    family = "Ivanov I.I.";
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
}
Student::Student(std::string fam)
{
    family = fam;
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
}
Student::Student(int num, int *scr)
{
    family = "Ivanov I.I.";
    number_score = num;
    arr_score = new int[num];
    for(int i=0;i<num;i++)
    arr_score[i]=scr[i];
}
Student::Student(std::string fam, int num, int *scr)
{
    family = fam;
    number_score = num;
    arr_score = new int[num];
    for(int i=0;i<num;i++)
    arr_score[i]=scr[i];
}
Student::~Student()
{
    delete[] arr_score;
}
std::string Student::getFamily()
{
    return family;
}
int Student::getNumber_score()
{
    return number_score;
}
int *Student::getArr_score()
{
    return arr_score;
}