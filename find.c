/* đề bài như sau
tính nghiệm x1 + x2 + x3 ....xn = k với k>0 tìm số nghiệm nguyên không âm của phương trình đó*/

/*chương trình tìm nghiệm x1 + x2 +x3......xn = k*/
#include<stdio.h>

// hàm khởi tạo cho cho số từ 0->k
void Init(int a[],int k){
    for(int i = 0; i<= k ;i++)
    a[i] = i;    
}
// hàm in ra nghiệm cần tìm
void Out(int a[], int n){
    for(int i = 1; i<= n ; i++)
    printf("%d ",a[i]);
    printf("\n");
}
// tìm giá trị của x1,x2,x3,....xn;
/*mô tả hàm như sau: 
chạy các vị trí nghiệm = 0 và các nghiệm được tìm như sau : x1 = điểm_1 - 0, x2 = điểm_2 - x1, ....xn = k - điểm_cuối
như vậy nó cũng tương tự ta tính khi chia k+n ra thành 1 đơn vị rồi xếp chúng  1 hàng dài và chọn n-1 từ các vách ngăn tính cả 2 đầu nữa */
void findx(int a[], int b[], int k, int n, int i,int j){
    static int count = 0;
    if(j == n){
        b[j] = k-a[i];
        printf("%d : ",++count);
        Out(b,n);
        return;
    }
    
    for( ; i<= k; i++){
       
        if(i == 0 || j == 1)
            b[j] = a[i];   
        else
            b[j] = a[i] - b[j-1];
        findx(a,b,k,n,i,j+1);

    }
}
// hàm gói tất cả các hàm trên 
void initialization(int a[], int b[], int k, int n){
    Init(a,k);
    findx(a,b,k,n,0,1);
}

int main(){
    int k, n;

    printf("Enter value k = ");
    scanf("%d",&k);
    printf("\nEnter value n = ");
    scanf("%d",&n);
    // sử dụng mảng a để lưu các giá trị từ 0->k và mảng b lưu n nghiệm
    int a[k+1],b[n+1];

    initialization(a,b,k,n);
    
}