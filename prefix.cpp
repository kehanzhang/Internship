#include<stdlib.h>
#include<iostream>
#include<ctype.h>
#include<string.h>

using namespace std;

int OperatorTest(char x){
    if(x == '+'||x == '-'||x == '*'){return 1;}
    else{return 0;}
}

class Enode {
    private:
        char data;
        int value;
        Enode *left;
        Enode *right;
    public:
        Enode(char d, int v, Enode *l, Enode *r){data=d; value=v; left=l; right=r;}
        char getChar(){return(data);}
        int getValue(){return(value);}
        Enode* getLeft(){return(left);}
        Enode* getRight(){return(right);}
        void setValue(int v){value=v;}
        void setLeft(Enode *l){left=l;}
        void setRight(Enode *r){right=r;}
};

class Prefix{
    private:
        Enode *root;
    public:
        Prefix(){root=NULL;}
        void print(Enode *x);
        void Place(int &i, string input, Enode *x);
        void calc(Enode *x);
        void Run();
};

void Prefix::print(Enode *x){
    if(x->getLeft() != NULL){
        print(x->getLeft());
    }
    cout<<x->getChar();
    if(x->getRight() != NULL){
        print(x->getRight());
    }
}

void Prefix::calc(Enode *x){
    /**x = current**/
    if(OperatorTest(x->getLeft()->getChar())){
        calc(x->getLeft());
    }
    if(OperatorTest(x->getRight()->getChar())){
        calc(x->getRight());
    }

    if(x->getChar() == '+'){
        x->setValue(x->getLeft()->getValue() + x->getRight()->getValue());
    }
    else if(x->getChar() == '-'){
        x->setValue(x->getLeft()->getValue() - x->getRight()->getValue());
    }
    else if(x->getChar() == '*'){
        x->setValue(x->getLeft()->getValue() * x->getRight()->getValue());
    }
}

void Prefix::Place(int &i, string input, Enode *x){
    Enode* current = x;
    Enode* temp;
    if(OperatorTest(current->getChar())){
        i++;
        temp=new Enode(input[i],NULL,NULL,NULL);
        current->setLeft(temp);
        Place(i, input, temp);
        i++;
        temp=new Enode(input[i],NULL,NULL,NULL);
        current->setRight(temp);
        Place(i, input, temp);
    }
    else{
        current->setValue(current->getChar() - '0');
    }
}

void Prefix::Run(){
    string input;
    cin>>input;
    root = new Enode(input[0],NULL,NULL,NULL);
    int zero = 0;
    Place(zero, input, root);
    print(root);
    calc(root);
    cout<<endl<<root->getValue();
}

int main(){
    Prefix expression;
    expression.Run();
    return 0;
}
