#ifndef SVGGROUP_H
#define SVGGROUP_H

#include "SVGStyleFill.h"
#include "SVGStyleStroke.h"
#include "SVGStyleTransform.h"
#include "SVGContainerElement.h"

class SVGGroup /* need some base classes here */ {
protected:
    virtual SVGElement* clone() const {
        /* actually, there is only one line here */
    }

    virtual SVGContainerElement* clone_as_container() const {
        /* think about what's the difference to `clone()`? */
    }

public:
    /* need a `constructor(id)` here */

    /* need a copy constructor here.
       remember to copy base.
       use `clone_body_from` to copy body */

    virtual std::ostream& print(std::ostream& out) const {
        print_tag_start(out);
        /* call `print_style` to print styles */
        out << ">" << std::endl; // close the opening tag
        /* call `print_body` to print elements inside the container */
        print_tag_close(out);
        return out;
    }
};

#endif
