char* multiply(char* num1, char* num2) {
    static char out[210];
    int r[210]={0};

    int n =strlen(num1),m = strlen(num2);

    for (int i= n-1; i>=0; i--){
    for (int j=m-1; j>=0; j--){
     
      int c=(num1[i]-'0')*(num2[j]-'0');
      int sum = r [i+j+1] + c;

    r[i+j+1] = sum %10;
    r[i+j]+=sum/ 10; 
   } 
}
 
  int k =0, i=0;
  while (i< n+ m && r[i]== 0)i++;

  if (i == n+m) return "0";

  while (i < n+m)
    out[k++]=r[i++] + '0';

    out[k]=0;
    return out;
}