#include<vector>
#include<iostream>

int main(){
    //operator[]
    std::vector<int> v1 = {2,3,5,7};
    std::cout<<"operator[] v1 elements:";
    /*if v1 is a empty vector ,v1.size()-1 will create endless cycle due to wrap around (unsigned integer underflow)
    for(std::vector<int>::size_type i = 0;i <=v1.size()-1;i++){

    }
    */
    for(size_t i = 0;i < v1.size();i++){
        std::cout<<" "<<v1[i];
    }
    std::cout<<"\n";

    //at()
    std::cout<<"at() v1 throw std::out_of_range:"<<std::endl;
    try
    {
        std::cout<<v1.at(5);
    }
    catch(std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    //front()
    std::cout<<"vector v1.front():"<<v1.front()<<std::endl;

    //back()
    std::cout<<"vector v1.back():"<<v1.back()<<std::endl;

    //data()
    /*
    the pointer returned by data() may invalidated if the vector's underlying storage is reallocated or modified.
    */
    const int* p = v1.data();
    std::cout<<"vector v1.data() const value_type* dereference:"<<*p<<std::endl;

    return 0;
}