#pragma once

#include "point.h"
#include <cassert>

class Shape
{
    public:

        enum class Type {Line,Circle};

        virtual ~Shape() = default;

        virtual void hide() = 0;
        virtual void show() = 0;
        virtual void move(const Point&) = 0;
        virtual bool inhere(const Point&) = 0;
};


class ShapeLine : public Shape
{
    public:

        template<typename... A>
        explicit ShapeLine(A...){ assert(true); }

        ShapeLine(const Point& begin, const Point& end);

        ~ShapeLine();

        void hide()  override;
        void show() override;
        void move(const Point&) override;
        bool inhere(const Point&) override;
        friend std::ostream& operator << (std::ostream&,const ShapeLine &);

    private:

        Point _begin;
        Point _end;
        double _k;  //  angular coefficient
        double _c;  //  abscissa offset coefficient

};


class ShapeCircle : public Shape
{
    public:

        template<typename... A>
        explicit ShapeCircle(A...){}

        ShapeCircle(const Point& center,int radius);

        ~ShapeCircle();

        void hide()  override;
        void show() override;
        void move(const Point& dp) override;
        bool inhere(const Point&) override;

        friend std::ostream& operator << (std::ostream&,const ShapeCircle&);

    private:

        Point _center;
        int _radius;
    
};
