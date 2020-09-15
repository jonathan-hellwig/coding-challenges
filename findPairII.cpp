#include <iostream>
#include <unordered_set>

bool findPair(int* arr, int N, int sum);
int main(int argc, char* argv[])
{
  int N = 6;
  int arr[N] = {8,7,2,5,3,1};
  for(int sum = 0; sum<=15; sum++)
  {
    if(findPair(arr, N, sum))
    {
      std::cout << "Sum=" << sum << " Pair found!" << std::endl;
    }
    else
    {
      std::cout << "Sum=" << sum << "No pair found!" << std::endl;
    }
  }
  
  return 0;
}
bool findPair(int* arr, int N, int sum)
{
  std::unordered_set<int> set;
  for(int i=0; i<N; i++)
  {
    if(set.count(sum-arr[i]))
      return true;
    set.insert(arr[i]);
  }
  return false;
}
