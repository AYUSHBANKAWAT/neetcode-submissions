class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {
        mini = INT_MAX;
    }

    void push(int val) {

        if (s.empty()) {
            s.push(val);
            mini = val;
        }
        else if (val < mini) {

            s.push(2LL * val - mini);
            mini = val;
        }
        else {
            s.push(val);
        }
    }

    void pop() {

        if (s.top() < mini) {
            mini = 2LL * mini - s.top();
        }

        s.pop();
    }

    int top() {

        if (s.top() < mini)
            return mini;

        return s.top();
    }

    int getMin() {
        return mini;
    }
};