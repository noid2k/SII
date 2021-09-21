//
//  customer.h
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 23.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#ifndef customer_h
#define customer_h
#include <iostream>
#include <vector>


class customer{
public:
    customer();
    void SetRefreshRate();
    int GetRefreshRate();
    void SetCompaniesToFollow();
    void AddCompaniesToFollow();
    void DeleteCompaniesToFollow();
    bool IsFull();
    void PrintFollowed();
    void AddSize();
    int GetSize();
    void SetSize(int i);
    void AddCompany(std::string company);
    std::string GetCompany(int i);
    friend customer oldData(customer temp);
    
private:
    int RefreshRate;
    int Size;
   
    std::vector <std::string> FollowedCompanies;

};

#endif /* customer_h */
