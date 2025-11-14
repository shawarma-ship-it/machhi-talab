#define swap(x,y,t){t=x;x=y;y=t;}
#define biggest(a,b,m){m=(a>b)?a:b;}
#include<stdio.h>
int max=1;
int product(int str[],int hi,int lo){
    int m=(hi+lo)/2;
    
    if(lo>=hi){
        return str[hi];
    }
    
    biggest((product(str,hi,m+1)),(product(str,m,lo)),max);
    int prod=(product(str,hi,m+1))*(product(str,m,lo));
    if(prod<max){
        return max;
    }
    else{
        max=prod;
        return max;
    }
    
    
}


int main(){
    int n,temp;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    
    printf("Enter array: ");
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				swap(a[j+1],a[j],temp);
			}
		}
	}
	
	int max_product=product(a,n,0);
	printf("Max product is %d",max_product);
	return 0;
}