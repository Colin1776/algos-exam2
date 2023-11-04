#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int coin_change(int denoms[], int num_coins, int sum)
{
    int sums[sum + 1];
    sums[0] = 0;

    for (int i = 1; i <= sum; i++)
    {
        sums[i] = INT_MAX;

        for (int j = 0; j < num_coins; j++)
        {
            if (i - denoms[j] >= 0)
            {
                int sub = sums[i - denoms[j]];
                if (sub != INT_MAX && sub + 1 < sums[i])
                {
                    sums[i] = sub + 1;
                }
            }
        }
    }
  
    return sums[sum] != INT_MAX ? sums[sum] : -1;
}

int main(void)
{
    int denoms[] = {1, 16, 31, 45};
    int sum = 87;
   
    int x = coin_change(denoms, 4, sum);
    printf("%d\n", x);    
}
