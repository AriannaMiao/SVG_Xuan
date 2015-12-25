#ifndef SVGSTYLEFILL_H
#define SVGSTYLEFILL_H

#include "SVGStyle.h"

class SVGStyleFill: public SVGStyle {
    std::string color;
    double opacity;

protected:
    virtual std::ostream& print_style(std::ostream& out) const {
        /* call `print_attr`
           fill          ->  color
           fill-opacity  ->  opacity */
        return out;
    }

public:
    SVGStyleFill() : color(), opacity() {}
    void setFillColor(const std::string& color) { this->color = color; }
    void setFillOpacity(const double opacity) { this->opacity = opacity; }
};

#endif
