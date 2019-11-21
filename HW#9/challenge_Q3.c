#include <stdio.h>

typedef struct complex
{
  double real;
  double imaginary;
} Complex;

Complex add(Complex a, Complex b)
{
  Complex result;

  result.real = a.real + b.real;
  result.imaginary = a.imaginary + b.imaginary;

  return result;
}

Complex mul(Complex a, Complex b)
{
  Complex result;
  result.real = a.real * b.real - a.imaginary * b.imaginary;
  result.imaginary = a.imaginary * b.real + a.real * b.imaginary;

  return result;
}

int main(void)
{
  Complex complexOne, complexTwo;

  printf("복소수 입력1[실수 허수]: ");
  scanf("%lf %lf", &complexOne.real, &complexOne.imaginary);
  printf("복소수 입력2[실수 허수]: ");
  scanf("%lf %lf", &complexTwo.real, &complexTwo.imaginary);

  Complex addResult = add(complexOne, complexTwo);
  Complex mulResult = mul(complexOne, complexTwo);

  printf("합의 결과] 실수 : %lf, 허수: %lf\n", addResult.real, addResult.imaginary);
  printf("곱의 결과] 실수 : %lf, 허수: %lf\n", mulResult.real, mulResult.imaginary);
  return 0;
}