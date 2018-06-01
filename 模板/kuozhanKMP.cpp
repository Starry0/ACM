void init(){
    int len = strlen(str1),a,p;
    nex[0] = len;
    for(int i = 1, j = -1; i < len; i ++, j--){
        if(j < 0 || i+nex[i-a] >= p){
            if(j < 0)
                p=i,j=0;
            while(p < len && str1[p]==str1[j])
                p++,j++;
            nex[i] = j;
            a = i;
        }else nex[i] = nex[i-a];
    }
}
void EKMP(){
    int a,p;
    int len = strlen(str), len1 = strlen(str1);
    for(int i = 1, j = -1; i < len; i++,j--){
        if(j<0 || i+nex[i-a] >= p){
            if(j < 0)
                p=i,j=0;
            while(p < len && str[p]==str1[j])
                p++,j++;
            extend[i] = j;
            a = i;
        }else extend[i] = nex[i-a];
    }
}