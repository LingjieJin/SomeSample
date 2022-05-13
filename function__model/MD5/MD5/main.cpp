//
//  main.cpp
//  test
//
//  Created by kIng_martin on 2019/7/12.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include <iostream>
#include "md5.h"


int main(int argc, const char * argv[])
{
    // insert code here...
    string filename = "filename";
    MD5 md5;
    string ret = md5.getVerifyCode(filename);
    printf("%s\n",ret.c_str());    
    //
    return 0;
}
