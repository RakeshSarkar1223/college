#include <stdio.h>

int countArr(int **arr, int n)
{
    int count = 0;
    // for(int i = 0; i< n; i++){
    //     int j = i + 1;
    //     count+= i+1;
    //     while(arr[i][j] != 0){
    //         j++;
    //         count++;
    //     }
    // }

    int i = 0;
    int j = n - 1;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == 1)
        {
            count++;
            j--;
        }
        else
        {
            i++;
        }
    }
    return count;
}
