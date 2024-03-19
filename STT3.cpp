#include <stdio.h>
#include <string.h>
#include <stdlib.h>	

struct Chuoi {
	char maso[7], KhuVuc[11];
	int GiongChuoi;
	int ThangTuoi;
};

struct NODE{
	Chuoi data;
	NODE *pNext;
};

struct list{
	NODE *pHead;
	NODE *pTail;
};

void Init(list &ds){
	ds.pHead = ds.pTail = NULL;
}

void Swap(Chuoi &a, Chuoi &b){
	Chuoi temp;
	strcpy(temp.maso,a.maso);
	strcpy(temp.KhuVuc,a.KhuVuc);
	temp.GiongChuoi = a.GiongChuoi;
	temp.ThangTuoi = a.ThangTuoi;
	
	strcpy(a.maso,b.maso);
	strcpy(a.KhuVuc,b.KhuVuc);
	a.GiongChuoi = b.GiongChuoi;
	a.ThangTuoi = b.ThangTuoi;

	strcpy(b.maso,temp.maso);
	strcpy(b.KhuVuc,temp.KhuVuc);
	b.GiongChuoi = temp.GiongChuoi;
	b.ThangTuoi = temp.ThangTuoi;
	
}

NODE *MAX(list ds){
	NODE *max;
	max = ds.pHead;
	NODE *p;
	p = max->pNext;
	for(;p!=NULL;p=p->pNext){
		if(strcmp(p->data.maso,max->data.maso)>0){
			max = p;
		}
	}
	return max;
}

NODE *MIN(list ds){
	NODE *min;
	min = ds.pHead;
	NODE *p;
	p = min->pNext;
	for(;p!=NULL;p=p->pNext){
		if(strcmp(p->data.maso,min->data.maso)<0){
			min = p;
		}
	}
	return min;
}

void SapXep_MS_Giam(list &ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach hien dang rong\n");
	}
	else{
		list l;
		Init(l);
		l.pHead = ds.pHead;
		l.pTail = ds.pTail;
		NODE *max, temp;
		for(;l.pHead!=l.pTail;l.pHead=l.pHead->pNext){
			max = MAX(l);
			Swap(l.pHead->data,max->data);
		}
	}
}

void SapXep_MS_Tang(list &ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach hien dang rong\n");
	}
	else{
		list l;
		Init(l);
		l.pHead = ds.pHead;
		l.pTail = ds.pTail;
		NODE *min, temp;
		for(;l.pHead!=l.pTail;l.pHead=l.pHead->pNext){
			min = MAX(l);
			Swap(l.pHead->data,min->data);
		}
	}
}

int ktms (list ds, NODE *New){
	if(ds.pHead == NULL){
		return 1;
	}
	else{
		NODE *p;
		p = ds.pHead;
		for(;p != NULL;p=p->pNext){
			if(strcmp(p->data.maso,New->data.maso)==0)
				return -1;
		}
		return 1;
	}		
}

void NhapGiongChuoi(int &x){
	do{
		scanf("%d", &x);
		if(x<1||x>5)
			printf("\nnhap sai vui long nhap lai: ");
	}while(x<1||x>5);
}

void XuatGiongChuoi(int x){
	switch(x){
		case 1: printf("Chuoi Do\n");break;
		case 2: printf("Chuoi Tieu Hong\n");break;
		case 3: printf("Chuoi Laba\n");break;
		case 4: printf("Chuoi Cau Ke\n");break;
		case 5: printf("Chuoi Gia Huong\n");break;
	}
}

void Nhap1Chuoi(Chuoi &x){
	printf("nhap ma so: ");fflush(stdin);gets(x.maso);fflush(stdin);
	printf("nhap khu vuc: ");fflush(stdin);gets(x.KhuVuc);fflush(stdin);
	printf("nhap giong chuoi: ");NhapGiongChuoi(x.GiongChuoi);
	printf("nhap so thang tuoi: ");scanf("%d", &x.ThangTuoi);
	
}

void Xuat1Chuoi(Chuoi x){
	printf("\nMa so: ");puts(x.maso);
	printf("Khu vuc: ");puts(x.KhuVuc);
	printf("Giong Chuoi: ");XuatGiongChuoi(x.GiongChuoi);
	printf("Thang Tuoi: %d", x.ThangTuoi);
	printf("\n");
}


