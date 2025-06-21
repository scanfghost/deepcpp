#include<vector>
#include<iostream>

int main(){

    std::vector<double> example = {0.9,2.8,4.7,6.6};

    std::cout<<"the value pointed by rbegin():"<<*example.rbegin()<<std::endl;
    std::cout<<"the value pointed by rend()-1:"<<*(example.rend()-1)<<std::endl;

    return 0;
}