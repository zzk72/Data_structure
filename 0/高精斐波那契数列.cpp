#include <iostream>
//´íÎó 
using namespace std;
int arr[3][500]={{0}};
int main(){
	int i,j,ex,tmp,n; 
    
    arr[1][1]=1;
    arr[2][1]=1;
    
	cin>>n;
	for(i=3;i<=n;i++){
		ex=0;tmp=0;
		for(j=1;j<=500;j++){
			tmp=arr[1][j]+arr[2][j]+ex;
			arr[1][j]=arr[2][j];
			arr[2][j]=tmp%1000000000;
			ex=tmp/1000000000;
		}
	}

	for(i=500;arr[2][i]==0;i--);
	ex=arr[2][i];
	int len=0;
	while(ex>0){
		ex/=10;
		len++;
	}
	len+=(i-1)*9;
	cout<<len<<endl;
	for(i;i>=1;i--)
		cout<<arr[2][i];
	
    return 0;
}

