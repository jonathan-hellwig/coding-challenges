#include <iostream>
#include <cmath>

int knapsack(int* v, int* w, int N, int W);

int main(int argc, char* argv[])
{
  int value[] = {20,5,10,40,15,25};
  int weight[] = {1,2,3,8,7,4};
  int W = 10;
  int N = sizeof(value) / sizeof(value[0]);
  std::cout << "The solution to the knapsack problem is: "
            << knapsack(value, weight, N, W) << std::endl;
  return 0;
}

int knapsack(int* v, int* w, int N, int W)
{
  int k[N+1][W+1];

  for(int j=0; j<=W; j++)
    k[0][j] = 0;

  for(int i=1; i<=N; i++)
  {
    for(int j=0; j<=W; j++)
    {
      k[i][j] = k[i-1][j];
      if(j - w[i-1] >= 0)
        k[i][j] = std::max(k[i-1][j-w[i-1]]+v[i-1], k[i-1][j]);
    }
  }
  return k[N][W];
}
