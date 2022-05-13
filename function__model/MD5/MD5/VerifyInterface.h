//
//  VerifyInterface.h
//  test
//
//  Created by kIng_martin on 2019/7/12.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#ifndef VerifyInterface_h
#define VerifyInterface_h

#include <iostream>

using namespace std;

class VerifyInterface
{
public:
    virtual string getVerifyCode(string &file) = 0;
};

#endif /* VerifyInterface_h */
