#include <stdio.h>
#include <string.h>
#include<bits/stdc++.h>
#include <unistd.h>
#define size 20000
struct bo{
	char maso [7];
	int giongbo;
	float trongluong;
	int thangtuoi;
};
struct list{
	int Count;
	bo a[size];
};

void Init(list &ds){
	ds.Count = 0;
}

bool isEmpty (list ds){
	return ds.Count == 0;
}

bool isFull (list ds){
	return ds.Count == size;
}

int ktms(list ds, bo x, int n){
	for(int i = 0;i<n;i++){
		if((strcmp(ds.a[i].maso,x.maso)==0))
			return 0;
	}
	return 1;
}

void NhapGiongBo(int &x){
	do{
		scanf("%d", &x);
		if(x<1||x>5)
			printf("\nnhap sai vui long nhap lai: ");
	}while(x<1||x>5);
}

void XuatGiongBo(int x){
	if(x == 1)
		printf("Bo Vang\n");
	else if(x == 2)
		printf("Bo H'Mong\n");
	else if(x == 3)
		printf("Bo U dau riu\n");
	else if(x == 4)
		printf("Bo Phu Yen\n");
	else if(x == 5)
		printf("Bo Bay Nui\n");
}

void NhapTrongLuong(float &x){
	do{
		scanf("%f", &x);
		if(x<=0){
			printf("khoi luong nhap khong phu hop, vui long nhap lai: ");
		}
	}while(x<=0);
}

void Nhap1ConBo(bo &x){
	printf("nhap ma so: ");fflush(stdin);gets(x.maso);fflush(stdin);
	printf("nhap giong bo: ");NhapGiongBo(x.giongbo);
	printf("nhap trong luong (kg/con): ");NhapTrongLuong(x.trongluong);
	printf("nhap so thang tuoi: ");scanf("%d", &x.thangtuoi);
	fflush(stdin);
}

void Xuat1ConBo(bo &x){
	printf("maso: ");puts(x.maso);
	printf("giong bo: ");XuatGiongBo(x.giongbo);
	printf("trong luong: %.2f\n", x.trongluong);
	printf("thang tuoi: %d\n", x.thangtuoi);
	printf("\n");
}

void Nhapds(list &ds){
	do{
		printf("nhap so luong bo [1<x<20000]: ");scanf("%d", &ds.Count);
		if(ds.Count<=0 || ds.Count>20000)
			printf("so luong khong hop le, vui long nhap lai\n");		
	}while(ds.Count<=0 || ds.Count>20000);
	for(int i = 0; i<ds.Count;i++){
		bo b;
		printf("\ncon bo thu %d: \n", i+1);
		do{
			Nhap1ConBo(b);
			if(ktms(ds,b,i)==0)
				printf("\nMa so vua nhap da co san, vui long nhap lai: \n\n");
		}while(ktms(ds,b,i)==0);
		ds.a[i] = b;
	}
}

void Xuatds (list ds){
	if(isEmpty(ds) == true){
		printf("khong co con bo nao trong danh sach\n");
	}
	else{
		printf("Danh sach con bo hien co: \n\n");
		for(int i = 0; i<ds.Count; i++){
			Xuat1ConBo(ds.a[i]);
			printf("\n");
		}
	}
}
void Them1PT(list &ds,bo New,int vitri)
{
	if(vitri>=ds.Count)
	 	vitri=ds.Count;
	else
        if(vitri<0)
            vitri=0;
    for(int i=ds.Count;i>vitri;i--)
    {
        ds.a[i]=ds.a[i-1];
	}
    ds.a[vitri]=New;
	ds.Count++;
}

void Swap(bo &a, bo &b){
	bo temp;
	strcpy(temp.maso,a.maso);
	temp.giongbo = a.giongbo;
	temp.trongluong = a.trongluong;
	temp.thangtuoi = a.thangtuoi;
	
	strcpy(a.maso,b.maso);
	a.giongbo = b.giongbo;
	a.trongluong = b.trongluong;
	a.thangtuoi = b.thangtuoi;
	
	strcpy(b.maso,temp.maso);
	b.giongbo = temp.giongbo;
	b.trongluong = temp.trongluong;
	b.thangtuoi = temp.thangtuoi;
}

void SapXep_MS_giam(list &ds){
	for(int i = 0;i<ds.Count;i++){
		for(int j = i+1;j<ds.Count;j++){
			if(strcmp(ds.a[i].maso,ds.a[j].maso)<0)
				Swap(ds.a[i],ds.a[j]);
		}
	}
}

