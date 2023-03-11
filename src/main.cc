#include <iostream>

int factorial(int x);
int combination(int &x, int &y);
int permutation(int &x, int &y);

int main(void)
{
  setlocale(LC_ALL, "Turkish");
  int x, y;

  std::cout << "Give (x,y): ";
  std::cin >> x >> y;

  if(std::cin.fail() || std::cin.eof())
  {
    std::cout << "Program finished 'cause of TypeError!\n";
    return -1;
  }
  std::cout << "Kombinasyon: " << combination(x, y) << '\n';
  std::cout << "Permutasyonu: " << permutation(x, y);
  return 0;
}

int factorial(int x) {
  if (x <= 1)
    return 1;
  else
    return x * factorial(x - 1);
}

int combination(int &x, int &y) {
  // formula = C(n,2) = [(n) * (n-1)] / 2!  => C(3,1) = 3/1! AND C(5,2) = 5*4/2!
  if (y > x)
    return -1;

  int numerator = 1;
  for (int i = 0; i < y; i++)
  {
    numerator *= x - i;
  }
  
  int denominator = factorial(y);

  return numerator / denominator;
}

int permutation(int &x, int &y)
{
  // formula = C(n,2) = [(n) * (n-1)]  => C(3,1) = 3 AND C(5,2) = 5*4
  if (y > x)
    return -1;
  int result{1};
  for (int i = 0; i < y; i++)
  {
    result *= x - i;
  }
  return result;
}
