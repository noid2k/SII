//
//  company.h
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 23.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#ifndef company_h
#define company_h
#include <string>
#include "customer.h"
#include "CurlObj.h"


class company : public customer, public CurlObj
{
public:
    
    company();
    company(double Price);
    company(customer temp);
    void SetStockName(std::string name);
    std::string GetStockName();
    void SetStockPrice(double price);
    double GetStockPrice();
    void WatchScreen();
    void fillPrice(std::string name, std::string html);
    char compare(company current, company old);
    bool operator== (const company & other);
    bool operator> (const company & other);
    bool operator< (const company & other);


private:
    static std::string constUrl;
    std::string StockName;
    double StockPrice;

};

#endif /* company_h */
