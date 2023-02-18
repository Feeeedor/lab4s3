#include "prog4.cpp"
#include "prog4.h"
#include "Student.h"
#include "Group.h"
#include "Student.cpp"
#include "Group.cpp"
#include <gtest/gtest.h>

TEST(student,constructor_empty)
{
    Student s;
    ASSERT_EQ(s.getFamily(), "no data");
    ASSERT_EQ(s.getNumber_score(), 0);
    ASSERT_EQ(s.getScore().empty(), true);
    ASSERT_EQ(s.getType(), "Junior Student");
}
TEST(student,constructor_unempty)
{
    int num = 3;
    std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    std::string fam = "Petrov P.P.";
    Student s(fam, num, scr);
    scr.clear();
    ASSERT_EQ(s.getFamily(), "Petrov P.P.");
    ASSERT_EQ(s.getNumber_score(), 3);
    ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
    ASSERT_EQ(s.getType(), "Junior Student");
}

TEST(student,set_family1)
{
    Student s;
    std::string fam = "Sidorov S.S.";
    s.setFamily(fam);
    ASSERT_EQ(s.getFamily(), "Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 0);
    ASSERT_EQ(s.getScore().empty(), true);
    ASSERT_EQ(s.getType(), "Junior Student");
}

TEST(student,set_family2)
{
    int num = 3;
    std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    std::string fam = "Petrov P.P.";
    Student s(fam, num, scr);
    scr.clear();
    fam = "Sidorov S.S.";
    s.setFamily(fam);
    ASSERT_EQ(s.getFamily(), "Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 3);
    ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
    ASSERT_EQ(s.getType(), "Junior Student");
}

TEST(student,set_number_score){
Student s;
s.setNumber_score(3);
ASSERT_EQ(s.getFamily(), "no data");
    ASSERT_EQ(s.getNumber_score(), 3);
    ASSERT_EQ(s.getScore().empty(), true);
    ASSERT_EQ(s.getType(), "Junior Student");
}
TEST(student,set_number_score2){
Student s;
s.setNumber_score(3);
s.setNumber_score(6);
ASSERT_EQ(s.getFamily(), "no data");
    ASSERT_EQ(s.getNumber_score(), 6);
    ASSERT_EQ(s.getScore().empty(), true);
    ASSERT_EQ(s.getType(), "Junior Student");
}
TEST(student,set_score)
{
    Student s;
    std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    s.setScore(scr);
    scr.clear();
    ASSERT_EQ(s.getFamily(), "no data");
    ASSERT_EQ(s.getNumber_score(), 0);
    ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
    ASSERT_EQ(s.getType(), "Junior Student");
}

TEST(student,set_score2)
{
    Student s;
    std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(4);
    scr.push_back(5);
    s.setScore(scr);
    std::vector<int> scr2;
    scr2.push_back(2);
    scr2.push_back(4);
    scr2.push_back(5);
    scr2.push_back(10);
    s.setScore(scr2);
    scr.clear();
    scr2.clear();
    ASSERT_EQ(s.getFamily(), "no data");
    ASSERT_EQ(s.getNumber_score(), 0);
    ASSERT_EQ(s.getScore().size(), 4);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 4);
    ASSERT_EQ(s.getScore()[2], 5);
    ASSERT_EQ(s.getScore()[3], 10);
    ASSERT_EQ(s.getType(), "Junior Student");
}

TEST (old_student,constructor_empty){
    Old_student s;
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,constructor_unempty){
    int num=3;
   std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    std::string fam="Petrov P.P.";
    std::string y="JOB";
    std::string py="PLACE";
    int sc=4;
    Old_student s(fam,num,scr,y,py,sc);
    scr.clear();
    ASSERT_EQ(s.getFamily(),"Petrov P.P.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
ASSERT_EQ(s.getYir(),"JOB");
ASSERT_EQ(s.getPlace_yir(),"PLACE");
ASSERT_EQ(s.getYir_score(), 4);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,set_family){
Old_student s;
std::string fam="Sidorov S.S.";
s.setFamily(fam);
    ASSERT_EQ(s.getFamily(),"Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,set_family2){
 int num=3;
   std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    std::string fam="Petrov P.P.";
    std::string y="JOB";
    std::string py="PLACE";
    int sc=4;
    Old_student s(fam,num,scr,y,py,sc);
 fam="Sidorov S.S.";
s.setFamily(fam);
    ASSERT_EQ(s.getFamily(),"Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
ASSERT_EQ(s.getYir(),"JOB");
ASSERT_EQ(s.getPlace_yir(),"PLACE");
ASSERT_EQ(s.getYir_score(), 4);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,set_numberscore){
Old_student s;
s.setNumber_score(3);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,set_numberscore2){
Old_student s;
s.setNumber_score(3);
s.setNumber_score(6);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 6);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}


TEST (old_student_set,score){
Old_student s;
std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    s.setScore(scr);
    scr.clear();
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().size(), 3);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 3);
    ASSERT_EQ(s.getScore()[2], 5);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student_set,score2){
Old_student s;
std::vector<int> scr;
    scr.push_back(2);
    scr.push_back(3);
    scr.push_back(5);
    s.setScore(scr);
    scr.clear();
std::vector<int> scr2;
    scr2.push_back(2);
    scr2.push_back(4);
    scr2.push_back(5);
    scr2.push_back(7);
    s.setScore(scr2);
    scr2.clear();
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().size(), 4);
    ASSERT_EQ(s.getScore()[0], 2);
    ASSERT_EQ(s.getScore()[1], 4);
    ASSERT_EQ(s.getScore()[2], 5);
    ASSERT_EQ(s.getScore()[3], 7);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}

