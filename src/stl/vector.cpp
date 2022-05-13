#include <iostream>
#include <vector>
#include <algorithm>

#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    std::vector<int> v1(10000);
    for (size_t i = 0; i < 10000; i++)
    {
        v1[i] = rand() % 100;
    }

    for (size_t i = 1; i < 10001; i++)
    {

        printf("%d ", v1[i]);

        if (i % 10 == 0)
            printf("\n");
    }

    printf("vector size: %d\n", v1.size());
    printf("vector size: %d\n", v1.max_size());

    std::vector<int> v2;
    for (size_t i = 0; i < 10; i++)
    {
        v2.push_back(i);
    }
    for (auto i = v2.begin(); i != v2.end(); i++)
    {
        printf("%d ", (*i));
    }
    printf("\n");
    for (auto i = v2.rbegin(); i != v2.rend(); i++)
    {
        printf("%d ", (*i));
    }
    printf("\n");

    std::vector<int> v3(v2);
    reverse(v3.rbegin(), v3.rend());
    for (auto i = v3.begin(); i != v3.end(); i++)
    {
        printf("%d ", (*i));
    }
    printf("\n");

    return 0;
}