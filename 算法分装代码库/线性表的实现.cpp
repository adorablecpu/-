 void unionList(List A,List B,List &LC)
 {
 	int lena,i;
 	ElemType e;
 	InitList(LC);         //初始化LC 
 	for(i=1;i<=ListLength(LA);i++)     //将LA中的所有元素复制到LC中 
	 {
	 	GetElem(LA,i,e);               //将LA中的第i个元素赋给e 
	 	ListInsert(LC,i,e);            //将元素e插入LC中 
	 }  
	 lena=ListLength(LA);              //求线性表LA的长度 
	 for(i=1;i<=ListLength(LB);i++)    //循环处理LB中的每一个元素 
	 { 
	 	GetElem(LB,i,e);               //取LB中的第i个元素赋给e 
	 	if(!LocateElem(LA,e))          //判断e是否在LA中 
	 	{
		 	ListInsert(LC,++lena,e);   //若e不在LA中，则将其插入LC中 
		 }
	 }
 }S
