#ifndef SVGROOT_H
#define SVGROOT_H

#include "SVGContainerElement.h"

class SVGRoot: public SVGContainerElement { //������д�� 
    double width, height;

protected:
    virtual SVGElement* clone() const {
        return new SVGRoot(*this);//������д�� 
    }

    virtual SVGContainerElement* clone_as_container() const {
        return (SVGContainerElement*)this;//������д��
    }

public:
    SVGRoot(const std::string& id_): SVGContainerElement("svg", id_) {} ; //������д��
    
    SVGRoot(): SVGContainerElement("svg", "") {} ; //������д��

	SVGRoot(const SVGRoot& root_): SVGContainerElement(root_) {
		width = root_.width;
		height = root_.height;
		clone_body_from(root_);
	} //������д�� 

    SVGRoot& setSize(const double w, const double h) {
        width = w;
        height = h;
        return *this;
    }

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        SVGBase::print_attr(out, "version", 1.1);
        SVGBase::print_attr(out, "baseProfile", "full");
        SVGBase::print_attr(out, "xmlns", "http://www.w3.org/2000/svg");
        SVGBase::print_attr(out, "width", width);
        SVGBase::print_attr(out, "height", height);
        out << ">" << std::endl; // close the opening tag
        print_body(out);
        print_tag_close(out);
        return out;
    }//������д�� 
};

#endif
