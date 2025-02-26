#include <stdio.h>
#include <string.h>

int convertire(char string[50]) 
{
    int nr = 0, n = strlen(string);
    for (int i = 0; i<n; i++) 
    {
        nr = nr * 10 + (string[i] - '0');
    }
    return nr;
}

int main() 
{
    FILE* f1;
    errno_t err = fopen_s(&f1, "in.txt", "r");
    if (err != 0) 
    {
        printf("Error opening file\n");
        return 1;//Asta e pentru fopen_s
    }

    char string[50];  
    int suma = 0;
    char c;
    int nr = 0;

    while ((c = fgetc(f1)) != EOF) 
    {
        if (c == '\n' || c == ' ') 
        { 
            if (nr > 0) {
                string[nr] = '\0';  
                suma += convertire(string); 
                nr = 0;  
            }
        }
        else 
        { 
            string[nr++] = c;
        }
    }
    if (nr > 0) 
    {
        string[nr] = '\0';
        suma += convertire(string);
    }

    printf("Suma: %d\n", suma);
    fclose(f1);
    return 0;
}
