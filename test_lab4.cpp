#include "prog4.h"
#include "prog4.cpp"

#include <gtest/gtest.h>


TEST (student_constructor, empty){
    Student s;
    ASSERT_EQ(s.getFamily(),"Ivanov I.I.");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
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
}
TEST (old_student_constructor, empty){
    Old_student s;
    ASSERT_EQ(s.getFamily(),"Ivanov I.I.");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
ASSERT_EQ(s.getYir(),"no data");
ASSERT_EQ(s.getPlace_yir(),"no data");
ASSERT_EQ(s.getYir_score(), 0);
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
}
