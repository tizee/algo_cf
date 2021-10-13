#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll=long long;

vector<int> digits(ll num){
  vector<int> res;
  while(num>10){
    res.push_back(num%10);
    num/=10;
  }
  if(num>0){
    res.push_back(num);
  }
  reverse(res.begin(),res.end());
  return res;
}

int max(int a,int b){
  return a>b?a:b;
}

int min(int a,int b){
return a>b?b:a;
}

ll get_val(vector<int>&nums,vector<bool> &removed){
  ll res=0;
  int end = nums.size();
  int count=0;
  for(ll i = 0;i<nums.size();i++){
    if(!removed[i]){
      count++;
    }
  }
  for(int i = nums.size()-1;i>0;i--){
    if(nums[i]!=0&&!removed[i]){
      break;
    }
    if(nums[i]!=0&&nums[i-1]==0&&removed[i]){
      end= i;
    }
  }

  while(end<nums.size()&&end>0&&nums[end-1]==0){
    end--;
  }

  for(int i = 0;i<end;i++){
    if(!removed[i]){
      res = res*(ll)10+(ll)nums[i];
      count--;
    }
  }
  if(count>0){
    res*=10;
  }
  return res;
}

void backtracking(int &steps,vector<int> &nums, vector<bool> &removed, int count,int cur_idx){
  if(count<=2 || cur_idx == nums.size()){
    return;
  }
  // 25 50 75 100
  for(ll i = cur_idx;i<nums.size();i++){
    if(!removed[i]){
      removed[i]=true;
      ll val = get_val(nums,removed);
      if(val>0&&val%(ll)25==0){
        cout<<"n:"<<nums.size()<<",count:"<<count<<",steps:"<<steps<<endl;
        cout<<"val:"<<val<<endl;
        steps = min(nums.size()-count+1,steps);
        removed[i]=false;
        return;
      }
      backtracking(steps, nums, removed, count-1,cur_idx+1);
      removed[i]=false;
    }
  }

}

int main(int argc, char *argv[])
{
  int n;
  ll num;
  cin>>n;
  while(n>0){
    cin>>num;
    // corner case
    int steps=0;
    if(num%(ll)25!=0){
      steps=INT_MAX;
      vector<int> nums=digits(num);
      vector<bool> removed(nums.size(),false);
      backtracking(steps,nums,removed,nums.size(),0);
    }
    cout<<steps<<endl;
    n--;
  }
  return 0;
}

