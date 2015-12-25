#ifndef SVGRECTANGLE_H
#define SVGRECTANGLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGRectangle /* need some base classes here */ {
    double x, y, width, height, rx, ry;
public:
    /* need a `constructor(id)` here */

    SVGRectangle& setPosition(double _x, double _y) {
        x = _x, y = _y;
        return *this;
    }

    SVGRectangle& setSize(double w, double h) {
        width = w, height = h;
        return *this;
    }

    SVGRectangle& setRadius(double _rx, double _ry) {
        rx = _rx, ry = _ry;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        /* call `print_attr` to print x, y, rx, ry, width, height */
        /* call `print_style` to print styles */
        print_tag_close(out);
        return out;
    }

protected:
    virtual SVGElement* clone() const {
        /* actually, there is only one line here */
    }

};

#endif

