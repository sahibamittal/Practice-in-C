#include <stdio.h>

int search_missing(int a[], int low, int high, int diff);

int main()
{
	int arr[] = {1,3,5,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int diff = (arr[n-1]-arr[0])/n;
	int missing = search_missing(arr,0,n-1,diff);
	printf("Size of array : %d\n",sizeof(arr));
	printf("Size of one element : %d\n",sizeof(arr[0]));
	printf("Missing is %d\n", missing);
	return 0;
}

int search_missing(int a[], int low, int high, int diff){
	    
	// elements less than two - cannot be compared
	if(high <= low) 
	    return -1;
	int mid = (high+low)/2;
	int mid_ele = a[low]+(mid*diff);
	
	// if missing element is just before mid position
	if(mid>0 && a[mid]-a[mid-1] != diff)
	   return a[mid]-diff;
	
	// if missing element is just after mid position
	if(a[mid+1]-a[mid] != diff)
	    return a[mid]+diff;
	                           
	if(mid_ele != a[mid]) 
	    high = mid-1;
	else
	    low = mid+1; 
	                                                                  
	return search_missing(a,low,high,diff);
	
}
	                                                                                                                         
	                                                                                                                                 
	                                                                                               
