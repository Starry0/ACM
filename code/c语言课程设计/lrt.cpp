/**http://youthlin.com/
*�Ӻ��� ���� 3��7��9��12
*@author lrt
*@package Student Achievement Management System
*@subpackage lrt.cpp
*@since main_v1.4.1.cpp
*/

/**
*����3--����ÿ�ſγ̵��ֺܷ�ƽ����
*@Date :  2013-12-26 01:31
*By : Youthlin
*/
int cal_every_cou(pstu head){
    system(CLEAR);
    system("color 0f");     //0f ������ɫ   ��������ɫ
    pstu p;
    p=head;
    int i;
    /** ���� */
	printf("Home->Calculate total and average score of every coursen��ҳ->����ÿ�ſγ̵��ֺܷ�ƽ����nn");
    if (p==NULL){
        printf("No content to calculate...tû�пɹ�����Ķ���...n");
        //system(P);
        return 0;
    }/* �ӿ� */

    while(p!=NULL){
            //�����ܷ�
            for(i=1;i<=k;i++){
            	course[i][0]+=p->score[i];  //��i�ſ�
            }/* �ܷ� */
            p=p->next;
    }/* while */

    //����ƽ����
    for(i=1;i<=k;i++){
        course[i][1]=course[i][0]/people;
    }/* for ƽ���� */

    /**course[7][2] 1-6����6�ſ�Ŀ��	0�ܷ�	1ƽ����*/

    /** ��� */
    for(i=1;i<=k;i++)
        printf("t��Ŀ%d",i);
    printf("n�ܷ�:t");
    for(i=1;i<=k;i++)
        printf("%5.0ft",course[i][0]);
    printf("nƽ��:t");
    for(i=1;i<=k;i++)
        printf("%5.2ft",course[i][1]);
    printf("nn");


    return 0;
}/* ����ÿ�ſγ��ֺܷ�ƽ���� */

/**
*����12--���ÿ��ѧ����ѧ��,����,���Ƴɼ�,�ܷ�,��ƽ����
*@Date 2013-12-26 02:09
*By : Youthlin
*/
int list(pstu head,int j){
    int ch,i,t;
    if (!j){
    	printf("Home->List recordn��ҳ->����ɼ���nn");
    }
    pstu p=head;
    if (p==NULL){
        printf("No content to list...tû�и��㿴�����ݶ�...n");
        return 0;
    }//�ӿ�
    cal_every_stu(head,1);      //�����ܷ�ƽ����

    printf("ѧ��Idtt����Namet");
    for(i=1;i<=k;i++)
        printf("%4d ",i);
    printf("ƽ��Ave �ܷ�Totnn");
    while(p!=NULL){
        printf("%-10d %-15s t",p->num,p->name);
        for(i=1;i<=k;i++)
            printf("%4.0f ",p->score[i]);
        printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        p=p->next;
    }/* while */
    printf("n");

    /**
	*����ɸѡ
	*ɸѡ�����㣬������
	*@since 1.6
	*@date 2013-12-29 22:24
	*@author YouthLin
	**/
	if (!j){
		t=0;
		printf ("tttYou can also:tt�㻹����:n");
		printf ("t1.Screening excellent list.ttt1��ɸѡ��������n");
		printf ("t2.Screening good list.tttt2��ɸѡ��������n");
		printf ("t3.Screening Medium list.ttt3��ɸѡ��������n");
		printf ("t4.Screening Pass list.tttt4��ɸѡ��������n");
		printf ("t5.Screening failing list.ttt5��ɸѡ����������n");
		printf ("t0.Back.tttttt0������nn");
		scanf("%d",&ch);
		if (ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5){
			return 0;
		}

		p=head;
		printf("nѧ��Idtt����Namet");
		for(i=1;i<=k;i++)
   			printf("%4d ",i);
   		printf("ƽ��Ave �ܷ�Totnn");	//��ӡ��ͷ

		if (ch==1){
			while(p!=NULL){
				if (p->score[0]>=90){
     	 		  	printf("%-10d %-15s t",p->num,p->name);
  		 			for(i=1;i<=k;i++)
            			printf("%4.0f ",p->score[i]);
        			printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        			t++;
				}
        		p=p->next;
			}//while
			if (t==0){
				printf("Not find...tttû�ҵ������Ϣ...n");
			}

			return 0;
		}//����
		if (ch==2){
			while(p!=NULL){
				if (p->score[0]>=80&&p->score[0]<90){
     	 		  	printf("%-10d %-15s t",p->num,p->name);
  		 			for(i=1;i<=k;i++)
            			printf("%4.0f ",p->score[i]);
        			printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        			t++;
				}
        		p=p->next;
			}//while
			if (t==0){
				printf("Not find...tttû�ҵ������Ϣ...n");
			}
			return 0;
		}// ����
		if (ch==3){
			while(p!=NULL){
				if (p->score[0]>=70&&p->score[0]<80){
     	 		  	printf("%-10d %-15s t",p->num,p->name);
  		 			for(i=1;i<=k;i++)
            			printf("%4.0f ",p->score[i]);
        			printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        			t++;
				}
        		p=p->next;
			}//while
			if (t==0){
				printf("Not find...tttû�ҵ������Ϣ...n");
			}
			return 0;
		}//�е�
		if (ch==4){
			while(p!=NULL){
				if (p->score[0]>=60&&p->score[0]<70){
     	 		  	printf("%-10d %-15s t",p->num,p->name);
  		 			for(i=1;i<=k;i++)
            			printf("%4.0f ",p->score[i]);
        			printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        			t++;
				}
        		p=p->next;
			}//while
			if (t==0){
				printf("Not find...tttû�ҵ������Ϣ...n");
			}
			return 0;
		} //����
		if (ch==5){
			while(p!=NULL){
				if (p->score[0]<60){
     	 		  	printf("%-10d %-15s t",p->num,p->name);
  		 			for(i=1;i<=k;i++)
            			printf("%4.0f ",p->score[i]);
        			printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        			t++;
				}
        		p=p->next;
			}//while
			if (t==0){
				printf("Not find...tttû�ҵ������Ϣ...n");
			}
			return 0;
		} //������

	} //ɸѡ

    return 0;
}/* list��� */

