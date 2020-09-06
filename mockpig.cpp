using namespace std;
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define random(a,b) (rand()%(b-a+1))+a
int divarea;
int samount,bwamount,bamount;
int psm,pdm;
double pwm;
int saleamount;
double sumprice;
int alldate[13];
int allweight[16];
int allspiece[4];
struct pig{
	int spiece;
	double weight;
	int days;
	pig *next=NULL; 
	int ipig=0;
};
class pigcircle{
	private:
		int sum;
		int ifblack;
		int number;
		pig *head;
		int is;
	public:
		pigcircle();
		int getnumber();
		int getsum();
		int getifblack();
		int getis();
		pig *gethead();
		void sendnumber(int i);
		void sendsum(int i);
		void sendifblack(int i);
		void sendhead(pig *p);
		void sendis(int i);
		int  searchspiece(int i);
		int  searchdays(int i);
		double searchweight(int i); 
		int pigcirclestatistics();
		void upping() ;
		void sale(); 
	    void insert(pig *p);
};
pigcircle::pigcircle()
{
	sum=0;
	ifblack=0;
	head=NULL;
} 
int pigcircle::getsum()
{
	return sum;
 }
int pigcircle::getnumber()
{
	return number;
}
pig* pigcircle::gethead()
{
	return head;
}
int pigcircle::getifblack()
{
	return ifblack;
}
int pigcircle::getis()
{
	return is;
}
void pigcircle::sendis(int i)
{
	is=i;
}
void pigcircle::sendnumber(int i)
{
	number=i;
}
void pigcircle::sendifblack(int i)
{
	ifblack=i;
}
void pigcircle::sendsum(int i)
{
	sum=i;
}
void pigcircle::sendhead(pig *p)
{
	head=p;
}
int pigcircle::searchspiece(int i)
{
	if(i>sum) return -1;
	int j;
	pig *p=head;
	for(j=1;j<i;j++)
	p=p->next;
	return p->spiece;
}
double pigcircle::searchweight(int i)
{
	if(i>sum) return -1;
	int j;
	pig *p=head;
	for(j=1;j<i;j++)
	p=p->next;
	return p->weight;
}
int pigcircle::searchdays(int i)
{
	if(i>sum) return -1;
	int j;
	pig *p=head;
	for(j=1;j<i;j++)
	p=p->next;
	return p->days;
}
int pigcirclestatistics(int t,int i,pigcircle pc[])
{
	int j;
	pig *p=pc[t].gethead();
	int ifblack1=pc[t].getifblack();
	samount=bwamount=bamount=0;
	if(ifblack1==1)
	{
		bamount=pc[t].getsum();
		return 1;
	}
	else 
	{
		while(p!=NULL)
		{
			if(p->spiece==2)
			samount+=1;
			else
			bwamount+=1;
			p=p->next;
		}
		return 2;
	}
}
void pigcircle::upping()
{
	pig *p=head;
	for(int i=1;i<=sum;i++)
	{
		p->weight=(random(0,12))/10.0;
		p->days+=1;
		p=p->next;
	}
}
void allupping(pigcircle pc[])
{
	int i;
	for(i=1;i<=100;i++)
	pc[i].upping();
	cout<<'s'<<endl;
}
void pigcircle::sale()
{
 	int i=1;
 	pig *p=head,*p1,*p2;
 	p1=head;
 	for(;i<=sum;i++)
 	{
 		if(p->weight>75||p->days>360)
 		{
 		  if(p->spiece==1)
		   	sumprice+=p->weight*15;
		   else if(p->spiece==2)
		   sumprice+=p->weight*7;
		   else
		   sumprice+=p->weight*6;
		   saleamount++;
		   if(p==head)
		   {
		   	p=p->next;
		   	head=p1=p;
		   }
		   else if(p1==p&&p!=head)
		   {
		   	p=p->next;
		   	p1=p;
		   }
		   if(p1!=p)
		   {
		   	p2=p;
		   	p1->next=p->next;
		   	p=p->next;   
		   }
		}
		else
		{
		 p1=p;
		 p=p->next;
	    }
	}
}
void saleall(pigcircle pc[])
{
	int i;
	saleamount=sumprice=0;
	for(i=1;i<=100;i++)
	pc[i].sale();
	ofstream destFile("buyandsale.txt",ios::app);
	destFile<<"sale"<<endl<<' '<<saleamount<<' '<<sumprice<<endl;
	destFile.close();
}
void initial(pigcircle pc[])
{
	srand(time(NULL));
	int i,j;
	pig *p,*p1,*q;
	for(i=1;i<=100;i++)
	{
		p1=pc[i].gethead();
		pc[i].sendsum(10);
		pc[i].sendnumber(i);
		if(i<=30)
		{
			pc[i].sendifblack(1);
			for(j=1;j<=10;j++)
			{
			p=new pig;
			p->spiece=1;
			p->weight=(random(200,500))/10.0;
			p->days=0;
			p->next=NULL;
			if(p1==NULL)
			p1=p;
			else
			q->next=p;
			q=p;
			q->next=NULL;
		    }
		}
		else
		{
			pc[i].sendifblack(0);
			for(j=1;j<=10;j++)
			{
			p=new pig;
			p->spiece=random(2,3);
			p->weight=(random(200,500))/10.0;
			p->days=0;
			p->next=NULL;
			if(p1==NULL)
			p1=p;
			else
			q->next=p;
			q=p;
			q->next=NULL;
		    }
		}
	}
	divarea=31;
}
void outFile(pigcircle pc[])
{
	ofstream destFile("pigsmessage.txt",ios::out);
	int i,j,sum;
	pig *p,*p1; 
	for(i=1;i<=100;i++)
	{
		p=pc[i].gethead();
		sum=pc[i].getsum();
		destFile<<pc[i].getnumber()<<endl;
		for(j=1;j<=sum;j++)
		{
			destFile<<p->spiece<<' '<<p->weight<<' '<<p->days<<endl;
			p1=p;
			p=p->next; 
		}
	}
	 destFile.close();
}
void inFile(pigcircle pc[])
{
	ifstream srcFile("pigsmessage.txt",ios::in);
	pig *p,*p1;
	int i,j,sum,t;
	for(i=1;i<=100;i++)
	{
		sum=pc[i].getsum();
		srcFile>>t;
		pc[i].sendnumber(t);
		for(j=1;j<=sum;j++)
		{
			p1=new pig;
			srcFile>>p1->spiece>>p1->weight>>p1->days;
			if(j==1) p=p1;
			else
			{
				p->next=p1;
				p=p1;
			}
		}
	}
	srcFile.close();
}
void allmember(pigcircle pc[])
{
	int i,sum,j,t;
	for(i=1;i<=100;i++)
	{
		sum=pc[i].getsum();
		for(j=1;j<=sum;j++)
		{
			allspiece[pc[i].searchspiece(j)]++;
			alldate[pc[i].searchdays(j)/31]++;
			allweight[int(pc[i].searchweight(j)/11.0)]++;
		}
	}
}
int buypigs(pigcircle pc[],int bp,int wp,int sp)
{
	ofstream destFile("buyandsale.txt",ios::app);
	destFile<<"buy"<<endl<<"black pig"<<' '<<bp<<endl<<"big white big"<<' '<<wp<<endl<<"samll white pig"<<' '<<sp<<endl;
	destFile.close();
	int i,sum=0,ave,gs,fg,j;
	pig *p,*np,*p1;
	for(i=1;i<divarea;i++)
	sum+=pc[i].getsum();
	sum+=bp;
	if(sum>divarea*10-10) return 0;
	ave=(sum/(divarea-1))+1; 
	for(i=1;i<divarea&&bp!=0;i++)
	{
		gs=pc[i].getsum();
		if(gs>=ave) continue;
		p=pc[i].gethead();
		pc[i].sendsum(ave);
		for(j=1;j<gs;j++)
		p=p->next;
		 for(j=gs+1;j<=ave&&bp!=0;j++)
		 {
		 	np=new pig;
		 	np->spiece=1;
	        np->weight=(random(200,500))/10.0;
	        np->days=0;
	        p->next=np;
	        bp--;
		 }
	 }

    for(i=divarea;i<=100;i++)
	sum+=pc[i].getsum();
	sum+=wp+sp;
	int ap=wp+sp;
	if(sum>(101-divarea)*10) return 0;
	ave=sum/(101-divarea)+1;
	for(i=divarea;i<=100&&ap!=0;i++)
	{
		gs=pc[i].getsum();
		if(gs>=ave) continue;
		p=pc[i].gethead();
		pc[i].sendsum(ave);
		for(j=1;j<gs;j++)
		p=p->next;
		 for(j=gs;j<=ave&&ap!=0;j++)
		 {
		 	np=new pig;
		 	np->spiece=random(2,3);
	        np->weight=(random(200,500))/10.0;
	        np->days=0;
	        p->next=np;
	        ap--;
		 }
	 }
	 return 1;
}
int isf(int i,int p,pigcircle pc[])
{
	srand(time(NULL));
	 int isamount=0,d=0;
	int j,sum,c,flag,is,is1,is2,t;
	pig *p1;
	p1=pc[i].gethead();
	cout<<p1->weight<<endl;
	sum=pc[i].getsum();
	pc[i].sendis(1);
	for(j=1;j<sum;j++)
	{
	p1=p1->next;
	cout<<'a';
	} 
	p1->ipig=1;
	while(isamount<100)
	{ 
	for(t=i;t>=0;t--)
	{
		is=pc[t].getis();
		sum=pc[t].getsum();
		if(sum==0||sum==is)  continue;
		else if(is>0)
		{
		  p1=pc[t].gethead();
		  for(j=1;j<=sum;j++)
		  {
		  	if(p1->ipig==0)
		  	{
		  		c=random(1,100);
		  		if(c<=50) 
		  		{
		  		 	p1->ipig=1;
		  		 	is++;
		  		 	isamount++;
				}
			}
			p1=p1->next;
		  }
		} 
		else if(is==0&&sum>0)
		{
			if(t-1>0) is1=pc[t-1].getis();
			else is1=0;
			is2=pc[t+1].getis();
			if(is2>0||is1>0)
			{
				p1=pc[t].gethead();
				for(j=1;j<=sum;j++)
				{
					c=random(1,100);
					if(c<=15) 
					{
						is++;
						isamount++;
						p1->ipig=1;
					}
					    p1=p1->next;
				}
			}
		}
		pc[t].sendis(is);
	}
	for(t=i+1;t<=100;t++)
	{
		is=pc[t].getis();
		sum=pc[t].getsum();
		if(sum==0||sum==is)  continue;
		else if(is>0)
		{
		  p1=pc[t].gethead();
		  for(j=1;j<=sum;j++)
		  {
		  	if(p1->ipig==0)
		  	{
		  		c=random(1,100);
		  		if(c<=50) 
		  		{
		  		 	p1->ipig=1;
		  		 	is++;
		  		 	isamount++;
				}
			}
			p1=p1->next;
		  }
		} 
		else if(is==0&&sum>0)
		{
			if(t+1<=100) is2=pc[t+1].getis();
			else is2=0;
			is1=pc[t-1].getis();
			if(is1>0||is2>0)
			{
				p1=pc[t].gethead();
				for(j=1;j<=sum;j++)
				{
					c=random(1,100);
					if(c<=15) 
					{
						is++;
						p1->ipig=1;
						isamount++;
					}
					    p1=p1->next;
				}
			}
		}
		pc[t].sendis(is);
	}
	d++;
}
return d;
}
int main()
{
	pigcircle pc[101];
	initial(pc);
	cout<<pc[60].searchspiece(5);
 } 
