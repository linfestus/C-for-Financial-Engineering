//
//  Property.cpp
//  Finance
//
//  Created by Bikramjeet Singh on 6/12/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "Property.hpp"
#include <iostream>


template <class Name, class Type>
Property<Name,Type>:: Property() {
    nam = Name();
    con = Type();
}

template <class Name, class Type>
Property<Name,Type>:: Property(const Name& name) {
    nam = name;
    con = Type();
}

template <class Name, class Type>
Property<Name,Type>:: Property(const Type& t) {
    nam = Name();
    con = t;
}

template <class Name, class Type>
Property<Name,Type>:: Property(const Name& name, const Type& t) {
    nam = name;
    con = t;
}

template <class Name, class Type>
Property<Name,Type>:: Property(const Property<Name,Type>& source) {
    nam = source.nam;
    con = source.con;
}

template <class Name, class Type>
Property< Name,  Type>::~Property()
{// Destructor
    
}

template <class Name, class Type>
Property< Name,  Type>& Property<Name, Type>::operator=(const Property<Name, Type> &source)
{
    if(*this == source)
        return *this;
    else{
        nam = source.nam;
        con = source.con;
    }
    return *this;
}

template <class Name, class Type>
Type Property<Name, Type>::operator ()() const {
    
    return con;
    
}

template <class Name, class Type>
void Property<Name, Type>::operator ()(const Type& t) {
    
    con = t;
    
}

template <class Name, class Type>
Name Property<Name, Type>::name () const {
    
    return nam;
    
}

template <class Name, class Type>
void Property<Name, Type>::name (const Name& name) {
    
    nam = name;
    
}

template <class Name, class Type>
bool Property<Name, Type>::operator==(const Property<Name, Type> &prop2) {
    
    if(nam!=prop2.name())
        return false;
    if(con!=prop2.con)
        return false;
    return true;
    
}

