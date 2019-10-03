#include "editor.h"
#include <string>

void Editor::create()
{
    if (_pcnv == nullptr)
        _pcnv = new Canvas();
    else
        std::cout << "Need close current document." << std::endl;
    
}
//------------------------------------------------------------------


void Editor::remove(const Point& p)
{
    if (_pcnv != nullptr)
        _pcnv->remove(p);
}
//------------------------------------------------------------------


void Editor::imp(const std::string& f)
{
    if (_pcnv == nullptr)
    {
        std::cout << "Import from " << f << std::endl;
        _pcnv = new Canvas{};
    }
    else
    {
        std::cout << "Need close current document." << std::endl;
    }
}
//------------------------------------------------------------------


void Editor::exp(const std::string& f)
{
    if (_pcnv != nullptr)
    {
        std::cout << "Export to " << f << std::endl;
    }
    else
    {
        std::cout << "There is no document." << std::endl;
    }
}
//------------------------------------------------------------------