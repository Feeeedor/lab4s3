#include "Student.h"
#include "Group.h"



Group::Group()
{
    number_disciplines = 1;
    type_students = "no data";
    index = "no data";
}
Group::Group(Student *&stud)
{
    number_disciplines = stud->getNumber_score();
    type_students = stud->getType();
    table.emplace(stud->getFamily(), stud);
    index = "no data";
}
Group::Group(const std::string& ind)
{
    number_disciplines = 0;
    type_students = "no data";
    index = ind;
}

void Group::setNumber_disciplines(int num_dis)
{
    number_disciplines = num_dis;
}
void Group::setType_students(const std::string &typ_st)
{
    type_students = typ_st;
}
void Group::setIndex(const std::string &ind)
{
    index = ind;
}
Group &Group::insert(Student *stud)
{
    
    if (table.find(stud->getFamily()) == table.end())
    {
        table.emplace(stud->getFamily(), stud);
        type_students=stud->getType();
        
      
    }
    return *this;
}
bool Group::erase(const std::string &stud)
{
    bool res = false;
    if (table.find(stud) != table.end())
    {
        table.erase(stud);
        res = true;
    }
    return res;
}

int Group::getNumber_disciplines() const
{
    return number_disciplines;
}
std::string Group::getType_students() const
{
    return type_students;
}
std::string Group::getIndex() const
{
    return index;
}
std::map<const std::string, Student *> Group::getTable() const
{
    return table;
}

void Group::show()
{
    std::cout << "Index: " << index << "; "
              << "Type of group: " << type_students << "\n";
    std::cout << "Number of disciplines: " << number_disciplines << "\n";
  
if(table.begin()!=table.end()){
    
    std::cout << "Family    Type of student     Number of score     Scores";
    std::map<const std::string, Student *>::iterator it=this->begin();
   std::string xh="junior Student";
    if (type_students == xh)
    {
       
        std::cout << "\n";
        for (it = table.begin(); it != table.end(); it++)
        {
           std::string qw=it->second->getFamily();
            std::cout << qw;
            std::cout<<"WWWWWWWWWWWWWWWWWWWWWWW\n";
            std::cout<< " " << it->second->getType() << " " << it->second->getNumber_score() << " ";
            std::cout<<"AAAAAAAAAAAAAAAAAAAAAAAAAAa\n";
            int *arr = it->second->getArr_score();
            std::cout<<"BBBBBBBBBBBBBBBBBBBBBBb\n";
            for (int i = 0; i < it->second->getNumber_score(); i++)
                std::cout << arr[i] << " ";
            std::cout << "\n";
            delete []arr;
        }
    }
    else
    {
        std::cout << "YIR     Place of YIR    YIR Score\n";
        for (it = table.begin(); it != table.end(); it++)
        {
            std::cout << it->second->getFamily() << "   " << it->second->getType() << "     " << it->second->getNumber_score() << ":    ";
            int *arr = it->second->getArr_score();
            for (int i = 0; i < it->second->getNumber_score(); i++)
                std::cout << arr[i] << " ";
            std::cout << "     " << it->second->getYir() << "   " << it->second->getPlace_yir() << "     " << it->second->getYir_score() << "\n";
        delete []arr;
        }
        
    }
    
    }
    else
    std::cout<<"no students\n";
}

std::string Group::getType(const std::string &fam) const
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end())
        return it->second->getType();
    std::cout << "not found \n";
    return "not found";
}
int *Group::getArr_score(const std::string &fam) const
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end())
        return it->second->getArr_score();
    std::cout << "not found \n";
    return 0;
}

bool Group::setScore(const std::string& fam, int num, int *&arr)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end())
    {
        it->second->setScore(num, arr);
        return true;
    }
    return false;
}

bool Group::setYir(const std::string &fam, const std::string &y)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
    {
        it->second->setYir(y);
        return true;
    }
    return false;
}
bool Group::setPlace_yir(const std::string &fam, const std::string &place)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
    {
        it->second->setPlace_yir(place);
        return true;
    }
    return false;
}
bool Group::setYir_score(const std::string &fam, int score)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
    {
        it->second->setYir_score(score);
        return true;
    }
    return false;
}

std::string Group::getYir(const std::string &fam)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
        return it->second->getYir();
    std::cout << "not found \n";
    return "not found";
}
std::string Group::getPlace_yir(const std::string& fam)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
        return it->second->getPlace_yir();
    std::cout << "not found \n";
    return "not found";
}
int Group::getYir_score(const std::string &fam)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
        return it->second->getYir_score();
    std::cout << "not found \n";
    return 0;
}

std::map<const std::string, Student *>::iterator Group::begin()
{
    std::map<const std::string, Student *>::iterator it = table.begin();
    return it;
}
std::map<const std::string, Student *>::iterator Group::end()
{
    std::map<const std::string, Student *>::iterator it = table.end();
    return it;
}