//
//  main.cpp
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 21.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//



#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include "company.h"
#include "CurlObj.h"

customer oldData(customer temp){
    
    std::ifstream myFile;
    myFile.open("StockNames.txt");
    std::string line;
    std::cout <<"According to our data you already have some followed companies\n";
    while (std::getline(myFile, line))
    {
        temp.AddSize();
        temp.AddCompany(line);
    }
    myFile.close();
    return temp;
}

int main()
{
    
    std::cout<<"Welcome to the Stock Index Identificator\n";
    customer temp;
    company watch(oldData(temp));
    

    int option;
    
    while (1)
    {
        std::cout<<"\nMain Menu\n";
        std::cout<<"1.Add|Delete following companies\n";
        std::cout<<"2.Print followed companies\n";
        std::cout<<"3.Set the refresh rate\n";
        std::cout<<"4.Watch Screen Mode\n";
        std::cout<<"5.Exit\n\n";
    

        std::cin>>option;
    
        switch (option) {
            case 1:
                watch.SetCompaniesToFollow();
                break;
            case 2:
                watch.PrintFollowed();
                break;
            case 3:
                watch.SetRefreshRate();
                break;
            case 4:
                watch.WatchScreen();
                break;
            case 5:
                return 0;

        }
    }
    
}
