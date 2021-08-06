#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<memory.h>
#include<vector>
#include<cmath>

using namespace std;

#define INF 2e9
int n,k;

int tree[400000]; 

//arr는 입력받은 배열, tree는 세그먼트 트리 배열.
int middle(int node,int start, int end, int index) 
{
  if(start==end)
  {
    return start;
  }

  int mid = (start + end) / 2;

  if(tree[node*2]>=index)
    return middle(node*2,start,mid,index);
  else
    return middle(node*2+1,mid+1,end,index-tree[node*2]);
}
void update(int node,int start,int end,int index,int val) 
{
  if(start>index || index>end)
    return;
  
  tree[node] += val;
    
  if(start!=end)
  {
    int mid = (start+end)/2;
    update(node*2,start,mid,index,val);
    update(node*2+1,mid+1,end,index,val);
  }
}
int main()                             
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 
  cin >> n >> k;

  //init
  for(int i=1;i<=n;i++)
    update(1,1,n,i,1);

  int index = 1; //움직이는 인덱스
  cout << "<";
  for(int i=1;i<=n;i++)
  {
    int size = n-i+1; //전체 사람.
    index += k-1; //다음 순번.

    if(index%size==0) 
      index = size;
    else if(index>size) 
      index %= size;

    int idx = middle(1,1,n,index); 
    update(1,1,100000,idx,-1);
    if(i==n)
      cout << idx;
    else
      cout << idx << ", ";
  }
  cout << ">";
  
  return 0;
}