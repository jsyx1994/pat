// this is the divide-and-conquer algorithom
#include <iostream>
#include<vector>
#include<limits.h>
int di,dj;
using namespace std;
int findcross(const vector<int> v,int low,int mid,int high,int &i,int &j)
{
    int lri,lrj,rri,rrj;
    int sum = 0;
    int lmax = -INT_MAX;
    lrj = mid;
    for(int k = mid;k >=low;--k)
    {
        sum += v[k];
        if(lmax <= sum)
        {
            lmax = sum;
            lri = k;
        }
    }
    sum = 0;
    int rmax = -INT_MAX;
    rri = mid+1;
    for(int k = mid+1;k<=high;++k)
    {
        sum += v[k];
        if(rmax < sum)
        {
            rmax = sum;
            rrj = k;
        }
    }
    int maxx = max(max(lmax,rmax),lmax+rmax);
    if (maxx == lmax)
    {
        i = lri;
        j = lrj;

    }
    else if(maxx == lmax+rmax)
    {
        i = lri;
        j = rrj;
    }
    else if(maxx == rmax)
    {
        i = rri;
        j = rrj;
    }
    return maxx;
}
int dac(const vector<int> v,int low,int high,int & i,int & j)
{
    int li,lj,ri,rj,ci,cj;
    if(low == high) return v[low];
    int mid = (low+high)/2;
    int maxleft = dac(v,low,mid,li,lj);
    int maxright = dac(v,mid+1,high,ri,rj);
    int maxcross = findcross(v,low,mid,high,ci,cj);
    int maxx = max(max(maxleft,maxright),maxcross);
    /*if (maxx == maxleft)
    {
        di = li;
        dj = lj;
    }
    else if(maxx == maxcross)
    {
        di = ci;
        dj = cj;
    }
    else
    {
        di = ri;
        dj = rj;
    }*/
    di = ci;
    dj = cj;
    return maxx;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;++i)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int low = 0,high = n-1;
    int i,j;
    int maxx = dac(v,low,high,i,j);
    if(maxx < 0)
        cout << 0 << " " << v.at(0) << " " << v.at(n-1);
    else
    {
        cout << maxx << " ";
        cout << v.at(di) << " " << v.at(dj);
    }

    return 0;
}

