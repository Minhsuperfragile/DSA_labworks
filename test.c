#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool is_pangram(char *str_in) {
  int arraySize = sizeof(str_in)/sizeof((str_in[0]));
  bool is_pangram = 1;
  bool alphabet[26];
  for (int i=0;i<26;i++){
    alphabet[i] = 0;
  }
  for (int i=0;i<arraySize;i++){
    // printf("%d ",str_in[i]);
    for (int j=97;j<123;j++){
        
      if (str_in[i] == j || str_in[i] == (j-32)){
        alphabet[j-97] = 1;
      }
    }
  }
  for (int i=0;i<26;i++){
    // printf("%d ",alphabet[i]);
    if(alphabet[i]==0){
      is_pangram = 0;
      break;
    }
  }
  return is_pangram;
}

int main(){
    char lol[] ="The quick, brown fox jumps over the lazy dog!";
    is_pangram(lol);
}