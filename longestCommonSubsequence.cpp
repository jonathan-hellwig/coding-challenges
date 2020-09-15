#include <iostream>
#include <string>
#include <cmath>

int lcs(std::string x, std::string y);
int main(int argc, char* argv[])
{
  std::string x = "ABCBDAB";
  std::string y = "BDCABA";
  std::cout << x << " " << y << " : " << lcs(x,y) << std::endl;
  return 0;
}

int lcs(std::string x, std::string y)
{
  int n = x.length();
  int m = y.length();

  int d[n+1][m+1];
  for(int i=0; i<n; i++)
    d[i][0] = 0;
  for(int j=0; j<m; j++)
    d[0][j] = 0;

  for(int i=1; i<n+1; i++)
  {
    for(int j=1; j<m+1; j++)
    {
      if(x[i] == y[j])
      {
        d[i][j] = d[i-1][j-1] + 1;
      }
      else 
      {
        d[i][j] = std::max(d[i-1][j], d[i][j-1]);
      }
    }
  }
  return d[n][m];
}


