#include "prog4.h"
#include "prog4.cpp"

#include <gtest/gtest.h>


TEST (student_constructor, empty){
    Student s;
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getType(),"junior Student");
}
TEST (student_constructor, unempty){
    int num=3;
     int *scr;
    scr=new int[num];
    scr[0]=2;
    scr[1]=3;
    scr[2]=5;
    std::string fam="Petrov P.P.";
    Student s(fam,num,scr);
    delete []scr;
    ASSERT_EQ(s.getFamily(),"Petrov P.P.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
ASSERT_EQ(s.getType(),"junior Student");
}

TEST (student_set, family){
int num=3;
     int *scr;
    scr=new int[num];
    scr[0]=2;
    scr[1]=3;
    scr[2]=5;
    std::string fam="Petrov P.P.";
    Student s(fam,num,scr);
    delete []scr;
fam="Sidorov S.S.";
s.setFamily(fam);
ASSERT_EQ(s.getFamily(),"Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
ASSERT_EQ(s.getType(),"junior Student");

}

TEST (student_set, score){
    Student s;
    int num=4;
    int *arr;
    arr=new int[num];
    arr[0]=2;
    arr[1]=3;
    arr[2]=5;
    arr[3]=7;
    s.setScore(num,arr);
    delete []arr;
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 4);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
ASSERT_EQ(s.getArr_score()[3], 7);
ASSERT_EQ(s.getType(),"junior Student");
}







TEST (old_student_constructor, empty){
    Old_student s;
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"old Student");
}

TEST (old_student_constructor, unempty){
    int num=3;
     int *scr;
    scr=new int[num];
    scr[0]=2;
    scr[1]=3;
    scr[2]=5;
    std::string fam="Petrov P.P.";
    std::string y="JOB";
    std::string py="PLACE";
    int sc=4;
    Old_student s(fam,num,scr,y,py,sc);
    delete []scr;
    ASSERT_EQ(s.getFamily(),"Petrov P.P.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
ASSERT_EQ(s.getYir(),"JOB");
ASSERT_EQ(s.getPlace_yir(),"PLACE");
ASSERT_EQ(s.getYir_score(), 4);
ASSERT_EQ(s.getType(),"old Student");
}

TEST (old_student_set,family){
Old_student s;
std::string fam="Sidorov S.S.";
s.setFamily(fam);
    ASSERT_EQ(s.getFamily(),"Sidorov S.S.");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"old Student");
}
TEST (old_student_set,score){
Old_student s;
int num=4;
    int *arr;
    arr=new int[num];
    arr[0]=2;
    arr[1]=3;
    arr[2]=5;
    arr[3]=7;
    s.setScore(num,arr);
    delete []arr;
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 4);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
ASSERT_EQ(s.getArr_score()[3], 7);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"old Student");
}
TEST (old_student_set,yir){
Old_student s;
std::string y="something";
s.setYir(y);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"something");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"old Student");
}
TEST (old_student_set,place_yir){
Old_student s;
std::string place="something";
s.setPlace_yir(place);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"something");
ASSERT_EQ(s.getYir_score(), 0);
ASSERT_EQ(s.getType(),"old Student");
}
TEST (old_student_set,yir_score){
Old_student s;
int score=3;
s.setYir_score(score);
    ASSERT_EQ(s.getFamily(),"no data");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 3);
ASSERT_EQ(s.getType(),"old Student");
}
