/*
codeforces
4A. Watermelon

*/
#include<iostream>
using namespace std;
int main()
{
  #ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
#endif
  int weight;
  cin>>weight;
  if(weight%2==0 && weight>=4)
  {
    cout<<"YES";
  }
  else
  {
    cout<<"NO";
  }
  return 0;
}