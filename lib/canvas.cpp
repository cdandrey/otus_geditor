#include "canvas.h"

Canvas::~Canvas()
{
    for (auto & v : _sh)
        delete v;
}
//--------------------------------------------------

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
