#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
void softmax( double * p, const int len ){
    double sum = 0;
    
    double* s = (double*)malloc(len * sizeof(double));
   
    for (int j = 0; j < len; j++){
        s[j] =  exp (p[j]);
        sum += exp (p[j]);
    }
        
    for (int j = 0; j < len; j++){
        p[j] = s[j] / sum;
    }
    free(s);
}
void argmax( double * p, const int len, int max_p){
    double max = 0;
    for(int j = 0; j < len; j++){   
       if (p[j] > max){
           max = p[j];
           max_p = j;    
       }
    }
    printf("%d ", max_p);
}
int main(){
    int count;
    int result = 0;
    int max_p=0;
    int len = 10;
    double* p = (double*)malloc(len * sizeof(double));
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &p[0], &p[1], &p[2], &p[3], &p[4], &p[5], &p[6], &p[7], &p[8], &p[9]);
        softmax(p, len);
        argmax(p, len, max_p);
        printf("%.4f %.4f %.4f %.4f %.4f %.4f %.4f %.4f %.4f %.4f\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7], p[8], p[9]);
    
    }
    free(p);
    return 0;
}
