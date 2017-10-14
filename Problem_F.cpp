//
// Created by beans on 2017/10/14.
//
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

typedef struct fo{
    string name;
    int id;
    int damage;
    int time;
    string next[5];
    int i_next[5];
};
int n,blood,res_damage,res_time = 1050*10+10,res_moves,A[10],res_A[10];
fo num[30];

void dfs(int tmp_moves,int tmp_damage,int tmp_time,int id){
   // printf("%d %d %d %d\n",id,tmp_moves,tmp_damage,tmp_time);
    if(tmp_moves==10||tmp_damage>=blood){
        if(tmp_damage<blood)
            return;
        if(tmp_time<res_time){
            res_time = tmp_time;
            res_damage = tmp_damage;
            res_moves = tmp_moves-1;
            memcpy(res_A,A,sizeof(A));
        }
    }else{
        for(int i = 0;i<5;i++){
            if(num[id].i_next[i]!=-1) {
                A[tmp_moves] = num[id].i_next[i];
                dfs(tmp_moves + 1, tmp_damage + num[id].damage, tmp_time + num[id].time, num[id].i_next[i]);
                A[tmp_moves] = 0;
            }
        }
    }

}

void init(){
    res_time = 1050*10+10;
    for(int i = 0;i<n;i++){
        A[0] = num[i].id;
        dfs(1,0,0,num[i].id);
        A[0] = 0;
    }
}

int main(){
    int kase;
    cin >> kase;

    while(kase--){
        cin >> n >> blood;
        string tmp;
        getline(cin,tmp);
        for(int i = 0;i<n;i++){
           // cout << i << endl;
            stringstream ss;
            string s;
            getline(cin,s);
           // cout << s << endl;
            ss << s;
            ss >> num[i].name >> num[i].damage >> num[i].time;
            num[i].id = i;
            int tmp  = 0;
            while(ss >> num[i].next[tmp++]){
                //cout << num[i].next[tmp-1] << endl;
            }
        }

        //convert next from string to id(int)
        for(int i = 0;i<n;i++){
            for(int j = 0;j<5;j++){

                if(num[i].next[j]!=""){
                    for(int k = 0;k<n;k++)
                        if(num[k].name==num[i].next[j])
                            num[i].i_next[j]= num[k].id;
                }else{//-1 for empty
                    num[i].i_next[j] = -1;
                }
                //cout << num[i].i_next[j] << " ";
            }
            //cout << endl;
        }

       init();
        //cout << "res" << endl;
        if(res_time == 1050*10+10){
            printf("impossible\n0 0\n");
        }else {
            for (int i = 0; i < res_moves; i++) {
                cout << num[res_A[i]].name << " ";
            }

            cout << endl << res_time << " " << res_damage << endl;
        }
    }


}