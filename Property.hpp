//
//  Property.hpp
//  Finance
//
//  Created by Bikramjeet Singh on 6/12/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef Property_hpp
#define Property_hpp

#include <string>

using namespace std;

template <class Name = string, class Type = double>
class Property {
    Name nam;
    Type con;
    
    Property<Name, Type>& operator = (const Property<Name, Type>& source);
    
public:
    Property();
    Property(const Name& name);
    Property(const Type& t);
    Property(const Name& name, const Type& t);
    Property(const Property<Name, Type>& source);
    
    virtual ~Property();
    // Accessing function operators
    virtual Type operator()() const;
    virtual void operator()(const Type& t);
    virtual Name name() const;
    virtual void name(const Name& new_name);
    bool operator == (const Property<Name, Type>& prop2);
};
#endif /* Property_hpp */
