#include<vector>
#include<iostream>

int main(){
    std::vector<double> example({1,3,5,7,9});

    //size()
    std::cout<<"vector example.size():"<<example.size()<<std::endl;

    //capacity()
    std::cout<<"vector example.capacity():"<<example.capacity()<<std::endl;

    //max_size()
    std::cout<<"vector example.max_size():"<<example.max_size()<<std::endl;

    //resize()
    example.resize(8,999);
    std::cout<<"vector example.resize(greater) , size():"<<example.size()<<std::endl;
    std::cout<<"vector example.resize(greater) , capacity():"<<example.capacity()<<std::endl;
    std::cout<<"vector example.resize(greater) ,max_size():"<<example.max_size()<<std::endl;
    for(std::vector<double>::iterator it = example.begin();it != example.end();it++){
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;
    example.resize(4);
    std::cout<<"vector example.resize(less) , size():"<<example.size()<<std::endl;
    std::cout<<"vector example.resize(less) , capacity():"<<example.capacity()<<std::endl;
    std::cout<<"vector example.resize(less) ,max_size():"<<example.max_size()<<std::endl;
    for(std::vector<double>::iterator it = example.begin();it != example.end();it++){
        std::cout<<" "<<*it;
    }
    std::cout<<std::endl;

    //empty()
    std::cout<<"vector example.empty():"<<example.empty()<<std::endl;
    std::cout<<"temporary vector() empty():"<<std::vector<int>().empty()<<std::endl;

    //reserve()
    std::vector<int> v_reserve(2,3);
    std::cout<<"vector v_reserve capacity before reserve(10):"<<v_reserve.capacity()<<std::endl;
    v_reserve.reserve(10);
    std::cout<<"vector v_reserve capacity after reserve(10):"<<v_reserve.capacity()<<std::endl;

    //shrink_to_fit()
    std::cout<<"vector v_reserve capacity before shrink_to_fit():"<<v_reserve.capacity()<<std::endl;
    v_reserve.shrink_to_fit();
    std::cout<<"vector v_reserve capacity after shrink_to_fit():"<<v_reserve.capacity()<<std::endl;

    return 0;
}