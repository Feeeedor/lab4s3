#include "prog4.h"

Student::Student()
{
    family = "Ivanov I.I.";
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
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

Old_student::Old_student():Student() 
{
yir="no data";
place_yir="no data";
yir_score=0;
}
Old_student::Old_student(std::string fam, int num, int *scr,std::string y, std::string py, int sc) : Student(fam,num, scr) 
{
yir=y;
place_yir=py;
yir_score=sc;
}
std::string Old_student::getYir(){
    return yir;
}
std::string Old_student::getPlace_yir(){
return place_yir;
}
int Old_student::getYir_score(){
    return yir_score;
}