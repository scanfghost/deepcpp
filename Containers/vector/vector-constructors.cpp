#include<vector>
#include<iostream>
using namespace std;

int main(){
    //default
    vector<int> first;
    cout<<"default vector size:"<<first.size()<<endl;

    //fill
    vector<double> second_1(3);
    vector<double> second_2(3,9.0);
    cout<<"fill vector second_1 elements:";
    for(vector<double>::iterator it = second_1.begin();it != second_1.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    cout<<"fill vector second_2 elements:";
    for(vector<double>::iterator it = second_2.begin();it != second_2.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    //range
    vector<double> third_1(second_2.begin(),second_2.end());
    cout<<"range vector third_1 elements:";
    for(vector<double>::iterator it = third_1.begin();it != third_1.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";    

    int myints[] = {2,4,6,8};
    vector<int> third_2(myints,myints+sizeof(myints)/sizeof(int));
    cout<<"range vector third_2 elements:";
    for(vector<int>::iterator it = third_2.begin();it != third_2.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    //copy
    vector<double> fourth(third_1);
    cout<<"copy vector fourth elements:";
    for(vector<double>::iterator it = fourth.begin();it != fourth.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    //move
    vector<double> fifth(move(fourth));
    cout<<"move vector fifth elements:";
    for(vector<double>::iterator it = fifth.begin();it != fifth.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    cout<<"moved fourth.data():"<<(fourth.data()==nullptr?"nullptr":0)<<endl;

    //initializer list 
    vector<double> sixth({1,2,3,4,5});
    cout<<"initializer list vector sixth elements:";
    for(vector<double>::iterator it = sixth.begin();it != sixth.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";

    return 0;
}
    