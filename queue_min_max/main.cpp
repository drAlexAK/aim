#include <iostream>
#include <queue>
#include <deque>

using namespace std;

template<typename T>

/// min and max in queue, O(1).
/// минимум и максимум в очереди за O(1).

class queue_min_max {
private:
    queue<T> que;
    deque<T> deq_min;
    deque<T> deq_max;

    void push_min(T crnt_element) {
        while (!deq_min.empty() && deq_min.back() > crnt_element) {
            deq_min.pop_back();
        }
        deq_min.push_back(crnt_element);
    }

    void push_max(T crnt_element) {
        while (!deq_max.empty() && deq_max.back() < crnt_element) {
            deq_max.pop_back();
        }
        deq_max.push_back(crnt_element);
    }

public:
    T get_min() {
        return deq_min.front();
    }
    T get_max() {
        return deq_max.front();
    }

    T front(){
        return que.front();
    }

    T size(){
        return que.size();
    }

    bool empty(){
        return que.empty();
    }

void pop() {
        if (!deq_max.empty() && deq_max.front() == que.front())
            deq_max.pop_front();
        if (!deq_min.empty() && deq_min.front() == que.front())
            deq_min.pop_front();
        que.pop();
    }

    void push(T x) {
        push_max(x);
        push_min(x);
        que.push(x);
    }
};

int32_t main() {
    queue_min_max<int> queue;

    string str;

    cin >> str;

    int val = 0;
    do {
        if (str == "push") {
            cin >> val;
            queue.push(val);
        } else if (str == "get") {
            cout << "min: " << queue.get_min() << " max: " << queue.get_max() << "\n";
        } else if (str == "pop") {
            queue.pop();
        } else {
            string errorLine;
            getline(cin, errorLine);
            cerr << "Unknown command: " << str + errorLine << "\n";
        }
        cin >> str;
    } while (str != "end");
    return 0;
}