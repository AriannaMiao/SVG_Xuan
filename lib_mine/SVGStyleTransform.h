#ifndef SVGSTYLETRANSFORM_H
#define SVGSTYLETRANSFORM_H

#include "SVGStyle.h"

class SVGStyleTransform: public SVGStyle {
    std::string transform;

protected:
    virtual std::ostream& print_style(std::ostream& out) const {
        SVGBase::print_attr(out, "transform", transform);
        return out; 
    }//±¾±¦±¦Ð´µÄ 

public:
    SVGStyleTransform() : transform() {}
    void setTransform(const std::string& transform) { this->transform = transform; }
};

#endif
