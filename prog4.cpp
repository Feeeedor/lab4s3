#include "prog4.h"



/*


bool Group_table::insertGroup(Group &g)
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

bool Group_table::erase_group(const std::string &ind)
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
{ 
std::map<const std::string,Student*>::iterator p;
for (p = table.begin(); p != table.end(); p++){
delete p->second;
p->second = nullptr;
}
table.clear();
}




std::map<const std::string, Student *>::iterator Group_table::begin(const std::string &ind)
{
    std::map<const std::string, Group>::iterator itt;
    itt = grouptable.find(ind);

    return itt->second.begin();
}

std::map<const std::string, Student *>::iterator Group_table::end(const std::string &ind)
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
    ind=vvods(ind);
    Group group(ind);
    G.insertGroup(group);
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
}*/