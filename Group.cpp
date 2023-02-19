#include "vector_r.h"
#include "Student.h"
#include "Group.h"

Group::Group()
{
    number_disciplines = 0;
    type_students = "no_data";
    index = "no_data";
}

Group::Group(const std::string &ind)
{
    number_disciplines = 0;
    type_students = "no_data";
    index = ind;
}
Group::~Group()
{
    std::map<const std::string, Student *>::iterator p;
    for (p = table.begin(); p != table.end(); p++)
    {
        delete p->second;
    }
    table.clear();
}

Group &Group::setNumber_disciplines(int num_dis)
{
    number_disciplines = num_dis;
    return *this;
}
Group &Group::setType_students(const std::string &typ_st)
{
    type_students = typ_st;
    return *this;
}
Group &Group::setIndex(const std::string &ind)
{
    index = ind;
    return *this;
}

Group &Group::insertStudent(Student *stud)
{

    if (table.find(stud->getFamily()) != table.end())
    {
        std::cout << "Student " << stud->getFamily() << "already included\n";
    }
    else
    {

        std::pair<const std::string, Student *> p(stud->getFamily(), stud);
        table.insert(p);
    }

    return *this;
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

    if (!table.empty())
    {
        std::cout << "Family    Type of student     Number of score     Scores      YIR     Place of YIR    YIR Score\n";
        for (std::map<const std::string, Student *>::const_iterator it = table.begin(); it != table.end(); it++)
        {
            std::cout << (*it).second->getFamily();
            std::cout << "   " << it->second->getType() << "     " << it->second->getNumber_score() << "     ";
            vector<int> scr = it->second->getScore();
            for (int i = 0; i < it->second->getNumber_score(); i++)
                std::cout << scr[i] << " ";
            std::cout << "      ";
            scr.clear();
            if (type_students == "Old Student")
            {
                std::cout << "     " << dynamic_cast<Old_student *>(table.at(it->second->getFamily()))->getYir() << "   ";
                std::cout << dynamic_cast<Old_student *>(table.at(it->second->getFamily()))->getPlace_yir();
                std::cout << "     " << dynamic_cast<Old_student *>(table.at(it->second->getFamily()))->getYir_score();
            }
            std::cout << "\n";
        }
    }
    else
        std::cout << "no students\n";
}

Group &Group::eraseStudent(const std::string &stud)
{
    if (table.find(stud) != table.end())
    {
        delete table.find(stud)->second;
        table.erase(stud);
    }
    return *this;
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

std::map<const std::string, Student *>::iterator Group::find(const std::string &fam)
{
    return table.find(fam);
}
Student *&Group::at(const std::string &fam)
{
    return table.at(fam);
}

