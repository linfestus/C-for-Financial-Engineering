//
//  EuropeanOption.hpp
//
//  Created by Bikramjeet Singh on 5/31/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp

#include <string>

using namespace std;

class EuropeanOption{
public:
    double interestRate; // interest rate
    double sigma; //volatility
    double strikePrice; //strike price
    double time; //Time to maturity
    double spotPrice; // Spot price
    double costOfCarry; // Cost of carry
    
    string optType;
    
    EuropeanOption();
    EuropeanOption( const EuropeanOption& option2);
    EuropeanOption(const string& optionType);
    
    virtual ~EuropeanOption();
    
    EuropeanOption& operator = (const EuropeanOption& option2);
    
    double Price() const;
    double Delta() const;
    
    void toggle(); // Change option type (C/P, P/C)
    
    
    
    
private:
    
    void init();
    void copy(const EuropeanOption& o2);
    
    double callPrice() const;
    double putPrice() const;
    double callDelta() const;
    double putDelta() const;
    
   
    
    
};
