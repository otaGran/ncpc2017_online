//
// Created by beans on 2017/10/14.
//


#include <iostream>

using namespace std;

int main(){
    int kase;
    cin >> kase;
    int num[1000+10];
    int pos[1000+10],neg[1000+10];
    while(kase--){
        int n,pos_length = 0,neg_length = 0,max = -1;
        cin >> n;
        for(int i = 0;i<n;i++) {
            cin >> num[i];
            //cout << num[i] << endl;
            if (num[i] > 0)
                pos_length++;
            if (num[i] < 0)
                neg_length++;
        }

        //cout << neg_length;

        int tmp_pos = 0,tmp_neg = 0;

        for(int i = 0;i<n;i++) {
            if (num[i] > 0)
                pos[tmp_pos++] = num[i];
            else
                neg[tmp_neg++] = num[i];
        }


        sort(pos,pos+pos_length);
        sort(neg,neg+neg_length);

        if(pos_length>=3){
            int pos3 = pos[pos_length-1]*pos[pos_length-2]*pos[pos_length-3];
            if(pos3>max)
                max = pos3;
        }


        if(pos_length>=2&&neg_length>=1){
            int pos2neg1 = pos[0]*pos[1]*neg[neg_length-1];
            if(pos2neg1>max)
                max = pos2neg1;
        }


        if(pos_length>=1&&neg_length>=2){
            int pos1neg2 = pos[pos_length-1]*neg[0]*neg[1];
            if(pos1neg2>max)
                max = pos1neg2;
        }

        if(neg_length>=3){
            int neg3 = neg[0]*neg[1]*neg[2];
            if(neg3>max)
                max = neg3;
        }

        cout << max << endl;

    }
}