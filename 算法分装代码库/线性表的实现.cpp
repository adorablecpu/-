 void unionList(List A,List B,List &LC)
 {
 	int lena,i;
 	ElemType e;
 	InitList(LC);         //��ʼ��LC 
 	for(i=1;i<=ListLength(LA);i++)     //��LA�е�����Ԫ�ظ��Ƶ�LC�� 
	 {
	 	GetElem(LA,i,e);               //��LA�еĵ�i��Ԫ�ظ���e 
	 	ListInsert(LC,i,e);            //��Ԫ��e����LC�� 
	 }  
	 lena=ListLength(LA);              //�����Ա�LA�ĳ��� 
	 for(i=1;i<=ListLength(LB);i++)    //ѭ������LB�е�ÿһ��Ԫ�� 
	 { 
	 	GetElem(LB,i,e);               //ȡLB�еĵ�i��Ԫ�ظ���e 
	 	if(!LocateElem(LA,e))          //�ж�e�Ƿ���LA�� 
	 	{
		 	ListInsert(LC,++lena,e);   //��e����LA�У��������LC�� 
		 }
	 }
 }S
