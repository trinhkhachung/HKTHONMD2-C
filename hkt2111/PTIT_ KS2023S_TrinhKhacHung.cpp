#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int n,m;
	int choice;
	printf("moi nhap gia tri n,m\n");
	scanf("%d%d",&n,&m);
	int numbers[n][m];
	int sum;
	int count;
	int max,min;
	
	do{
		printf("---------MENU---------\n");
		printf("1.nhap gia tri cac phan tu cac phan tu cua mang\n");
		printf("2.in ra cac gia tri cua mang theo ma tran\n");
		printf("3.tinh cac so phan tu le chia het cho 5 trong mang\n");
		printf("4.in ra cac phan tu co gia tri lon nhat nho nhat nam tren duong bien,duong cheo chinh,duong cheo phu\n");
		printf("5.su dung thuat toan sap xep lua chon sap xep phan tu giam dan theo dong cua mang\n");
		printf("6.tinh tong cac phan tu so nguyen to trong mang\n");
		printf("7.su dung toan chen sap xep cac phan tu tren duong cheo phu cua mang tang dan\n");
		printf("8.nhap gia tri mot mang 1 chieu gom n phan tu va chi so cot muon chen vao mang thuc hien chen vao mang hai chieu\n");
		printf("9.thoat\n");
		printf("moi nhap lua chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				for(int i=0;i < n;i++){
					for(int j=0;j < m;j++){
						printf("numbers[%d][%d] = ",i,j);
						scanf("%d",&numbers[i][j]);
					}
				}
				break;
			case 2:
				for(int i=0;i < n;i++){
					for(int j=0;j < m;j++){
						printf("%d\t",numbers[i][j]);
				    }
				    printf("\n");
				}
				break;
			case 3:
				for(int i=0;i < n;i++){
					for(int j=0;j < m;j++){
						if(numbers[i][j] % 5 == 0){
							printf("%d\n",numbers[i][j]);
						}
					}
				}
				break;
			case 4:
				max=numbers[0][0];
				min=numbers[0][0];
				for(int i=0;i < n;i++){
					if(max < numbers[i][0])max = numbers[i][0];
					if(min > numbers[i][0])min = numbers[i][0];
				}
				printf("MAX MIN duong bien cheo lan luot la %d,%d\n",max,min);
				max = numbers[n-1][m-1];
       			min = numbers[n][m];
       			for (int i=0;i<n;i++) {
        			if (max < numbers[i][m-1]) max = numbers[i][m-1];
        			if (min > numbers[i][m-1]) min = numbers[i][m-1];
    			}
    			printf("MAX MIN duong bien phai lan luot la %d %d \n", max ,min);
    			max = numbers[0][0];
       			min = numbers[0][0];
       			for (int j=0;j<n;j++) {
        			if (max < numbers[0][j]) max = numbers[0][j];
        			if (min > numbers[0][j]) min = numbers[0][j];
    			}
    			printf("MAX MIN duong bien tren lan luot la %d %d \n", max ,min);
    			max = numbers[n-1][m-1];
       			min = numbers[n-1][m-1];
       			for (int j=0;j<n;j++) {
        			if (max < numbers[n-1][j]) max = numbers[n-1][j];
        			if (min > numbers[n-1][j]) min = numbers[n-1][j];
    			}
    			printf("MAX MIN duong bien duoi lan luot la %d %d \n", max ,min);
    				if (m == n) {
     						int i = 1;
     						int j = 1;
     				    max = numbers[0][0];
     				    min = numbers[0][0];
     				while (i<n) {
      				     if (max < numbers[i][j]) max = numbers[i][j];
         				 if (min > numbers[i][j]) min = numbers[i][j];
      					 i++;
      					 j++;
     				}
     			printf("MAX MIN duong cheo chinh lan luot la %d %d \n",max ,min);
        				i = 1;
        				j = n-2;
        				max = numbers[0][n-1];
        				min = numbers[0][n-1];
      				while (j>=0) {
       					if (max < numbers[i][j]) max = numbers[i][j];
          				if (min > numbers[i][j]) min = numbers[i][j];
       					i++;
       					j--;
      				}
     			printf("MAX MIN duong cheo phu lan luot la %d %d \n",max ,min);
    		} else printf("khong co duong cheo chinh va phu\n");
    				break;

			case 5:
				for(int i=0;i < m;i++){
					for(int j=0;j < n;j++){
						int key = numbers[i][j];
						int f = i-1;
						while(f>=0 && key > numbers[j][f]){
							numbers[j][f+1]=numbers[j][f];
							f-=1;
						}
						numbers[j][f+1]=key;
					}
				}
				break;
			case 6:
				sum=0;
				
				for(int i=0;i < n;i++){
					for(int j=0;j < m;j++){
					count=0;
					for(int k=2;k<numbers[i][j];k++){
						if(numbers[i][j] % k == 0){
							count=1;
							break;
						}
					}
						if(count == 0 && numbers[i][j] >=2){
						sum+=numbers[i][j];
						}
				}
			}	
				printf("tong so nguyen to la: %d\n",sum);
				break;
			case 9:
				printf("thoat");
				break;
			default:
				printf("khong hop le");
		}
	}while(choice != 9);
}
