#pragma once

#include "canvas.h"

class Editor
{
    public:

        explicit Editor() = default;
        ~Editor() { delete _pcnv; }

        void create();
        void imp(const std::string&);
        void exp(const std::string&);

        template<typename... A>
        void add(const Shape::Type& t,A... a);

        void remove(const Point& p);

    private:

        Canvas *_pcnv {nullptr};
};
//-----------------------------------------------------


template<typename... A>
void Editor::add(const Shape::Type& t,A... a)
{
    if (_pcnv != nullptr)
        _pcnv->add(t,a...);
}
