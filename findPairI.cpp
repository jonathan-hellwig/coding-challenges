#include <iostream>
#include <algorithm>

bool binarySearch(int* arr, int lower, int upper, int target);
bool findPair(int* arr, int N, int sum);
int main(int argc, char* argv[])
{
  int N = 6;
  int arr[N] = {8,7,2,5,3,1};
  int sum = 10;
  if(findPair(arr, N, sum))
  {
    std::cout << "Target found!" << std::endl;
  }
  else
  {
    std::cout << "Target not found!" << std::endl;
  }
  return 0;
}
bool findPair(int* arr, int N, int sum)
{  
  std::sort(arr, arr+N);
  for(int i=0; i<N; i++)
  {
    if(binarySearch(arr, i+1, N-1, sum-arr[i]))
      return true;
  }
  return false;
}
bool binarySearch(int* arr, int lower, int upper, int target)
{
  int middle;
  while(lower <= upper)
  {
    middle = (upper + lower)/2; 
    if(target < arr[middle])
    {
      upper = middle - 1;
    }
    else if(target > arr[middle])
    {
      lower = middle + 1;
    }
    else
    {
      return true;
    }
  }
  return false;
}


