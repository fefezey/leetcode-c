char* convertToTitle(int n) {
    static char s[20];
    int i=0;

    while (n) {
        n--;
        s[i++] ='A' + (n % 26);
        n /= 26;
    }
    s[i]= '\0';
     
   for (int j= 0;j< i/2; j++){
    char t =s[j];
    s[j] = s [i-1-j];
    s[i-1-j] = t;
   }   
   return s;
}