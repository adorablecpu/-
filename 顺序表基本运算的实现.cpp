//���������СΪһ�����ͳ��� 
#define Maxsize 50       //�������һ�����Ա��ᳬ��50��Ԫ�� 


//����˳���
void CreateList(SqList *&L,ElemType a[],int n)  //��a�е�n��Ԫ�ؽ���˳���
{
	int i=0,k=0;                                //k��ʾL��Ԫ�صĸ�������ʼֵΪ0 
	L=(SqList*)malloc(sizeof(SqList));          //���������Ա�Ŀռ�
	while(i<n)                                  //iɨ������a��Ԫ�� 
	{
		L->data[k]=a[i];                        //��Ԫ��a[i]��ŵ�L�� 
		k++;i++;
	} 
	L->length=k;                                //����L�ĳ���Ϊk 
} 


//�������Ա�DestroyList(&L)
void  DestroyList(SqList *&L)
{
	free(L);                                    //�ͷ�L��ָ��˳���ռ� 
}


//�ж����Ա��Ƿ�Ϊ�ձ�ListEmpty(L)
bool  ListEmpty(SqList *L)
{
	return(L->length==0);
}


//�����Ա��ȣ�ListLength(L)
int  ListLength(SqList *L)
{
	return(L->length);
}


//������Ա�DispList(L)
void  DispList(SqList *L)
 {
 	for(int i=0;i<L->length;i++)               //ɨ�����Ա������Ԫ��ֵ 
 	printf("%d",L->data[i]);
 	printf("\n");
 }
 
 
//����������Ա��е�Ԫ�أ�GetElem(L,i,&e)
bool GetElem(SqList *L,int i,ElemType &e)
 {
 	if(i<1||i>L->length)                       
 	return false;                              //����i����ʱ����false 
 	e=L->data[i-1];                            //ȡԪ�ص�ֵ 
 	return true;                               //�ɹ��ҵ�Ԫ��ʱ����true 
 } 
 
 
//��Ԫ�ز��ң�LocateElem(L,e)
int  LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
	i++;                                       //����Ԫ��e 
	if(i>=L->length)                           //δ�ҵ�ʱ����0 
	return 0;
	else
	return i+1;                                //�ҵ��󷵻����߼���� 
}


//��������Ԫ�أ�ListInsert(&L,i,e)
bool  ListInsert(SqList *&L,int i,ElemType e)
{
	int j;
	if(i<1||i>L->length+1||L->length==Maxsize)  
	return false;                              //����i����ʱ����false 
	i--;                                       //��˳�����߼����ת��Ϊ������� 
	for(j=L->length;j>i;j--)                   //��data[i]�������Ԫ�غ���һ��λ�ã������Ǵ����һ��Ԫ�ؿ�ʼ�� 
	L->data[j]=L->data[j-1];
	L->data[i]=e;                              //����Ԫ��e 
	L->length++;                               //˳���ĳ��ȼ�1 
	return true;                               //�ɹ����뷵��true 
}


//ɾ������Ԫ�أ�ListDelete(&L,i,&e)
bool ListDelete(SqList *&L,int i,ElemType &e)
{
	int j;
	if(i<1||i>L->length)                       //����i����ʱ����false 
	return false;
	i--;                                       //��˳�����߼����ת��Ϊ�������
	e=L->data[i];
	for(j=i;j<L->length-1;j++)                 //��data[i]�������Ԫ��ǰ��һ��λ��
	L->data[j]=L->data[j+1];
	L->length--;                               //˳���ĳ��ȼ�1 
	return true;                               //�ɹ�ɾ������true
} 
