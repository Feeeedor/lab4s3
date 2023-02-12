#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>
class Student
{
protected:
    std::string family;
    int number_score;
    int *arr_score;

public:
    Student();
    Student(std::string &, int num, int *&scr);
    virtual ~Student();
    Student &setFamily(std::string &fam);
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
    Old_student(std::string &, int num, int *&scr, std::string &y, std::string &py, int sc);
    std::string getType() const;
    std::string getYir() const;
    std::string getPlace_yir() const;
    int getYir_score() const;
    void setYir(const std::string &y);
    void setPlace_yir(const std::string &place);
    void setYir_score(int score);
};

class Group
{
private:
    std::string index;
    int number_disciplines;
    std::string type_students;
    std::map<const std::string, Student *> table;

public:
    Group();
    Group(std::string);
    Group(Student *);
    ~Group();
    void setIndex(std::string);
    void setNumber_disciplines(int);
    void setType_students(std::string);
    int getNumber_disciplines() const;
    std::string getType_students() const;
    std::string getIndex() const;
    bool insert(Student *);
    bool erase(std::string);
    std::map<const std::string, Student *> getTable() const;
    void show();
    std::string getType(std::string) const;
    int *getArr_score(std::string) const;
    bool setScore(std::string, int, int *);
    bool setYir(std::string, const std::string &y);
    bool setPlace_yir(std::string, const std::string &place);
    bool setYir_score(std::string, int score);
    std::string getYir(std::string);
    std::string getPlace_yir(std::string);
    int getYir_score(std::string);

    std::map<const std::string, Student *>::iterator begin();
    std::map<const std::string, Student *>::iterator end();
};

class Group_table
{
private:
    std::map<const std::string, Group> grouptable;

public:
    Group_table(){

    };
    // Group_table(std::string, int, std::string);
    ~Group_table(){};

    bool setYir(std::string, std::string, const std::string &y);
    bool setPlace_yir(std::string, std::string, const std::string &place);
    bool setYir_score(std::string, std::string, int score);
    std::string getYir(std::string, std::string);
    std::string getPlace_yir(std::string, std::string);
    int getYir_score(std::string, std::string);

    std::string getType(std::string, std::string) const;
    int *getArr_score(std::string, std::string) const;
    bool setScore(std::string, std::string, int, int *);

    int getNumber_disciplines(std::string) const;
    std::string getType_students(std::string) const;
    std::string getIndex(std::string) const;
    bool erase_student(std::string, std::string);
    std::map<const std::string, Student *> getTable(std::string) const;
    void show(std::string); // 2
    bool erase_group(std::string ind);
    bool setGroup(Group); // 1
    bool insert(std::string, Student *);
    bool changeStudent(std::string, std::string, std::string, int);

    std::map<const std::string, Student *>::iterator begin(std::string);
    std::map<const std::string, Student *>::iterator end(std::string);
};

int dialog(Group_table &G);

void d_Add_group(Group_table &);
void d_Show_group(Group_table &);

void d_Get_number_disciplines(Group_table &);
void d_Get_type_group(Group_table &);
void d_Add_student(Group_table &);

void d_Get_type_studient(Group_table &);
void d_Set_scores(Group_table &);
void d_Get_scores(Group_table &);
void d_Set_yir(Group_table &);
void d_Get_yir(Group_table &);
void d_Set_place_yir(Group_table &);
void d_Get_place_yir(Group_table &);
void d_Get_yir_score(Group_table &);
void d_Set_yir_score(Group_table &);
void d_New_semester(Group_table &);
void d_Set_scores_semester(Group_table &);
void d_Get_average_scare(Group_table &);
int vvodm(int &a);