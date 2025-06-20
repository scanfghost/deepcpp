#include<vector>
#include<iostream>

int main(){
    std::vector<int> x({1,2,3});

    //copy 
    std::vector<int> first=x;
    std::cout<<"copy vector first elements:";
    for(std::vector<int>::iterator it = first.begin();it != first.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    //move 
    std::vector<int> second

    return 0;
}