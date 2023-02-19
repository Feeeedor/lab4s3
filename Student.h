
#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include "vector_r.h"

class Student
{
protected:
    std::string family;
    int number_score;
    vector<int> score;
public:
    Student();

    Student(const std::string &fam, int num, vector<int> &scr);
    virtual ~Student();

    Student &setFamily(const std::string &fam);
    Student &setNumber_score(int num);
    Student &setScore(vector<int> &);

    std::string getFamily() const;
    int getNumber_score() const;
    vector<int> getScore() const;

    virtual std::string getType() const;
};

class Old_student : public Student
{
private:
    std::string yir;
    std::string place_yir;
    int yir_score;

public:
    Old_student();
    Old_student(const std::string &, int num, vector<int> &scr, const std::string &y, const std::string &py, int sc);

    std::string getType() const override;
    std::string getYir() const;
    std::string getPlace_yir() const;
    int getYir_score() const;

    Old_student &setYir(const std::string &y);
    Old_student &setPlace_yir(const std::string &place);
    Old_student &setYir_score(int score);
};

