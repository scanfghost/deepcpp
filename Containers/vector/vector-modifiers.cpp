#include<vector>
#include<iostream>
using namespace std;

void assign(){
    vector<int> x({2,4,6,8});
    vector<int> y(3);

    //range
    y.assign(x.begin(),x.end()-1);
    cout<<"range elements:";
    for(vector<int>::iterator it = y.begin();it != y.end();it++){
        cout<<" "<<*it;
    }
    cout<<"\nsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";

    //fill
    y.assign(5,6);
    cout<<"fill to expand elements:";
    for(vector<int>::iterator it = y.begin();it != y.end();it++){
        cout<<" "<<*it;
    }
    cout<<"\nsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";
    y.assign(3,6);
    cout<<"fill to shrink elements:";
    for(vector<int>::iterator it = y.begin();it != y.end();it++){
        cout<<" "<<*it;
    }
    cout<<"\nsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";

    //initializer list 
    y.assign({1,2});
    cout<<"initializer list to shrink elements:";
    for(vector<int>::iterator it = y.begin();it != y.end();it++){
        cout<<" "<<*it;
    }
    cout<<"\nsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";
}
using vint = vector<int>;
void push(){
    

    vint x = {1};
    //const value_type&
    x.push_back(3);
    x.push_back(7);

    cout<<"push_back const value_type&:";
    for(vint::iterator it = x.begin();it != x.end();it++){
        cout<<" "<<*it;
    }
    cout<<'\n';

    //

}

void pop(){
    vint x({2,4,6,8});

    cout<<"size:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";
    x.pop_back();
    cout<<"size:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";
}

template<class T>
void cout_alll(T& cnt){
    for(typename T::iterator it = cnt.begin();it != cnt.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
void insert(){
    vint x({1,2,3,4});
    vint y({20,30,40,50});
    //single element
    x.insert(x.begin()+1,10);
    cout<<"insert single elements:";
    cout_alll(x);

    //fill
    x.insert(x.begin()+1,2,11);
    cout<<"fill elements:";
    cout_alll(x);

    //range
    x.insert(x.begin(),y.rbegin(),y.rend()-2);
    cout<<"range elements:";
    cout_alll(x);

    //move
    
    //initializer list
    /*
    the first parameter must be a const_iterator , not a reverse_iterator
    */
    x.insert(x.end()-1,{100,200});
    cout<<"initializer list elements:";
    cout_alll(x);
}

void erase(){
    vint x = {2,3,4,5,6,7,8};

    x.erase(x.begin()+1);
    cout<<"erase single element:";
    cout_alll(x);

    x.erase(x.begin()+1,x.begin()+3);
    cout<<"erase a range of elements:";
    cout_alll(x);

}

void swap(){
    vint x(5,100);
    vint y(7,20);

    cout<<"y before swaping"<<"\tdata()"<<y.data()<<"\tsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";
    cout<<"x before swaping"<<"\tdata()"<<x.data()<<"\tsize:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";
    x.swap(y);
    cout_alll(x);
    cout<<"x after swaping"<<"\tdata()"<<x.data()<<"\tsize:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";
    cout<<"y after swaping"<<"\tdata()"<<y.data()<<"\tsize:"<<y.size()<<"\tcapacity:"<<y.capacity()<<"\n";
}

void clear(){
    vint x{2,8};

    cout<<"x before clearing"<<"\tdata()"<<x.data()<<"\tsize:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";
    x.clear();
    cout<<"x after clearing"<<"\tdata()"<<x.data()<<"\tsize:"<<x.size()<<"\tcapacity:"<<x.capacity()<<"\n";

}

void emplace(){
    vint x{10,2,4,5};

    //cannot call constructor fill because emplace() insert only one element
    // x.emplace(x.begin(),3,9);
    cout<<"emplace():";
    x.emplace(x.begin(),9);
    cout_alll(x);
    cout<<"emplace_back():";
    x.emplace_back(100);
    cout_alll(x);
}

int main(){
        cout<<"vector::assign():\n";
        assign();
        cout<<"\n";

        cout<<"vector::push():\n";
        push();
        cout<<"\n";

        cout<<"vector::pop():\n";
        pop();
        cout<<"\n";

        cout<<"vector::insert():\n";
        insert();
        cout<<"\n";

        cout<<"vector::erase():\n";
        erase();
        cout<<"\n";

        cout<<"vector::swap():\n";
        swap();
        cout<<"\n";

        cout<<"vector::clear():\n";
        clear();
        cout<<"\n";

        cout<<"vector::emplace():\n";
        emplace();
        cout<<"\n";

    return 0;
}