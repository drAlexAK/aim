#include <iostream>
#include <queue>
#include <deque>

using namespace std;

template<typename T>

/// min and max in queue, O(1).
/// минимум и максимум в очереди за O(1).

struct get_min_queue {
private:
    queue<T> que;
    deque<T> deq_min_max;
public:
    T get_min() {
        return deq_min_max.front();
    }

    T pop() {
        if (!deq_min_max.empty() && deq_min_max.front() == que.front()) {
            deq_min_max.pop_front();
            que.pop();
        } else que.pop();
    }

    T push(T crnt_element) {
        que.push(crnt_element);
        while (!deq_min_max.empty() && deq_min_max.back() > crnt_element) {
            deq_min_max.pop_back();
        }
        deq_min_max.push_back(crnt_element);
    }
};

int32_t main() {
    get_min_queue<int> a;

    string s;

    cin >> s;

    double tmp = 0;
    do {
        if (s == "push") {
            cin >> tmp;
            a.push(tmp);
        } else if (s == "pop") {
            a.pop();
        } else if (s == "min") {
            cout << "min: " << a.get_min() << "\n";
        } else if(s != "end"){
            string tmp;
            getline(cin, tmp);
            cerr << "Try again, unknown command:" << " " << s + tmp;
        }
    } while (s != "end");
    return 0;
}