bool IsEmpty(list ds){
	if(ds.pHead == NULL)
		return true;
	return false;
}

NODE* TaoNODE(Chuoi x){
	NODE* p=new NODE;
    if (p==NULL){
        printf("Khong cap duoc vung nho cho NODE");
    }
    else{
        p->data = x;
        p->pNext=NULL;
    }
    return p;
}

void ThemVaoDau(list &ds, NODE *New){
	New->pNext = ds.pHead;
	ds.pHead = New;
	NODE *p;
	p = ds.pHead;
}

void ThemVaoCuoi(list &ds, NODE *New){
	if(ds.pHead == NULL){
		ds.pHead = New;
		ds.pTail = New;
	}
	else{
		NODE *p;
		p = ds.pHead;
		for(;p->pNext!=NULL;){
			p=p->pNext;
		}
		p->pNext = New;
		New->pNext = NULL;
		ds.pTail = New;
	}
}

void ThemVaoViTriBatKy(list &ds, NODE *New, int vitri){
	if(vitri <= 1)
		ThemVaoDau(ds,New);
	else{
		NODE *p = ds.pHead;
		int i = 1;
		for(;p!= NULL;p=p->pNext,i++){
			if(p==NULL){
				ThemVaoCuoi(ds,New);
			}
			else{
				if(i == vitri-1){
					New->pNext = p->pNext;
					p->pNext = New;
				}
			}
		}
	}
}

void XoaDau(list &ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach Hien dang rong\n");
	}
	else{
		NODE *p,*q;
		p = ds.pHead;
		q = ds.pHead;
		p = p->pNext;
		ds.pHead = p;
		delete q;
	}
}

void XoaCuoi(list &ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach Hien dang rong\n");
	}
	else if(ds.pHead == ds.pTail){
		NODE *x;
		x = ds.pHead;
		ds.pHead = NULL;
		ds.pTail = NULL;
		delete x;
	}
	else{
		NODE *p, *q;
		p = ds.pHead;
		q = p->pNext;
		for(;q->pNext!=NULL;q=q->pNext);
		for(;p->pNext != q;p=p->pNext);
		ds.pTail = p;
		p->pNext = NULL;
		delete q;
	}
}

void XoaViTriBatKy(list &ds, char maso[]){
	if(ds.pHead == NULL){
		printf("\nDanh sach hien dang rong\n");
	}
	else if(strcmp(ds.pHead->data.maso,maso)==0) {
		XoaDau(ds);
	}
	else{
		NODE *p, *q, *k;
		p = ds.pHead;
		q = p->pNext;
		for(;q->pNext!=NULL;q=q->pNext){
			if(strcmp(q->data.maso,maso)==0){
				break;
			}
		}
		if(strcmp(q->data.maso,maso)!=0){
			printf("\nDanh sach khong co phan tu co ma so can xoa\n");
		}
		else{
			for(;p->pNext != q;p=p->pNext);
			k = q->pNext;
			p->pNext = k;
			delete q;
		}
	}
}

void Taolist(list &ds){
	int n;
    do{
        printf("Nhap so luong phan tu: ");scanf("%d", &n);
        if (n<=0)
            printf("So luong vua nhap khong phu hop.Nhap lai\n");
    }while(n<=0);
    for(int i = 0; i < n; i++){
    	Chuoi x;
    	NODE *p;
    	do{
    		Nhap1Chuoi(x);
   			p = TaoNODE(x);
    		if(ktms(ds,p)==-1)
    			printf("\nMa so vua nhap da co san. Vui long nhap lai\n\n");
		}while(ktms(ds,p)==-1);
		ThemVaoCuoi(ds,p);
    	printf("\n");
	}
}

void Xuatlist(list ds){
	if(IsEmpty(ds)==true)
		printf("Danh sach rong\n");
	NODE *p ;
	p = ds.pHead;
	for(;p!=NULL;p = p->pNext){
		Xuat1Chuoi(p->data);
		printf("\n");
	}
}

void Cau6(list ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach hien dang rong\n");
	}
	else{
		NODE *p;
		p = ds.pHead;
		for(;p!=NULL;p=p->pNext){
			switch (p->data.GiongChuoi){
				case 1:
					Xuat1Chuoi(p->data);
					break;
				case 3:
					Xuat1Chuoi(p->data);
					break;
				case 5:
					Xuat1Chuoi(p->data);
					break;
			}
		}
	}
}

