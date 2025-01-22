/*Scrivi un programma in C che dati due numeri in 
input mostri quale dei due ha più divisori.*/
#include <stdio.h>
int main()
{
    int N1, N2, cnt1=0, cnt2=0;
      
    printf("Inserisci due valori: ");
    scanf("%d %d", &N1, &N2);
                    
    for(int i=1; i<=N1; i++)
    {
    if(N1%i==0)
    cnt1++;
    }
    for(int j=1; j<=N2; j++)
    {
    if(N2%j==0)
    cnt2++;
    }
    if(cnt1>cnt2)
    printf("%d ha più divisori con %d divisori\n", N1, cnt1);
    else if(cnt2>cnt1)
    printf("%d ha più divisori con %d divisori\n", N2, cnt2);
    else
    printf("%d ha la stessa quantità di divisori di %d con %d divisori", N1, N2, cnt1);
    return 0;
}
                                                            