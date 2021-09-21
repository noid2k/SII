//
//  customer.c
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 23.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "customer.h"
#include "company.h"


customer:: customer(){
        this->Size=0;
        RefreshRate = 10;
        FollowedCompanies.clear();

}

void customer::SetSize(int i){
    Size=i;
}
void customer::SetRefreshRate(){
    std::cout<<"Provide how often do you want the 'Watch screen' tool to update (in seconds)\n";
    std::cout<<"Please note that the refresh rate can not be less than 5 seconds and larger than 60 seconds\n";
    while (1)
    {
        int seconds;
        while(!(std::cin>>seconds)) {
            // Cleanup the stream state
            std::cin.clear();
            std::string dummy;
            std::cin >> dummy; // Consume the invalid input
            std::cout << "Provide the number between 5 and 60\n" << std::endl;
        }
        try{
            if(seconds<5||seconds>60)
                throw "Provide the number between 5 and 60\n";
            RefreshRate=seconds;
            std::cout<<"Refresh rate has been set successfully\n";
            return;
        }
        catch (const char* exception){
            std::cout <<"Error: " << exception<<std::endl;
            continue;
        }
    }
}

int customer::GetRefreshRate(){
    return RefreshRate;
}

void customer::SetCompaniesToFollow()
{
    while (1)
    {
        std::cout<<"\nSelect the option\n";
        std::cout<<"1.Add companies to follow\n";
        std::cout<<"2.Clear followed companies\n";
        std::cout<<"3.Go back\n\n";
        int option;
        
        while(!(std::cin>>option)) {
            // Cleanup the stream state
            std::cin.clear();
            std::string dummy;
            std::cin >> dummy; // Consume the invalid input
            std::cout << "Please provide appropriate command\n\n" << std::endl;
        }
        
        
        switch (option)
        {
            case 1:
                AddCompaniesToFollow();
                break;
            case 2:
                DeleteCompaniesToFollow();
                break;
            case 3:
                return;
            default:
                std::cout<<"Please provide appropriate command\n\n";
                break;
        }
    }
}
void customer::AddCompany(std::string company)
{
    FollowedCompanies.push_back(company);
}

void customer::AddCompaniesToFollow()
{
    std::ofstream myFile("StockNames.txt");
    std::cout<<"Enter a ticker of a company or type x to exit the tool\n";
    std::string company;
    

    while (1)
    try {
        std::cin>>company;
        if(IsFull())
            throw "You can't add more companies than 5. Try delete companies tool and try again\n";
        else if(company=="x")
        {
            myFile.close();
            return;
        }
        
        FollowedCompanies.push_back(company);
        if(myFile.is_open())
        {
            std::string str;
            myFile<<company<< std::endl;
     
        }
        else std::cerr<<"Unable to open file";
        AddSize();
    }
    catch (const char* exception)
    {
        std::cout <<"Error: " << exception<<std::endl;
        myFile.close();
        return;
    }
    
}
void customer::DeleteCompaniesToFollow()
{
    std::ofstream MyFile;
    MyFile.open("StockNames.txt", std::ofstream::out | std::ofstream::trunc);
    MyFile.close();

    FollowedCompanies.clear();
    this->Size = 0;
}

bool customer::IsFull()
{
    return (this->Size == 5) ? true : false;
}

void customer::PrintFollowed()
{
    std::cout<<"You are following these companies\n";
    if(this->Size!=0)
        for(int i = 0; i < this->Size; ++i)
            std::cout<<this->FollowedCompanies[i]<<std::endl;
    else
        std::cout<<'\n'<<"You are not following any company.\nUse 'Add companies to follow' tool\n";
    while (std::cin.get() != 'x')
        std::cout << '\n' << "Press an 'x' to continue...\n";
    
}
std::string customer::GetCompany(int i)
{
    return FollowedCompanies[i];
}

void customer::AddSize()
{
    if (this->Size>5)
        return;
    Size++;
}

int customer::GetSize()
{
    return Size;
}
