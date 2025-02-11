#include <iostream>
#include <queue>

using namespace std;
/*
priority_queue<{kiểu dữ liệu}, {class container}, {class compare}> q;

{kiểu dữ liệu} 

{class container} vector, stack, queue, deque đều là class container, vector là container mặc định của priority_queue

compare sẽ là phép toán trong thư viện functional. Một số phép toán trong thư viện này là less, greater, less_equal, ... phép toán mặc định là less
    q.push(1);  <-- greater
    q.push(3);
    q.push(5);
    q.push(7);  <-- less

Như vậy, mục đích của queue là sắp sếp các element theo thứ tự.
Mình cần test thứ tự nào đầu, đuôi là được.




*/
int main()
{

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    q.push(3);
    q.push(5);
    q.push(7);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, less<pair<int, pair<int, int>>>> pq;
    pq.push({1, {2, 3}});
    pq.push({2, {4, 5}});
    cout << pq.top().first << endl;
    system("pause");
    return 0;
}