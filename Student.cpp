#include "Student.h"


    
Student::Student()
{
    family = "no_data";
    number_score = 0;
}

Student::Student(const std::string &fam, int num, std::vector<int> &scr)
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

std::vector<int> Student::getScore() const
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

Student &Student::setNumber_score(int num){
number_score=num;
return *this;
}
    Student &Student::setScore(std::vector<int> &scr){
        score=scr;
return *this;
    }





Old_student::Old_student() : Student()
{
    yir = "no_data";
    place_yir = "no_data";
    yir_score = 0;
}
Old_student::Old_student(const std::string &fam, int num, std::vector<int> &scr, const std::string &y,const  std::string &py, int sc) : Student(fam, num, scr)
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
Old_student& Old_student::setPlace_yir(const std::string &place)
{
    place_yir = place;
    return *this;
}
Old_student& Old_student::setYir_score(int score)
{
    yir_score = score;
    return *this;
}


int dialog(Student *&student)
{
    std::cout << "\n";
    if(student->getType()=="Junior Student"){
    std::string words[] = {"1. Set family", "2. Set number score",
                           "3. Set score", "4. Get family",
                           "5. Get number score", "6. Get score",
                           "7. Get Type", "0. Quit"};
    int N = 8;
    int m;
    do
    {
        for (int i = 0; i < N; i++)
            std::cout << words[i] << std::endl;
        printf("выбор: --> ");
        vvodm(m,N);

        switch (m)
        {
        case 1:
            d_setFamily(student);
            break;
        case 2:
            d_setNumber_score(student);
            break;
        case 3:
            d_setScore(student);
            break;
        case 4:
           std::cout<<student->getFamily()<<"\n";
            break;
        case 5:
            std::cout<<student->getNumber_score()<<"\n";
            break;
        case 6:
            d_getScore(student);
            break;
        case 7:
            std::cout<<student->getType()<<"\n";
            break;
        case 0:
            return 1;
        default:
            std::cout << "Должно быть введено значение от 0 до 7" << std::endl;
            break;
        }
    } while (1);}
    else
    {
        std::string words[] = {"1. Set family", "2. Set number score",
                           "3. Set score", "4. Get family",
                           "5. Get number score", "6. Get score",
                           "7. Get Type", "8. Set Yir", "9. Set Yir score",
                           "10. Set Yir place", "11. Get Yir",
                           "12. Get Yir score", "13. Get Yir place","0. Quit"};
    int N = 14;
    int m;
    do
    {
        for (int i = 0; i < N; i++)
            std::cout << words[i] << std::endl;
        printf("выбор: --> ");
        vvodm(m,N);

        switch (m)
        {
        case 1:
            d_setFamily(student);
            break;
        case 2:
            d_setNumber_score(student);
            break;
        case 3:
            d_setScore(student);
            break;
        case 4:
           std::cout<<student->getFamily()<<"\n";
            break;
        case 5:
            std::cout<<student->getNumber_score()<<"\n";
            break;
        case 6:
            d_getScore(student);
            break;
        case 7:
            std::cout<<student->getType()<<"\n";
            break;
        case 8:
            d_setYir(student);
            break;
        case 9:
            d_setYir_score(student);
            break;
        case 10:
            d_setYir_place(student);
            break;
        case 11:
           std::cout<<dynamic_cast<Old_student*>(student)->getYir()<<"\n";
            break;
        case 12:
            std::cout<<dynamic_cast<Old_student*>(student)->getYir_score()<<"\n";
            break;
        case 13:
            std::cout<<dynamic_cast<Old_student*>(student)->getPlace_yir()<<"\n";
            break;
        case 0:
            return 1;
        default:
            std::cout << "Должно быть введено значение от 0 до 7" << std::endl;
            break;
        }
    } while (1);
    }
    return 1;
}

void d_setFamily(Student *&s){
std::cout << "Введите фамилию студента:\n";
    std::string fam;
    fam=vvods(fam);
    s->setFamily(fam);
}
void d_setNumber_score(Student *&s){
std::cout << "Введите число дисциплин:\n";
    int num;
    std::cin>>num;
    s->setNumber_score(num);
}
void d_setScore(Student *&s){
std::cout << "Введите "<<s->getNumber_score()<<" оценок:\n";
    std::vector<int> scr;
    int n;
    for(int i=0;i<s->getNumber_score();i++){
    std::cin>>n;
    scr.push_back(n);}
    s->setScore(scr);
    scr.clear();
}


void d_getScore(Student *&s){
std::vector<int> scr=s->getScore();
for(int i=0;i<(int)scr.size();i++)
std::cout<<scr[i]<<" ";
std::cout<<"\n";
scr.clear();
}

void d_setYir(Student *&s){
std::cout << "Введите тему уир:\n";
    std::string yir;
    yir=vvods(yir);
    dynamic_cast<Old_student*>(s)->setYir(yir);
}
void d_setYir_score(Student *&s){
std::cout << "Введите оценку за уир:\n";
    int num;
    std::cin>>num;
    dynamic_cast<Old_student*>(s)->setYir_score(num);
}
void d_setYir_place(Student *&s){
std::cout << "Введите место уир:\n";
    std::string yir;
    yir=vvods(yir);
    dynamic_cast<Old_student*>(s)->setPlace_yir(yir);
}