TEST (old_student,set_yir){
Old_student s;
std::string y="something";
s.setYir(y);
   ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"something");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student,set_yir2){
Old_student s;
std::string y="something";
s.setYir(y);
y="sth";
s.setYir(y);
   ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"sth");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student,set_place_yir){
Old_student s;
std::string place="something";
s.setPlace_yir(place);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"something");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student,set_place_yir2){
Old_student s;
std::string place="something";
s.setPlace_yir(place);
place="sth";
s.setPlace_yir(place);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"sth");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student,set_yir_score){
Old_student s;
s.setYir_score(5);
   ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 5);
ASSERT_EQ(s.getType(),"Old Student");
}
TEST (old_student,set_yir_score2){
Old_student s;
s.setYir_score(5);
s.setYir_score(7);
   ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 0);
ASSERT_EQ(s.getScore().empty(), true);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 7);
ASSERT_EQ(s.getType(),"Old Student");
}



TEST (old_student_student,set_yir){
    
    Old_student s;
    Student *stud=&s;

std::string y="something";
dynamic_cast<Old_student*>(stud)->setYir(y);
   ASSERT_EQ(stud->getFamily(),"no data");
    ASSERT_EQ(stud->getNumber_score(), 0);
ASSERT_EQ(stud->getScore().empty(), true);
ASSERT_EQ(dynamic_cast<Old_student*>(stud)->getYir(),"something");
ASSERT_EQ(dynamic_cast<Old_student*>(stud)->getPlace_yir(),"no data");
ASSERT_EQ(dynamic_cast<Old_student*>(stud)->getYir_score(), 0);
ASSERT_EQ(stud->getType(),"Old Student");
}

TEST(dialog,student){
Student s;
Student *st=&s;
dialog(st);
}
TEST(dialog,old_student){
Old_student s;
Student *st=&s;
dialog(st);
}




TEST(group_constructor, empty){
    Group g;
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getIndex(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_constructor, unempty){
    std::string ind="101";
    Group g(ind);
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getIndex(),"101");
    ASSERT_EQ(g.getTable().empty(), true);
}

TEST(group_set, index){
    Group g;
    std::string ind="101";
    g.setIndex(ind);
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getIndex(),"101");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_set, index2){
    Group g;
    std::string ind="101";
    g.setIndex(ind);
    ind="103";
    g.setIndex(ind);
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getIndex(),"103");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_set, number_disciplines){
    Group g;
    g.setNumber_disciplines(4);
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getIndex(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 4);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_set, number_disciplines2){
    Group g;
    g.setNumber_disciplines(4);
    g.setNumber_disciplines(8);
    ASSERT_EQ(g.getType_students(),"no data");
    ASSERT_EQ(g.getIndex(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 8);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_set, type_students){
    Group g;
    std::string ind="junior";
    g.setType_students(ind);
    ASSERT_EQ(g.getType_students(),"junior");
    ASSERT_EQ(g.getIndex(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getTable().empty(), true);
}
TEST(group_set, type_student2){
    Group g;
    std::string ind="junior";
    g.setType_students(ind);
    ind="jun";
    g.setType_students(ind);
    ASSERT_EQ(g.getType_students(),"jun");
    ASSERT_EQ(g.getIndex(),"no data");
    ASSERT_EQ(g.getNumber_disciplines(), 0);
    ASSERT_EQ(g.getTable().empty(), true);
}

TEST(Group_insert,insert){
Group g;
    Student *s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
ASSERT_EQ(g.getTable().begin()->second->getFamily(),"jun");
    ASSERT_EQ(g.getTable().begin()->second->getNumber_score(), 0);
    ASSERT_EQ(g.getTable().begin()->second->getScore().empty(), true);
ASSERT_EQ(g.getTable().begin()->second->getType(),"Junior Student");

}
TEST(Group_insert,insert2){
Group g;
    Student* s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
    fam="oop";
    Student *q=new Student();
    q->setFamily(fam);
    g.insertStudent(q); 
    std::map<const std::string, Student *> ::iterator it=g.begin();
    ASSERT_EQ(g.getTable().size(),2);
ASSERT_EQ(it->second->getFamily(),"jun");
ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"oop");

    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");


}
TEST(Group_insert,insert3){
Group g;

    Student *s=new Student();   
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
   
    Student *s2=new Student();
    fam="check";
    s2->setFamily(fam);
    g.insertStudent(s2);
    
    
   Student *s3=new Student();
    fam="third";
    s3->setFamily(fam);
    g.insertStudent(s3);
    
    
    std::map<const std::string, Student *> ::iterator it=g.begin();
ASSERT_EQ(it->second->getFamily(),"check");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"jun");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"third");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    
ASSERT_EQ(it->second->getType(),"Junior Student");



}



