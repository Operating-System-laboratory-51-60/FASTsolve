#include <math.h>
#include <stdlib.h>
#include "matrix.h"
#include "det.h"

double compute_determinant(Matrix *m)
{
    // We work on a copy to avoid destroying the matrix for others
    Matrix *temp = copy_matrix(m);
    int n = temp->n;
    double det = 1.0;

    for(int i=0;i<n;i++)
    {
        int pivot = i;
        while(pivot < n && fabs(temp->data[pivot][i]) < 1e-9) pivot++;
        if(pivot == n)
        { 
            free_matrix(temp);
            return 0.0;
        }
        
        if(pivot != i)
        {
            double *swap = temp->data[i];
            temp->data[i] = temp->data[pivot];
            temp->data[pivot] = swap;
            det = -det;
        }
        det *= temp->data[i][i];
        for(int j=i+1;j<n;j++)
        {
            double factor = temp->data[j][i] / temp->data[i][i];
            for(int k=i;k<n;k++)
            temp->data[j][k] -= (factor*temp->data[i][k]);
        }
    }
    
    free_matrix(temp);
    return det;
}