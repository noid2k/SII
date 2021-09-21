//
//  CurlObj.h
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 25.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#ifndef CurlObj_h
#define CurlObj_h

#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

class CurlObj {
public:
    CurlObj ();
    CurlObj (std::string url);
    static int curlWriter(char *data, int size, int nmemb, std::string *buffer);
    std::string getStockData();
    
protected:
    CURL * curl;
    std::string curlBuffer;
};
#endif /* CurlObj_h */
