#include <cstdlib>
#include <stdio.h>
#include <io.h>
#include <math.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    
    struct sved
    {
      char fam[20];
      int math;
      int phis;
      int IT;
      double s_bal;
    };

    FILE *f, *ft;
    char name[15] = "0", nametxt[15];
    int kod, size = sizeof (sved), n, k;
    sved zap, a[30];

    while ( 1 )
    {
        system("cls");
        puts(" Чтобы создать файл, нажмите - 1 ");
        puts(" Чтобы открыть файл, нажмите - 2 ");
        puts(" Чтобы добавить в файл, нажмите - 3 ");
        puts(" Чтобы отсортировать данные в файле, нажмите - 4 ");
        puts(" Чтобы изменить тип файла на текстовый, нажмите - 5 ");
        puts(" Чтобы найти студентов, имеющих средний балл выше введенного с клавиатуры., нажмите - 6 ");
        puts(" Чтобы завершить, нажмите - 0 ");

        switch (getch())
        {
            case '0' : return 0;           
            
            case '1' :                      
                system("cls");
                cout << " Укажите имя создаваемого файла :  "; cin >> name;
                f = fopen (name, "wb"); fclose (f);

            case '3' :                      
                system("cls");
                f = fopen (name, "ab");
                while ( 3 )
                {
                    cout << "Фамилия студента : "; cin >> zap.fam;
                    if ( zap.fam[0] == '.') break;
                    cout << "Отметка по математике  =  ";  cin >> zap.math ;
                    cout << "Отметка по физике      =  ";  cin >> zap.phis ;
                    cout << "Отметка по информатике =  ";  cin >> zap.IT;
                    printf ("\n");
                    zap.s_bal = (zap.math + zap.phis + zap.IT)/ 3.;
                    fwrite(&zap, size, 1, f);
                }
                fclose (f);
                break;

            case '2' :                      
                system("cls");
                cout << "Имя файла, котоырй нужно открыть : "; cin >> name;
                f = fopen (name, "rb");
                cout << "\n      Фамилия  матем. Физика Информатика Ср.балл \n\n"; 
                while (fread(&zap, size, 1, f))
                    printf ("%12s %5d %7d %9d %9.1lf\n", zap.fam, zap.math, zap.phis, zap.IT, zap.s_bal);
                fclose (f);  
                getch();
                break;
                
            case '5' :                       
                system("cls");
                cout << "Имя текстового файла : "; cin >> nametxt;
                f = fopen (name, "rb");
                ft = fopen (nametxt, "wt");
                fprintf (ft, "      Фамилия  матем. Физика Информатика Ср.балл \n\n");
                while (fread(&zap, size, 1, f))
                    fprintf (ft,"%12s %5d %7d %9d %9.1lf\n", zap.fam, zap.math, zap.phis, zap.IT, zap.s_bal);
                fclose(f);  fclose(ft);
                break;
                
            case '4' :                       
                system ("cls");
                f =  fopen (name , "rb");
                n = 0;
                while (fread(&a[n], size, 1, f)) n++; 
                fclose(f);
                
                for (int i = 1; i<n; i++)
                    for (int j = 0; j < n-i; j++)
                        if ( strcmp(a[j].fam, a[j+1].fam) > 0 )
                        {
                            zap = a[j];
                            a[j] = a[j+1];
                            a[j+1] = zap;      
                        } 
                
                f = fopen (name, "wb");
                cout << "\n      Фамилия  матем. Физика Информатика Ср.балл \n\n";
                for (int j = 0; j < n; j++)
                {
                    fwrite (&a[j], size, 1, f);
                    printf ("%12s %5d %7d %9d %9.1lf\n", a[j].fam, a[j].math, a[j].phis, a[j].IT, a[j].s_bal);
                }
                
                fclose (f);                
                getch();
                break;
                
            case '6' :                              
                system ("cls");
                cout << "Введите ср.балл :"; 
                cin >> k; system ("cls");
                f = fopen (name, "rb");
                cout << "\n      Фамилия  матем. Физика Информатика Ср.балл \n\n";
                while(fread(&zap, size, 1, f) )
                    if (zap.s_bal > k)
                        printf ("%12s %5d %7d %9d %9.1lf\n", zap.fam, zap.math, zap.phis, zap.IT, zap.s_bal);   
                fclose (f); getch();    
                break;
        }



    }
}
//---------------------------------------------------------------------------

