#ifndef SVGCONTAINERELEMENT_H
#define SVGCONTAINERELEMENT_H

#include <map>
#include <list>
#include "SVGElement.h"

class SVGContainerElement /* need some base classes here */ {
    typedef std::list<SVGElement*> ElementList;
    typedef std::map<std::string, ElementList::iterator> IDMap;
    typedef std::list<SVGContainerElement*> CElementList;
    typedef std::map<std::string, CElementList::iterator> CIDMap;
    ElementList elements;
    IDMap id2elm; // id -> element
    CElementList celements;
    CIDMap cid2elm; // id -> container element

protected:
    /* need a `constructor(tag, id)` here */

    std::ostream& print_body(std::ostream& out) const {
        /* call `print` to print the elements inside this container */
        return out;
    }

    void clone_body_from(const SVGContainerElement& from) {
        /* call `add` to clone body from `from` */
        ElementList::const_iterator ei = from.elements.begin();
        ElementList::const_iterator ee = from.elements.end();
        CElementList::const_iterator ci = from.celements.begin();
        CElementList::const_iterator ce = from.celements.end();
        for (; ei != ee; ++ei) {
            if (ci == ce || *ei != *ci) {
                /* something here (1 line) */
            } else {
                /* something similar here (2 lines) */
            }
        }
    }

    virtual std::ostream& print_tag_close(std::ostream& out) const {
        out << "</" << tag << ">" << std::endl;
        return out;
    }

private:
    void add_element(SVGElement* e) {
        ElementList::iterator iter = elements.insert(elements.end(), e);
        const std::string id = e->getID();
        if (!id.empty()) {
            id2elm[id] = iter;
        }
    }

public:
    void add(const SVGContainerElement& elm) {
        SVGContainerElement* e = elm.clone_as_container();
        CElementList::iterator iter = celements.insert(celements.end(), e);
        if (!e->getID().empty()) {
            cid2elm[elm.getID()] = iter;
        }

        add_element(e);
    }

    void add(const SVGElement& elm) {
        /* given the above example, what should be here? (1 line) */
    }

    SVGContainerElement& findContainer(const std::string& id) {
        CIDMap::iterator iter = cid2elm.find(id);
        if (iter == cid2elm.end()) {
            throw "element not found";
        }
        return **iter->second;
    }

    void remove(const std::string& id) {
        IDMap::iterator iter = id2elm.find(id);
        if (iter == id2elm.end()) {
            throw "element not found";
        }
        /* now you need to erase the iterators (3 lines) */

        CIDMap::iterator iter2 = cid2elm.find(id);
        if (iter2 != cid2elm.end()) {
            celements.erase(iter2->second);
            cid2elm.erase(iter2);
        }
    }

    virtual SVGContainerElement* clone_as_container() const = 0;

    virtual ~SVGContainerElement() {
        /* is anything here? */
    }
};

#endif

