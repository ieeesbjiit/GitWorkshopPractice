#include<bits/stdc++.h>
using namespace std;

void build(int v,int tl,int tr,long long st[],int a[])
{
    if(tl==tr)
    {
        st[v]=a[tl];
    }
    else
    {
        build(2*v,tl,(tl+tr)/2,st,a);
        build(2*v+1,(tl+tr)/2+1,tr,st,a);
        st[v]=st[v*2]+st[v*2+1];
    }
    return;
}

void update(int v,int tl,int tr,int pos,int val,long long st[])
{
    if(pos<tl||pos>tr)
    {
        return;
    }
    else if(pos==tl&&pos==tr)
    {
        st[v]=val;
    }
    else
    {
        update(2*v,tl,(tl+tr)/2,pos,val,st);
        update(2*v+1,(tl+tr)/2+1,tr,pos,val,st);
        st[v]=st[v*2]+st[v*2+1];
    }
    return;
}

long long query(int v,int tl,int tr,int l,int r,long long st[])
{
    if(r<tl||l>tr||r<l)
    {
        return 0;
    }
    else if(l==tl&&r==tr)
    {
        return st[v];
    }
    else
    {
        return query(v*2,tl,(tl+tr)/2,l,min(r,(tl+tr)/2),st) +
            query(2*v+1,(tl+tr)/2+1,tr,max(l,(tl+tr)/2+1),r,st);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,q;
    cin>>n>>q;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    long long st[4*(n+1)];

    build(1,1,n,st,a);

    for(int i=1;i<=q;i++)
    {
        int type;
        cin>>type;

        if(type==1)
        {
            int k,x;
            cin>>k>>x; // a[k]=x;

            update(1,1,n,k,x,st);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            cout<<query(1,1,n,l,r,st)<<'\n';
        }
    }


    return 0;
}
