//定义数组大小为一个整型常量 
#define Maxsize 50       //如果估计一个线性表不会超过50个元素 


//建立顺序表
void CreateList(SqList *&L,ElemType a[],int n)  //由a中的n个元素建立顺序表
{
	int i=0,k=0;                                //k表示L中元素的个数，初始值为0 
	L=(SqList*)malloc(sizeof(SqList));          //分配存放线性表的空间
	while(i<n)                                  //i扫描数组a的元素 
	{
		L->data[k]=a[i];                        //将元素a[i]存放到L中 
		k++;i++;
	} 
	L->length=k;                                //设置L的长度为k 
} 


//销毁线性表：DestroyList(&L)
void  DestroyList(SqList *&L)
{
	free(L);                                    //释放L所指的顺序表空间 
}


//判断线性表是否为空表：ListEmpty(L)
bool  ListEmpty(SqList *L)
{
	return(L->length==0);
}


//求线性表长度：ListLength(L)
int  ListLength(SqList *L)
{
	return(L->length);
}


//输出线性表：DispList(L)
void  DispList(SqList *L)
 {
 	for(int i=0;i<L->length;i++)               //扫描线性表输出各元素值 
 	printf("%d",L->data[i]);
 	printf("\n");
 }
 
 
//按序号求线性表中的元素：GetElem(L,i,&e)
bool GetElem(SqList *L,int i,ElemType &e)
 {
 	if(i<1||i>L->length)                       
 	return false;                              //参数i错误时返回false 
 	e=L->data[i-1];                            //取元素的值 
 	return true;                               //成功找到元素时返回true 
 } 
 
 
//按元素查找：LocateElem(L,e)
int  LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while(i<L->length&&L->data[i]!=e)
	i++;                                       //查找元素e 
	if(i>=L->length)                           //未找到时返回0 
	return 0;
	else
	return i+1;                                //找到后返回其逻辑序号 
}


//插入数据元素：ListInsert(&L,i,e)
bool  ListInsert(SqList *&L,int i,ElemType e)
{
	int j;
	if(i<1||i>L->length+1||L->length==Maxsize)  
	return false;                              //参数i错误时返回false 
	i--;                                       //将顺序表的逻辑序号转化为物理序号 
	for(j=L->length;j>i;j--)                   //将data[i]及后面的元素后移一个位置（这里是从最后一个元素开始） 
	L->data[j]=L->data[j-1];
	L->data[i]=e;                              //插入元素e 
	L->length++;                               //顺序表的长度加1 
	return true;                               //成功插入返回true 
}


//删除数据元素：ListDelete(&L,i,&e)
bool ListDelete(SqList *&L,int i,ElemType &e)
{
	int j;
	if(i<1||i>L->length)                       //参数i错误时返回false 
	return false;
	i--;                                       //将顺序表的逻辑序号转化为物理序号
	e=L->data[i];
	for(j=i;j<L->length-1;j++)                 //将data[i]及后面的元素前移一个位置
	L->data[j]=L->data[j+1];
	L->length--;                               //顺序表的长度减1 
	return true;                               //成功删除返回true
} 
