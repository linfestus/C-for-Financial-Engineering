//
//  SimplePropertySet.cpp
//  Finance
//
//  Created by Bikramjeet Singh on 6/12/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "SimplePropertySet.hpp"

template <class N,class V>
SimplePropertySet<N, V>::SimplePropertySet() {
    nam = N();
    sl = list<Property<N,V> >();
}

template <class N,class V>
SimplePropertySet<N, V>::SimplePropertySet(const N& name) {
    nam = name;
    sl = list<Property<N,V> >();
}

template <class N,class V>
SimplePropertySet<N, V>::SimplePropertySet(const SimplePropertySet<N,V>& source) {
    nam = source.nam;
    sl = source.sl;
}

template <class N, class V>
SimplePropertySet<N,V>::~SimplePropertySet()
{ // Destructor
    
}

template <class N, class V>
typename SimplePropertySet<N,V>::iterator SimplePropertySet::begin() {
    return sl.begin();
}

template <class N, class V>
typename SimplePropertySet<N,V>::const_iterator SimplePropertySet::begin() {
    return sl.begin();
}

template <class N, class V>
typename SimplePropertySet<N,V>::iterator SimplePropertySet::end() {
    return sl.end();
}

template <class N, class V>
typename SimplePropertySet<N,V>::const_iterator SimplePropertySet::end() {
    return sl.end();
}

template <class N, class V>
int SimplePropertySet::Count() {
    return sl.size();
}

template <class N, class V>
N SimplePropertySet::operator()() {
    return nam;
}

template <class N, class V>
bool SimplePropertySet::hasProperty(const N& search_name) {
    const_iterator it;
    
    for (it=sl.begin(); it!=sl.end(); it++)
    {
        
        if ((*it).name() == search_name)
        {
            return true;
        }
    }
    
    return false;
}

template <class N, class V>
void SimplePropertySet::operator()(const N& name) {
    nam = name;
}

template <class N, class V>
Property<N,V> SimplePropertySet::value(const N&name) {
    const_iterator it;
    
    for (it=sl.begin(); it!=sl.end(); it++)
    {
        
        if ((*it).name() == name)
        {
            return (*it);
        }
    }
    
}

template <class N, class V>
void SimplePropertySet::add(const Property<N,V>& p) {
    sl.push_back(p);
    
}

template <class N, class V>
void SimplePropertySet<N,V>::add(const SimplePropertySet<N,V>& ps)
{ // Add a property set to the list
    
    
    const_iterator it;
    
    for (it=ps.sl.begin(); it!=ps.sl.end(); it++)
    {
        
        add((*it));
    }
    
}

template <class N, class V>
void SimplePropertySet<N,V>::remove(const N& value)
{ // Remove all elements with 'value' O(N)
    
    // We iterate over the list until we find the value
    iterator it;
    
    for (it=sl.begin(); it!=sl.end(); it++)
    {
        
        if ((*it)() == value)
        {
            erase(it);
        }
    }
    
}

template <class N, class V>
SimplePropertySet<N,V>& SimplePropertySet<N,V>::operator = (const SimplePropertySet<N,V>& source)
{ // Assignment
    
    // Exit if same object
    if (this==&source) return *this;
    
    
    nam = source.nam;
    
    sl = source.sl;
    
    return *this;
}


