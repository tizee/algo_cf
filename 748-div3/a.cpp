#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int a,b,c;
  cin >> n;

  while(n>0){
    cin>>a>>b>>c;
    int diffA= max(b,c)-a+1, diffB= max(a,c)-b+1, diffC=max(a,b)-c+1;
    if(diffA<=0){
        diffA=0;
    }
    if(diffB<=0){
        diffB=0;
    }
    if(diffC<=0){
        diffC=0;
    }
    cout << diffA<<" "<<diffB<<" "<<diffC<<endl;
    n--;
  }
  return 0;
}