void SapXep_MS_tang(list &ds){
	for(int i = 0;i<ds.Count;i++){
		for(int j = i+1;j<ds.Count;j++){
			if(strcmp(ds.a[i].maso,ds.a[j].maso)>0)
				Swap(ds.a[i],ds.a[j]);
		}
	}
}

int TKiemNP_MS(list ds, char tkiem[]){
	SapXep_MS_tang(ds);
	int l = 0, r = ds.Count-1, m;
	
	while(r>=l){
		m = (r+l)/2;
		if(strcmp(ds.a[m].maso,tkiem)==0)
			return m;
		if(strcmp(ds.a[m].maso,tkiem)>0){
			r = m-1;
		}
		if(strcmp(ds.a[m].maso,tkiem)<0){
			l = m+1;
		}
	}
	return -1;
}

void LKe_GB(list ds){
	for(int i = 0; i<ds.Count;i++){
		if(ds.a[i].giongbo==2 || ds.a[i].giongbo==3 || ds.a[i].giongbo==5)
			Xuat1ConBo(ds.a[i]);
	}
	
}

int demsl(list ds){
	int count = 0;
	for(int i = 0; i<ds.Count;i++){
		if((ds.a[i].thangtuoi>=12 && ds.a[i].thangtuoi<=18)&&(ds.a[i].trongluong>=80 && ds.a[i].trongluong<=130))
			count++;	
	}
}

void Xoa1PT(list &ds, char MS[]){
	if(ds.Count==0)
		return;
	int vitri;
	vitri = TKiemNP_MS(ds,MS);
	for(int i = vitri; i<ds.Count;i++){
		ds.a[i] = ds.a[i+1];
	}
	--ds.Count;
}

void menu(int &chon ){
		printf("=======================================CHUONG TRINH QUAN LY TRANG TRAI=======================================");
		printf("|1. Nhap danh sach cac con bo.\n");
		printf("|2. Liet ke danh sach tat ca cac con bo.\n");
		printf("|3. Them 1 con bo.\n");
		printf("|4. sap xep danh sach cac con bo giam dan theo ma so.\n");
		printf("|5. tim kem con bo dua tren ma so (tim kiem nhi phan).\n");
		printf("|6. liet ke thong tin cac con bo thuoc 1 trong cac giong: H'Mong, U dau riu, Bay nui.\n");
		printf("|7. Dem so luong con bo co so thang tuoi 12->18, trong luong 80->130.\n");
		printf("|8. xoa mot con bo dua tren ma so.\n");
		printf("|0. thoat.\n");
		printf("============================================================================================================");
		do{

					printf("moi chon chuc nang : ");
					scanf("%d",&chon);	
		switch (chon){
			case 1:
				list ds;
				Init(ds);
				Nhapds(ds);
				break;
			case 2:
				Xuatds(ds);
				break;
			case 3:
				int vitri;
				printf("nhap vi tri: ");scanf("%d", &vitri);
				bo New;
				do{
					Nhap1ConBo(New);
					if(ktms(ds,New,ds.Count)==0)
						printf("Ma so vua nhap da co san, vui long nhap lai: \n\n");
				}while(ktms(ds,New,ds.Count)==0);
				Them1PT(ds,New,vitri);
				Xuatds(ds);
				break;
			case 4:
				SapXep_MS_giam(ds);
				Xuatds(ds);
				break;
			case 5:
				char search[7];
				do{
					printf("nhap ma so can tim: ");fflush(stdin);gets(search);fflush(stdin);
					if(TKiemNP_MS(ds,search)==-1)
						printf("khong tim thay, vui long tim lai\n");
					else{
						printf("ket qua: \n");
						Xuat1ConBo(ds.a[TKiemNP_MS(ds,search)]);
					}
				}while(TKiemNP_MS(ds,search)==-1);
				break;
			case 6:
				printf("cac con bo thuoc giong: H'Mong, U dau riu, Bay nui la:\n\n");
				LKe_GB(ds);
				break;
			case 7:
				
				printf("so bo co thang tuoi thuoc [12,18] va co trong luong thuoc [80,130]kg la: %d\n\n", demsl(ds));
				break;
			case 8:
				char dele[7];
				printf("\n\nnhap Ma so can xoa: ");fflush(stdin);gets(dele);fflush(stdin);
				Xoa1PT(ds,dele);
				Xuatds(ds);
				break;
		}
	}while(chon!=0);
	
}
int main(){
	int chon;
	system("cls");
	menu(chon);
	return 0;
}

