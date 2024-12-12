/*il codice deve dare come output un / disegnato con gli "*"
*/
#include <stdio.h>
int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(i==0 || i==0 || i==9-j){
                printf("*");
            } else{
                printf(" ");
            }
        }
        printf("\n");
    } 
}