#ifndef SVGPATH_H
#define SVGPATH_H

#include <sstream>
#include "SVGElement.h"
#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"

class SVGPath: public SVGElement, public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransform {//本宝宝写的 
    std::ostringstream dss;
public:
    /* need a `constructor(id)` here */

    /* you'll also need a copy constructor here,
       since std::ostringstream is not copyable */

    SVGPath& moveToAbs(const double x, const double y) {
        dss << "M " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& moveTo(const double dx, const double dy) {
        dss << "m " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& lineToAbs(const double x, const double y) {
        dss << "L " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& lineTo(const double dx, const double dy) {
        dss << "l " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& vLineAbs(const double x) {
        dss << "V " << x << std::endl;
        return *this;
    }
    SVGPath& vLine(const double dx) {
        dss << "v " << dx << std::endl;
        return *this;
    }
    SVGPath& hLineAbs(const double y) {
        dss << "H " << y << std::endl;
        return *this;
    }
    SVGPath& hLine(const double dy) {
        dss << "h " << dy << std::endl;
        return *this;
    }
    SVGPath& cubicBezierAbs(const double x1, const double y1, const double x2, const double y2, const double x, const double y) {
        dss << "C " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& cubicBezier(const double dx1, const double dy1, const double dx2, const double dy2, const double dx, const double dy) {
        dss << "c " << dx1 << " " << dy1 << " " << dx2 << " " << dy2 << " " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& stringCubicBezierAbs(const double x2, const double y2, const double x, const double y) {
        dss << "S " << x2 << " " << y2 << " " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& stringCubicBezier(const double dx2, const double dy2, const double dx, const double dy) {
        dss << "s " << dx2 << " " << dy2 << " " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& quadBezierAbs(const double x1, const double y1, const double x, const double y) {
        dss << "Q " << x1 << " " << y1 << " " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& quadBezier(const double dx1, const double dy1, const double dx, const double dy) {
        dss << "q " << dx1 << " " << dy1 << " " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& stringQuadBezierAbs(const double x, const double y) {
        dss << "T " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& stringQuadBezier(const double dx, const double dy) {
        dss << "t " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& arcToAbs(const double rx, const double ry, const double xAxisRotate, const int LargeArcFlag, const int SweepFlag, const double x, const double y) {
        dss << "A " << rx << " " << ry << " " << xAxisRotate << " " << LargeArcFlag << " " << SweepFlag << " " << x << " " << y << std::endl;
        return *this;
    }
    SVGPath& arcTo(const double rx, const double ry, const double xAxisRotate, const int LargeArcFlag, const int SweepFlag, const double dx, const double dy) {
        dss << "a " << rx << " " << ry << " " << xAxisRotate << " " << LargeArcFlag << " " << SweepFlag << " " << dx << " " << dy << std::endl;
        return *this;
    }
    SVGPath& closePath() {
        dss << "z" << std::endl;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        SVGBase::print_attr(out, "d", d.str());
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
