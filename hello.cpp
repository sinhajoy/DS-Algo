#include<bits/stdc++.h>
#include<cmath>
using namespace std;
float area(int dX0, int dY0, int dX1, int dY1, int dX2, int dY2)
{
    float dArea = (float)((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}
struct same
{
	int i;
	int r;
};

vector<float> bleft(vector<same> sm,vector<float> v,vector<float> bl)
{
	vector<int> r;
	for (int i = 0; i < sm.size(); ++i)
	{
		r.push_back(sm[i].r);	
	}
	r.push_back(-1);
	for (int i = 0; i < v.size(); ++i)
	{
		if(find(r.begin(),r.end(),i)==r.end())
		{
			bl.push_back(v[i]);
		}
	}
	return bl;
}

vector<vector<int>> dtleft(vector<vector<int>>dt,vector<same> sm,vector<vector<int>>dtl)
{
	vector<int> lf;
	for (int i = 0; i < sm.size(); ++i)
	{
		lf.push_back(sm[i].i);	
	}
	lf.push_back(-1);
	for (int i = 0; i < dt.size(); ++i)
	{
		if(find(lf.begin(),lf.end(),i)==lf.end())
		{
			dtl.push_back(dt[i]);
		}
	}
	return dtl;	
}

vector<same> check(int x[],int y[],vector<vector<int>>dt,vector<float> b,vector<same> sm)
{
	int m=dt.size();
	int p1,p2,p3;
	float ar;
	struct same s1;
	vector<same> ns;
	vector<float>::iterator it;
	int l;
	for (int i = 0; i < m; ++i)
	{
		p1=dt[i][0];
		p2=dt[i][1];
		p3=dt[i][2];
		ar=area(x[p1+1],y[p1+1],x[p2+1],y[p2+1],x[p3+1],y[p3+1]);
		it=find(b.begin(),b.end(),2*ar);
		if (it!=b.end())
		{
			l=it-b.begin();
			s1.i=i;
			s1.r=l;
			sm.push_back(s1);
		}	
	}
	return sm;
}

vector<vector<int>> sortar(int x[],int y[],vector<vector<int>>dt,vector<vector<int>> x2)
{
	int f=x2.size();
	float ar[f],a;
	vector<int> x1;
	for (int i = 0; i < f; ++i)
	{
		int p1,p2,p3,p4,p5,p6;
		p1=dt[x2[i][0]][0];
		p2=dt[x2[i][0]][1];
		p3=dt[x2[i][0]][2];
		p4=dt[x2[i][1]][0];
		p5=dt[x2[i][1]][1];
		p6=dt[x2[i][1]][2];
		ar[i]=area(x[p1+1],y[p1+1],x[p2+1],y[p2+1],x[p3+1],y[p3+1])+area(x[p4+1],y[p4+1],x[p5+1],y[p5+1],x[p6+1],y[p6+1]);
	}
	for (int i = 0; i < f; ++i) 
    {
        for (int j = i + 1; j < f; ++j)
        {
            if (ar[i] > ar[j]) 
            {
 
                a =  ar[i];
                ar[i] = ar[j];
                ar[j] = a;
                x1=x2[i];
                x2[i]=x2[j];
                x2[j]=x1;
            }
 
        }
 
    }
    return x2;
}

vector<vector<int>> rem(vector<vector<int>> x, int rt1,int rt2)
{
	int k=x.size();
	for (int i = 0; i < k; ++i)
	{
		if(x[i][0]==rt1||x[i][1]==rt2){
			x.erase(x.begin()+i);
		}
	}
	return x;
}

vector<int> findquad(vector<vector<int>>dt,vector<float> v,int x[],int y[])//dt=dtl,v=bl;
{
	int p1,p2,p3,p4,p5,p6,c;
	vector<int> u1;
	vector<vector<int>> x3;
	for (int i = 0; i < dt.size(); ++i)
	{
		p1=dt[i][0];
		p2=dt[i][1];
		p3=dt[i][2];
		c=0;
		for (int j = i+1; j < dt.size(); ++j)
		{
			p4=dt[j][0];
			p5=dt[j][1];
			p6=dt[j][2];
			if(p4==p1||p4==p2||p4==p3)
				c++;
			if(p5==p1||p5==p2||p5==p3)
				c++;
			if(p6==p1||p6==p2||p6==p3)
				c++;		
			if(c==2)
				x3.push_back({i,j});
		}
	}
	int k=v.size(), y1=x3.size();
	int g=0,qw1,qw2,upoint=0;
	x3=sortar(x,y,dt,x3);
	int l1,l2;
	while(k--)
	{
		qw1=x3[g][0];
		qw2=x3[g][1];
		p1 =dt[qw1][0];
		p2=dt[qw1][1];
		p3=dt[qw1][2];
		p4=dt[qw2][0];
		p5=dt[qw2][1];
		p6=dt[qw2][2];

		if(1){
		if(p1==p4){
			u1.push_back(p1);	
		}
		else
		if(p1==p5){
			u1.push_back(p1);
		}
		else
		if(p1==p6){
			u1.push_back(p1);
		}
		if(p2==p4){
			u1.push_back(p2);
		}
		else
		if(p2==p5){
			u1.push_back(p2);
		}
		else
		if(p2==p6){
			u1.push_back(p2);
		}
		if(p3==p4){
			u1.push_back(p3);
		}
		else
		if(p3==p5){
			u1.push_back(p3);
		}
		else
		if(p3==p6){
			u1.push_back(p3);
		}
		x3=rem(x3,qw1,qw2);
		}
	}
	return u1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,r;
	cin>>n>>m>>r;
	vector<int> u1;
	vector<same> sm;
	int x[n+2]={-1},y[n+2]={-1};
	for (int i = 0; i < n; ++i)
	{
		cin>>x[i+1]>>y[i+1];
	}
    vector<vector<int> > dt;
    vector<vector<int> > dtl;
    int p[3];
    for (int i = 0; i < m; ++i)
    {
    	cin>>p[0]>>p[1]>>p[2];
    	sort(p,p+3);
    	dt.push_back({p[0],p[1],p[2]});
    }
    float b1;
    vector<float> b;
    vector<float> bl;
    for (int i = 0; i < r; ++i)
    {
		cin>>b1;
		b.push_back(b1); 
    }
    sm=check(x,y,dt,b,sm);
    dtl=dtleft(dt,sm,dtl);
    bl=bleft(sm,b,bl);
    u1=findquad(dtl,bl,x,y);
    int lio=u1.size();
    cout<<0<<"\n"<<lio/2;
    for (int i = 0; i < lio/2; ++i)
    {
    	cout<<u1[2*i]<<u1[2*i+1]<<"\n";
    }
    return 0;

}
