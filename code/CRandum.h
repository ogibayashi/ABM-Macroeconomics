//CRandum.h
#ifndef INC_CRandum
#define INC_CRandum
#define N 310
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
class CRandum
{
public:
	CRandum();
	CRandum(int p);
	double strand();
	int strand(int n1,int n2);
	long long strand_l(long long n1,long long n2);
	double sdrand(double min,double max);
	double seiki(double a,double b);
	double shisu(double ave);
	double kaijyou(int n);
	void erlan(double x,int k,double ramda,double *f,double *fint);
	double erland(int k,double ramda);
	void kentei(int n1,int n2,int n);
};


double CRandum::sdrand(double min,double max)
{
	double y;
	y=min+rand()/float(RAND_MAX)*(max-min);
	return y;
}
double CRandum::strand()
{
	double y;
	y=rand()/float(RAND_MAX);
	return y;
}
void CRandum::kentei(int n1,int n2,int n)
{
	int i,j;int *sum=new int[n2+2];
	for(j=n1;j<=n2+1;j++) sum[j]=0;
	for(i=0;i<n;i++){
		for(j=n1;j<=n2;j++) if(strand(n1,n2)==j) sum[j]++;
	}
	for(j=n1;j<=n2+1;j++) printf(" %4d %4d \n",j,sum[j]);
}
int CRandum::strand(int n1,int n2)
{
	//n1����n2�̐��������𔭐�������
	int y;
	y=n1+int(rand()/float(RAND_MAX)*(n2-n1+1));
	if(y>n2) y=n2;
	return y;
}
long long CRandum::strand_l(long long n1,long long n2)
{
	//n1����n2�̐��������𔭐�������
	long long y;
	y=n1+long(rand()/float(RAND_MAX)*(n2-n1+1));
	if(y>n2) y=n2;
	return y;
}
double CRandum::shisu(double ave)
{
	double y,Na,ramda;
	ramda=1/ave;
	//y=strand();
y=rand()/float(RAND_MAX);
	Na=-log(1-y)/ramda;
	return Na;
}
CRandum::CRandum()
{
	//��l�����̏�����
	srand((unsigned)time(NULL));  //�����ŏ�����
	//printf("�����ŏ��������܂�\n");
}
CRandum::CRandum(int p)
{
	//��l�����̏�����
	//if(p<10) srand(p);
	//else srand(5);
	printf("srand(%d)�ŏ��������܂�\n",p);
}
double CRandum::seiki(double a,double b)
{
	double sum1,y,Nab;
	int i;
		sum1=0.0;
			for(i=1;i<=12;i++){
				y=strand();
				sum1+=y;
				}
		Nab=sqrt(b)*(sum1-6)+a;//���K���z�����̒l
		return Nab;
}
double CRandum::erland(int k,double ramda)
{
	double yr,x,xnew[N],Na,ips,f,fint;
	int j,Ns=31;
		ips=0.001;
			yr=strand();//0-1 ��l�����̔���
			xnew[0]=1/ramda;//Newton�@�̏����l
			for(j=0;j<Ns;j++)
			{
				//Newton�@�ŉ��iyr�ɑΉ�����x�̒l)�����߂�
				x=xnew[j];
			erlan(x,k,ramda,&f,&fint);//fint:���z�֐��i�m�����x�֐��̐ϕ��l�j
			if(f==0) f=0.0001;
			xnew[j+1]=xnew[j]-(fint-yr)/f;
			Na=xnew[j+1];
			if(fabs(xnew[j+1]-xnew[j])<ips) goto out;
			}
out:
			return Na;
}
void CRandum::erlan(double x,int k,double ramda,double *f,double *fint)
{
	double a,c,sum,y,dy,f1,f2;
	int p;
	c=ramda*k;
	p=k-1;
	a=kaijyou(p);
	*f=pow(c,k)*pow(x,p)*exp(-c*x)/a;	//erlan���z�֐�f(x)�̒l
	/*x���l�ϕ�*/
	*fint=0.;
		dy=0.001;
		y=0.;
		sum=0.;
		while(y<=(x-dy))
		{
			f1=pow(c,k)*pow(y,p)*exp(-c*y)/a;
			f2=pow(c,k)*pow((y+dy),p)*exp(-c*(y+dy))/a;
			sum=sum+(f1+f2)/2.*dy;
			y=y+dy;
		}
		*fint=sum;
}
double CRandum::kaijyou(int n)
{
	int k,ns;double pai;
	ns=n;
	pai=1;
	for(k=1;k<=ns;k++) pai=(pai)*(ns-k+1);
	return pai;
}


#endif
