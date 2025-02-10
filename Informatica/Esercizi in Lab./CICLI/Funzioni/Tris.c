#include <stdio.h>

void SceltaSimbolo(char _x, char _o, char *_P1, char *_P2);
void gioco();
void griglia();


int main(){
    char P1, P2;
    char x='X', o='O';
    
    SceltaSimbolo(x, o, &P1, &P2);
    gioco();




}

void SceltaSimbolo(char _x, char _o, char *_P1, char *_P2){

    printf("scegli il simbolo tra X e O");
    scanf(" %c", &*_P1);

    switch (*_P1)
    {
    case 'X':
        *_P1=_x; *_P2=_o;
        break;
    case 'O':
        *_P2=_x; *_P1=_o;
    default:
        printf("Opzione inesistenze.");
        break;
    }
}

void gioco(){
    char c1=' ',c2=' ',c3=' ',c4=' ',c5=' ',c6=' ',c7=' ',c8=' ',c9=' ';
    printf("|%c|%c|%c|\n", c1, c2, c3);
    
}