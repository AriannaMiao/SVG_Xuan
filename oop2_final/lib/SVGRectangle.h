#ifndef SVGRECTANGLE_H
#define SVGRECTANGLE_H

#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGStyleTransform.h"
#include "SVGContainerElement.h"

class SVGRectangle: public SVGElement, public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransform { //本宝宝写的 
    double x, y, width, height, rx, ry;
public:
	SVGRectangle(const std::string& id_): SVGElement("rect", id_), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		rx = 0;
		ry = 0;
	} //本宝宝写的 
	
	SVGRectangle(): SVGElement("rect", ""), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		rx = 0;
		ry = 0;
	} //本宝宝写的 
			
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
        SVGBase::print_attr(out, "x", x);
        SVGBase::print_attr(out, "y", y);
        SVGBase::print_attr(out, "rx", rx);
        SVGBase::print_attr(out, "ry", ry);
        SVGBase::print_attr(out, "width", width);
        SVGBase::print_attr(out, "height", height);
        SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        print_tag_close(out);
        return out;
    } //本宝宝写的 

protected:
    virtual SVGElement* clone() const {
    	return new SVGRectangle(*this);//本宝宝写的 
    }

};

#endif

