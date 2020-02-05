#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/// stack supports fast getting of minimum and maximum values
/// стек с быстрым получением максимального и минимального элемента

template<class T>
struct stack_min_max{
private:
    stack<T> st; /// primary stack
    stack<T> st_min; /// minimum of the stack
    stack<T> st_max; /// maximum of the stack
public:
    void pop(){
        st.pop();
        st_min.pop();
        st_max.pop();
    }
    T get_min(){
        return st_min.top();
    }
    T get_max(){
        return  st_max.top();
    }
    T top()
    {
        return st.top();
    }
    T push(T x){
        st.push(x);
        if(st_min.empty()) st_min.push(x);
        if(st_max.empty()) st_max.push(x);

        st_min.push(min(x, st_min.top()));
        st_max.push(max(x, st_max.top()));
    }
    T size(){
        return st.size();
    }
    bool empty(){
        return st.empty();
    }
};

int main() {

    stack_min_max<int> a;

    string s;

    cout << "use push, pop, get or exit commands\n";

    do {
        int tmp;
        cin >> s;
        if(s == "pop") {
            cout << a.top() << "\n";
            a.pop();
        }
        else if(s == "push"){
            cin >> tmp;
            a.push(tmp);
        }else if (s == "get"){
            cout << "min: " << a.get_min() << "\n";
            cout << "max: " << a.get_max() << "\n";
        }else{break;}
    } while(true);

    return 0;

}