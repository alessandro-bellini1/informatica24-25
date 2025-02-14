#include <stdio.h>

void SceltaSimbolo(char _x, char _o, char *_P1, char *_P2);
int gioco(char _simbolo_turno, char *_c1, char *_c2, char *_c3, char *_c4, char *_c5, char *_c6, char *_c7, char *_c8, char *_c9);
void griglia(char *_c1, char *_c2, char *_c3, char *_c4, char *_c5, char *_c6, char *_c7, char *_c8, char *_c9);
int vittoria(char _simbolo_turno, char _x, char _o, char _c1, char _c2, char _c3, char _c4, char _c5, char _c6, char _c7, char _c8, char _c9);

int main(){
    char P1, P2;
    char x='X', o='O', simbolo_turno;
    char c1=' ',c2=' ',c3=' ',c4=' ',c5=' ',c6=' ',c7=' ',c8=' ',c9=' ';
    int turno=0;
    SceltaSimbolo(x, o, &P1, &P2);

    while(turno<9){
        if(turno%2==0)
            simbolo_turno=P1;
        else
            simbolo_turno=P2;
    griglia(&c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9);

    printf("giocatore %c scegli la posizone dove inserire il simbolo\nScelta: ", simbolo_turno);
    
    if(gioco(simbolo_turno, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9)==0)
        turno++;
    if(vittoria(simbolo_turno, x, o, c1, c2, c3, c4, c5, c6, c7, c8, c9)==1)
        turno=9;

}
    




}

void SceltaSimbolo(char _x, char _o, char *_P1, char *_P2){
    printf("scegli il simbolo tra X e O\nScelta: ");
    scanf(" %c", &*_P1);

    switch (*_P1)
    {
    case 'X':
        *_P1=_x; *_P2=_o;
        break;
    case 'O':
        *_P2=_x; *_P1=_o;
        break;
    default:
        printf("Opzione inesistenze.\n");
        break;
    }
}

void griglia(char *_c1, char *_c2, char *_c3, char *_c4, char *_c5, char *_c6, char *_c7, char *_c8, char *_c9){

    printf("| %c| %c| %c|\n", *_c1, *_c2, *_c3);
    printf("----------\n");
    printf("| %c| %c| %c|\n", *_c4, *_c5, *_c6);
    printf("----------\n");
    printf("| %c| %c| %c|\n", *_c7, *_c8, *_c9);
}

int gioco(char _simbolo_turno, char *_c1, char *_c2, char *_c3, char *_c4, char *_c5, char *_c6, char *_c7, char *_c8, char *_c9){
    int p;
    scanf("%d", &p);

    switch(p){
        case 1:
        if(*_c1==' '){
        *_c1=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 2:
        if(*_c2==' '){
        *_c2=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 3:
        if(*_c3==' '){
        *_c3=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 4:
        if(*_c4==' '){
        *_c4=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 5:
        if(*_c5==' '){
        *_c5=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 6:
        if(*_c6==' '){
        *_c6=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 7:
        if(*_c7==' '){
        *_c7=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 8:
        if(*_c8==' '){
        *_c8=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        case 9:
        if(*_c9==' '){
        *_c9=_simbolo_turno;
        return 0;
        }else return 1;
        break;
        default:
        printf("posizione inesistente\n");
        return 1;
        }
        return 1;
}

int vittoria(char _simbolo_turno, char _x, char _o, char _c1, char _c2, char _c3, char _c4, char _c5, char _c6, char _c7, char _c8, char _c9){
        if(_c1==_x&&_c1==_c2&&_c1==_c3){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c4==_x&&_c4==_c5&&_c4==_c6){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c7==_x&&_c7==_c8&&_c7==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c1==_x&&_c1==_c4&&_c1==_c7){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c2==_x&&_c2==_c5&&_c2==_c8){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c3==_x&&_c3==_c6&&_c3==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c1==_x&&_c1==_c5&&_c1==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c3==_x&&_c3==_c5&&_c3==_c7){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }
        else if(_c1==_o&&_c1==_c2&&_c1==_c3){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c4==_o&&_c4==_c5&&_c4==_c6){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c7==_o&&_c7==_c8&&_c7==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c1==_o&&_c1==_c4&&_c1==_c7){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c2==_o&&_c2==_c5&&_c2==_c8){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c3==_o&&_c3==_c6&&_c3==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c1==_o&&_c1==_c5&&_c1==_c9){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }else if(_c3==_o&&_c3==_c5&&_c3==_c7){
            printf("il giocatore %c, HA VINTO!",_simbolo_turno);
            return 1;
        }
        
}
