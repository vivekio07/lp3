#include <iostream>
using namespace std;

int recursive_fibo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return recursive_fibo(n-1) + recursive_fibo(n-2);
}

void non_recursive_fibo(int n) {
    int fib1 = 0, fib2 = 1, fib3;

    for(int i = 0; i < n; i++) {
        cout<<fib1<<" ";
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }   
}

int main() {
    non_recursive_fibo(5);
    cout<<endl;
    
    for(int i = 0; i < 5; i++) {
        cout<<recursive_fibo(i)<<" ";
    }
}
