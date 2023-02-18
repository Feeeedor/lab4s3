#pragma once
#include "Student.h"
#include <map>


class Group
{
private:
    std::string index;
    int number_disciplines;
    std::string type_students;
    std::map<const std::string, Student *> table;//нужен ли конст?
public:
    Group();
    Group(const std::string&);
    //Group(Student *&);
    virtual ~Group();
    Group &setIndex(const std::string&);
    Group &setNumber_disciplines(int);
    Group &setType_students(const std::string&);

    int getNumber_disciplines() const;
    std::string getType_students() const;
    std::string getIndex() const;

    Group &insertStudent(Student*);

    Group &eraseStudent(const std::string&);

    std::map<const std::string, Student *> getTable() const;

    void show();
    std::map<const std::string, Student *>::iterator find(const std::string&);
Student *&at(const std::string&);
    std::map<const std::string, Student *>::iterator begin();
    std::map<const std::string, Student *>::iterator end();
};

int dialog(Group *&g);
void d_setindex(Group*&);//1
void d_setNumber_disciplines(Group*&);//2
void d_setType_students(Group*&);//3
void d_getIndex(Group*&);//4
void d_getNumber_disciplines(Group*&);//5
void d_getType_students(Group*&);//6
void d_insertStudent(Group*&);//7
void d_eraseStudent(Group*&);//8
void d_change_student(Group*&);//10