void Cau7(list ds){
	if(ds.pHead == NULL){
		printf("\nDanh sach hien dang rong\n");
	}
	else {
		NODE *p;
		p = ds.pHead;
		int sl = 0;
		for(;p!=NULL;p=p->pNext){
			if(p->data.GiongChuoi == 4 && (p->data.ThangTuoi>36 && p->data.ThangTuoi<60)){
				sl++;
			}
		}
		if(sl == 0){
			printf("\nDanh sach khong co phan tu thoa man dieu kien\n");
		}
		else{
			printf("so luong phan tu thoa man dieu kien la: %d", sl);
		}
		
	}
}

NODE* middle(NODE* start, NODE* last)
{
    if (start == NULL)
        return NULL;
 
    struct NODE* slow = start;
    struct NODE* fast = start->pNext;
 
    while (fast != last)
    {
        fast = fast->pNext;
        if (fast != last)
        {
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }
 
    return slow;
}

NODE* binarySearch(list ds, char ms[] ){
	if(strcmp(ds.pHead->data.maso,ms)==0)
		return ds.pHead;
	if(strcmp(ds.pTail->data.maso,ms)==0)
		return ds.pTail;
    struct NODE* start = ds.pHead;
    struct NODE* last = NULL;
 
    do
    {
        NODE* mid = middle(start, last);
        if (mid == NULL)
            return NULL;
        if (strcmp(mid->data.maso,ms)==0)
            return mid;
        else if (strcmp(mid->data.maso,ms) < 0)
            start = mid->pNext;
        else
            last = mid;
    } while (last == NULL || last != start);
    return NULL;
}

void menu(int &chon){
		printf("\n\n-------------------QUAN LY CHUOI----------------\n\n");
		printf("1.Nhap danh sach cach cay chuoi.\n");
		printf("2.Liet ke danh sach cac cay chuoi.\n");
		printf("3.Chen them 1 cay chuoi.\n");
		printf("4.Sap xep danh sach ma so giam dan (Selection sort).\n");
		printf("5.Tim kiem cay chuoi.\n");
		printf("6.Liet ke thong tin 3 giong chuoi (Do, Laba, Gia Huong).\n");
		printf("7.Dem so luong cay chuoi Cau Ke co so thang tuoi tu 36 den 60 thang.\n");
		printf("8.Xoa 1 cay chuoi.\n");
		printf("0.Thoat.\n");
		do{
			printf("moi con chuc nang ");          scanf("%d",&chon);
			switch(chon){
			case 1:
				list ds;
				Init(ds);
				Taolist(ds);
				break;
			case 2:
				Xuatlist(ds);
				break;
			case 3:
				int vitrithem;
				printf("\nNhap vi tri: ");scanf("%d", &vitrithem);
				Chuoi x;
				NODE *New ;
				do{
					Nhap1Chuoi(x);
					New = TaoNODE(x);
					if(ktms(ds,New)==-1)
						printf("Ma so vua nhap da co san. Vui long nhap lai\n\n");
				}while(ktms(ds,New)==-1);
				ThemVaoViTriBatKy(ds,New,vitrithem);
				Xuatlist(ds);
				break;
			case 4:
				SapXep_MS_Giam(ds);
				break;
			case 5:
				SapXep_MS_Tang(ds);
				char msct[10];
				printf("\nNhap ma so can tim: ");fflush(stdin);gets(msct);fflush(stdin);
				NODE *kq;
				kq = binarySearch(ds,msct);
				if(kq != NULL)
					Xuat1Chuoi(kq->data);
				else
					printf("\nKhong tim thay\n");
				break;
			case 6:
				Cau6(ds);
				break;
			case 7:
				Cau7(ds);
				break;
			case 8:
				char maso[7];
				printf("\nNhap ma so can xoa: ");fflush(stdin);gets(maso);fflush(stdin);
				XoaViTriBatKy(ds,maso);
				break;
			case 0: exit(0);
		}
	}while(chon != 0);
	
	
}
int main() {
	
	int chon;
	menu(chon);
	
	
return 0;	
}