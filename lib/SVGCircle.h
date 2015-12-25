#ifndef SVGCIRCLE_H
#define SVGCIRCLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGCircle /* need some base classes here */ {
    double cx, cy, r;
public:
    /* need a `constructor(id)` here */

    SVGCircle& setPosition(double _x, double _y) {
        cx = _x, cy = _y;
        return *this;
    }

    SVGCircle& setRadius(double _r) {
        r = _r;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        /* call `print_attr` to print cx, cy, r */
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
