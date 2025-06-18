#include <stdio.h>

#define MAX_ITEMS 4
#define MAX_WEIGHT 4

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapsack(int weights[], int values[], int n, int capacity)
{
    int dp[MAX_ITEMS + 1][MAX_WEIGHT + 1];
    int i, w;

    // Inicializar tabla
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Mostrar resultado
    printf("Valor maximo posible: $%d\n\n", dp[n][capacity]);

    // Encontrar los objetos seleccionados
    int res = dp[n][capacity];
    w = capacity;
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res != dp[i - 1][w])
        {
            printf("Incluir objeto %d:\n", i);
            switch (i)
            {
            case 1:
                printf("iPhone (Peso: %dlb, Valor: $%d)\n", weights[i - 1], values[i - 1]);
                break;
            case 2:
                printf("Guitarra (Peso: %dlb, Valor: $%d)\n", weights[i - 1], values[i - 1]);
                break;
            case 3:
                printf("Laptop (Peso: %dlb, Valor: $%d)\n", weights[i - 1], values[i - 1]);
                break;
            case 4:
                printf("Estéreo (Peso: %dlb, Valor: $%d)\n", weights[i - 1], values[i - 1]);
                break;
            }
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }
}

int main()
{
    int weights[] = {1, 1, 3, 4};            // guitarra en diferentes posiciones
    int values[] = {1500, 1500, 2000, 3500}; // valores segun la tabla
    int n = 4;

    printf("Problema de la Mochila\n");
    printf("Capacidad maxima: %d libras\n\n", MAX_WEIGHT);

    knapsack(weights, values, n, MAX_WEIGHT);

    return 0;
}
