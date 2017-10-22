#include<stdio.h>
#include<stdlib.h>

#define MAX 100
struct polynomial{
	int coef ; 
 	int expon ; 
};
struct mypoly{
	mypoly();
	mypoly(char*);
 	polynomial terms[MAX] ; //�h�����}�C
 	int size ; //�h�����j�p
 	void ShowPoly( ) ; //�L�X�h�������e
 	mypoly Add(mypoly) ; //�h�����ۥ[
 	void SingleMult(int) ; //�N�h�������W�@�Y��
 	float Lead_Exp() ; //�^�Ǧh�������̤j���ƪ��Y��
 	void Attach(int, int) ; //�s�W 1 �Ӷ�����h������
 	void Remove(int); //�R���h���������Y�@����
 	void Mult(mypoly); //�h�����ۭ�
};
 

int main(){
	int option;
	
	
 	mypoly Mypoly1("value1.txt"),Mypoly2("value2.txt");
	
	while(1){
		printf("1. Ū�J�h����\n2. �L�X�h�������e\n3. �h�����ۥ[\n4. �h�������W�@�ƭ�\n5. �L�X�h�������̤j���ƪ��Y��\n6. �s�W����\n7. �R���h����������\n8. �h�����ۭ�\noption:");
		scanf("%d",&option);
		switch(option){
			case 1:
				
				break;
			case 2:
				Mypoly1.ShowPoly();
				Mypoly2.ShowPoly();
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				Mypoly1.Mult(Mypoly2);
				break;
			
		}
	}
		
	system("PAUSE");
	return 0;
}

mypoly::mypoly(){

	size =0;
}
mypoly::mypoly(char* filename){
	int in_coe;
	int in_exp;
	size = 0;
	FILE* fptr = fopen(filename,"r");
	while(!feof(fptr))
	{
		fscanf(fptr,"%d %d",&in_coe, &in_exp);
		Attach(in_coe, in_exp);
	}
}
void mypoly::ShowPoly(){
	for(int i=0;i<size-1;i++){
		printf("%dx^%d+",terms[i].coef,terms[i].expon);	
	}
	
	if(size!=0)
	{
		printf("%dx^%d\n",terms[size-1].coef, terms[size-1].expon);		
	}
	
}
void mypoly::Attach(int coe,int exp){
	int index = 0;
	for(index=0;index<size;index++){
		if(exp>terms[index].expon)
			break;	
	}
	for(int i=size-1;i>=index;i--)
	{
		terms[i+1]=terms[i];
	}
	terms[index].coef=coe;
	terms[index].expon=exp;
	size++;
	
}
void mypoly::SingleMult(int num){
	for(int i=0;i<size;i++){
		terms[i].coef = num*terms[i].coef;
	}
	
}
mypoly mypoly::Add(mypoly B){
	mypoly D;
	int index1=0, index2=0;
	while(index1<size && index2<B.size){
	
		if(terms[index1].expon>B.terms[index2].expon){
			D.Attach(terms[index1].coef, terms[index1].expon);
			index1++;
		}else if(terms[index1].expon==B.terms[index2].expon){
			int sum = terms[index1].coef+ B.terms[index2].coef;
			D.Attach(sum,terms[index1].expon);
			index1++;
			index2++;			
		}else{
			D.Attach(B.terms[index2].coef, B.terms[index2].expon);
			index2++;
		}
		
	}
	for(int i=index1;i<size;i++)
		D.Attach(terms[i].coef, terms[i].expon);
	for(int i=index2;i<B.size;i++)
		D.Attach(B.terms[i].coef, B.terms[i].expon);
	
	return D;
}
void mypoly::Mult(mypoly B) {
	mypoly D;
	int index1=0, index2=0;
	for(index1=0;index1<size;index1++){
		for(index2=0;index2<B.size;index2++){
			D.Attach(terms[index1].coef*B.terms[index2].coef,terms[index1].expon+B.terms[index2].expon);
		}
	}
	size = D.size;
	for(int i=0;i<D.size;i++){
		terms[i].coef = D.terms[i].coef;
		terms[i].expon = D.terms[i].expon;
		
	}
	
}
void mypoly::Remove(int exp){
	int index = 0;
	for(index=0;index<size;index++){
		if(exp==terms[index].expon)
			break;	
	}
	for(int i=index;i<size-1;i++)
	{
		terms[i]=terms[i+1];
	}

	if(index != size)size--;
}
