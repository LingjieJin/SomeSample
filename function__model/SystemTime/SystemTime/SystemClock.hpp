//
//  SystemClock.hpp
//  SystemTime
//
//  Created by kIng_martin on 2019/8/1.
//  Copyright © 2019 Jin Lingjie. All rights reserved.
//

#ifndef SystemClock_hpp
#define SystemClock_hpp

#include <stdio.h>
#include <sys/time.h>

long SysGetTick();
void SysSleep(long delay_ms);
long DeltaTime(long &elapsed);

#endif /* SystemClock_hpp */
