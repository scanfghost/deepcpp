#include<vector>
#include<iostream>
using namespace std;

void print_alll(const vector<int>&);
vector<int> Maxheap_sort(const vector<int>& v);
vector<int> heapify(const vector<int>& v);
vector<int> heapify_2(vector<int>& v,int p_par,int visible_last);
vector<int> heapify_3(vector<int>& v,int p_par,int visible_last);
void swap_element(int& a,int& b);
int main(){

    vector<int> nums = {
        -1,57, 23, 89, 12, 45,
        68, 34, 91, 7,  29,
        73, 16, 82, 5,  41,
        98, 63, 20, 54, 37
    };

    cout<<"vector:";
    print_alll(nums);

    cout<<"Maxheap_sort:";
    print_alll(Maxheap_sort(nums));

    return 0;
}

vector<int> Maxheap_sort(const vector<int>& v){
    vector<int> local = v;
    int p_par = (local.size()-1)/2;

    heapify_3(local,p_par,local.size()-1);

    for(int visible_last = local.size()-1;visible_last>1;visible_last--){
        swap_element(local.at(visible_last),local.at(1));
        heapify_3(local,1,visible_last-1);
    }

    return local;
}

vector<int> heapify_3(vector<int>& v,int p_par,int visible_last){
    int& par_value = v.at(p_par);
    int p_left = p_par*2;
    int p_right = p_par*2+1;
    int p_larger = -1;

    if(p_right<=visible_last && v.at(p_right)>par_value){
        p_larger = p_right;
    }
    //The left child has higher priority , which means that left child will replace its parent if both are larger
    if(p_left<=visible_last && v.at(p_left)>par_value){
        p_larger = p_left;
    }
    
    if (p_larger != -1)
    {
        swap_element(v.at(p_larger),v.at(p_par));
        heapify_3(v,p_larger,visible_last);
    }

    return v;
}

vector<int> heapify_2(vector<int>& v,int p_par,int visible_last){
    int& par_value = v.at(p_par);
    int p_left = p_par*2;
    int p_right = p_par*2+1;
    

    if(p_right<=visible_last && v.at(p_right)>par_value){
        swap_element(par_value,v.at(p_right));
        heapify_2(v,p_right,visible_last);
    }

    if(p_left<=visible_last && v.at(p_left)>par_value){
        swap_element(par_value,v.at(p_left));
        heapify_2(v,p_left,visible_last);
    }
    
    if(p_par>1){
        heapify_2(v,p_par-1,visible_last);
    }
    
    return v;
}

vector<int> heapify(const vector<int>& v){
    vector<int> local = v;
    int p_last = local.size()-1;

    if (p_last%2==1)
    {
        if(local.at(p_last-1)>local.at(p_last) && local.at(p_last-1)>local.at(p_last/2)){
            swap_element(local.at(p_last-1),local.at(p_last/2));
        }else if(local.at(p_last)>local.at(p_last-1) && local.at(p_last)>local.at(p_last/2)){
            swap_element(local.at(p_last),local.at(p_last/2));
        }
        p_last -= 2;
    }else {
        if(local.at(p_last)>local.at(p_last/2)){
            swap_element(local.at(p_last),local.at(p_last/2));
            p_last -= 1;
        }
    }

    while (p_last>1)
    {
        if(local.at(p_last)>local.at(p_last-1) && local.at(p_last)>local.at(p_last/2)){
            swap_element(local.at(p_last),local.at(p_last/2));
            p_last -= 2;
        }else if(local.at(p_last-1)>local.at(p_last) && local.at(p_last-1)>local.at(p_last/2)){
            swap_element(local.at(p_last-1),local.at(p_last/2));
            p_last -= 1;
        }else{
            p_last -= 2;
        }
    }
    
    return local;
}
void swap_element(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

void print_alll(const vector<int>& v){
    for(vector<int>::const_iterator it = v.begin();it != v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
