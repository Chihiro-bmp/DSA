// #include <stdio.h>
// #include <stdlib.h>

// void maxTripletSum(int arr[], int n) {

//     if(n<3){
//         printf("Invalid input\n");
//         return;
//     }
//     int max_sum=0;
//     int i, j, k;
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 int sum=arr[i]+arr[j]+arr[k];
//                 if(sum>max_sum){
//                     max_sum=sum;
//                 }
//             }
//         }
//     }
//     printf("%d\n",max_sum);
//     return;
// 	// Your code here 
// }

// int main() {
// 	int T, t, n, i;
// 	int *arr;
// 	FILE *fin, *fout;
// 	// Redirect input and output streams
// 	fin  = freopen("input.txt", "r", stdin);
// 	fout = freopen("output.txt", "w", stdout);

// 	// Input the number of test cases
// 	scanf("%d", &T);

// 	for (t = 0; t < T; t++) {
// 		// Input the size of  the array
// 		scanf("%d", &n);
// 		// Dynamically allocate the size of the array
// 		arr = (int *)malloc(n * sizeof(int));
// 		// Input the elements of the array
// 		for (i = 0; i < n; i++) {
// 		scanf("%d", &arr[i]);
// 		}
// 		// Find and print the max-triplet
// 		maxTripletSum(arr, n);
// 		free(arr);
// 	}
// 	// Close the file streams
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }


// 


// #include <stdio.h>
// #include <stdlib.h>

// void findSecondLargest(int arr[], int n) {

//     if(n<2){
//         printf("invalid input\n");
//         return;
//     }

//     int largest=arr[0];

//     int slargest;

//     for(int i=0;i<n;i++){
//         if(arr[i]>largest){
//             slargest=largest;
//             largest=arr[i];
//         }
//         else if(arr[i]>slargest&& arr[i]<largest){
//             slargest=arr[i];
//         }

//     }
//     if(slargest==largest){
//         printf("There are no second largest element\n");
//     }
//     printf("%d\n",slargest);
// 	// Your code here 
// }

// int main() {
// 	int T, t, n, i, second;
// 	int *arr;
// 	FILE *fin, *fout;
// 	// Redirect input and output streams
// 	fin  = freopen("input.txt", "r", stdin);
// 	fout = freopen("output.txt", "w", stdout);

// 	// Input the number of test cases
// 	scanf("%d", &T);

// 	for (t = 0; t < T; t++) {
// 		// Input the size of  the array
// 		scanf("%d", &n);
// 		// Dynamically allocate the size of the array
// 		arr = (int *)malloc(n * sizeof(int));
// 		 // Input the elements of the array
//     		for (i = 0; i < n; i++) {
//     			scanf("%d", &arr[i]);
// 		}
// 		// Find and print the second largest element
// 		findSecondLargest(arr, n);
// 		free(arr);
// 	}
// 	// Close the file streams
// 	fclose(fin);
// 	fclose(fout);
// 	return 0;
// }


// finding the missing odd number
#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);

    int a[n-1];

    for(int i=0;i<n-1;i++){
        scanf("%d",&a[i]);
    }

    int max=n*n;
    int sum=0;

    for(int i=0;i<n-1;i++){
        sum+=a[i];
    }

    int missing=max-sum;

    printf("%d\n",missing);

}
