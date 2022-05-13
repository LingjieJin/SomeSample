//
//  main.cpp
//  test_bigorsmall
//
//  Created by kIng_martin on 2019/8/2.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#include <iostream>
#include "SystemEnvironment.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    if (isSmallIndain())
    {
        printf("small.\n");
    }
    else
    {
        printf("big.\n");
    }
    return 0;
}
