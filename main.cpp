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

// include the config file and subsequent modules
#include "configs.cpp"
#include "post.cpp"


int main(void){
    std::string postcontent;
    std::cout << "Enter post content: ";
    std::getline(std::cin , postcontent);
    post(G_USERNAME,G_PASSWORD,postcontent);
    return 0;
}
