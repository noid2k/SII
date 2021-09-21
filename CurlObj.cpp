//
//  curl.cpp
//  Stock_Index_Identificator
//
//  Created by Aleksei Khvorostov on 23.04.2021.
//  Copyright © 2021 Aleksei Khvorostov. All rights reserved.
//

#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "CurlObj.h"

CurlObj::CurlObj (){
    
}
CurlObj::CurlObj (std::string url) {
    curl = curl_easy_init();
    if (!curl) {
        throw std::string ("Curl did not initialize.");
    }
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_perform(curl);
    }
    
    int CurlObj::curlWriter(char *data, int size, int nmemb, std::string *buffer) {
        int result = 0;
        if (buffer != NULL) {
            buffer->append(data, size * nmemb);
            result = size * nmemb;
        }
        
        return result;
    }
    
    std::string CurlObj::getStockData() {
        return curlBuffer;
    }
    
