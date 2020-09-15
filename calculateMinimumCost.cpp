#include <vector>
#include <iostream>

void calculateMimimumCost(std::vector<std::vector<int>> costMatrix)
{
  std::vector<int> minimumCost;
  std::vector<int> path(costMatrix.size());
  int minimizer;

  for(int i=0; i<costMatrix.size(); i++)
  {
    int min = costMatrix[0][i];
    minimizer = 0; 
    for(int j=0; j<minimumCost.size(); j++)
    {
      if(minimumCost[j]+costMatrix[j][i]<min)
      {
        min = minimumCost[j]+costMatrix[j][i];
        minimizer = j;
      }
    }
    minimumCost.push_back(min);
    path[i] = minimizer;
  }
  std::cout << "Path: ";
  int index = path.size()-1;
  std::cout << index << " ";
  while(index > 0)
  {
    std::cout << path[index] << " ";
    index = path[index];
  }
  std::cout << std::endl;
  std::cout << "Minimum cost: " << minimumCost[costMatrix.size()-1] << std::endl;

}

int main()
{
  std::vector<std::vector<int>> costMatrixA {
                        {0, 20, 30, 100},
                        {20, 0, 15, 75 },
                        {30, 15, 0, 50 },
                        {100, 75, 50, 0}
                      };
  std::vector<std::vector<int>> costMatrixB {
                        {0, 25, 20, 10, 105},
                        {20, 0, 15, 80, 80 },
                        {30, 15, 0, 70, 90 },
                        {10, 10, 50, 0, 100},
                        {40, 50, 5, 10, 0  }
                      };
  calculateMimimumCost(costMatrixA);
  calculateMimimumCost(costMatrixB);
  return 0;
}

