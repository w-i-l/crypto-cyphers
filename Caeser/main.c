#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* encode(const char* text, int shift){
    
    char* encoded = malloc((strlen(text) + 1) * sizeof(char));
    
    int i;
    
    for(i=0; text[i]; i++){
        if('a' <= text[i] && text[i]<= 'z'){
            encoded[i] = ((text[i]%'a' + shift) % 26) + 'a';
        }
        else{
             if('A' <= text[i] && text[i] <= 'Z'){
                encoded[i] = ((text[i]%'A' + shift) % 26) + 'A';
            }
            else{
                encoded[i] = text[i];
            }
        }
    }
    
    encoded[i] = 0;
    
    return encoded;
}


char* decode(const char* text, int shift){
    
    char* decoded = malloc((strlen(text) + 1) * sizeof(char));
    
    int i;
    
    for(i=0; text[i]; i++){
        if('a' <= text[i] && text[i]<= 'z'){
            char x = ((text[i] - 'a') - shift) % 26;
            decoded[i] = ((x < 0 ? x + 26 : x)) + 'a';
        }
        else{
             if('A' <= text[i] && text[i]<= 'Z'){
                char x = ((text[i] - 'A') - shift) % 26;
                decoded[i] = ((x < 0 ? x + 26 : x)) + 'A';
            }
            else{
                decoded[i] = text[i];
            }
        }
    }
    
    decoded[i] = 0;
    
    return decoded;
}
