//
//  main.cpp
//  curl_download
//
//  Created by kIng_martin on 2019/7/12.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include <iostream>
#include "curl_myhttp.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    char* url = "http://localhost/test_download/test.cpp";
    char* save = "/Users/king_martin/Desktop/new";
    //
    curlDownload c_download;
    c_download.download(url, save);
    //
    
    //
    return 0;
}
