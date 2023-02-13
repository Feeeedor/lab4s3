#include "Student.h"


    
Student::Student()
{
    family = "no data";
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
}

Student::Student(const std::string &fam, int num, int *&scr)
{
    family = fam;
    number_score = num;
    arr_score = new int[num];
    for (int i = 0; i < num; i++)
        arr_score[i] = scr[i];
}

Student::~Student()
{
    delete[] arr_score;
}

std::string Student::getFamily() const
{
    return family;
}

int Student::getNumber_score() const
{
    return number_score;
}

int *Student::getArr_score() const
{
    return arr_score;
}

std::string Student::getType() const
{
    return "junior Student";
}

void Student::setFamily(const std::string &fam)//ща поменяю с на воид
{
    family = fam;
}
Student &Student::setScore(int num, int *&arr)
{
    number_score = num;
    delete[] arr_score;
    arr_score = new int[num];
    for (int i = 0; i < num; i++)
        arr_score[i] = arr[i];
    return *this;
}

std::string Student::getYir() const
{
    return "УИР не определен для студентов этого типа\n";
}
std::string Student::getPlace_yir() const
{
    return "УИР не определен для студентов этого типа\n";
}
int Student::getYir_score() const
{
    std::cout << "УИР не определен для студентов этого типа\n";
    return 0;
}
void Student::setYir(const std::string &y)
{
    if (y == y)
        std::cout << "УИР не определен для студентов этого типа\n";
}
void Student::setPlace_yir(const std::string &place)
{
    if (place == place)
        std::cout << "УИР не определен для студентов этого типа\n";
}
void Student::setYir_score(int score)
{
    score += 0;
    std::cout << "УИР не определен для студентов этого типа\n";
}

Old_student::Old_student() : Student()
{
    yir = "no data";
    place_yir = "no data";
    yir_score = 0;
}
Old_student::Old_student(const std::string &fam, int num, int *&scr, const std::string &y,const  std::string &py, int sc) : Student(fam, num, scr)
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
    return "old Student";
}
void Old_student::setYir(const std::string &y)
{
    yir = y;
}
void Old_student::setPlace_yir(const std::string &place)
{
    place_yir = place;
}
void Old_student::setYir_score(int score)
{
    yir_score = score;
}
