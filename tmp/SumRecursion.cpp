#include <iostream>
#include <vector>
using namespace std;
int total = 0;

void f2()
{
    cout << "f2" << endl;
}
void f1()
{
    cout << "f1" << endl;
    f2();
}

void SumRecursion(int n)
{
    n+=1;
    total +=1;
    cout << "n: " << n << " total: " << total << endl;
    if (total < 3)
    {
        SumRecursion(n);
    }
    cout << "... n: " << n << " total: "<< total << endl;
}
int main()
{
     f1();
    
    SumRecursion(0);
    system("pause");
    return 0;
}