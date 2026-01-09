#include<iostream>

using namespace std;

int main() {

    int var = 20;
    int *ptr = &var;

    cout << "Valor de var: " << *ptr << endl;

    system("pause");
    return 0;
}