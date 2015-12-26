#ifndef SVGCONTAINERELEMENT_H
#define SVGCONTAINERELEMENT_H

#include <map>
#include <list>
#include "SVGElement.h"

class SVGContainerElement: public SVGElement {//������д�� 
    typedef std::list<SVGElement*> ElementList;
    typedef std::map<std::string, ElementList::iterator> IDMap;
    typedef std::list<SVGContainerElement*> CElementList;
    typedef std::map<std::string, CElementList::iterator> CIDMap;
    ElementList elements;
    IDMap id2elm; // id -> element
    CElementList celements;
    CIDMap cid2elm; // id -> container element

protected:
    SVGContainerElement(const std::string& tag_, const std::string& id_): SVGElement(tag_, id_) {} ; //������д�� 

    std::ostream& print_body(std::ostream& out) const {
        ElementList::const_iterator ei = elements.begin();
        ElementList::const_iterator ee = elements.end();
        CElementList::const_iterator ci = celements.begin();
        CElementList::const_iterator ce = celements.end();
        for (; ei != ee; ++ei) {
            if (ci == ce || *ei != *ci) {
            	SVGElement* e0 = *ei;
                e0->print(out);
            } else {
            	SVGContainerElement* c0 = *ci;
                c0->print(out);
                ++ci;
            }
        }
        return out;
    }//������д�� 

	/* call `add` to clone body from `from` */
    void clone_body_from(const SVGContainerElement& from) {
        ElementList::const_iterator ei = from.elements.begin();
        ElementList::const_iterator ee = from.elements.end();
        CElementList::const_iterator ci = from.celements.begin();
        CElementList::const_iterator ce = from.celements.end();
        for (; ei != ee; ++ei) {
            if (ci == ce || *ei != *ci) {
            	SVGElement* e0 = *ei;
                add(*e0);
            } else {
            	SVGContainerElement* c0 = *ci;
                add(*c0);
                ++ci;
            }//������д�� 
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
		add_element(elm.clone()); 
    }//������д�� 

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
        SVGElement* iter1 = *iter->second; 
        delete iter1->clone();
        elements.erase(iter->second);
        id2elm.erase(iter);
		//������д�� 
        CIDMap::iterator iter2 = cid2elm.find(id);
        if (iter2 != cid2elm.end()) {
            celements.erase(iter2->second);
            cid2elm.erase(iter2);
        }
    }

    virtual SVGContainerElement* clone_as_container() const = 0;

    virtual ~SVGContainerElement() {
    	ElementList::const_iterator ei = elements.begin();
        ElementList::const_iterator ee = elements.end();
        CElementList::const_iterator ci = celements.begin();
        CElementList::const_iterator ce = celements.end();
        for (; ei != ee; ++ei) {
 			if (ci == ce || *ei != *ci) {
            	SVGElement* e0 = *ei;
                delete e0->clone();
            } else { 
                ++ci;
            }
        }
        elements.erase(elements.begin(), elements.end());
        id2elm.erase(id2elm.begin(), id2elm.end());
        celements.erase(celements.begin(), celements.end());
        cid2elm.erase(cid2elm.begin(), cid2elm.end());
    }//������д�� 
};

#endif

