#include "prog4.h"

Student::Student()
{
    family = "no data";
    number_score = 1;
    arr_score = new int[1];
    arr_score[0] = 0;
}

Student::Student(std::string &fam, int num, int *&scr)
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

Student &Student::setFamily(std::string &fam)
{
    family = fam;
    return *this;
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
Old_student::Old_student(std::string &fam, int num, int *&scr, std::string &y, std::string &py, int sc) : Student(fam, num, scr)
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

Group::Group()
{
    number_disciplines = 0;
    type_students = "no data";
    index = "no data";
}
Group::Group(Student *stud)
{
    number_disciplines = stud->getNumber_score();
    type_students = stud->getType();
    table.emplace(stud->getFamily(), stud);
    index = "no data";
}
Group::Group(std::string ind)
{
    number_disciplines = 0;
    type_students = "no data";
    index = ind;
}

void Group::setNumber_disciplines(int num_dis)
{
    number_disciplines = num_dis;
}
void Group::setType_students(std::string typ_st)
{
    type_students = typ_st;
}
void Group::setIndex(std::string ind)
{
    index = ind;
}
bool Group::insert(Student *stud)
{
    bool res = false;
    if (table.find(stud->getFamily()) == table.end())
    {
        table.emplace(stud->getFamily(), stud);
        res = true;
    }
    return res;
}
bool Group::erase(std::string stud)
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
    std::cout << "Family    Type of student     Number of score     Scores";
    std::map<const std::string, Student *>::iterator it;
    it = table.begin();
    if (it->second->getType() == "junior Student")
    {
        std::cout << "\n";
        for (it = table.begin(); it != table.end(); it++)
        {
            std::cout << it->second->getFamily() << " " << it->second->getType() << " " << it->second->getNumber_score() << " ";
            int *arr = it->second->getArr_score();
            for (int i = 0; i < it->second->getNumber_score(); i++)
                std::cout << arr[i] << " ";
            std::cout << "\n";
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
        }
    }
}

std::string Group::getType(std::string fam) const
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end())
        return it->second->getType();
    std::cout << "not found \n";
    return "not found";
}
int *Group::getArr_score(std::string fam) const
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end())
        return it->second->getArr_score();
    std::cout << "not found \n";
    return 0;
}

bool Group::setScore(std::string fam, int num, int *arr)
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

bool Group::setYir(std::string fam, const std::string &y)
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
bool Group::setPlace_yir(std::string fam, const std::string &place)
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
bool Group::setYir_score(std::string fam, int score)
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

std::string Group::getYir(std::string fam)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
        return it->second->getYir();
    std::cout << "not found \n";
    return "not found";
}
std::string Group::getPlace_yir(std::string fam)
{
    std::map<const std::string, Student *>::const_iterator it;
    it = table.find(fam);
    if (it != table.end() && it->second->getType() == "old Student")
        return it->second->getPlace_yir();
    std::cout << "not found \n";
    return "not found";
}
int Group::getYir_score(std::string fam)
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

bool Group_table::setYir(std::string ind, std::string fam, const std::string &y)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.setYir(fam, y);
    return false;
}
bool Group_table::setPlace_yir(std::string ind, std::string fam, const std::string &y)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.setPlace_yir(fam, y);
    return false;
}

bool Group_table::setYir_score(std::string ind, std::string fam, int score)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.setYir_score(fam, score);
    return false;
}

std::string Group_table::getYir(std::string ind, std::string fam)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getYir(fam);
    return "not found";
}
std::string Group_table::getPlace_yir(std::string ind, std::string fam)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getPlace_yir(fam);
    return "not found";
}
int Group_table::getYir_score(std::string ind, std::string fam)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getYir_score(fam);
    return 0;
}

std::string Group_table::getType(std::string ind, std::string fam) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getType(fam);
    return 0;
}
int *Group_table::getArr_score(std::string ind, std::string fam) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getArr_score(fam);
    return 0;
}
bool Group_table::setScore(std::string ind, std::string fam, int num, int *arr)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.setScore(fam, num, arr);
    return false;
}

