#include <stdio.h>

typedef struct complex{
    int real;
    int imagine;
}Complex;

Complex add(Complex a, Complex b){
    Complex result;
    result.imagine = a.imagine + b.imagine;
    result.real = a.real + b.real;     
    return result;
}

Complex multiply(Complex a, Complex b){
    Complex result;
    result.real = a.real*b.real - a.imagine*b.imagine;
    result.imagine = a.real*b.imagine + b.real*a.imagine;
    return result;
}

Complex init(int real, int imagine){
    Complex z;
    z.imagine = imagine;
    z.real = real;
    return z;
}

int main(){
    Complex z1,z2,addResult,multiplyResult;
    z1 = init(12,-3);
    z2 = init(-4,7);
    addResult = add(z1,z2);
    printf("z1 + z2 = %d + %di\n",addResult.real,addResult.imagine);
    multiplyResult = multiply(z1,z2);
    printf("z1 * z2 = %d + %di\n",multiplyResult.real,multiplyResult.imagine);
    return 0;
}