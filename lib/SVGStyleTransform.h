#ifndef SVGSTYLETRANSFORM_H
#define SVGSTYLETRANSFORM_H

#include "SVGStyle.h"

class SVGStyleTransform: public SVGStyle {
    std::string transform;

protected:
    virtual std::ostream& print_style(std::ostream& out) const {
        /* call `print_attr`
           transform   ->   transform */
        return out;
    }

public:
    SVGStyleTransform() : transform() {}
    void setTransform(const std::string& transform) { this->transform = transform; }
};

#endif
