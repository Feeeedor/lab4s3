#include "Student.h"
#include "Group.h"

Group::Group()
{
    number_disciplines = 0;
    type_students = "no_data";
    index = "no_data";
}

Group::Group(const std::string& ind)
{
    number_disciplines = 0;
    type_students = "no_data";
    index = ind;
}
Group::~Group(){
    std::map<const std::string, Student *>::iterator p;
for (p = table.begin(); p != table.end();p++){
    //Student *s=p->second;
delete p->second;
}
table.clear();
}

Group & Group::setNumber_disciplines(int num_dis)
{
    number_disciplines = num_dis;
    return *this;
}
Group & Group::setType_students(const std::string &typ_st)
{
    type_students = typ_st;
    return *this;
}
Group & Group::setIndex(const std::string &ind)
{
    index = ind;
    return *this;
}

Group &Group::insertStudent(  Student *stud)
{
    
    if (table.find(stud->getFamily()) != table.end())
    {
        std::cout<<"Student "<<stud->getFamily()<<"already included\n";
    }
else{

    std::pair<const std::string ,Student*> p(stud->getFamily(), stud);
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
  
if(!table.empty()){
    std::cout << "Family    Type of student     Number of score     Scores      YIR     Place of YIR    YIR Score\n";
for (std::map<const std::string, Student *>::const_iterator it = table.begin(); it != table.end(); it++)
        {
 std::cout << (*it).second->getFamily();   
            std::cout<< "   " << it->second->getType() << "     " << it->second->getNumber_score() << "     ";
            std::vector<int> scr = it->second->getScore();
            for (int i = 0; i < it->second->getNumber_score(); i++)
                std::cout << scr[i] << " ";
            std::cout << "      ";
            scr.clear();
            if (type_students == "Old Student"){
                std::cout << "     " << dynamic_cast<Old_student*>(table.at(it->second->getFamily()))->getYir() << "   ";
            std::cout <<dynamic_cast<Old_student*>(table.at(it->second->getFamily()))->getPlace_yir();
            std::cout<< "     " << dynamic_cast<Old_student*>(table.at(it->second->getFamily()))->getYir_score();
            }
std::cout<<"\n";
        }
}
    else
    std::cout<<"no students\n";
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


std::map<const std::string, Student *>::iterator Group::find(const std::string &fam){
return table.find(fam);
}
Student *&Group::at(const std::string&fam){
return table.at(fam);
}



int dialog(Group *&g)
{
    (*g).show();
    std::cout << std::endl;
    std::string words[] = {"1. Set number disciplines", "2. Set type of students",
                           "3. Get index", "4. Get number disciplines",
                           "5. Get type of students", "6. Insert student",
                           "7. Delete student", "8. Show", 
                            "9. Change student", "0. Quit"};
    int N = 10;
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
            d_setNumber_disciplines(g);
            break;
        case 2:
            d_setType_students(g);
            break;
        case 3:
            d_getIndex(g);
            break;
        case 4:
            d_getNumber_disciplines(g);
            break;
        case 5:
            d_getType_students(g);
            break;
        case 6:
            d_insertStudent(g);
            break;
        case 7:
            d_eraseStudent(g);
            break;
        case 8:
            g->show();
            break;
        case 9:
            d_change_student(g);
            break;
        case 0:
            return 1;
        default:
            std::cout << "Должно быть введено значение от 0 до 10" << std::endl;
            break;
        }
    } while (1);
    return 1;
}


void d_setNumber_disciplines(Group*&g){
    std::cout << "Введите число дисциплин:\n";
    int num;
    std::cin>>num;
    g->setNumber_disciplines(num);
}
void d_setType_students(Group*&g){
    std::cout << "Введите тип студентов: Junior(1) или Old(2)\n";
    int m;
    std::cin>>m;
    std::string type;
    if(m%2==1)
    type="Junior Student";
    else
    type="Old Student";
    g->setType_students(type);
}
void d_getIndex(Group*&g){
    std::cout<<"Index is "<<g->getIndex()<<"\n";
}
void d_getNumber_disciplines(Group*&g){
    std::cout<<"Number disciplines is "<<g->getNumber_disciplines()<<"\n";
}
void d_getType_students(Group*&g){
    std::cout<<"Type of students is "<<g->getType_students()<<"\n";
}
void d_insertStudent(Group *&g)
{
    std::cout << "Выберите тип студента: Junior(1) или  Old(2)\n";
    int type;
    std::cin>>type;
    Student *s;
    if(type%2==1){
    s=new Student();
    //stud=&s;
    }
    else{
s=new Old_student();
//stud=&s;
    }
dialog(s);
g->insertStudent(s);
}
void d_eraseStudent(Group*&g){
    std::cout << "Введите фамилию студента:\n";
    std::string fam;
    fam=vvods(fam);
    if(g->find(fam)!=g->end())
    g->eraseStudent(fam);
    else
    std::cout<<"Студент не найден\n";
}

void d_change_student(Group*&g){
    std::cout << "Введите фамилию студента:\n";
    std::string fam;
    fam=vvods(fam);
     if(g->find(fam)!=g->end()){
    dialog(g->at(fam));
     }
    else
    std::cout<<"Студент не найден\n";
}