#include <stdio.h>
#include <math.h>

double poly0(double x) { 
	return 1.0;
 }
double poly1(double x) { 
	return x; 
	}
double poly2(double x) { 
	return x*x; 
	}
double poly3(double x) { 
	return x * x * x; 
	}
double poly4(double x) { 
	return x*x*x*x; 
	}
double exact_integral(int n,double a,double b) 
{
   return (pow(b,n+1)-pow(a,n+1))/(n+1);
}
double chebyshev_integral(double (*f)(double),double a,double b) {
    double sqrt2 = sqrt(2.0);
    double x1=(a+b)/2.0-(sqrt2/4.0)*(b-a);
    double x2=(a+b)/2.0;
    double x3=(a+b)/2.0 +(sqrt2 / 4.0)*(b-a);
    double w=(b-a)/3.0;
    return w*(f(x1)+ f(x2)+f(x3));
}
int main() {
    double a=0.0,b=1.0;
    double approx0=chebyshev_integral(poly0,a,b);
    double exact0=exact_integral(0,a,b);   
    double approx1=chebyshev_integral(poly1,a,b);
    double exact1=exact_integral(1,a,b);   
    double approx2=chebyshev_integral(poly2,a,b);
    double exact2=exact_integral(2,a,b);  
    double approx3=chebyshev_integral(poly3,a,b);
    double exact3=exact_integral(3,a,b); 
    double approx4=chebyshev_integral(poly4,a,b);
    double exact4=exact_integral(4,a,b);
    printf("Функция   | Квадратурная формула | Точное значение | Погрешность\n");
    printf("---------------------------------------------------------------\n");
    printf("x^0       | %.6f            | %.6f       | %.6e\n",approx0,exact0,fabs(approx0-exact0));
    printf("x^1       | %.6f            | %.6f       | %.6e\n",approx1,exact1,fabs(approx1-exact1));
    printf("x^2       | %.6f            | %.6f       | %.6e\n",approx2,exact2,fabs(approx2-exact2));
    printf("x^3       | %.6f            | %.6f       | %.6e\n",approx3,exact3,fabs(approx3-exact3));
    printf("x^4       | %.6f            | %.6f       | %.6e\n",approx4,exact4,fabs(approx4-exact4));
 return 0;
}

