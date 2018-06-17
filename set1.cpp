//
//
//Creating sets. Simple functions for starters.
//
// 1. Create sets with string elements
// 2. Compare sets with '==' operator
// 3. Swap two sets using the swap() function
// 4. Assigning sets to each other
//  Created by Bikramjeet Singh on 6/8/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include <set>
#include <iostream>
#include <string>

using namespace std;

template <class T> void print(const set<T> &mySet, const string& name) {
    typename set<T>::const_iterator i;
    for(i = mySet.begin();i!=mySet.end();i++)
        cout<<endl<<(*i);
    
}

int chp4set1(){
    set<string> first;
    
    first.insert("r");
    first.insert("T");
    first.insert("sigma");
    
    cout<<"First Size:" << first.size()<<endl;
    
    set<string> second(first);
    
    second.insert("r");
    second.insert("K");
    second.insert("S");
    second.insert("b");
    
    cout<<"Second Size:"<<second.size()<<endl;
    
    if(first==second)
        cout<<"Sets have same elements"<<endl;
    else
        cout<<"Not same elements \n";
    
    swap(first, second);
    
    set<string> third = first;
    
    print(first, "First set");
    print(second, "Second set");
    print(third, "Third set");
    
    // Now create a set representing Executive options
    set<string> execOption(first);
    execOption.insert("lambda"); // The jump rate, see Haug (1998)
    print(execOption, "An Executive Option");
    
    return 0;
}

int intersection(){
    set<int> firstSet;
    
    firstSet.insert(1);
    firstSet.insert(2);
    firstSet.insert(3);
    
    print(firstSet, "First Set");
    
    set<int> secondSet(firstSet);
    
    secondSet.erase(3);
    secondSet.insert(999);
    
    print(secondSet, "Second Set");
    
    set<int> myIntersect;
    set<int>::iterator i =myIntersect.begin();
    
    insert_iterator<set<int> > insertIter(myIntersect,i);
    
    set_intersection(firstSet.begin(), firstSet.end(), secondSet.begin(), secondSet.end(), insertIter);
    
    print(myIntersect, "Intersection");
    
    return 0;
    
    
    
    
}
