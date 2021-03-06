#define pushS(x) sa[--bkt[s[x]]] = x  
#define pushL(x) sa[bkt[s[x]]++] = x
#define induce_sort(v){\
	fill_n(sa,n,0);\
	copy_n(_bkt,A,bkt);\
	for(i=n1-1;~i;--i)pushS(v[i]);\
	copy_n(_bkt,A-1,bkt+1);\
	for(i=0;i<n;++i)if(sa[i]&&!t[sa[i]-1])pushL(sa[i]-1);\
	copy_n(_bkt,A,bkt);\
	for(i=n-1;~i;--i)if(sa[i]&&t[sa[i]-1])pushS(sa[i]-1);\
}
template<typename T>
void sais(const T s,int n,int *sa,int *_bkt,int *p,bool *t,int A){
	int *rnk=p+n,*s1=p+n/2,*bkt=_bkt+A;
	int n1=0,i,j,x=t[n-1]=1,y=rnk[0]=-1,cnt=-1;
	for(i=n-2;~i;--i)t[i]=(s[i]==s[i+1]?t[i+1]:s[i]<s[i+1]);
	for(i=1;i<n;++i)rnk[i]=t[i]&&!t[i-1]?(p[n1]=i,n1++):-1;
	fill_n(_bkt,A,0);
	for(i=0;i<n;++i)++_bkt[s[i]];
	for(i=1;i<A;++i)_bkt[i]+=_bkt[i-1];
	induce_sort(p);
	for(i=0;i<n;++i)if(~(x=rnk[sa[i]]))
		j=y<0||memcmp(s+p[x],s+p[y],(p[x+1]-p[x])*sizeof(s[0]))
		,s1[y=x]=cnt+=j;
	if(cnt+1<n1)sais(s1,n1,sa,bkt,rnk,t+n,cnt+1);
	else for(i=0;i<n1;++i)sa[s1[i]]=i;
	for(i=0;i<n1;++i)s1[i]=p[sa[i]];
	induce_sort(s1);
}