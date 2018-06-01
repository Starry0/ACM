#include <iostream>
#include <string>
#include<cstring>
using namespace std;
int main(){
    string num1,num2;
    cin>>num1>>num2;
    const char *n1;
    const char *n2;
    if(num1.size()<num2.size()){
        n1=num2.c_str();
        n2=num2.c_str();
    }
    else {
        n1=num1.c_str();
        n2=num2.c_str();
    }
    char *n=new char[strlen(n1)+strlen(n2)+1];
    for(unsigned int i=0;i<strlen(n1)+strlen(n2);i++)
        n[i]='0';
    n[strlen(n1)+strlen(n2)]='\0';
    int count=0,flag=0;
    for(int i=strlen(n1)-1;i>=0;i--){
        flag++;
        int x1=n1[i]-'0'; cout << "n1["<< i << "]Îª£º" << x1 << endl;
        char carry ='0';
        for(int j=strlen(n2)-1;j>=0;j--){
            int x2=n2[j]-'0';
            int sum=x1*x2+(carry-'0')+n[count]-'0';
            n[count++]=(sum%10)+'0';
            carry=(sum/10)+'0';
        }
        if(carry!='0'){
            n[count]=carry;
            count=flag;
        }
        else count=flag;
    }
        for(int i=strlen(n)-1;i>=0;i++){
            if((i==strlen(n)-1)&&n[i]=='0')
                continue;
            cout<<n[i];
        }
        cout<<endl;
        delete[]n;
        return 0;
}
