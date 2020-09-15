#include <iostream>

bool findPair(int* arr, int N, int sum);
int main(int argc, char* argv[])
{
  int N = 6;
  int arr[N] = {8,7,2,5,3,1};
  int sum = 10;
  if(findPair(arr, N, sum))
  {
    std::cout << "Pair found!" << std::endl;
  }
  else
  {
    std::cout << "No pair found!" << std::endl;
  }
  
  return 0;
}
bool findPair(int* arr, int N, int sum)
{  
  for(int i=0; i<N; i++)
  {
    for(int j=i+1; j<N; j++)
    {
      if(arr[i] + arr[j] == sum)
        return true;
    }
  }
  return false;
}
