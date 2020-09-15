#include <iostream>
#include <cmath>
#include <climits>

int lis(int* x, int N);

int main()
{
  int x[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
  int N = sizeof(x) / sizeof(x[0]);
  std::cout << N << std::endl;
  std::cout << "The longest increasing subsequence is "
            << lis(x, N) << " long." << std::endl;
}

int lis(int* x, int N)
{
  int d[N+1];
  //int backtrack[N+1];
  int index; 
  int maximumValue;
  //backtrack[0] = 0;
  d[0] = 0;

  for(int i=0; i<N; i++)
  {
    index = 0; 
    maximumValue = INT_MIN;
    for(int j=i-1; j>=0; j--)
    {
      if(x[j] < x[i] && d[j+1] >= maximumValue)
      {
        index = j+1;
        maximumValue = d[j+1];
      }
    }
    //backtrack[i+1] = (d[i]>d[index]+1)?i:index;
    d[i+1] = std::max(d[i], d[index]+1);
  }
  /*for(int i=N; i>0;)
  {
    std::cout << "Index: " << backtrack[i] 
              << " Value: " << x[backtrack[i]-1] 
              << std::endl;
    i = backtrack[i];
  }*/

  return d[N];
}