/**
*����7--��ѧ�Ŵ�С�����ų��ɼ���
*@Author �� ������
*@Date	:	2013-12-26
*��������
*
*/
int sort_by_num(pstu head){
	pstu p,q;
	int bnum,l,i;
	char bname[NL];
	float bscore[NS];
	system(CLEAR);
	printf("Home->Sort in ascending order by numbern��ҳ->��ѧ����С�����ų��ɼ���nn");
	for (l=1;l<=people;l++){
		p=head;
		q=p->next;
		while (q!=NULL){
		//while (q->next!=NULL){
			if ((p->num)>(q->num)){
				bnum=p->num;
				p->num=q->num;
				q->num=bnum;
				for (i=0;i<NL;i++){
					bname[i]=p->name[i];
					p->name[i]=q->name[i];
					q->name[i]=bname[i];
				}/* for */
				for (i=0;i<NS;i++){
					bscore[i]=p->score[i];
					p->score[i]=q->score[i];
					q->score[i]=bscore[i];
				}/* for */
			}/* if */
			p=p->next;
			q=q->next;
		}/* while */
	}/* for */


	//output(front);
	return 0;
}


/**
*����9--����ѧ�Ų���ѧ���ĳɼ�
*@Date : 2013-12-27
*/
int search_by_num(pstu head){
	int i=0,flag=1,gole=0,id,ii;
	pstu p=head;
	system(CLEAR);
	printf("Home->Search by numblen��ҳ->��ѧ�Ų�ѯѧ���������俼�Գɼ�nn");
	if (head==NULL){
		printf("There are nothing.tʲô��û��.n");
		return 0;
	}
   	printf("please input the student id:n");
	//scanf("%d",id);
	scanf("%d",&id);
while(flag){
	system(CLEAR);
	printf("Home->Search by numble->Resultsn��ҳ->��ѧ�Ų�ѯѧ���������俼�Գɼ�->���nn");
	printf("ѧ��Id     ����Namet   �ܷ�Total   ����Rank  ");
	for (ii=0;ii<k;ii++){
		printf(" %3d",ii+1);
	}
	printf("n");
	while(p!=NULL){
		i++;
		if(id==(p->num)){
			printf("%-10d %-15s   ",p->num,p->name);
			printf("%.2ft",p->score[7]);
			printf("%dt ",i);
			for (ii=0;ii<k;ii++){
				printf(" %3.0f",p->score[ii+1]);
			}
			printf("n");
			gole++;
		}
		p=p->next;
 	}
 	if(gole==0){

 		printf("û����Ҫ�ҵ���Ϣ������������(����-1�˳���ѯ)n");
 		scanf("%d",&id);
 		getchar();
 		if(id==-1)
 			flag=0;
		//printf("%d[����]n",id);
	 	p=head;
	 	i=0;
 	}
 	else
		return 0;
} /* while */

 	return 0;
}
