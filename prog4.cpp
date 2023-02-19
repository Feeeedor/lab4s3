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
        std::vector<int> scr;
        for (it = G.at(ind)->begin(); it != G.at(ind)->end(); it++)
        {
            std::cout << "Фамилия: " << it->second->getFamily() << "       Число оценок:" << it->second->getNumber_score() << "     Оценки:";
            scr = it->second->getScore();
            for (int j = 0; j < it->second->getNumber_score(); j++)
                std::cout << scr[j] << " ";
            std::cout << "\n";
            std::cout << "Новое числооценок:";
            int num;
            std::cin >> num;
            std::cout << "Новый оценки:";
            std::vector<int> scr2;
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
            std::vector<int> scr;
            n++;
            scr = it->second->getScore();
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
