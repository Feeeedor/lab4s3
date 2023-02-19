#pragma once

#include "Student.h"
#include "Group.h"

class Group_table
{
private:
    std::map<const std::string, Group *> grouptable;

public:
    Group_table(){};
    ~Group_table();
    Group_table &eraseGroup(const std::string &ind);
    Group_table &insertGroup(Group *);

    std::map<const std::string, Group *>::iterator begin();
    std::map<const std::string, Group *>::iterator end();

    std::map<const std::string, Group *>::iterator find(const std::string &ind);
    Group *&at(const std::string &ind);
};

int dialog(Group_table &G);


void d_insert_group(Group_table &);        
void d_erase_group(Group_table &);         
void d_change_group(Group_table &);        
void d_new_student(Group_table &);         
void d_new_semester(Group_table &);        
void d_Set_scores_semester(Group_table &); 
void d_Get_average_scare(Group_table &);   

void d_setindex(Group *&);              
void d_setNumber_disciplines(Group *&); 
void d_setType_students(Group *&);      
void d_getIndex(Group *&);              
void d_getNumber_disciplines(Group *&); 
void d_getType_students(Group *&);      
void d_insertStudent(Group *&);         
void d_eraseStudent(Group *&);          
void d_change_student(Group *&);        
