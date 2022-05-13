#include <iostream>
#include <thread>
#include <mutex>
// time library
#include <chrono>

#include <stdlib.h>

void sayHello(int n)
{
    std::cout << " I am " << n << " ." << std::endl;
}

void thread_pause()
{
    // sleep 500毫秒
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // sleep 到指定时间点
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::milliseconds(500));
}

auto fn = [](int *a) {
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << *a << std::endl;
    }
};

/* 资源获取即初始化（RAII,Resource Acquisition Is Initialization) */
class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread &_t) : t(_t) {}

    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }

    thread_guard(const thread_guard &) = delete;
    thread_guard &operator=(const thread_guard &) = delete;
};

int increase(int *p, int times)
{
    for (size_t i = 0; i < times; i++)
    {
        ++*p;
    }
    return 0;
}

int increase_mutex(int *num, int times, std::mutex &mtx)
{
    for (size_t i = 0; i < times; i++)
    {
        mtx.lock();
        ++*num;
        mtx.unlock();
    }
    return 0;
}

int main()
{
    /* */
    std::cout << "1. general function:" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::thread t(sayHello, i);
        t.detach();
    }

    /**/
    std::cout << "2. lambda function:" << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        std::thread t([i] { std::cout << i << std::endl; });
        t.detach();
    }

    /**
     *  
     * 使用引用变量会出现问题
     * 创建的新线程对当前作用域的变量的使用
     * 创建新线程的作用域结束后，有可能线程仍然在执行，这时局部变量随着作用域的完成都已销毁
     * 如果线程继续使用局部变量的引用或者指针，会出现意想不到的错误
     */
    {
        int a = 100;
        std::thread t(fn, &a);
        t.detach();
    }

    /*无论是何种情况，当函数退出时，局部变量g调用其析构函数销毁，从而能够保证join一定会被调用*/
    {
        std::thread t([] {
            std::cout << "Hello thread" << std::endl;
        });
        thread_guard g(t);
    }

    /**异常情况下等待线程完成
     * 当决定以detach方式让线程在后台运行时，可以在创建thread的实例后立即调用detach，
     * 这样线程就会后thread的实例分离，即使出现了异常thread的实例被销毁，仍然能保证线程在后台运行。
     * 但线程以join方式运行时，需要在主线程的合适位置调用join方法，
     * 如果调用join前出现了异常，thread被销毁，线程就会被异常所终结
     * 即使当线程函数已经执行完成后，调用join仍然是有效的。*/
    {
        std::thread t([] {
            std::cout << "hello C++ 11" << std::endl;
        });
        try
        {
            sayHello(10);
        }
        catch (...)
        {
            t.join();
            throw;
        }
        t.join();
    }

    /**/
    {
        std::thread thread(thread_pause);
        thread.join();
    }

    /* 对num进行没有加锁的操作，输出在10000-20000之间，同时说明++num操作不是原子的 */
    std::cout << "没有加锁操作下num：" << std::endl;
    {
        int num = 0;
        std::thread t1(increase, &num, 10000);
        std::thread t2(increase, &num, 10000);
        std::thread t3(increase, &num, 10000);
        std::thread t4(increase, &num, 10000);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        std::cout << "num=" << num << std::endl;
    }

    /* 对num进行没有加锁的操作，输出在10000-20000之间，同时说明++num操作不是原子的 */
    std::cout << "加锁操作下num：" << std::endl;
    {
        int num = 0;
        std::mutex mtx;
        std::thread t1([&]() {
            for (size_t i = 0; i < 10000; i++)
            {
                mtx.lock();
                ++num;
                mtx.unlock();
            }
        });

        std::thread t2([&]() {
            increase_mutex(&num, 10000, mtx);
        });

        // ??????
        // std::thread t3(increase_mutex, &num, 10000, &mtx);

        t1.join();
        t2.join();
        std::cout << "num=" << num << std::endl;
    }

    return 0;
}