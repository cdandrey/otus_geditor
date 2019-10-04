#include "canvas.h"

Canvas::~Canvas()
{
    for (auto & v : _sh)
        delete v;
}
//--------------------------------------------------

void Canvas::add(Shape *p)
{
    if (p != nullptr)
    {
        _sh.push_back(p);
        _sh.at(_sh.size() - 1)->show();
    }
}
//-----------------------------------------------------------------


void Canvas::remove(const Point& p)
{
    for (auto it = _sh.begin(); it != _sh.end(); ++it)
        if ((*it)->inhere(p))
        {
            delete *it;
            _sh.erase(it);
            break;
        }
}
//--------------------------------------------------
