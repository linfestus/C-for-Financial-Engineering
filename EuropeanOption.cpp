//
//  EuropeanOption.cpp
//
//  Created by Bikramjeet Singh on 5/31/18.
//  Copyright © 2018 Bikramjeet Singh. All rights reserved.
//

#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>

using namespace std;

//IMPORTANT
double norm(double x) // Phi(-∞, x) aka N(x)
{
    return erfc(-x/sqrt(2))/2;
}

double EuropeanOption::callPrice() const{
  
    double temp = sigma*sqrt(time);
    
    double d1 = (log(double(spotPrice)/strikePrice) +(costOfCarry + (sigma*sigma * 0.5))* time)/ temp;
    double d2= d1- temp;
    
 
    return (spotPrice*exp((costOfCarry-interestRate)*time)*norm(d1)) - (strikePrice* exp(-interestRate*time) *norm(d2));
    
}

double EuropeanOption::putPrice() const{
    
    double temp = sigma*sqrt(time);
    
    double d1 = (log(spotPrice/strikePrice) +(costOfCarry + (sigma*sigma) * 0.5)* time)/ temp;
    double d2= d1- temp;
    
    return (strikePrice* exp(-interestRate*time) * (1-norm(d2))) - (spotPrice*exp((costOfCarry-interestRate)*time)* (1-norm(d1)));
    
}

double EuropeanOption::callDelta() const{
    
    double temp = sigma*sqrt(time);
    
    double d1 = (log(spotPrice/strikePrice) +(costOfCarry + (sigma*sigma) * 0.5)* time)/ temp;
    
    return exp((costOfCarry-interestRate)*time)*norm(d1);
    
}

double EuropeanOption::putDelta() const{
    
    double temp = sigma*sqrt(time);
    
    double d1 = (log(spotPrice/strikePrice) +(costOfCarry + (sigma*sigma) * 0.5)* time)/ temp;
    
    return exp((costOfCarry-interestRate)*time) * (norm(d1)-1);
    
}

void EuropeanOption::init()
{ // Initialise all default values
    // Default values
    interestRate = 0.08;
    sigma= 0.30;
    strikePrice = 65.0;
    time = 0.25;
    spotPrice = 60.0; // S == stock in this case
    costOfCarry = interestRate; // Black and Scholes stock option model (1973)
    optType = "C"; // European Call Option (the default type)
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
    interestRate = o2.interestRate;
    sigma = o2.sigma;
    strikePrice = o2.strikePrice;
    time = o2.time;
    spotPrice = o2.spotPrice;
    costOfCarry = o2.costOfCarry;
    optType = o2.optType;
}

EuropeanOption::EuropeanOption()
{ // Default call option
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor
    copy(o2);
}

EuropeanOption::~EuropeanOption()
{ // Destructor
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt2)
{ // Assignment operator (deep copy)
    if (this == &opt2) return *this;
    copy (opt2);
    return *this;
}

double EuropeanOption::Price() const
{
    if (optType == "C")return callPrice();
    else return putPrice();
}

double EuropeanOption::Delta() const
{
    if (optType == "C")return callDelta();
    else return putDelta();
}

// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)
    if (optType == "C")optType = "P";
    else optType = "C";
}
