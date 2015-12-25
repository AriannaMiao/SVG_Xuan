#ifndef SVGELEMENT_H
#define SVGELEMENT_H

#include "SVGBase.h"

class SVGElement: public SVGBase {
    friend inline std::ostream& operator<<(std::ostream& out, const SVGElement& elm) {
        /* DRY, don't repeat yourself (1 line) */
    }

protected:
    std::string tag;
    std::string id;

    SVGElement(const std::string& tag_, const std::string& id_)
        : SVGBase(), tag(tag_), id(id_) {}

    virtual std::ostream& print_tag_start(std::ostream& out) const {
        out << "<" << tag;
        SVGBase::print_attr(out, "id", id);
        return out;
    }

    virtual std::ostream& print_tag_close(std::ostream& out) const {
        out << " />" << std::endl;
        return out;
    }

public:
    const std::string& getID() const { return id; }
    const std::string& getTag() const { return tag; }

    /* need a pure virtual function `ostream& print(ostream&) const` */

    virtual SVGElement* clone() const = 0;

    virtual ~SVGElement() {}
};

#endif
