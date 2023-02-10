#include "prog4.h"

Student::Student()
{
    family = "no data";
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
}

Student::Student( std::string &fam, int num, int *&scr)
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

std::string Student::getFamily()const
{
    return family;
}

int Student::getNumber_score()const
{
    return number_score;
}

int *Student::getArr_score()const
{
    return arr_score;
}

std::string Student::getType()const {
    return "junior Student";
}

Student &Student::setFamily(std::string &fam)
{
    family=fam;
    return *this;
}
Student &Student::setScore(int  num, int* &arr)
{
    number_score=num;
    delete []arr_score;
    arr_score = new int[num];
    for(int i=0;i<num;i++)
    arr_score[i]=arr[i];
    return *this;
}






Old_student::Old_student():Student() 
{
yir="no data";
place_yir="no data";
yir_score=0;
}
Old_student::Old_student(std::string &fam, int num, int *&scr,std::string &y, std::string &py, int sc) : Student(fam,num, scr) 
{
yir=y;
place_yir=py;
yir_score=sc;
}
std::string Old_student::getYir()const{
    return yir;
}
std::string Old_student::getPlace_yir()const{
return place_yir;
}
int Old_student::getYir_score()const{
    return yir_score;
}
std::string Old_student::getType()const {
    return "old Student";
}
Old_student &Old_student::setYir(const std::string &y){
    yir=y;
}
Old_student &Old_student::setPlace_yir(const std::string &place){
    place_yir=place;
}
Old_student &Old_student::setYir_score(int score){
yir_score=score;
}
/*
Group_table::Group_table(){
    group_index="no data";
    number_disciplines=0;
    type_studients="no data";
}
Group_table::Group_table(std::string index, int number, std::string type){
    group_index=index;
    number_disciplines=number;
    type_studients=type;
}
*/
