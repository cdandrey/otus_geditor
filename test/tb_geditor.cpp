
#include "../lib/editor.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

TEST(test_geditor,add)
{
    std::ostringstream lout;    // local out
    auto backup_buf = std::cout.rdbuf();
    std::cout.rdbuf(lout.rdbuf());

    Editor *e = new Editor();
    e->create();
    e->add(Shape::Type::Line,Point(0,0),Point(9,9));

    EXPECT_EQ(lout.str().substr(0,lout.str().find_first_of('\n',0)),"Create line: begin: {0,0} end: {9,9}");

    std::cout.rdbuf(backup_buf);

    delete e;
}