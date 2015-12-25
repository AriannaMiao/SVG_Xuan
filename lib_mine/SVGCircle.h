#ifndef SVGCIRCLE_H
#define SVGCIRCLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGCircle: public SVGElement, public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransfor { //本宝宝写的 
    double cx, cy, r;
public:
    SVGCircle(const std::string& id_): SVGElement(circle, id_), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {
		cx = 0;
		cy = 0;
		r = 0;
	} //本宝宝写的 

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
        SVGBase::print_attr(out, "cx", cx);
        SVGBase::print_attr(out, "cy", cy);
        SVGBase::print_attr(out, "r", r);
        SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        print_tag_close(out);
        return out;
    }//本宝宝写的 

protected:
    virtual SVGElement* clone() const {
        /* actually, there is only one line here */
    }

};

#endif
