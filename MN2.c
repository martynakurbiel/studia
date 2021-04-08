#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
 
float a, b, Ksi;
int n;
float xi[100] = { 0 };
float yi[100] = { 0 };
 
 
// f. przyjmujaca dane
void input_data()
{
    printf("Podaj a\n");    scanf_s("%f", &a);
    printf("Podaj b\n");    scanf_s("%f", &b);
    printf("Podaj Ksi\n");  scanf_s("%f", &Ksi);
    printf("Podaj n\n");    scanf_s("%d", &n);
}
 
// f. definiujaca interpolowana funkcje
float function(float x)
{    
    return pow(x, 4);
}
 
// f. wyznaczajaca wezly rownoodlegle i wartosc funkcji f(x) dla tych wezlow
void wezly_rownoodlegle()
{
    float step = fabs((b - a) / n);
    for (int i = 0; i <= n; i++)
    {
        xi[i] = a + i * step;
        yi[i] = function(xi[i]);
        printf("x%d=%f\n", i, xi[i]);
        printf("Wn(x%d)=%f\n\n", i, yi[i]);
    }
}
 
void wezly_czebyszewa()
{
    const double pi = 3.14159265358979323846264338327950288419716939937510;
    double z;
 
    for (int i = 0; i <= n; i++)
    {
        z = cos(pi * (2 * i + 1) / (2 * n + 2));
        xi[i] = 0.5 * ((b - a) * z + (a + b));
        yi[i] = function(xi[i]);
    }
}
 
// f. wyznaczajaca wielomian i jego wartosc w wybranym punkcie
float Wielomian_lagrange(float Ksi)
{
    int k, i, j;
    float Wn1 = 1;
    float Wn2 = 0;
    float Wn3 = 1;
 
    for (k = 0; k <= n; k++)        // pomocnicze wyznaczenie Wn+1(x)
    {
        Wn1 = Wn1 * (Ksi - xi[k]);
        printf("%f\n", Wn1);
    }
 
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i != j)
            {
                Wn3 = Wn3 * ((Ksi - xi[j]) * (xi[j] - xi[i]));
            }
        }
 
        Wn2 = Wn2 + (yi[i] / Wn3);
        Wn3 = 1;
 
    }
 
    return Wn1 * Wn2;
}
 
int main()
{
    input_data();
 
    wezly_rownoodlegle();  
 
    printf("Wartosc wielomianu w punkcie Ksi=%f wynosi %f", Ksi, Wielomian_lagrange(Ksi));
 
 
    return 0;
}