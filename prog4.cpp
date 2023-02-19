#include "prog4.h"

Group_table &Group_table::insertGroup(Group *g)
{
    if (grouptable.find(g->getIndex()) == grouptable.end())
    {
        std::pair<const std::string, Group *> p(g->getIndex(), g);
        grouptable.insert(p);
    }
    else
    {
        std::cout << "This class already have\n";
    }
    return *this;
}

Group_table::~Group_table()
{
    std::map<const std::string, Group *>::iterator p;
    for (p = grouptable.begin(); p != grouptable.end(); p++)
    {
        delete p->second;
    }
    grouptable.clear();
}
Group_table &Group_table::eraseGroup(const std::string &ind)
{
    if (grouptable.find(ind) != grouptable.end())
    {
        delete grouptable.find(ind)->second;
        grouptable.erase(ind);
    }
    return *this;
}

std::map<const std::string, Group *>::iterator Group_table::begin()
{
    return grouptable.begin();
}

std::map<const std::string, Group *>::iterator Group_table::end()
{
    return grouptable.end();
}

std::map<const std::string, Group *>::iterator Group_table::find(const std::string &ind)
{
    return grouptable.find(ind);
}

Group *&Group_table::at(const std::string &ind)
{
    return grouptable.at(ind);
}

int dialog(Group_table &G)
{
    std::cout << std::endl;
    std::string words[] = {"1. Add a group", "2. Delete a group", "3. Change sth in group",
                           "4. New student", "5. New semester",
                           "6. Fill scores", "7. Average scores", "0. Quit"};
    int m;
    int N = 8;
    do
    {
        for (int i = 0; i < N; i++)
            std::cout << words[i] << std::endl;
        printf("выбор: --> ");
        vvodm(m, N);

        switch (m)
        {
        case 1:
            d_insert_group(G);
            break;
        case 2:
            d_erase_group(G);
            break;
        case 3:
            d_change_group(G);
            break;
        case 4:
            d_new_student(G);
            break;
        case 5:
            d_new_semester(G);
            break;
        case 6:
            d_Set_scores_semester(G);
            break;
        case 7:
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

void d_insert_group(Group_table &G)
{
    std::cout << "Введите индекc группы:\n";
    std::string ind;
    ind = vvods(ind);
    Group *group = new Group();
    group->setIndex(ind);

    G.insertGroup(group);
}
void d_erase_group(Group_table &G)
{
    std::cout << "Введите индекc группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
        G.eraseGroup(ind);
    else
        std::cout << "Группа не найдена\n";
}
void d_change_group(Group_table &G)
{
    std::cout << "Введите индекc группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
    {
        dialog(G.at(ind));
    }
    else
        std::cout << "Группа не найдена\n";
}

void d_new_student(Group_table &G)
{
    std::cout << "Введите индекc группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
        d_insertStudent(G.at(ind));
    else
        std::cout << "Группа не найдена\n";
}
void d_new_semester(Group_table &G)
{
    std::cout << "Ввелите индекс группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
    {
        d_eraseStudent(G.at(ind));
        d_insertStudent(G.at(ind));
    }
    else
        std::cout << "Группа не найдена\n";
}
void d_Set_scores_semester(Group_table &G)
{
    std::cout << "Введите индекc группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
    {
        std::map<const std::string, Student *>::iterator it;
        //vector<int> scr;
        for (it = G.at(ind)->begin(); it != G.at(ind)->end(); it++)
        {
            std::cout << "Фамилия: " << it->second->getFamily() << "       Число оценок:" << it->second->getNumber_score() << "     Оценки:";
            vector<int> scr = it->second->getScore();
            for (int j = 0; j < it->second->getNumber_score(); j++)
                std::cout << scr[j] << " ";
            std::cout << "\n";
            std::cout << "Новое числооценок:";
            int num;
            std::cin >> num;
            std::cout << "Новый оценки:";
            vector<int> scr2;
            int n;
            for (int i = 0; i < num; i++)
            {
                std::cin >> n;
                scr2.push_back(n);
            }
            it->second->setNumber_score(num);
            it->second->setScore(scr2);
            scr.clear();
            scr2.clear();
        }
        G.at(ind)->show();
    }
    else
        std::cout << "Группа не найдена\n";
}
void d_Get_average_scare(Group_table &G)
{
    std::cout << "Ввелите индекс группы:\n";
    std::string ind;
    ind = vvods(ind);
    if (G.find(ind) != G.end())
    {
        std::map<const std::string, Student *>::iterator it = G.find(ind)->second->begin();
        int s = 0;
        int n = 0;
        int nscr = it->second->getNumber_score();
        for (it = G.find(ind)->second->begin(); it != G.at(ind)->end(); it++)
        {
            
            n++;
           vector<int> scr = it->second->getScore();
            for (int j = 0; j < it->second->getNumber_score(); j++)
                s += scr[j];
            if (it->second->getNumber_score() > nscr)
                nscr = it->second->getNumber_score();
        }
        double average = ((double)s) / ((double)n * nscr);
        std::cout << "Средняя оценка: " << average << "\n";
    }
    else
        std::cout << "Группа не найдена\n";
}


int dialog(Student *&student)
{
    std::cout << "\n";
    if (student->getType() == "Junior Student")
    {
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
            vvodm(m, N);

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
                std::cout << student->getFamily() << "\n";
                break;
            case 5:
                std::cout << student->getNumber_score() << "\n";
                break;
            case 6:
                d_getScore(student);
                break;
            case 7:
                std::cout << student->getType() << "\n";
                break;
            case 0:
                return 1;
            default:
                std::cout << "Должно быть введено значение от 0 до 7" << std::endl;
                break;
            }
        } while (1);
    }
    else
    {
        std::string words[] = {"1. Set family", "2. Set number score",
                               "3. Set score", "4. Get family",
                               "5. Get number score", "6. Get score",
                               "7. Get Type", "8. Set Yir", "9. Set Yir score",
                               "10. Set Yir place", "11. Get Yir",
                               "12. Get Yir score", "13. Get Yir place", "0. Quit"};
        int N = 14;
        int m;
        do
        {
            for (int i = 0; i < N; i++)
                std::cout << words[i] << std::endl;
            printf("выбор: --> ");
            vvodm(m, N);

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
                std::cout << student->getFamily() << "\n";
                break;
            case 5:
                std::cout << student->getNumber_score() << "\n";
                break;
            case 6:
                d_getScore(student);
                break;
            case 7:
                std::cout << student->getType() << "\n";
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
                std::cout << dynamic_cast<Old_student *>(student)->getYir() << "\n";
                break;
            case 12:
                std::cout << dynamic_cast<Old_student *>(student)->getYir_score() << "\n";
                break;
            case 13:
                std::cout << dynamic_cast<Old_student *>(student)->getPlace_yir() << "\n";
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

void d_setFamily(Student *&s)
{
    std::cout << "Введите фамилию студента:\n";
    std::string fam;
    fam = vvods(fam);
    s->setFamily(fam);
}

void d_setNumber_score(Student *&s)
{
    std::cout << "Введите число дисциплин:\n";
    int num;
    std::cin >> num;
    s->setNumber_score(num);
}

void d_setScore(Student *&s)
{
    std::cout << "Введите " << s->getNumber_score() << " оценок:\n";
    vector<int> scr;
    int n;
    for (int i = 0; i < s->getNumber_score(); i++)
    {
        std::cin >> n;
        scr.push_back(n);
    }
    s->setScore(scr);
    scr.clear();
}

void d_getScore(Student *&s)
{
    vector<int> scr = s->getScore();
    for (int i = 0; i < (int)scr.size(); i++)
        std::cout << scr[i] << " ";
    std::cout << "\n";
    scr.clear();
}

void d_setYir(Student *&s)
{
    std::cout << "Введите тему уир:\n";
    std::string yir;
    yir = vvods(yir);
    dynamic_cast<Old_student *>(s)->setYir(yir);
}

void d_setYir_score(Student *&s)
{
    std::cout << "Введите оценку за уир:\n";
    int num;
    std::cin >> num;
    dynamic_cast<Old_student *>(s)->setYir_score(num);
}

void d_setYir_place(Student *&s)
{
    std::cout << "Введите место уир:\n";
    std::string yir;
    yir = vvods(yir);
    dynamic_cast<Old_student *>(s)->setPlace_yir(yir);
}

int vvodm(int &a, int N)
{
    while (1)
    {
        std::cin >> a;
        if (std::cin.good() == 1 && a >= 0 && a < N)
            break;
        std::cout << "You are wrong. Repeat please" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    }
    return 1;
}

std::string &vvods(std::string &a)
{
    while (1)
    {
        std::cin >> a;
        if (std::cin.good() == 1)
            break;
        std::cin.clear();
        std::cin.ignore(1024, '\n');
        std::cout << "You are wrong. Repeat please" << std::endl;
    }
    return a;
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
        vvodm(m, N);

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

void d_setNumber_disciplines(Group *&g)
{
    std::cout << "Введите число дисциплин:\n";
    int num;
    std::cin >> num;
    g->setNumber_disciplines(num);
}
void d_setType_students(Group *&g)
{
    std::cout << "Введите тип студентов: Junior(1) или Old(2)\n";
    int m;
    std::cin >> m;
    std::string type;
    if (m % 2 == 1)
        type = "Junior Student";
    else
        type = "Old Student";
    g->setType_students(type);
}
void d_getIndex(Group *&g)
{
    std::cout << "Index is " << g->getIndex() << "\n";
}
void d_getNumber_disciplines(Group *&g)
{
    std::cout << "Number disciplines is " << g->getNumber_disciplines() << "\n";
}
void d_getType_students(Group *&g)
{
    std::cout << "Type of students is " << g->getType_students() << "\n";
}
void d_insertStudent(Group *&g)
{
    std::cout << "Выберите тип студента: Junior(1) или  Old(2)\n";
    int type;
    std::cin >> type;
    Student *s;
    if (type % 2 == 1)
    {
        s = new Student();
    }
    else
    {
        s = new Old_student();
    }
    d_setFamily(s);
    dialog(s);
    g->insertStudent(s);
}
void d_eraseStudent(Group *&g)
{
    std::cout << "Введите фамилию студента:\n";
    std::string fam;

    fam = vvods(fam);
    if (g->find(fam) != g->end())
        g->eraseStudent(fam);
    else
        std::cout << "Студент не найден\n";
}

void d_change_student(Group *&g)
{
    std::cout << "Введите фамилию студента:\n";
    std::string fam;
    fam = vvods(fam);
    if (g->find(fam) != g->end())
    {
        dialog(g->at(fam));
    }
    else
        std::cout << "Студент не найден\n";
}
