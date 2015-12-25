#ifndef SVGSTYLESTROKE_H
#define SVGSTYLESTROKE_H

#include "SVGStyle.h"

class SVGStyleStroke: public SVGStyle {
    std::string color;
    double width;
    double opacity;

protected:
    virtual std::ostream& print_style(std::ostream& out) const {
        /* call `print_attr`
           stroke          ->  color
           stroke-width    ->  width
           stroke-opacity  ->  opacity */
        return out;
    }

public:
    SVGStyleStroke() : color(), width(), opacity() {}
    void setStrokeColor(const std::string& color) { this->color = color; }
    void setStrokeWidth(const double width) { this->width = width; }
    void setStrokeOpacity(const double opacity) { this->opacity = opacity; }
};

#endif
