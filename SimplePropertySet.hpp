//
//  SimplePropertySet.hpp
//  Finance
//
//  Created by Bikramjeet Singh on 6/12/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef SimplePropertySet_hpp
#define SimplePropertySet_hpp

#include "Property.cpp"
#include <set>
#include <list>
#include <iostream>

using namespace std;

template <class N, class V>
class SimplePropertySet {
    N nam;
    
    list<Property<N,V> > sl;
    
public:
    typedef typename list<Property<N,V> >::iterator iterator;
    typedef typename list<Property<N,V> >::const_iterator const_iterator;
    
    SimplePropertySet(); // Default constructor
    SimplePropertySet(const N& name); // Named property set
    SimplePropertySet(const SimplePropertySet<N,V>& source);
    virtual ~SimplePropertySet();
    
    
    iterator Begin(); // Return iterator at begin of composite
    const_iterator Begin() const; // Return const iterator
    iterator End(); // Return iterator after end
    const_iterator End() const; // Return const iterator after end
    
    int Count() const; // The number of properties in the list
    N operator ()() const; // The name of the property set
    bool hasProperty(const N& search_name) const; // In list?
    
    void operator () (const N& name); // Change the name of PSet
    Property<N,V> value(const N& name) const; // Get the Property
    
    // Add and remove functions (sort of mixin or embedded
    // inheritance)
    void add(const Property<N,V>& p);
    void add(const SimplePropertySet<N,V>& p);
    void remove(const N& value); // Remove all elements with 'value'
    
    // Operators
    SimplePropertySet<N,V>& operator = (const SimplePropertySet<N,V>& source);
};

#endif /* SimplePropertySet_hpp */
