#include <iostream>

using namespace std;

char a[1000];
int main()
{
    int i=0,j=0,k=0,l=0,p=0;
    cin>>a;
    for(i=0;i<a[i];i++){
        if(a[i]=='h'){
            for(j=i+1;a[j];j++){
                if(a[j]=='e'){
                    for(k=j+1;a[k];k++){
                        if(a[k]=='l'){
                            for(l=k+1;a[l];l++){
                                if(a[l]=='l'){
                                    for(p=l+1;a[p];p++){
                                        if(a[p]=='o'){
                                            cout<<"YES"<<endl;
                                            goto tt;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"NO"<<endl;
    tt:return 0;
}
