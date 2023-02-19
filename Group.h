#pragma once
#include "Student.h"
#include <map>

class Group
{
private:
    std::string index;
    int number_disciplines;
    std::string type_students;
    std::map<const std::string, Student *> table; 
public:
    Group();
    Group(const std::string &);
    virtual ~Group();
    Group &setIndex(const std::string &);
    Group &setNumber_disciplines(int);
    Group &setType_students(const std::string &);

    int getNumber_disciplines() const;
    std::string getType_students() const;
    std::string getIndex() const;

    Group &insertStudent(Student *);

    Group &eraseStudent(const std::string &);

    std::map<const std::string, Student *> getTable() const;

    void show();
    std::map<const std::string, Student *>::iterator find(const std::string &);
    Student *&at(const std::string &);
    std::map<const std::string, Student *>::iterator begin();
    std::map<const std::string, Student *>::iterator end();
};

    
