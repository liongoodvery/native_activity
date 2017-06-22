//
// Created by lion on 17-6-22.
//
#include <iostream>
#include <cstdlib>
using namespace std;
#define RAND(pMax) (float(pMax) * float(rand()) / float(RAND_MAX))


int main(){
    cout << RAND(100)<<endl;
    return 0;
}
