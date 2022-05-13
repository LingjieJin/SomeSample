//
//  SystemEnvironment.cpp
//  test_bigorsmall
//
//  Created by kIng_martin on 2019/8/2.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include "SystemEnvironment.hpp"


bool isSmallIndain()
{
    unsigned int val = 'A';
    unsigned char* p = (unsigned char*)&val;
        //C/C++：对于多字节数据，取地址是取的数据对象的第一个字节的地址，也就是数据的低地址
    
    return *p == 'A';
}