int Group_table::getNumber_disciplines(std::string ind) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getNumber_disciplines();
    return 0;
}
std::string Group_table::getType_students(std::string ind) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getType_students();
    return "not found";
}
std::string Group_table::getIndex(std::string ind) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.getIndex();
    return "not found";
}
bool Group_table::erase_student(std::string ind, std::string fam)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.erase(fam);
    return false;
}
std::map<const std::string, Student *> Group_table::getTable(std::string ind) const
{
    std::map<const std::string, Group>::const_iterator itt;
    itt = grouptable.find(ind);

    return itt->second.getTable();
}

void Group_table::show(std::string ind)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    itt->second.show();
}

bool Group_table::setGroup(Group g)
{
    bool res = false;
    std::map<const std::string, Group>::iterator p = grouptable.find(g.getIndex());
    if (p == grouptable.end())
    {
        grouptable.emplace(g.getIndex(), g);
        res = true;
    }
    return res;
}

bool Group_table::erase_group(std::string ind)
{
    bool res = false;
    std::map<const std::string, Group>::iterator p = grouptable.find(ind);
    if (p != grouptable.end())
    {
        p->second.~Group();
        grouptable.erase(p);
        res = true;
    }
    return res;
}

Group::~Group()
{ /*
std::map<const std::string,Student*>::iterator p;
for (p = table.begin(); p != table.end(); p++){
delete p->second;
p->second = nullptr;
}
table.clear();*/
}

bool Group_table::insert(std::string ind, Student *stud)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
        return itt->second.insert(stud);
    return false;
}

bool Group_table::changeStudent(std::string ind, std::string fam, std::string type, int num)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);
    if (itt != grouptable.end())
    {
        int *arr;
        arr = new int[num];
        for (int i = 0; i < num; i++)
            arr[i] = 0;

        if (type != "junior Student")
        {
            std::string yir = "no data";
            std::string place = "no data";
            Old_student st(fam, num, arr, yir, place, 0);
        }
        Student st(fam, num, arr);
        itt->second.erase(fam);
        itt->second.insert(&st);
        delete[] arr;
    }
    return true;
}

std::map<const std::string, Student *>::iterator Group_table::begin(std::string ind)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);

    return itt->second.begin();
}

std::map<const std::string, Student *>::iterator Group_table::end(std::string ind)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);

    return itt->second.end();
}

int dialog(Group_table &G)
{
    std::cout << std::endl;
    std::string words[] = {"1. Add a group", "2. Show a group", "3. Add new student in group",
                           "4. Get type of  studient", "5. Set scores",
                           "6. Get scores", "7. Set yir", "8. Get yir", "9. Set place of yir",
                           "10. Get place of yir", "11. Get yir score", "12. Set yir score",
                           "13. New semester", "14. Set scores for semester", "15. Get average scare for group", "0. Quit"};
    int m;
    int N = 16;
    do
    {
        for (int i = 0; i < N; i++)
            std::cout << words[i] << std::endl;
        printf("выбор: --> ");
        vvodm(m);

        switch (m)
        {
        case 1:
            d_Add_group(G);
            break;
        case 2:
            d_Show_group(G);
            break;
        case 3:
            d_Add_student(G);
            break;
        case 4:
            d_Get_type_studient(G);
            break;
        case 5:
            d_Set_scores(G);
            break;
        case 6:
            d_Get_scores(G);
            break;
        case 7:
            d_Set_yir(G);
            break;
        case 8:
            d_Get_yir(G);
            break;
        case 9:
            d_Set_place_yir(G);
            break;
        case 10:
            d_Get_place_yir(G);
            break;
        case 11:
            d_Get_yir_score(G);
            break;
        case 12:
            d_Set_yir_score(G);
            break;
        case 13:
            d_New_semester(G);
            break;
        case 14:
            d_Set_scores_semester(G);
            break;
        case 15:
            d_Get_average_scare(G);
            break;
        case 0:
            return 1;
        default:
            std::cout << "Должно быть введено значение от 0 до 15" << std::endl;
            break;
        }
    } while (1);
    return 1;
}

