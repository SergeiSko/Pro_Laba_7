#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define SIZE 100

int fend(int first, int last);

int main()
{
    setlocale(LC_ALL, "Rus");

    ///----- -----
    double x[SIZE];
    int otv, PEnd, i, n, e;
    int first = 0, last = 0;
    char *str, *fname;

    do
    {
        do
        {
            printf ("(1)Read console\n(2)file\nOtv:");
            scanf("%d", &otv);
            switch (otv)
            {
                case 1:///
                {
                    printf("vvedite n: ");
                    scanf("%d", &n);
                    str = (int*) malloc(n*sizeof(int));
                    fflush(stdin);
                    printf("Write string: ");
                    gets(str);

                    for (i = 0; i < n; i++)
                    {
                        if(str[i] == ',')
                        {
                            if(e != 1)
                            {
                                first = i + 1;
                                e = 1;
                            }
                            else
                            {
                                last = i + 1;
                            }
                        }
                    }


                    fend(first, last);
                    PEnd = 1;
                    break;
                }
                case 2:///
                {
                    FILE *file;

                    printf("Enter filename: ");
                    fname = (int*) malloc(128*sizeof(int));
                    gets(fname);

                    file = fopen(fname, "r");
                    fscanf(file, "%d", &str);



                    fend(first, last);
                    PEnd = 1;
                    otv = 0;
                    ///fclose(file);
                    break;

                }
                default:
                {
                    PEnd = 0;
                }
            }
        }while(PEnd == 0);

        if(otv != 0)
        {
            do
            {
                printf ("Povtorit(1 = da/0 = net)?\nOtv:");
                scanf("%d", &otv);
                switch (otv)///
                {
                    case 1:
                    {
                        PEnd = 1;
                        break;
                    }
                    case 0:
                    {
                        PEnd = 1;
                        break;
                    }
                    default:
                    {
                        PEnd = 0;
                    }
                }
            }while(PEnd == 0);
        }
    }while(otv == 1);

    printf ("Press \"Enter\" to complete...");
    return 0;
}

int fend(int first, int last)
{
    setlocale(LC_ALL, "Rus");

    int otv, pend;
    do
    {
        printf ("(1)Vivesti v console\n(2)Vivesti v file\nOtv:");
        scanf("%d", &otv);
        switch (otv)
        {
            case 1:///
            {
                printf("first: %d\nlast: %d\n", first, last);

                pend = 1;
                break;
            }
            case 0:///
            {
                FILE *Sfile;
                Sfile = fopen("C:\\Laba\\smas.txt", "w");

                fprintf(Sfile, "first: %d\nlast: %d\n", first, last);

                fclose(Sfile);
                pend = 1;
                break;
            }
            default:
            {
                pend = 0;
            }
        }
    }while(pend == 0);
    return 0;
}
