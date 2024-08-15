#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fileTable{
	char name[20];
	int nob;
	struct block *sb;
}ft[30];

struct block{
	int bno;
	struct block *next;
};

int main(){
	int i,j,n;
	char s[20];
	struct block *temp;
	printf("Enter no fo files :");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		printf("\nEnter file name %d :", i+1);
		scanf("%s",&ft[i].name);
		printf("Enter on of blocks in the file %d :", i+1);
		scanf("%d", &ft[i].nob);
		ft[i].sb=(struct block*)malloc(sizeof(struct block));
		temp=ft[i].sb;
		printf("Enter the block of file:");
		scanf("%d", &temp->bno);
		temp->next = NULL;
		
		for(j=1;j<ft[i].nob;j++){
			temp->next = (struct block*)malloc(sizeof(struct block));
			temp = temp->next;
			scanf("%d", &temp->bno);
		}
		temp->next = NULL;
	}
	printf("\nEnter the file name to be searched --");
	scanf("%s", s);
	for(i=0;i<n;i++)
		if(strcmp(s,ft[i].name)==0){
		break;
	}
	if(i==n){
		printf("\nFile not found");
	}
	else{
		printf("FILE NAME\tNO OF BLOCKS\tBLOCKS OCCUPIED");
		printf("\n%s\t\t%d\t\t", ft[i].name, ft[i].nob);
		temp=ft[i].sb;
		for(j=0;j<ft[i].nob;j++){
			printf("%d ->", temp->bno);
			temp = temp->next;
		}
	}
}