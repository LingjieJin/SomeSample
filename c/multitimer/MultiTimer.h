#ifndef __MULTITIMER_H__
#define __MULTITIMER_H__

#include <stdint.h>

#ifdef __cplusplus  
extern "C" {  
#endif

typedef uint64_t (*PlatformTicksFunction_t)(void);

typedef struct MultiTimerHandle MultiTimer;

typedef void (*MultiTimerCallback_t)(MultiTimer* timer, void* userData);

struct MultiTimerHandle {
    MultiTimer* next;
    uint64_t deadline;
    MultiTimerCallback_t callback;
    void* userData;
};

/**
 * @brief Platform ticks function.
 * 
 * @param ticksFunc ticks function.
 * @return int 0 on success, -1 on error.
 */
int MultiTimerInstall(PlatformTicksFunction_t ticksFunc);

/**
 * @brief Start the timer work, add the handle into work list.
 * 
 * @param timer target handle strcut.
 * @param timing Set the start time.
 * @param callback deadline callback.
 * @param userData user data.
 * @return int 0: success, -1: fail.
 */
int MultiTimerStart(MultiTimer* timer, uint64_t timing, MultiTimerCallback_t callback, void* userData);

/**
 * @brief Stop the timer work, remove the handle off work list.
 * 
 * @param timer target handle strcut.
 * @return int 0: success, -1: fail.
 */
int MultiTimerStop(MultiTimer* timer);

/**
 * @brief Check the timer expried and call callback.
 * 
 * @return int The next timer expires.
 */
int MultiTimerYield(void);

#ifdef __cplusplus
} 
#endif

#endif
