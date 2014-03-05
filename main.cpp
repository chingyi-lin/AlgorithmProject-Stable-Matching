#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//--------------class----------------//

class Depart{
public:
    string name;
    int L[100], ListSize, receive, num, lastOrder;//size = Li
    bool Received[100];
    Depart(){
        ListSize = 0;
        receive = 0;
        num = 0;
    }
    void findlastOrder(){
        int last=-1;
        for(int i = 0 ; i < ListSize; i++){
            if(Received[i] && i>last)
                last = i;
        }
        lastOrder = last;
    }
    int ReceiveStu(int S){//-1代表不錄取 0代表直接錄取 其他就代表被踢出榜單的學生代號
        int Sorder = -1;
        findlastOrder();
        for(int i = 0; i < ListSize; i++){
            if(S == L[i]){
                Sorder = i;
                break;
            }
        }
        if (Sorder==-1){//不在榜單上 拜拜
            //cout<<"你不在我的榜單上喔"<<endl;
            return -1;
        }
        else{
            if(num<receive){//還沒收滿，但榜上有名，先直接錄取
                Received[Sorder] = true;
                num++;
                return 0;
            }
            else{
                if(Sorder<lastOrder){//order越小表示越想要
                    Received[Sorder] = true;
                    Received[lastOrder] = false;                    return L[lastOrder];
                }
                else
                    return -1;
            }
        }
    }
    void display2(){
        cout<<name<<endl;
        for(int i = 0 ; i <ListSize; i++){
            if(Received[i]==true)
                cout<<L[i]<<" ";
        }
        cout<<endl;
    }
};

class Student{
public:
    string T[10000], TnowApply;
    Depart *next;
    int ListSize, nowApply;
    bool hasSchool;
    bool finish;
    Student(){
        ListSize = 0;
        hasSchool = false;
        nowApply = 0;
        finish = false;
    }
    void findNow(){
        if(finish)
            return;
        if(nowApply>=ListSize){
            //cout<<"finish"<<endl;
            finish = true;
            return;
        }
        TnowApply = T[nowApply];
        nowApply++;//下一次再檢查有沒有超過
        //cout<<nowApply<<endl;
    }
};
Depart dep[1001];
Student stu[10001];
string DepName[1001];
int main(int argc, const char * argv[])
{
    int D, N, result;
    bool key = true;
    cin>>D>>N;
    for(int i = 0; i < D; i++){
        //cin.get();
        //getline(cin, dep[i].name);
        cin>>dep[i].name;
        DepName[i] = dep[i].name;
        //cout<<dep[i].name<<endl;
        cin>>dep[i].receive>>dep[i].ListSize;
        for(int j = 0 ; j < dep[i].ListSize; j++)
            cin>>dep[i].L[j];
        //for(int j = 0 ; j < dep[i].ListSize; j++)
          //  cout<<dep[i].L[j]<<" ";
    }
    
    for(int i = 1 ; i < N+1; i++){//考生從編號1開始
        cin>>stu[i].ListSize;
        for(int j = 0 ; j < stu[i].ListSize; j++){
            cin>>stu[i].T[j];
            //cout<<stu[i].T[j];
        }
    }
    sort(DepName, DepName+D);
    //分發開始//
    while(key){
        key = false;
        for(int i = 1 ; i < N+1; i ++){
            if(!stu[i].hasSchool && !stu[i].finish){
                //cout<<i<<endl;
                //cout<<"next apply:";
                stu[i].findNow();//更新
                for(int j = 0 ; j < D; j++){
                    if(stu[i].TnowApply == dep[j].name){
                        result = dep[j].ReceiveStu(i);
                        //cout<<"I got a result"<<endl;
                        if(result == 0){
                            //cout<<"被錄取了"<<endl;
                            stu[i].hasSchool = true;
                        }
                        else if(result != -1){//代表有錄取 但踢掉別人了
                            //cout<<"I kick sb else!"<<endl;
                            stu[i].hasSchool = true;
                            stu[result].hasSchool = false;
                        }
                        else if(result == -1) //cout<<"我落榜了"<<endl;
                        break;
                    }
                }
            }
        }
        
        for(int i = 1; i < N+1; i++){
            if(!stu[i].finish && !stu[i].hasSchool){//只要有一個人沒學校也沒finish 我就繼續
                //  cout<<i<<"還沒finish"<<endl;
                key = true;
                break;
            }
        }
    }
    for(int i = 0 ; i < D; i++){
        for(int j = 0 ; j < D; j++){
            if(DepName[i]==dep[j].name){
                dep[j].display2();
                break;
            }
        }
    }
    return 0;
}

