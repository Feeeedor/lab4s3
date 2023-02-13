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
    Group(const std::string&);
    Group(Student *&);
    //~Group();
    void setIndex(const std::string&);
    void setNumber_disciplines(int);
    void setType_students(const std::string&);
    int getNumber_disciplines() const;
    std::string getType_students() const;
    std::string getIndex() const;
    Group &insert(Student *);
    bool erase(const std::string&);
    std::map<const std::string, Student *> getTable() const;
    void show();
    std::string getType(const std::string&) const;
    int *getArr_score(const std::string&) const;
    bool setScore(const std::string&, int, int *&);
    bool setYir(const std::string&, const std::string &y);
    bool setPlace_yir(const std::string&, const std::string &place);
    bool setYir_score(const std::string&, int score);
    std::string getYir(const std::string&);
    std::string getPlace_yir(const std::string&);
    int getYir_score(const std::string&);

    std::map<const std::string, Student *>::iterator begin();
    std::map<const std::string, Student *>::iterator end();
};


