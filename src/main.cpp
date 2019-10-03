#include "editor.h"
#include <string>
#include <cassert>

const std::string C_HELP_SHAPES = "add l x0 y0 x1 y1 - added to current document line with coordinates (x0,y0) , (x1,y1)"
                                  "\nadd c x0 y0 r     - added to current document circle center is (x0,y0), radius (r)";

const std::string C_HELP = "new               - create new document"
                           "\nimp <file_name>   - import <file_name> to new document"
                           "\nexp <file_name>   - export current document to <file_name>"
                           "\nrm  x y           - remove from current document shape with point (x,y)"
                           "\nexit              - exit"
                           "\nhelp              - view help";
int main()
{
    Editor *e = new Editor{};
    std::string cmd{""};
    std::string fname{""};
    std::string shape{""};
    Point a;
    Point b;
    int r;
    bool exit{false};

    std::cout << "Commands:" << std::endl;
    std::cout << C_HELP << std::endl;
    std::cout << C_HELP_SHAPES << std::endl;

    while (!exit)
    {
        std::cin >> cmd;

        if (cmd == "new")
        {
            e->create();
        }
        else if (cmd == "imp")
        {
            std::cin >> fname;
            e->imp(fname);
        }
        else if (cmd == "exp")
        {
            std::cin >> fname;
            e->exp(fname);
        }
        else if (cmd == "rm")
        {
            std::cin >> a;
            e->remove(a);
        }
        else if (cmd == "add")
        {
            std::cin >> shape;
            if (shape == "l")
            {
                std::cin >> a >> b;
                e->add(Shape::Type::Line,a,b);
            }
            else if (shape == "c")
            {
                std::cin >> a >> r;
                e->add(Shape::Type::Circle,a,r);
            }
            else
            {
                std::cout << "Unknow shape" << std::endl;
                std::cout << C_HELP_SHAPES << std::endl;
            }
            
        }
        else if (cmd == "help")
        {
            std::cout << "Commands:" << std::endl;
            std::cout << C_HELP << std::endl;
            std::cout << C_HELP_SHAPES << std::endl;
        }
        else if (cmd == "exit")
            exit = true;
        else 
        {
            std::cout << "Unknow command" << std::endl;
            std::cout << C_HELP << std::endl;
            std::cout << C_HELP_SHAPES << std::endl;
        }
    }

    delete e;

    return 0;
}