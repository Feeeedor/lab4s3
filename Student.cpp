#include "Student.h"

Student::Student()
{
    family = "no_data";
    number_score = 0;
}

Student::Student(const std::string &fam, int num, vector<int> &scr)
{
    family = fam;
    number_score = num;
    score = scr;
}

Student::~Student()
{
    score.clear();
}

std::string Student::getFamily() const
{
    return family;
}

int Student::getNumber_score() const
{
    return number_score;
}

vector<int> Student::getScore() const
{
    return score;
}

std::string Student::getType() const
{
    return "Junior Student";
}

Student &Student::setFamily(const std::string &fam)
{
    family = fam;
    return *this;
}

Student &Student::setNumber_score(int num)
{
    number_score = num;
    return *this;
}

Student &Student::setScore(vector<int> &scr)
{
    score = scr;
    return *this;
}

Old_student::Old_student() : Student()
{
    yir = "no_data";
    place_yir = "no_data";
    yir_score = 0;
}

Old_student::Old_student(const std::string &fam, int num, vector<int> &scr, const std::string &y, const std::string &py, int sc) : Student(fam, num, scr)
{
    yir = y;
    place_yir = py;
    yir_score = sc;
}

std::string Old_student::getYir() const
{
    return yir;
}

std::string Old_student::getPlace_yir() const
{
    return place_yir;
}

int Old_student::getYir_score() const
{
    return yir_score;
}

std::string Old_student::getType() const
{
    return "Old Student";
}

Old_student &Old_student::setYir(const std::string &y)
{
    yir = y;
    return *this;
}

Old_student &Old_student::setPlace_yir(const std::string &place)
{
    place_yir = place;
    return *this;
}

Old_student &Old_student::setYir_score(int score)
{
    yir_score = score;
    return *this;
}
