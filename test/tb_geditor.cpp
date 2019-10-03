
#include "../lib/editor.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(test_geditor,add_and_remove)
{
    std::ostringstream lout;    // local out
    auto backup_buf = std::cout.rdbuf();
    std::cout.rdbuf(lout.rdbuf());

    Editor *e = new Editor();
    e->create();

    e->add(Shape::Type::Line,Point(1,1),Point(1,10));
    auto p0 = lout.str().find_first_of('\n',0);
    EXPECT_EQ(lout.str().substr(0,p0),"Create line: begin: {1,1} end: {1,10}");
    auto p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Show line: begin: {1,1} end: {1,10}");

    e->add(Shape::Type::Line,Point(1,1),Point(10,1));
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Create line: begin: {1,1} end: {10,1}");
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Show line: begin: {1,1} end: {10,1}");

    e->add(Shape::Type::Line,Point(10,1),Point(10,10));
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Create line: begin: {10,1} end: {10,10}");
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Show line: begin: {10,1} end: {10,10}");

    e->add(Shape::Type::Line,Point(1,10),Point(10,10));
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Create line: begin: {1,10} end: {10,10}");
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Show line: begin: {1,10} end: {10,10}");

    e->add(Shape::Type::Circle,Point(5,5),4);
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Create circle: center: {5,5} radius: 4");
    p0 = p1;
    p1 = lout.str().find_first_of('\n',p0 + 1);
    EXPECT_EQ(lout.str().substr(p0,p1),"Show circle: center: {5,5} radius: 4");

    std::cout.rdbuf(backup_buf);

    delete e;
}