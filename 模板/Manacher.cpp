/*
回文子串
*/

int Manacher(){
    int ans = 0, id = 0, len = strlen(str);
    for(int i = len; i >= 0; i --){
        str[i+i+2] = str[i];
        str[i+i+1] = '#';
    }
    str[0] = '*';
    for(int i = 2; i<2*len+1; i ++){
        if(p[id] + id > i) p[i] = min(p[2*id-i],p[id]+id-i);
        else p[i] = 1;
        while(str[i-p[i]] == str[i+p[i]])++p[i];
        if(p[id] + id < p[i]+i) id = i;
        if(ans < p[i]) ans = p[i];
    }
    return ans-1;
}