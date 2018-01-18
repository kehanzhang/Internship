#include<iostream>

using namespace std;

int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;
int check5 = 0;

int const n = 10;

void display(int values[]){
    for(int i = 0; i < n; i++){
        cout<<values[i]<<" ";
    }
}

void swapf(int x, int y, int ary[]){
    int temp = ary[x];
    ary[x] = ary[y];
    ary[y] = temp;
}

void qsort(int ary[], int S, int E){
    int L = E;
    int F = S;
    int P = S-1;
    check1++;
    if(E - S >= 0){
        if(E - S == 0){//check 2 things
            check2++;
            if(ary[P] > ary[S]){//comparison of 2 things
                swapf(P, S, ary);
            }
        }
        else{
            while(ary[P] <= ary[L] && L != P){
                L--;
            }
            while(ary[P] > ary[F] && F != E){
                F++;
            }
            if(L == P){
                check3++;
                qsort(ary, S+1, E);
            }//Right side
            else if(F == E && ary[P] < ary[E]){
                check4++;
                qsort(ary, S, E-1);
            }//Left side case 1
            else if(F == E && ary[P] > ary[E]){
                swapf(P, E, ary);
                check4++;
                qsort(ary, S, E-1);
            }//Left side case 2
            else{//Middle
                if(F < L){
                    swapf(F, L, ary);
                    qsort(ary, S, E);
                }
                else{
                    check5++;
                    swapf(P, L, ary);
                    qsort(ary, L+2, E);
                    qsort(ary, S, L-1);
                }
            }
        }
    }
    //end of q sort
}

int main(){
    int values[n] = {5,5,3,-2,3,4,6,9,5,-6};
    display(values);
    cout<<endl;
    qsort(values, 1, n-1);
    display(values);
    cout<<endl;
return 0;
}
