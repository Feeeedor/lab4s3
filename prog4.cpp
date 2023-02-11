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

std::string Student::getYir()const{
return "УИР не определен для студентов этого типа\n";
}
    std::string Student::getPlace_yir()const{
return "УИР не определен для студентов этого типа\n";
    }
    int Student::getYir_score()const{
std::cout<<"УИР не определен для студентов этого типа\n";
    return 0;
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
    return *this;
}
Old_student &Old_student::setPlace_yir(const std::string &place){
    place_yir=place;
    return *this;
}
Old_student &Old_student::setYir_score(int score){
yir_score=score;
return *this; 
}



Group::Group(){
    number_disciplines=0;
    type_studients="no data";
    index="no data";
}
Group::Group(Describer* stud){
    number_disciplines=stud->getNumber_score();
    type_studients=stud->getType();
    table.emplace(stud->getFamily(),stud);
    index="no data";
}

void Group::setNumber_disciplines(int num_dis){
    number_disciplines=num_dis;
}
void Group::setType_studients(std::string typ_st){
    type_studients=typ_st;
}
void Group::setIndex(std::string ind){
    index=ind;
}
bool Group::insert(Describer* stud){
    bool res=false;
    if(table.find(stud->getFamily())==table.end()){
table.emplace(stud->getFamily(),stud);
    res=true;}
    return res;
}
bool Group::erase(std::string stud){
    bool res=false;
    if(table.find(stud)!=table.end()){
table.erase(stud);
    res=true;}
    return res;
}


int Group::getNumber_disciplines()const{
    return number_disciplines;
}
std::string Group::getType_studients()const{
    return type_studients;
}
std::string Group::getIndex()const{
    return index;
}
std::map<const std::string,Describer*> Group::getTable()const{
    return table;
}

void Group::show()
{
    std::cout << "Index: " << index << "; "
              << "Type of group: " << type_studients << "\n";
    std::cout << "Number of disciplines: " << number_disciplines << "\n";
    std::cout << "Family    Type of student     Number of score     Scores\n";
    std::map<const std::string, Describer *>::iterator it;
    for (it = table.begin(); it != table.end(); it++)
    {
    std::cout << it->second->getFamily() << " " << it->second->getType() << " " << it->second->getNumber_score() << " ";
    int *arr = it->second->getArr_score();
    for (int i = 0; i < it->second->getNumber_score(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    }
}

std::string Group::getType(std::string fam)const{
std::map<const std::string, Describer *>::const_iterator it;
it=table.find(fam);
if(it!=table.end())
return it->second->getType();
std::cout<<"not found \n";
return "not found";
}
int* Group::getArr_score(std::string fam)const{
std::map<const std::string, Describer *>::const_iterator it;
it=table.find(fam);
if(it!=table.end())
return it->second->getArr_score();
std::cout<<"not found \n";
return 0;
}


/*

Group_table::Group_table(std::string index, int number, std::string type){
    info in;
    in.number_disciplines=number;
    in.type_studients=type;
    grouptable.emplace(index, in);
}*/



