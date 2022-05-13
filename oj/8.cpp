#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        map<int, int> m;
        int key, value;
        for(int i=0;i<n;i++)
        {
            cin >> key >> value;
            if(!m[key])
            {
                m[key] = value;
            }
            else
            {
                m[key]+=value;
            }
        }
        for(auto it=m.begin(); it !=m.end(); ++it)
        {
            cout << it->first << " " <<it->second <<endl;
        }
    }
    
    return 0;
}