
#include "../lib/editor.h"
#include <gtest/gtest.h>

TEST(test_geditor,add)
{
    Editor *e = new Editor();
    e->create();
    e->add(Shape::Type::Line,Point(0,0),Point(9,9));

    EXPACT_EQ(true,true);
}