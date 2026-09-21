char* convert(char* s, int numRows) {
    if (numRows == 1) return s;

    int len =strlen (s) ;

    char** rows =(char**)malloc(numRows * sizeof (char *));
    int* sizes =(int *)calloc (numRows, sizeof (int));

    for (int i = 0; i < numRows; i++) {
        rows [i] = (char*)malloc (len + 1);
    }

    int row = 0 ;
    int dir = 1;
    
    for (int i= 0; i < len; i++) {
        rows[row][sizes[row]++] = s[i];

        if (row == 0) dir =1;
        if (row == numRows - 1) dir = -1;
            row +=dir ;
    }
    char* result =(char*) malloc (len +1);
    int idx = 0;
     
     for (int i = 0; i < numRows; i++) {
        for (int j= 0; j < sizes[i]; j++){
            result [idx++] = rows[i][j];
        
        }
     }
      result [idx] = '\0';
      return result;
}