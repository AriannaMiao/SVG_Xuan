#ifndef SVGELLIPSE_H
#define SVGELLIPSE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGEllipse /* need some base classes here */ {
    double cx, cy, rx, ry;
public:
    /* need a `constructor(id)` here */

    SVGEllipse& setPosition(double _x, double _y) {
        cx = _x, cy = _y;
        return *this;
    }

    SVGEllipse& setRadius(double _rx, double _ry) {
        rx = _rx, ry = _ry;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        /* call `print_attr` to print cx, cy, rx, ry */
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
