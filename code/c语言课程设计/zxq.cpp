/**http://youthlin.com
*�Ӻ��� ���� 4��6��10��13
*@author zxq
*@package Student Achievement Management System
*@subpackage zxq.cpp
*@since main_v1.4.cpp
*/


/**
*����4--����ÿ��ѧ�����ܳɼ���ƽ���ɼ�
*@Date 2013-12-24
@Author ��Тȫ
*/
int cal_every_stu(pstu head,int j){
                 	//���j=1���������Ӻ�������,�����
    system("color 0f");     	//0f    ������ɫ   ��������ɫ
	pstu p0,p;
	p0=NULL;
	p=head;

	if(p==NULL){
		printf("Home->Calculate total and average score of every studentn��ҳ->����ѧ�����ֺܷ�ƽ����nn");
		printf("No content to calculate.tû�пɹ�����Ķ���.n");
        return 0;
	}
	while(p!=NULL){
        //������6��,������0
		p->score[7]=p->score[1]+p->score[2]+p->score[3]+p->score[4]+p->score[5]+p->score[6];
		p->score[0]=p->score[7]/k;
		p0=p;
		p=p->next;
	}
	if (j!=1){
		printf("Home->Calculate total and average score of every studentn��ҳ->����ѧ�����ֺܷ�ƽ����nn");
		printf("ѧ��Idtt����Namettt�ܷ�Totaltƽ����Averagenn");
		p=head;
		while(p!=NULL){
      	  //float score[NS];        //NS=8 1-6�ɼ� 0ƽ�� 7�ܷ�
       	 printf("%-10dt%-15s  tt%5.0ftt%5.2fn",p->num,p->name,p->score[7],p->score[0]);
       	 p=p->next;
		}/* while */
		printf("n");
	}/** ��� */
	return 0;
}/** ����ÿ��ѧ�����ܳɼ���ƽ���ɼ� */

/**
*����13--��ÿ��ѧ��������Ϣ�ͳɼ�д���ļ�
*@Date 2013-12-26 02:40
*/
int write_to_file(pstu head){
    system(CLEAR);
    pstu p=head;
    int i;
    char filename[160];
    FILE * fp;

    time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	//printf ( "The current date/time is: %s", asctime (timeinfo) );
	//printf ( "%4d-%02d-%02d %02d:%02d:%02dn",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);

    printf("Home->Write to a filen��ҳ->�������ļ�nn");
    if (p==NULL){
        printf("There are nothing need to write to a file.nû������д���ļ���~~n");
        return 0;
    }
    printf("Please input file name:t�����ļ���:n");
    scanf("%s",filename);
    if((fp=(fopen(filename,"a")))==NULL){
        printf("Can not open file!! :( t���ļ�ʧ��!!n");

    }
    cal_every_stu(head,1);      //�����ܷ�ƽ����

    fprintf(fp,"ѧ��Idtt����Namet");
    for(i=1;i<=k;i++)
        fprintf(fp,"%4d ",i,i);
    fprintf(fp,"ƽ��Ave �ܷ�Totnn");
    while(p!=NULL){
        fprintf(fp,"%-10d%-15s t",p->num,p->name);
        for(i=1;i<=k;i++)
            fprintf(fp,"%4.0f ",p->score[i]);
        fprintf(fp,"t%5.2ft%5.0fn",p->score[0],p->score[7]);
        p=p->next;
    }/* while */
    fprintf(fp,"n");

    fprintf (fp,"nSaved in: %4d-%02d-%02d %02d:%02d:%02dtttt",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
    fprintf (fp,"%s", asctime (timeinfo) );
	fprintf(fp,"nn");
    fclose(fp);

    printf("successfully write to file :) t�ɹ�д���ļ�n");

    ifsave=1;   //�ѱ���

    return 0;
}/**д���ļ�*/


/**
*����6--���ִܷӵ͵�������
*���� : ��������
*�ο� ���̲�P336-338
*ԭ�����ӣ�
*@Author 	����Тȫ
*@Date 		: 2013-12-26
*@Update 	: 22:20
*�Ľ�		�����������������
*i=1�Ӹߵ���	i=0�ӵ͵��� (v1.4.2 ����)
*/
qstu sort_by_total_asc(qstu head,int j){
	pstu p,p0,r,r0,q;
	cal_every_stu(head,1);
	p0=NULL;
	p=head;
	if (!j){
		printf("Home->Sort in ascending order by total score of every studentn��ҳ->��ÿ��ѧ�����ܷ��ɵ͵����ų����α�nn");
	}
	if (p==NULL){
		printf("Nothing can be sortednû�пɹ����������n");
		return head;
	}
	while(p!=NULL){/* �������p���뵽�������У�������base--p�ź��� */
		/* Ѱ��qҪ�����λ�� r0,r */
		r=head;

		while((r->score[7]<p->score[7])&&(r!=p)){
				r0=r;
				r=r->next;
		}

		/* p���뵽r0,r֮�� */
		if (r!=p){		/* ��r==p������β�����ò��� */
			/* ��p������������qָ���� */
			q=p;
			p0->next=p->next;
			p=p0;
			/* ���� */
			if (r==head){	/* �������� */
				q->next=head;
				head=q;
			}else{			/* ����r0,r֮�� */
				q->next=r;
				r0->next=q;
			}/* if--else */
		}/* if */
		/* ǰ�� */
		p0=p;
		p=p->next;
	}/* while */


//	output(head);
	return head;
} /* ���� */


/**
*����10--������������ѧ���ĳɼ�
*
*/
int search_by_name(pstu head){
	int i=0,flag=1,ii;
	int gole=0;
	char name0[NL];
	pstu p=head;
	system(CLEAR);
	printf("Home->Search by namen��ҳ->��������ѯѧ���������俼�Գɼ�nn");
	if (head==NULL){
		printf("There are nothing.tʲô��û��.n");
		return 0;
	}
	//�����������������:@Update : 2013-12-26 OK
	//p=sort_by_total_des(head);
	//p=front;

	 /**
	 *@UPdate : 2013-12-27
	 *���ڴ˺����ڲ�������������sort_by_total_des�����ڵ��ô˺���֮ǰ����
	 */


   	printf("please input a name:n");
	scanf("%s",name0);
while(flag){
	system(CLEAR);
	printf("Home->Search by name->Resultsn��ҳ->��������ѯѧ���������俼�Գɼ�->���nn");
	printf("ѧ��Id      ����Namet   �ܷ�Total   ����Rank  ");
	for (ii=0;ii<k;ii++){
		printf(" %3d",ii+1);
	}
	printf("n");
	while(p!=NULL){
		i++;
		if(strcmp(name0,p->name)==0){
			printf("%-10d %-15st",p->num,p->name);
			printf("%.2f   ",p->score[7]);
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
 		printf("û����Ҫ�ҵ���Ϣ������������(����EXIT�˳���ѯ)n");

 		scanf("%s",name0);
 		if(strcmp(name0,"EXIT")==0)
 			flag=0;
			p=head;	//����ָ�� ��@Update : 2013-12-27 @By :���٣�����裮�̣�
			i=0;
	}
	else
		return 0;
} /*  while */
 	return 0;
}
