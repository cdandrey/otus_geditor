
#include "../lib/editor.h"
#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <array>

TEST(test_geditor,add_remove)
{
    std::array<std::ostringstream,11> lout;    // local out
    auto backup_buf = std::cout.rdbuf();
    std::cout.rdbuf(lout[0].rdbuf());

    Editor *e = new Editor();
    e->create();

    e->add(Shape::Type::Line,Point(1,1),Point(1,10));
    EXPECT_EQ(lout[0].str(),"Create line: begin: {1,1} end: {1,10}\nShow line: begin: {1,1} end: {1,10}\n");

    std::cout.rdbuf(lout[1].rdbuf());
    e->add(Shape::Type::Line,Point(1,1),Point(10,1));
    EXPECT_EQ(lout[1].str(),"Create line: begin: {1,1} end: {10,1}\nShow line: begin: {1,1} end: {10,1}\n");

    std::cout.rdbuf(lout[2].rdbuf());
    e->add(Shape::Type::Line,Point(10,1),Point(10,10));
    EXPECT_EQ(lout[2].str(),"Create line: begin: {10,1} end: {10,10}\nShow line: begin: {10,1} end: {10,10}\n");

    std::cout.rdbuf(lout[3].rdbuf());
    e->add(Shape::Type::Line,Point(1,10),Point(10,10));
    EXPECT_EQ(lout[3].str(),"Create line: begin: {1,10} end: {10,10}\nShow line: begin: {1,10} end: {10,10}\n");

    std::cout.rdbuf(lout[4].rdbuf());
    e->add(Shape::Type::Circle,Point(5,5),4);
    EXPECT_EQ(lout[4].str(),"Create circle: center: {5,5} radius: 4\nShow circle: center: {5,5} radius: 4\n");

    std::cout.rdbuf(lout[5].rdbuf());
    e->add(Shape::Type::Circle,Point(5,5),10);
    EXPECT_EQ(lout[5].str(),"Create circle: center: {5,5} radius: 10\nShow circle: center: {5,5} radius: 10\n");

    std::cout.rdbuf(lout[6].rdbuf());
    e->remove(Point(1,1));
    EXPECT_EQ(lout[6].str(),"Remove line: begin: {1,1} end: {1,10}\n");

    std::cout.rdbuf(lout[7].rdbuf());
    e->remove(Point(10,10));
    EXPECT_EQ(lout[7].str(),"Remove line: begin: {1,10} end: {10,10}\n");

    std::cout.rdbuf(lout[8].rdbuf());
    e->remove(Point(11,11));
    EXPECT_EQ(lout[8].str(),"Remove circle: center: {5,5} radius: 10\n");

    std::cout.rdbuf(lout[9].rdbuf());
    e->remove(Point(11,11));
    EXPECT_EQ(lout[9].str(),"");

    std::cout.rdbuf(lout[10].rdbuf());
    delete e;
    EXPECT_EQ(lout[10].str(),"Remove line: begin: {1,1} end: {10,1}\n"
                             "Remove line: begin: {10,1} end: {10,10}\n"
                             "Remove circle: center: {5,5} radius: 4\n");

    std::cout.rdbuf(backup_buf);
}
//----------------------------------------------------------------------------------


TEST(test_geditor,import_export)
{
    std::array<std::ostringstream,2> lout;    // local out
    auto backup_buf = std::cout.rdbuf();
    std::cout.rdbuf(lout[0].rdbuf());

    Editor *e = new Editor();

    std::cout.rdbuf(lout[0].rdbuf());
    e->imp("image.bmp");
    EXPECT_EQ(lout[0].str(),"Import from image.bmp\n");

    std::cout.rdbuf(lout[1].rdbuf());
    e->exp("image.jpg");
    EXPECT_EQ(lout[1].str(),"Export to image.jpg\n");

    std::cout.rdbuf(backup_buf);
}
//----------------------------------------------------------------------------------
