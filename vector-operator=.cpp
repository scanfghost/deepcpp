#include<vector>
#include<iostream>

int main(){
    std::vector<int> x({1,2,3,4,5});

    //copy 
    std::vector<int> first=x;
    std::cout<<"copy= vector first elements:";
    for(std::vector<int>::iterator it = first.begin();it != first.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    //move 
    std::vector<int> second_1 = std::move(x);
    std::cout<<"move= vector second_1 elements:";
    for(std::vector<int>::iterator it = second_1.begin();it != second_1.end();it++){
        std::cout<<" "<<*it;
    }
    std::cout<<"\n";
    /* vector is left in an unspecified but valid
    std::vector<int> second_2 = std::vector<int>(x.rbegin()+1,x.rend()-1);{4,3,2}*/
    std::vector<int> second_2 = std::vector<int>(second_1.rbegin()+1,second_1.rend()-1);
    std::cout<<"move= vector second_2 elements:";
    for(std::vector<int>::iterator it = second_2.begin();it != second_2.end();it++){
        std::cout<<" "<<*it;
    }
    std::cout<<"\n";

    return 0;
}