TEST(Group,erase){
Group g;
    Student *s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
    Student *s2=new Student();
fam="juni";
s2->setFamily(fam);
g.insertStudent(s2);
fam="jun";
g.eraseStudent(fam);
ASSERT_EQ(g.getTable().begin()->second->getFamily(),"juni");
    ASSERT_EQ(g.getTable().begin()->second->getNumber_score(), 0);
    ASSERT_EQ(g.getTable().begin()->second->getScore().empty(), true);
ASSERT_EQ(g.getTable().begin()->second->getType(),"Junior Student");

}


TEST(Group,show){
Group g;
    Student *s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
    g.show();
ASSERT_EQ(g.getTable().begin()->second->getFamily(),"jun");
    ASSERT_EQ(g.getTable().begin()->second->getNumber_score(), 0);
    ASSERT_EQ(g.getTable().begin()->second->getScore().empty(), true);
ASSERT_EQ(g.getTable().begin()->second->getType(),"Junior Student");
}
TEST(Group,show2){
Group g;
    Student *s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 
    fam="oop";
    Student *q=new Student();
    q->setFamily(fam);
    g.insertStudent(q); 
    std::map<const std::string, Student *> ::iterator it=g.begin();
    g.show();
    ASSERT_EQ(g.getTable().size(),2);
ASSERT_EQ(it->second->getFamily(),"jun");
ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"oop");

    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
}
TEST(Group,show3){
Group g;

    Student *s=new Student();
    std::string fam="jun";
    s->setFamily(fam);
    g.insertStudent(s); 

    Student *s2=new Student();
    fam="check";
    s2->setFamily(fam);
    g.insertStudent(s2);
   
    Student *s3=new Student();
    fam="third";
    s3->setFamily(fam);
    g.insertStudent(s3);
    
    
   
    g.show();
    std::map<const std::string, Student *> ::iterator it=g.begin();
ASSERT_EQ(it->second->getFamily(),"check");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"jun");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    ASSERT_EQ(it->second->getScore().empty(), true);
ASSERT_EQ(it->second->getType(),"Junior Student");
it++;
ASSERT_EQ(it->second->getFamily(),"third");
    ASSERT_EQ(it->second->getNumber_score(), 0);
    
ASSERT_EQ(it->second->getType(),"Junior Student");


}


TEST(Group,dialog){
    Group g;
    Group *group=&g;
dialog(group);
}
/*
TEST(Group_table,constructor){
    Group_table g;
}

TEST(Group_table,insert){
    Group_table g;
    Group *g2=new Group(); 
    g.insertGroup(g2);
    ASSERT_EQ(g.begin()->second->getIndex(),"no data");
    ASSERT_EQ(g.begin()->second->getNumber_disciplines(),0);
    ASSERT_EQ(g.begin()->second->getType_students(),"no data");
    ASSERT_EQ(g.begin()->second->getTable().empty(),true);
}
TEST(Group_table,erase){
    Group_table g;
    Group *g2=new Group();
    std::string ind="100";
    g2->setIndex(ind);
    Group *g3=new Group();
    ind="101";
    g3->setIndex(ind);
    g.insertGroup(g2);
    g.insertGroup(g3);
    ind="100";
    g.eraseGroup(ind);
    ASSERT_EQ(g.begin()->second->getIndex(),"101");
    ASSERT_EQ(g.begin()->second->getNumber_disciplines(),0);
    ASSERT_EQ(g.begin()->second->getType_students(),"no data");
    ASSERT_EQ(g.begin()->second->getTable().empty(),true);
}



TEST(Group, show4){
    std::string ind="1";
    Group *g;
    g=new Group(ind);
    std::vector<int> u;
    Student s(ind,0, u);
    g->insertStudent(&s);
    dialog(g);
    delete g;
}
*/


