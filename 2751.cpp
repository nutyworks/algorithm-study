#include <iostream>

using namespace std;

#include<cstdlib>
#include<cstring>
#define Z template<typename T>
Z inline void e(T*a,T*b){T c=*a;*a++=*b;*b++=c;}
Z inline void t(T*a,T*b,int n){while(n--)e(a++,b++);}
Z static void a(T*e,int t,int a,int o,int(*i)(T*,T*)){int n=t+a+o-1,s=t+a-1,h=t-1;while(h>=0){if(s<t||i(e+h,e+s)>0){e[n--]=e[h--];}else{e[n--]=e[s--];}}if(s!=n)while(s>=t)e[n--]=e[s--];}
Z static void o(T*e,int t,int a,int o,int(*i)(T*,T*)){int n=0,s=t;a+=t;while(s<a){if(n==t||i(e+n,e+s)>0)e[o++]=e[s++];else e[o++]=e[n++];}if(o!=n)while(n<t)e[o++]=e[n++];}
Z static void i(T*e,T*t,int a,int o,int(*i)(T*,T*)){int n=0,s=0,h=-o;while(s<o){if(n==a||i(e+n,t+s)>=0)e[h++]=t[s++];else e[h++]=e[n++];}if(h!=n)while(n<a)e[h++]=e[n++];}
Z static void n(T*e,int*t,int*a,int o,int i,int(*n)(T*,T*)){int s=-i,h=0,r=*t,d=r,l=r+o,c=1-*a;while(h<d&&r<l){if(n(e+h,e+r)-c<0)e[s++]=e[h++];else e[s++]=e[r++];}if(h<d){*t=d-h;while(h<d) e[--l]=e[--d];}else{*t=l-r;*a=c;}}
Z static void s(int*e,int t,T*a,int i,int s,int h,int r,int(*d)(T*,T*)){int l,c,u,m,w,f,g,y;if(i==0){l=h*s;o(a,l,r,-s,d);return;}u=s;m=e[0]<t?0:1;w=s;for(f=1;f<i;f++,w+=s){c=w-u;g=e[f]<t?0:1;if(g==m){memcpy(a+c-s,a+c,u*sizeof(T));c=w;u=s;}else{n(a+c,&u,&m,s,s,d);}}c=w-u;if(r){y=w+s*h;if(m){memcpy(a+c-s,a+c,u*sizeof(T));c=w;u=s*h;m=0;}else{u+=s*h;}o(a+c,u,r,-s,d);}else{memcpy(a+c-s,a+c,u*sizeof(T));}}
Z static void h(T*e,int L,int K,int(*t)(T*,T*)){int m,u,h,i,n,s,z,p;for(m=1;m<L;m+=2){u=0;if(t(e+(m-1),e+m)>0)u=1;e[m-3]=e[m-1+u];e[m-2]=e[m-u];}if(L%2)e[L-3]=e[L-1];e-=2;for(h=2;h<K;h*=2){i=0;n=L-2*h;while(i<=n){o(e+i,h,h,-h,t);i+=2*h;}s=L-i;if(s>h){o(e+i,h,s-h,-h,t);}else{for(;i<L;i++)e[i-h]=e[i];}e-=h;}z=L%(2*K);p=L-z;if(z<=K)memcpy(e+p+K,e+p,z*sizeof(T));else a(e+p,K,z-K,K,t);while(p>0){p-=2*K;a(e+p,K,K,K,t);}}
Z static void h(T*t,int a,int(*o)(T*,T*)){int i,j;for(i=1;i<a;i++){for(j=i-1;j>=0 && o(t+(j+1),t+j)<0;j--)e(t+j,t+(j+1));}}
Z static void r(T*e,int z,int a,int o,int *n,int(*h)(T*,T*)){int r,d,b,l,c,m,u,i,p,v,w,f,g;T*y;r=z/(2*a);m=z%(2*a);d=(2*a)/o;if(r==0)d=(r-1)/o+1;if(m<=a){z-=m;m=0;}for(b=0;b<=r;b++){if(b==r && m==0)break;y=e+b*2*a;l=(b==r?m:2*a)/o;u=l+(b==r?1:0);for(i=0;i<=u;i++)n[i]=i;c=a/o;for(u=1;u<l;u++){p=u-1;for(v=u;v<l;v++){w=h(y+p*o,y+v*o);if(w>0||(w==0&&n[p]>n[v]))p=v;}if(p!=u-1){t(y+(u-1)*o,y+p*o,o);i=n[u-1];n[u-1]=n[p];n[p]=i;}}f=g=0;if(b==r)g=m%o;if(g!=0){while(f<l && h(y+l*o,y+(l-f-1)*o)<0)f++;}s(n,c,y,l-f,o,f,g,h);}for(p=z;--p>=0;)e[p]=e[p-o];}
Z void d(T*e,int t,T*a,int*o,int(*n)(T*,T*)){int s,l;if(t<16){h(e,t,n);return;}s=1;while(s*s<t)s*=2;memcpy(a,e,s*sizeof(T));d(a,s,e,o,n);h(e+s,t-s,s,n);l=s;while(t>(l*=2)){r(e+s,t-s,l,s,o,n);}i(e+s,a,t-s,s,n);}
Z void sqrtsort(T*arr,int nel,int(*compar)(T*,T*)){int e=1;T*t,*a;while(e*e<nel)e*=2;int o=(nel-1)/e+2;t=(T*)malloc(e*sizeof(T));if(t==NULL)return;a=(int*)malloc(o*sizeof(int));if(a==NULL)return;d(arr,nel,t,a,compar);free(a);free(t);}

int cmp(int *a, int *b) {
	return *a - *b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, *arr;
	cin >> n;

	arr = (int*) malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		arr[i] = t;
	}

	sqrtsort<int>(arr, n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	free(arr);

	return 0;
}
