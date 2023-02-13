#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>

class Student
{
protected:
    std::string family;
    int number_score;
    int *arr_score;

public:
    Student();
    Student(const std::string &, int num, int *&scr);
    virtual ~Student();
    void setFamily(const  std::string &fam );
    Student &setScore(int num, int *&arr);
    std::string getFamily() const;
    int getNumber_score() const;
    int *getArr_score() const;
    virtual std::string getType() const;

    virtual std::string getYir() const;
    virtual std::string getPlace_yir() const;
    virtual int getYir_score() const;
    virtual void setYir(const std::string &y);
    virtual void setPlace_yir(const std::string &place);
    virtual void setYir_score(int score);
};

class Old_student : public Student
{
private:
    std::string yir;
    std::string place_yir;
    int yir_score;

public:
    Old_student();
    Old_student(const std::string &, int num, int *&scr,const  std::string &y,const  std::string &py, int sc);
    std::string getType() const;
    std::string getYir() const;
    std::string getPlace_yir() const;
    int getYir_score() const;
    void setYir(const std::string &y);
    void setPlace_yir(const std::string &place);
    void setYir_score(int score);
};
