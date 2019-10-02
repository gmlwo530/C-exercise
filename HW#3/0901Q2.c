#include <stdio.h>

double CelToFah(double cel)
{
  return 1.8 * cel + 32;
}

double FahToCel(double fah)
{
  return (fah - 32) / 1.8;
}

int main(void)
{
  printf("섭씨에서 화씨로 : %f\n", CelToFah(32.0));
  printf("화씨에서 섭씨로 : %f", FahToCel(CelToFah(32.0)));
  return 0;
}