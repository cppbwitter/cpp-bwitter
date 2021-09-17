/*
    cpp_bwitter: a program to post to the website bwitter.me
    Copyright (C) 2021  Ian Hiew and associates

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <iostream>
#include <curl/curl.h>
#include <cstdlib>
#include <string>

// include the config file
#include "configs.cpp"

// std::string server_link = "https://cleantalk.cf/bwitter/response.php?page=1";

//init curl handle :vomit:
/*int initCurl(void){
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl,CURLOPT_URL,"https://bwitter.me/");
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            std::cout << "Hello error with curl" << std::endl;
        }
    }
    curl_easy_cleanup(curl);
    return 0;
}
*/
int post(std::string username,std::string password,std::string postdata){
    std::string loginfields = "username_or_email=" + username + "&password=" + password + "&commit";
    std::cout << loginfields << std::endl;
    std::string postfields = "content=" + postdata;
    std::cout << postfields << std::endl;
    std::string cookiefile = "sessions.txt";
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl){
        //login
        curl_easy_setopt(curl,CURLOPT_URL,"https://bwitter.me/sessions");
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,loginfields.c_str());
        
        // Save cookies from *this* session in MyCookieFileName
        curl_easy_setopt( curl, CURLOPT_COOKIEJAR, cookiefile.c_str() );
        curl_easy_setopt(curl, CURLOPT_POST, 1L);


        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            std::cout << "Error logging in. Wrong password?";
        }
        else{
            //now post
            // Read cookies from a previous session, as stored in MyCookieFileName.
            curl_easy_setopt( curl, CURLOPT_COOKIEFILE, cookiefile.c_str() );
            std::cout << "Logged in " << std::endl;
            curl_easy_setopt(curl,CURLOPT_URL,"https://bwitter.me/bweet");
            curl_easy_setopt(curl,CURLOPT_POSTFIELDS,postfields.c_str());
            res = curl_easy_perform(curl);
            if(res != CURLE_OK){
                std::cout << postfields << " has been posted!" << std::endl;
                return 0;
            }
        }
    }
}
int main(void){
    post(c_username,c_password,c_postcontent);
    return 0;
}