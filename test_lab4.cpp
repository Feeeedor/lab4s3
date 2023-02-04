#include "prog4.h"
#include "prog4.cpp"

#include <gtest/gtest.h>


TEST (constructor, empty){
    Student s;
    ASSERT_EQ(s.getFamily(),"Ivanov I.I.");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
}
TEST (constructor, family){
    std::string fam="Petrov P.P.";
    Student s(fam);
    ASSERT_EQ(s.getFamily(),"Petrov P.P.");
    ASSERT_EQ(s.getNumber_score(), 1);
ASSERT_EQ(s.getArr_score()[0], 0);
}
TEST (constructor, scores){
    int num=3;
    int *scr;
    scr=new int[num];
    scr[0]=2;
    scr[1]=3;
    scr[2]=5;
    Student s(num,scr);
      delete []scr;
    ASSERT_EQ(s.getFamily(),"Ivanov I.I.");
    ASSERT_EQ(s.getNumber_score(), 3);
ASSERT_EQ(s.getArr_score()[0], 2);
ASSERT_EQ(s.getArr_score()[1], 3);
ASSERT_EQ(s.getArr_score()[2], 5);
}

TEST (constructor, family_scores){
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
