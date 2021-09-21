//
//  company.cpp
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 23.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>


#include "company.h"
#include "CurlObj.h"


company::company(){
    StockPrice = 0;
}

company::company(double price){
    StockPrice=price;
}

company::company(customer temp){
    SetSize(temp.GetSize());
    for(int i=0;i<GetSize();i++)
        AddCompany(temp.GetCompany(i));
    
}
std::string company::constUrl = "https://finance.yahoo.com/quote/";

void company::SetStockName(std::string name)
{
    StockName=name;
}



std::string company::GetStockName()
{
    return StockName;
}

void company::SetStockPrice(double Price)
{
    StockPrice=Price;
    
}

double company::GetStockPrice()
{
    return StockPrice;
}

void company::fillPrice(std::string name, std::string html)
{
    std::string code="";
    size_t index = html.find("Mb(-4px) D(ib)");
    code = html.substr(index+34,6);
    float temp = std::stod(code);
    SetStockPrice(temp);
}

void company::WatchScreen()
{
    company OldPrice;
    company Price;
    double tempArr[5]={};
    while(1)
    {
        std::cout<<"-----------------------------";
        for(int i=0;i<GetSize();i++)
        {

            OldPrice.SetStockPrice(tempArr[i]);
            
            std::string company = GetCompany(i);
            std::string url = constUrl+ company;
            try {
                CurlObj html(url);
                Price.fillPrice(company, html.getStockData());
            } catch (std::exception e) {
                std::cout << "\n" << company << " is not a valid ticker." << std::endl;
                continue;
            }
            std::cout<<"\n"<<GetCompany(i);
            std::cout<<std::setw(10)<< Price.GetStockPrice()<<std::setw(10)<<compare(Price, OldPrice);
            tempArr[i]=Price.GetStockPrice();

        }
        std::cout<<"\n-----------------------------\n";
        std::cout<<"\n";

        std::this_thread::sleep_for(std::chrono::seconds(GetRefreshRate()));
    }
}
char company::compare(company current, company old)
{
    if (old.GetStockPrice()==0)
        return '?';
    else if (current==old)
        return '-';
    else if (current<old)
        return 'v';
    else if (current>old)
        return '^';
    return '-';
}

bool company::operator== (const company & other)
{
    if (this->StockPrice==other.StockPrice)
        return true;
    else
        return false;
}

bool company::operator> (const company & other)
{
    if (this->StockPrice>other.StockPrice)
        return true;
    else
        return false;
}

bool company::operator< (const company & other)
{
    if (this->StockPrice<other.StockPrice)
        return true;
    else
        return false;
}

