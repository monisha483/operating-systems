#include<iostream.h>
#include<conio.h>
void main()
{clrscr();
int n,i,j,allo[3][3], max[3][3], need[3][3], avail[3], res[3],tota[3], work[3],f;
int finish[3];
cout<<"\nenter no. process;";
cin>>n;
cout<<"\nenter allo:";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>allo[i][j];

cout<<"\nenter max:";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cin>>max[i][j];

for(i=0;i<n;i++)
for(j=0;j<n;j++)
need[i][j]=max[i][j]-allo[i][j];

cout<<"\nenter resource";
for(i=0;i<n;i++)
{cin>>res[i]; tota[i]=0; finish[i]=1;}

for(i=0;i<n;i++)
for(j=0;j<n;j++)
tota[j]+=allo[i][j];

//disp col total of allo
cout<<"\ntota";
for(i=0;i<n;i++)
cout<<tota[i]<<' ';

cout<<"\navail\n";
for(i=0;i<n;i++)
{avail[i]=res[i]-tota[i];   work[i]=avail[i];
cout<<avail[i]<<' ';}

cout<<"\n need:\n";
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
 cout<<need[i][j]<<' ';
 cout<<'\n';}

int pos[3],k=0,safe[3];

int flag=n;
while(flag>0){  cout<<"\nwhilee\n";
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(finish[i]==1)
{ if(work[i]<need[i][j])
   {continue;}
  else
  { if(j==n-1)
    {for(int y=0;y<n;y++)
     work[y]=work[y]+allo[i][y];
     finish[i]=0;
     flag--;
     safe[k++]=i;}
     }
     }
if(flag==n) {cout<<"\ndeadlock.."; break;}     }
cout<<"\nsafe sequence:";
for(i=0;i<k;i++)
cout<<'p'<<safe[i]<<' ';
getch();}

