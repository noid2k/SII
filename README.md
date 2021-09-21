# SII
Welcome to Stock_Index_Identificator_How_To

To set up the program on cluster you need to type next

g++ *file_name*.cpp for each cpp file
 
-lcurl //the most important part for it to work on cluster


After launching the program you will get the main menu

Main Menu
1.Add|Delete following companies
2.Print followed companies
3.Set the refresh rate
4.Watch Screen Mode
5.Exit

Option 1 in Main Menu - here you can manage companies which you want to follow and get the stock prices for

After pressing option 1 you will get to the selection menu whether you want to follow/unfollow a company

Select the option
1.Add companies to follow
2.Clear followed companies
3.Go back

Option 1 let's you to follow your favourite companies, you should type a ticker of a company such as "appl" for Apple or "amd" for Advanced Micro Devices (AMD).

if you have provided wrong ticker - don't worry. You can use Option 2 to clear the list of followed companies. 

Option 3 let's you return to the main menu.

Option 2 in Main Menu allows you print the list of followed companies.

Option 3 in Main Menu allows you to set the most favourable Refresh Rate for Watch Screen Mode. This means that if you type in 15 then in Watch Screen Mode you will get updates on following companies every 15 seconds. 

!!!IMPORTANT!!! the allowed range of Refresh Rate is from 5 to 60 seconds in case of DDos protection occurance.

Option 4 in Main Menu is Watch Screen Mode. Here you will get an actual data on the selected followed companies with the Refresh Rate you have provided previously(standart refresh rate is 15 second). After entering you won't be able to return to main menu but the followed companies are save in txt file so you don't need to fill the information again.

Option 5 in Main Menu exits the program.






