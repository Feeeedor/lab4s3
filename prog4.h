#pragma once

#include "Student.h"
#include "Group.h"



class Group_table
{
private:
    std::map<const std::string, Group*> grouptable;
public:
    Group_table(){};
    // Group_table(std::string, int, std::string);
    ~Group_table();
    Group_table& eraseGroup(const std::string &ind);
    Group_table& insertGroup(Group*&); 

    std::map<const std::string, Group*>::iterator begin();
    std::map<const std::string, Group*>::iterator end();

    std::map<const std::string, Group*>::iterator find(const std::string &ind);
    Group *&at(const std::string &ind);
};

int dialog(Group_table &G);
//int dialog(Group *&g);
//int dialog(Student *&);

void d_insert_group(Group_table &);//1
void d_erase_group(Group_table &);//2
void d_change_group(Group_table &);//3
void d_new_student(Group_table &);//4
void d_new_semester(Group_table &);//5
void d_Set_scores_semester(Group_table &);//6
void d_Get_average_scare(Group_table &);//7

int vvodm(int &a, int N);
std::string &vvods(std::string &a);

void d_setindex(Group*&);//1
void d_setNumber_disciplines(Group*&);//2
void d_setType_students(Group*&);//3
void d_getIndex(Group*&);//4
void d_getNumber_disciplines(Group*&);//5
void d_getType_students(Group*&);//6
void d_insertStudent(Group*&);//7
void d_eraseStudent(Group*&);//8
void d_change_student(Group*&);//10

/*
void d_setFamily(Student *&);
void d_setNumber_score(Student *&);
void d_setScore(Student *&);
void d_getScore(Student *&);*/


