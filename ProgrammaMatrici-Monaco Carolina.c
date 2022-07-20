#include <stdio.h>
#include <stdlib.h>


int calcolo_determinante(int a, int b, int c, int d);


int main()
{
    const int DIM_RIGA=3;
    const int DIM_COL=3;
    int scelta;
    int rango_calcolato=0;
    int traccia=0;
    int mat[DIM_RIGA][DIM_COL];
    // acquisizione valori

    printf("PROGRAMMA SUL CALCOLO DEL RANGO, TRASPOSTA E TRACCIA DI UNA MATRICE 3X3 NON NULLA \n");

    for (int i=0;i < DIM_RIGA ; i++)
      {
      for (int j=0 ; j<DIM_COL; j++)

        {
            printf (" Inserisci riga %d colonna %d\n", i +1,j+1);
            scanf ("%d", &mat [i][j]);
        }
      }

    //stampa valori
    for (int i=0; i<DIM_RIGA ;i++)
     {
       for(int j=0;j < DIM_COL;j++)

        {
            printf("%d\t", mat [i][j]);
        }
            printf("\n");
     }

    do
       {
        printf("MENU' \n");
        printf("1.calcolo del rango della matrice inserita \n");
        printf ("2.calcolo della trasposta della matrice inserita \n");
        printf ("3.calcolo della traccia della matrice inserita \n");
        printf("4.fine del programma \n");
        printf("inserire il numero corrispondente alla funzione che si intende eseguire:");
        scanf("%d", &scelta);

    switch (scelta){

     case 1 :
        {
            printf ("C'e' almeno un elemento della matrice diverso da zero, pertanto il rango e' almeno 1 \n \n");
        if( calcolo_determinante(mat[0][0], mat[0][1], mat[1][0], mat[1][1]) != 0)
            printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
            mat[0][0], mat[0][1], mat[1][0], mat[1][1]);
        else if ( calcolo_determinante(mat[0][0], mat[0][2], mat[1][0], mat[1][2]) != 0)
                  printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                  mat[0][0], mat[0][2], mat[1][0], mat[1][2]);
        else if ( calcolo_determinante(mat[0][0], mat[0][1], mat[2][0], mat[2][1]) != 0)
                  printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                  mat[0][0], mat[0][1], mat[2][0], mat[2][1]);
        else if ( calcolo_determinante(mat[0][0], mat[0][2], mat[2][0], mat[2][2]) != 0)
                  printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                  mat[0][0], mat[0][2], mat[2][0], mat[2][2]);
        else if ( calcolo_determinante(mat[0][1], mat[0][2], mat[1][1], mat[1][2]) != 0)
                printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                       mat[0][1], mat[0][2], mat[1][1], mat[1][2]);
        else if ( calcolo_determinante(mat[0][1], mat[0][2], mat[1][1], mat[1][2]) != 0)
                printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                       mat[0][1], mat[0][2], mat[1][1], mat[1][2]);
        else if ( calcolo_determinante(mat[1][0], mat[1][1], mat[2][0], mat[2][1]) != 0)
                printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                       mat[1][0], mat[1][1], mat[2][0], mat[2][1]);
        else if ( calcolo_determinante(mat[1][1], mat[1][2], mat[2][1], mat[2][2]) != 0)
                printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                       mat[1][1], mat[1][2], mat[2][1], mat[2][2]);
        else if ( calcolo_determinante(mat[1][0], mat[1][2], mat[2][0], mat[2][2]) != 0)
                printf("Il determinante della sottomatrice \n %d\t %d\n %d\t %d\ne' diverso da 0, dunque il rango della matrice di partenza  e' almeno 2 \n \n ",
                       mat[1][0], mat[1][2], mat[2][0], mat[2][2]);
        else
        {
            printf("Nesssuna sottomatrice 2x2 ha determinante diverso da 0, pertanto il rango e' 1 \n");
            rango_calcolato=1;
        }

        //calcolo del determinante della matrice
    int determinante;
        determinante=mat[0][0]*calcolo_determinante(mat[1][1], mat[1][2],mat[2][1],mat[2][2])
        -mat[1][0]*calcolo_determinante(mat[0][1], mat[0][2],mat[2][1],mat[2][2])
        +mat[2][0]*calcolo_determinante(mat[0][1], mat[0][2],mat[1][1],mat[1][2]);
    if (determinante != 0 )
        printf("Siccome il determinante della matrice  inserita e' diverso da 0 allora il rango e' 3 \n");

    else if(determinante==0 && rango_calcolato !=1 )
        printf("Siccome il determinante della matrice inserita e' uguale a 0 allora il rango e' 2 \n");

    }
    break;

    case 2:
      {
        for (int i=0;i < DIM_RIGA; i++)
        {
          for (int j=i;j<DIM_COL; j++)
           {
             int temp=mat[i][j];
             mat[i][j]=mat[j][i];
             mat[j][i]=temp;
           }
        }
        printf("La trasposta della matrice inserita e': \n");
        for (int i=0; i<DIM_RIGA ;i++)
        {
          for(int j=0;j < DIM_COL;j++)
          {
            printf("%d\t", mat [i][j]);
          }
            printf("\n");
        }
     }
     break;

     case 3:
        {
        for(int i=0; i< DIM_RIGA; i++)
            for(int j=0;j<DIM_COL;j++)
              {
               if (i==j)
               traccia += mat[i][j];
              }
            printf("La traccia e' uguale a %d \n",traccia);
        }

    break;

    case 4:
        printf("fine del programma");
        break;

     default:
        printf("il numero inserito non corrisponde a nessuna delle opzioni \n");
        break;
        }

      } while (scelta!=4 );

return 0;
}

 // sottoprogramma che calcola il determinante della matrice (a b c d)
 int calcolo_determinante(int a, int b, int c, int d)
 {
    int determinante;
    determinante = a*d-b*c;
    return determinante;
 }
