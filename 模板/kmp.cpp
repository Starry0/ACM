void init(){
    int j = nex[0] = -1, i = 0;
    int len = strlen(str);
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            nex[++i] = ++j;
        }else j = nex[j];
    }
}
int KMP(){
    int i  = 0, j = 0, sum = 0;
    int len = strlen(str), len1 = strlen(str1);
    while(j < len1){
        if(i == -1 || str[i] == str1[j]){
            i++;j++;
        }else i = nex[i];
        if(i == len) sum++;
    }
    return sum;
}