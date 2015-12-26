#ifndef SVGGROUP_H
#define SVGGROUP_H

#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGStyleTransform.h"
#include "SVGContainerElement.h"

class SVGGroup: public SVGContainerElement,public SVGStyleFill, public SVGStyleStroke, public SVGStyleTransform { //本宝宝写的 
protected:
    virtual SVGElement* clone() const {
        return new SVGGroup(*this);//本宝宝写的 
    }

    virtual SVGContainerElement* clone_as_container() const {
		return (SVGContainerElement*)this;		
    }

public:
    SVGGroup(const std::string& id_): SVGContainerElement("g", id_), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {} ; //本宝宝写的
    
    SVGGroup(): SVGContainerElement("g", ""), SVGStyleFill(), SVGStyleStroke(), SVGStyleTransform() {} ; //本宝宝写的

	SVGGroup(const SVGGroup& group_): SVGContainerElement(group_), SVGStyleFill(group_), SVGStyleStroke(group_), SVGStyleTransform(group_) {
		clone_body_from(group_);
	} //本宝宝写的 

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        SVGStyleFill::print_style(out);
		SVGStyleStroke::print_style(out);
		SVGStyleTransform::print_style(out);
        out << ">" << std::endl; // close the opening tag
        print_body(out);
        print_tag_close(out);
        return out;
    }//本宝宝写的 
};

#endif
