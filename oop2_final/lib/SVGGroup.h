#ifndef SVGGROUP_H
#define SVGGROUP_H

#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGStyleTransform.h"
#include "SVGContainerElement.h"

class SVGGroup: public SVGContainerElement,public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransform { //������д�� 
protected:
    virtual SVGElement* clone() const {
        return new SVGGroup(*this);//������д�� 
    }

    virtual SVGContainerElement* clone_as_container() const {
		return (SVGContainerElement*)this;		
    }

public:
    SVGGroup(const std::string& id_): SVGContainerElement("g", id_), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {} ; //������д��
    
    SVGGroup(): SVGContainerElement("g", ""), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {} ; //������д��

	SVGGroup(const SVGGroup& group_): SVGContainerElement(group_), SVGStyleFill(group_), SVGStyleStroke(group_), SVGStyleTransform(group_) {
		clone_body_from(group_);
	} //������д�� 

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        out << ">" << std::endl; // close the opening tag
        print_body(out);
        print_tag_close(out);
        return out;
    }//������д�� 
};

#endif