int vvodm(int &a)
{
    while (1)
    {
        std::cin >> a;
        if (std::cin.good() == 1 && a >= 0 && a <= 15)
            break;
        std::cout << "You are wrong. Repeat please" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
    return 1;
}

void d_Add_group(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    Group group(ind);
    G.setGroup(group);
}
void d_Show_group(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    G.show(ind);
}
void d_Get_number_disciplines(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << G.getNumber_disciplines(ind) << "\n";
}
void d_Get_type_group(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << G.getType_students(ind) << "\n";
}
void d_Add_student(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите Фамилию нового студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Выберите Junior(1) или Old(2) : ";
    int t;
    std::cin >> t;
    std::cout << "Введите число дисциплин\n";
    int num;
    std::cin >> num;
    std::cout << "Введите оценки по " << num << " дисциплинам\n";
    int *arr;
    arr = new int[num];
    for (int i = 0; i < num; i++)
        std::cin >> arr[i];
    if (t % 2 == 0)
    {
        std::cout << "Введите тему по уир\n";
        std::string yir;
        std::cin >> yir;
        std::cout << "Введите место проведения уир\n";
        std::string place;
        std::cin >> place;
        std::cout << "Введите оценку за уир\n";
        int score;
        std::cin >> score;
        Old_student st(fam, num, arr, yir, place, score);
    }
    Student st(fam, num, arr);
    G.insert(ind, &st);
    delete[] arr;
}
void d_Get_type_studient(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << G.getType(ind, fam) << "\n";
}
void d_Set_scores(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Введите число дисциплин\n";
    int num;
    std::cin >> num;
    std::cout << "Введите оценки по " << num << " дисциплинам\n";
    int *arr;
    arr = new int[num];
    for (int i = 0; i < num; i++)
        std::cin >> arr[i];
    G.setScore(ind, fam, num, arr);
    delete[] arr;
}
void d_Get_scores(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    int *arr;
    arr = G.getArr_score(ind, fam);
    for (int i = 0; i < G.getNumber_disciplines(ind); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    delete[] arr;
}
void d_Set_yir(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Введите тему уир\n";
    std::string yir;
    std::cin >> yir;
    G.setYir(ind, fam, yir);
}
void d_Get_yir(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << G.getYir(ind, fam);
}
void d_Set_place_yir(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Введите место уир\n";
    std::string place;
    std::cin >> place;
    G.setPlace_yir(ind, fam, place);
}
void d_Get_place_yir(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << G.getPlace_yir(ind, fam);
}
void d_Get_yir_score(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << G.getYir_score(ind, fam);
}
void d_Set_yir_score(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Введите оценку за уир\n";
    int yir;
    std::cin >> yir;
    G.setYir_score(ind, fam, yir);
}
void d_New_semester(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::cout << "Введите фамилию студента\n";
    std::string fam;
    std::cin >> fam;
    std::cout << "Введите новый статус студента(old student или junior student)\n";
    std::string type;
    std::cin >> type;
    std::cout << "Введите число дисциплин в новом семестре\n";
    int num;
    std::cin >> num;
    G.changeStudent(ind, fam, type, num);
}
void d_Set_scores_semester(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::map<const std::string, Student *>::iterator it;
    for (it = G.begin(ind); it != G.end(ind); it++)
    {
        std::cout << "Введите " << it->second->getNumber_score() << " оценок дисциплин " << it->second->getFamily() << " :\n";
        int *arr;
        arr = new int[it->second->getNumber_score()];
        for (int i = 0; i < it->second->getNumber_score(); i++)
            std::cin >> arr[i];
        it->second->setScore(it->second->getNumber_score(), arr);
        delete[] arr;
    }
    G.show(ind);
}
void d_Get_average_scare(Group_table &G)
{
    std::cout << "Введите индекc группы\n";
    std::string ind;
    std::cin >> ind;
    std::map<const std::string, Student *>::iterator it;
    int sum = 0;
    int *arr;
    double sr = 0;
    int p = 0;
    for (it = G.begin(ind); it != G.end(ind); it++)
    {
        p++;
        arr = it->second->getArr_score();
        for (int i = 0; i < it->second->getNumber_score(); i++)
            sum += arr[i];
        delete[] arr;
        sr += (double)sum / ((double)it->second->getNumber_score());
    }
    std::cout << sr / ((double)p) << "\n";
}