#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>

class Describer
{
public:
    virtual std::string getType()const = 0;
};

class Student : public Describer
{
protected:
    std::string family;
    int number_score;
    int *arr_score;
public:
    Student();
    Student(std::string&, int num, int *&scr);
    ~Student();
    Student &setFamily(std::string &fam);
    Student &setScore(int num, int *&arr);
    std::string getFamily() const;
    int getNumber_score() const;
    int *getArr_score() const;
    std::string getType()const;
};

class Old_student : public Student
{
private:
    std::string yir;
    std::string place_yir;
    int yir_score;
public:
    Old_student();
    Old_student(std::string&, int num, int *&scr, std::string &y, std::string &py, int sc);
    std::string getType()const;
    std::string getYir()const;
    std::string getPlace_yir()const;
    int getYir_score()const;
    Old_student &setYir(const std::string &y);
    Old_student &setPlace_yir(const std::string &place);
    Old_student &setYir_score(int score);
};

/*
struct info{
    int number_disciplines;
    std::string type_studients;
std::map <const std::string, Describer*> table;
};

class Group_table{

    private:
    std::map<const std::string , info> grouptable;
    public:

    Group_table();
    Group_table(std::string, int, std::string);
    ~Group_table(){};
};

class ConstGroupIt{
private:
std::map<const std::string, info>::iterator cur;
public:
ConstGroupIt(){}
ConstGroupIt(std::map<const std::string, info>::iterator it) :cur(it){}

int operator !=(const ConstGroupIt &) const;
int operator ==(const ConstGroupIt &) const;
std::pair<const std::string, info> & operator *();

std::pair<const std::string, info> * operator ->();

ConstGroupIt & operator ++();
ConstGroupIt operator ++(int);
};*/
