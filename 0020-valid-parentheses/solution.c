#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    int n = strlen (s);
    char stack [n];
    int top = -1;

  for(int i = 0 ; i< n; i++){
char c = s[i];

   if(c == '(' || c == '{' || c == '['){
    stack[++top] = c;
  }  
  else {
    if (top == -1) return false;
    
char last = stack[top--];
    if ((c == ')' && last != '(') ||
        (c == '}' && last != '{') ||
        (c == ']' && last != '[')) {
            return false;

        }
   }
  }   
  return top == -1 ;
}