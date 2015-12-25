#ifndef SVGELLIPSE_H
#define SVGELLIPSE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGEllipse: public SVGElement, public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransform {//������д�� 
    double cx, cy, rx, ry;
public:
    SVGEllipse(const std::string& id_): SVGElement(ellipse, id_), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {
		cx = 0;
		cy = 0;
		rx = 0;
		ry = 0;
	} //������д�� 

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
        SVGBase::print_attr(out, "cx", cx);
        SVGBase::print_attr(out, "cy", cy);
        SVGBase::print_attr(out, "rx", rx);
        SVGBase::print_attr(out, "ry", ry);
        SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        print_tag_close(out);
        return out;
    }//������д�� 

protected:
    virtual SVGElement* clone() const {
        /* actually, there is only one line here */
    }

};

#endif
