/**
*�Ӻ��� ���� 1��2��5��8��11
*@author Youthlin  http://youthlin.com/
*@package Student Achievement Management System
*@subpackage youthlin.cpp
*@since main_v1.0.cpp
*/

#define Str "SAMS filenStudent Achievement Management Systemnѧ���ɼ�����ϵͳn"
#define length (sizeof(Str))
/**
*������Ӻ���
*�ο��Խ̲�P335
*
*�� ���ļ�������ֶ�¼�� ����
*/
int inqueuce(pstu head){
	pstu p;
	int i;
	if ((p=(pstu)malloc(sizeof(stu)))==NULL){
		printf("Memory allocation failure!t�ڴ�����ʧ�ܣ�tn");
		return 1;					//ʧ���з���ֵ����read�����������ж�~~~
	}
	p->num=head->num;
	strcpy(p->name,head->name);
	for (i=0;i<NS;i++)
		p->score[i]=head->score[i];
	p->next=NULL;
	if (rear==NULL){
		rear=p;
		front=p;
	}else{
		rear->next=p;
		rear=p;
	}

	return 0;
}

/**
*���
*���  ������
*/
int output(pstu pstu0){
	pstu p,p0;
	p=pstu0;
	p0=NULL;
	if (k==0||front==NULL){
		printf("No available content for output :( tû�пɹ����������...tn");
		system(P);
		return 0;
	}
	while(p!=NULL){

		int i=0;

		printf("%-10d %-15s t",p->num,p->name);		//��� ѧ������
		for(i=0;i<NS;i++){
			printf(" %3.0f ",p->score[i]);				//��� �ɼ�
		}
		printf("n");
		//printf("[Output]n");
	p0=p;
	p=p->next;
	}

	return 0;
}



/**
*����1--���ļ�����
*@Author Youth.Lin
*@since main_v0.1.cpp
*@LastUpDate : 2013-12-25
*����д�ĺ�����������õġ�����
*/
int read(){
	int i,t=0,ch,j,yn,flag;			//i����ѭ����tΪ��¼��j������Ӻ�������ֵ��chΪѡ�� ,flag�жϷ����Ƿ����� 	k0������ʱk
	struct student stu0;
	struct student * pstu0;
	pstu0=&stu0;
	char f[160];				//�ļ���
	FILE *fp;					//�ļ�ָ��
	system(CLEAR);
	printf("Home->Read from filen��ҳ->���ļ�����nn");

	//ϵͳ�����м�¼ʱ
	if (front!=NULL){
		getchar();
		printf("Record already existed,still add record?t���м�¼��׷�ӣ�(1-yes,other-no)n");
		scanf("%d",&yn);		//�ַ���%c̫���ÿ����ˡ�����������Ҳ����һֱ��С������....
		getchar();
		if(yn !=1)
			return 0;			//��׷�ӣ����������˵�
	}/* if */

 	//while(1)��Ϊ��ѡ���������continue����
	while (1){
		j=0;
		system(CLEAR);
		system("color 2f");		//2f ������ɫ	ǰ������ɫ
		/**����
		*@since 1.5
		*@author YouthLin
		*/
		printf("Home->Read from filen��ҳ->���ļ�����nn");
		//��ʾ�ļ��ĸ�ʽ
		printf("You have choose to read infomation from file,nplease ensure your file formot is as follows:n");
		printf("��ѡ���˴��ļ�����ѧ����Ϣ����ȷ�������ļ���ʽ���£�n");
		printf("the number of courses in the sample file is 6.tʾ���ļ��п�Ŀ��Ĭ��Ϊ6.n");
		printf("(The first line will be ignored.t��һ�н������ԡ� n<=6 )nn");
		printf("   ѧ��tt����tt����t��Ŀ2t��Ŀ3t��Ŀ4t...t��Ŀnttn");
		printf("   54131001tliuruitaot80t75t68t86t78t90n");
		printf("   54131002tchenmeilint90t85t78t88t68t95n");
		printf("   ......t......tnn");
		printf("t1. I have read about it.t��֪����nt2. Use sample file.ttʹ��ʾ���ļ�nt0. Back to main menu.tt�������˵�n");
		scanf("%d",&ch);

		if (ch==0)
			return 0;
		//�������˵�

		/* �û��ļ� */
		if (ch==1){

			//��ǰ �ӿյĻ�
			if (k==0&&people==0){
				printf("Please input the number of courses:t������γ̿�Ŀ������n");
				/**
				*��Ŀ�����ļ���һ�»Ῠ��������
				*@Update : 2013-12-25
				*/
				printf("Please make sure your input is equal to the file's number of courses!nOR it will be cause unpredictable consequences!!!n");
				printf("��ȷ��������Ŀ�Ŀ�����ļ�����һ�µģ�n���򽫵��²���Ԥ�ϵĺ��������n");
				/* update */
				scanf("%d",&k);
				if (k<1||k>6){
					k=0;					// ��ʼ����ȥ
					printf("Input error!tttt��������tn");
					system(P);
					continue;	/* ��whule(1)�ļ���ʽ��ʾ */
				}/*����Ŀ����*/
			}
			//���գ������м�¼
			else{
				printf("The current numble of courses is %d.ttn��ǰϵͳ�γ�Ϊ%d�ơ�tn",k,k);
				printf("nTo change the course number, please restart this program.tnҪ���ĵ�ǰ��Ŀ����������������tn");
				printf("nForced to read a file whose number of courses is different with current courses will cause unpredictable consequences.n");
				printf("ǿ�ж����뵱ǰϵͳ��Ŀ����һ�µ��ļ������²���Ԥ�ϵĺ����tn");
			}/*if--else*/


			printf("nPlease input your filename:tt�������ļ�����tn");
			scanf("%s",&f);

			if ((fp=fopen(f,"r"))==NULL){
				printf("Error! Can not open file!tt���ļ�ʧ�ܣ�tn");
				system(P);
				continue;
			}/*���ļ�*/

			while(fgetc(fp)!='n');					//�Թ���һ��
			while (!feof(fp)){
				if (fgetc(fp)=='n')continue;		//�س�����ֱ������//continued����һ��while(!feof()) �ļ�δ����
				else{
					fseek(fp,-2L,1);				//�����ǻس����У�Ҳִ������һ��fgetc ������Ҫ��ǰ����һ���ַ�
					fscanf(fp,"%d%s",&stu0.num,&stu0.name);
					for (i=1;i<k+1;i++)
						fscanf(fp,"%f",&stu0.score[i]);		//�м��мǸ����ͣ�����
				}/*if--else*/

				//�淶����ʱ�ṹ��
				stu0.score[0]=0;
				stu0.score[NS-1]=0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						stu0.score[i]=0.0;
				}/*�淶�� Ϊ���׼��*/


				/**
				*�������Ƿ�������0-100��
				*@Update : 2013-12-25
				*/
				flag=0;
				for (i=1;i<=k;i++){
					if (stu0.score[i]>100||stu0.score[i]<0)
						flag=1;			//������������flag��־��Ϊ1
				}
				if (flag){
					printf("Please check your file and make sure the score is 0-100.n�����ļ���ȷ��������0-100�ڣ�n");
					fclose(fp);

					return 1;
				} /* �������Ϸ��� */



				/*���*/
				j=inqueuce(&stu0);
				if (j)
					return 1;		//j����Ӻ������أ�j=1��ʧ�ܣ�return�����˵�
				if (j==0){
					t++;		//t��¼��
					continue;
				}//j=0,��ӳɹ�������������continue�Ƕ�while�ļ�����
			}/*while�ļ�����*/

			/*�ر��ļ�*/
			fclose(fp);

			printf("nSuccessfully read %d record.tt�ɹ�����%d����¼��tn",t,t);
			people+=t;		//��ǰ��������
			t=0;
			printf("nCurrent number of student is %d .t��ǰϵͳѧ������Ϊ%d�ˡ�tnn",people,people);
			output(front);
			return 0;			//�������˵���
		}/*if ch==1 �û��ļ�*/

		/* ʾ���ļ� */
		if (ch==2){
			if ((fp=fopen("sample.dat","r"))==NULL){
				printf("Can not open the sample file!t��ʾ���ļ�ʧ�ܣ�tn");
				system(P);
				continue;		//������ʾ�ļ���ʽ,continue��while (1)
			}/*���ļ�*/

			//printf("k===========%d",k);
			if (!(k==0||k==6)){
				/**
				*�жϵ�ǰ��Ŀ����
				*@Update : 2013-12-25
				*/
				printf("The current numble of courses is %d.ttn��ǰϵͳ�γ�Ϊ%d�ơ�tn",k,k);
				printf("The number of course in the sample file is 6.tʾ���ļ�Ĭ�Ͽ�Ŀ��Ϊ6��n");
				printf("nForced to read a file whose number of courses is different with current courses will cause unpredictable consequences.n");
				printf("ǿ�ж����뵱ǰϵͳ��Ŀ����һ�µ��ļ������²���Ԥ�ϵĺ����tn");
				printf("nPlease back to chose another item.tt�뷵����ѡ...n");
				system(P);
				continue;
			}


			k=6;	//ʾ���ļ�Ĭ�Ͽ�ĿΪ6

			while (fgetc(fp)!='n');		//�Թ���һ��

			while (!feof(fp)){
				if (fgetc(fp)=='n')continue;		//�س�����ֱ������
				else{
					fseek(fp,-2L,1);				//�����ǻس����У�Ҳִ������һ��fgetc ������Ҫ��ǰ����һ���ַ�

					fscanf(fp,"%d",&pstu0->num);
					fscanf(fp,"%s",pstu0->name);
					for(i=1;i<=6;i++){
						fscanf(fp,"%f",&stu0.score[i]);		//�ر�Ҫע�⣬����ʱscore�Ǹ����ͣ��������score��Ҫ��%f
					}

				}/*if--else*/

				stu0.score[0]=0;
				stu0.score[NS-1]=0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						stu0.score[i]=0.0;
				}/* �ⲻ�Ƕ��һ�٣����Ǻ궨��NS���������ڣ�ĿǰNS=8��  */

				/*//���Բ鿴������Ƿ���ȷ����
				printf("���Բ鿴%d/ %s/t",stu0.num,pstu0->name);
				for(i=0;i<NS;i++){
					printf("%4.0f",pstu0->score[i]);
				}
				printf("n");
				*/

				j=inqueuce(&stu0);	//���
				//printf("%d%s%4.0f%4.0fn",front->num,front->name,front->score[1],front->score[2]);

				if (j)
					return 1;		//������������������ʾ��Ϣ��inqueuce
				if(j==0){
					t++;
					continue;		//continue��while�ļ�δ����
					//printf("%d   %s  %dn",front->num,front->name,front->score[1]);
				}/*if*/

				//printf("%d   %s  %dn",front->num,front->name,front->score[1]);
			}/*while �ļ����� */

			/*�ر��ļ�*/
			fclose(fp);

			printf("Successfully read %d record.ttt�ɹ�����%d����¼��n",t,t);
			people+=t;		//��ǰ��������
			printf("nCurrent number of student is %d .tt��ǰϵͳѧ������Ϊ%d�ˡ�nn",people,people);
			output(front);
			//printf("%dtt%st%dtn",front->num,front->name,front->score[1]);
			//printf("%d   %s  %dn",front->num,front->name,front->score[1]);


			return 0;			//�������˵���
		}/*if ch==2 ʾ���ļ�*/


		else{

			printf("nSelect not correct...tttѡ�����󡣡���tn");
			/*
			printf("Press any key to continue.tt�������������tn");
			//_getch();
			getchar();			//getchar��һ���ܲ��Ѻõļһ����pause
			getchar();
			*/

			//printf("nD==%dC--%cS--%on",ch,ch,ch);

			ch=0;
			//printf("D==%dC--%cS--%on",ch,ch,ch);

			system(P);
			continue;
		}	//continue��ȥ�ļ���ʽ��ʾ while(1)

	}/*while��1��*/
	return 0;
}/*  read()  */


/**
*����2--�ֶ�����
*@Author Youth.Lin
*@since main_v1.3.cpp
*/
int append(){
	int i,t=0,j,yn,ch,flag;			//i����ѭ����tΪ��¼��j������Ӻ�������ֵ
	pstu pstu0;
	pstu0=(pstu)malloc(sizeof(stu));
	system(CLEAR);
	printf("Home->Append record manullyn��ҳ->�ֹ�¼��nn");

	//ϵͳ�����м�¼ʱ
	if (front!=NULL){
		getchar();
		printf("Record already existed,still add record?t���м�¼��׷�ӣ�(1-yes,other-no)tn");
		scanf("%d",&yn);
		getchar();

		if(yn !=1)
			return 0;			//��׷�ӣ����������˵�
	}/* if */

	while(1){
		system(CLEAR);
		system("color 2f");		//2f ������ɫ	ǰ������ɫ
		printf("Home->Append record manullyn��ҳ->�ֹ�¼��nn");

		printf("Tips:You can Batch Import student information via read from filenС��ʾ��������ѡ����ļ���������ѧ����ϢŶnn");
		printf("t1.Continue to append record manuallyt1�������ֹ�����n");
		printf("t0.Go back to main menu.ttt0�����������˵�n");
		printf("nPlease input your choice:t��������ѡ��n");
		scanf("%d",&ch);

		if (ch==0)
			return 0;
		else if (ch==1){
			if (k==0){
				printf("Please input the number of courses:tt������γ̿�Ŀ������n");
				printf("The number of courses CAN NOT be modified.t�γ̿�Ŀ�����������ܡ����޸ģ�n");
				scanf("%d",&k);
				if (k<1||k>6){
					k=0;

					printf("Input error!ttttt��������tn");
					system(P);
					continue;		//��while 1 С�˵�
				} /* ������� */
			}/* k==0 */

			/* k!=0 */
			printf("The current numble of courses is %d.ttn��ǰϵͳ�γ�Ϊ%d�ơ�tn",k,k);
			printf("nTo change the course number, please restart this program.tnҪ���ĵ�ǰ��Ŀ����������������tnn");

			printf("Pease input Student ID:t������ѧ�ţ�n");
			scanf("%d",&(pstu0->num));
			//system(P);
			printf("Please input name:t������ѧ��������n");
			scanf("%s",pstu0->name);
			printf("Please input %d scores:t������%d�ųɼ�n",k,k);
			for (i=1;i<=k;i++)
				scanf("%f",&(pstu0->score[i]));
			getchar();
			/* ����ȷ�� */
			printf("nIs it right?tȷ��һ�£�nn");
			printf("%d %s ",pstu0->num,pstu0->name);
			for (i=1;i<=k;i++)
				printf("%4.0f ",pstu0->score[i]);
			printf("n");
			/* ����ȷ�� */
			printf("n:) Yes,it's right.(input 1)tttû������1��n");
			printf(":( No I want to Re-enter.(input any other)t���ԣ��������루������������nn");
			scanf("%d",&yn);
			if (yn==1){
				/**
				*�������Ƿ�������0-100��
				*@Update : 2013-12-25
				*/
				flag=0;
				for (i=1;i<=k;i++){
					if (pstu0->score[i]>100||pstu0->score[i]<0)
						flag=1;			//������������flag��־��Ϊ1
				}
				if (flag){

					printf("Please check your input and make sure the score is 0-100.n�������벢ȷ��������0-100�ڣ�n");
					system(P);
					continue;	//��С�˵�
				} /* �������Ϸ��� */

				pstu0->score[0]=0.0;
				pstu0->score[NS-1]=0.0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						pstu0->score[i]=0.0;
				}/*�淶�� Ϊ���׼��*/

				j=inqueuce(pstu0);
				if (j)
					return 1;		//j����Ӻ������أ�j=1��ʧ�ܣ�return�����˵�
				if (j==0){
					t++;		//t��¼��
				}//j=0,��ӳɹ���
			}/* ����ȷ��û�� */
			else
				continue;
			/* �д� *//////continue��С�˵�

		 	printf("nSuccessfully read %d record.tt�ɹ�����%d����¼��tn",t,t);
			people+=t;		//��ǰ��������
			printf("Current number of student is %d .t��ǰϵͳѧ������Ϊ%d�ˡ�tn",people,people);

			printf("nContinue to append record?tt����������n(1--yestother--no)n");
			scanf("%d",&yn);
			if (yn==1){
				t=0;	//@Update : 2013-12-27 ������t�ᵼ��ȫ�ֱ���people�д�
				continue;
			}

			else{
     //               output(front);
				return 0;
			}
			/* ������ */
		}/* ch==1 */
		else{
			printf("Select not correct...tttѡ�����󡣡���tn");
			system(P);
			continue;
		} /* С�˵�ѡ����� */

	}/* while(1) */

	return 0;
}/* append() */

/*
*����5--���ִܷӸ���������
*��������Ԫ����|ѡ������
*��Ԫ���򣺽̲� p138-139
*��Ҫ��������������̲�p330
*@Date : 2013-12-24
*/

/**
*����5--���ִܷӸ���������
*������ð������
*@Old �ɷ��� ��Ԫ����:ʧ��...
*��Ҫ��������������̲�p330
*@Date : 2013-12-26
*/

/**
*����5--���ִܷӸ���������
*���� : ��������
*�ο� ���̲�P336-338
*ԭ�����ӣ�
*@Date : 2013-12-26
*/
pstu sort_by_total_des(pstu head,int j){
	pstu p,p0,r,r0,q;
	cal_every_stu(head,1);
	p0=NULL;
	p=head;
	if (!j){//j=0�����������������������ǰλ��
		printf("Home->Sort in descending order by total score of every studentn��ҳ->��ÿ��ѧ���ܷ��ɸߵ�������nn");
	}//j!=0 �����

	if (p==NULL){
		printf("Nothing can be sortednû�пɹ����������n");
		return head;
	}

	while(p!=NULL){/* �������p���뵽�������У�������base--p�ź��� */
		/* Ѱ��qҪ�����λ�� r0,r */
		r=head;

		while((r->score[7]>p->score[7])&&(r!=p)){
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


	return head;
} /* ���� */


/**
*����11--�ȼ�ͳ��
*@Author Youth.Lin
*@�ݸ� : 2013-12-24
*@Date : 2013-12-25 22:24�깤!
*/
int statistic (pstu head){
	system(CLEAR);
	system("color 4e");		//4e	������ɫ	���ֵ���ɫ
	pstu p0=NULL,p;
	int i,grade[7][5]={{0},{0},{0},{0}};        //grade[i][0-4]��ʾi������-������
	float temp;
	char filename[160];
	FILE * fp;

	/**
	*���� ��ȡ��ǰʱ��
	*@Date 2013-12-29 16:10
	*@link http://zhidao.baidu.com/link?url=o3Xma9gGC1DgrpVW_5sv9s2CqAeHElWEObJXtR3LR_jjqspsBAc5bEkCGLRBk5zOOdJk3Tcu3XNelQAIQiaOTq
	*����������ļ�
	*/
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );



	printf("Home->Statistic analysis for every coursen��ҳ->���ȼ�ͳ�ƿ��Գɼ�nn");
	if (front==NULL){
		printf("Er...statistic what?t���������ʺ����n");
		return 0;
	} /* �ӿ� */
	p=head;
	while(p!=NULL){
        for(i=1;i<=k;i++){
            temp=p->score[i];
            if (temp>0&&temp<59)
                grade[i][4]++;
            else if (temp<69)
                grade[i][3]++;
            else if (temp<79)
                grade[i][2]++;
            else if (temp<89)
                grade[i][1]++;
            else if (temp<=100)
                grade[i][0]++;
            else{
                printf("Error!the achievement can NOT be <0 or >100t������!��������С��0�����100!n");
                return 1;
            }
        }/* for */
        p0=p;
        p=p->next;
	}/* while */
	/* ͳ����� */

	/* �������Ļ */
	printf("      �U����  ������  ����  ������  �е�  �е���  ����  ������  ������  ��������n");
	printf("�T�T�T�p�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�Tn");
	for(i=1;i<=k;i++){
        printf("��Ŀ %d�U%3d  %6.2f%%  %3d  %6.2f%%  %3d  %6.2f%%   %3d  %6.2f%%   %3d   %6.2f%%n",i,grade[i][0],grade[i][0]*100.0/people,grade[i][1],grade[i][1]*100.0/people,grade[i][2],grade[i][2]*100.0/people,grade[i][3],grade[i][3]*100.0/people,grade[i][4],grade[i][4]*100.0/people);
        //���k�ſ�Ŀ 5 ���ȼ�
	}
	while(1){
        printf("nPlease input a filename to save the statistic result:n�������ļ����Ա�������ͳ����Ϣ��n");
        printf("(Will create a file,if file already exist the result will be write to the end of the file.���ᴴ������ļ�������ļ��Ѿ���������ļ�βд�롣)n");
        scanf("%s",filename);
        if ((fp=fopen(filename,"a"))==NULL){
            printf("Can not creat the file!t�����ļ�ʧ�ܣ�n");
            continue;
        }/* ���ļ� */
        //fprintf(fp,"////////////////////////////////////////////////////////////////////////////////n");
        //fprintf(fp,"//The fallows are statistical results of Student Achievement Management System//n");
        //fprintf(fp,"//Copyright (c)2013 Software College of Jilin University Grade 2013 Class 10////n//By Chen Meilin,Zhang xiaoquan,Liu ruitao//////////////////////////////////////n");
        //fprintf(fp,"////////////////////////////////////////////////////////////////////////////////");
        fprintf(fp,"n      �U����  ������  ����  ������  �е�  �е���  ����  ������  ������  ��������n");
        fprintf(fp,"�T�T�T�p�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�Tn");
        for(i=1;i<=k;i++){
            fprintf(fp,"��Ŀ %d�U%3d  %6.2f%%  %3d  %6.2f%%  %3d  %6.2f%%   %3d  %6.2f%%   %3d   %6.2f%%n",i,grade[i][0],grade[i][0]*100.0/people,grade[i][1],grade[i][1]*100.0/people,grade[i][2],grade[i][2]*100.0/people,grade[i][3],grade[i][3]*100.0/people,grade[i][4],grade[i][4]*100.0/people);
        //���k�ſ�Ŀ 5 ���ȼ�
        }
        fprintf (fp,"nSaved in: %4d-%02d-%02d %02d:%02d:%02dtttt",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
        fprintf (fp,"%s", asctime (timeinfo) );
		fprintf(fp,"nn");


        fclose(fp);//�ر��ļ�
        printf("Write to file successful!tд���ļ��ɹ�!n");

        return 0;
	}/* while (1) */
	return 0;
}/* ͳ�� */

/**
*����8-- �������ֵ�˳���ų��ɼ���
*
*/
pstu sort_by_name(pstu head){
	pstu p,p0,r,r0,q;
	//cal_every_stu(head,1);
	p0=NULL;
	p=head;
	system(CLEAR);
	printf("Home->Sort in ascending order by namen��ҳ->���������ֵ�˳���ų��ɼ���nn");
	while(p!=NULL){/* �������p���뵽�������У�������base--p�ź��� */
		/* Ѱ��qҪ�����λ�� r0,r */
		r=head;

		while((strcmp(r->name,p->name)<0)&&(r!=p)){
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
*�浵����
*@since 1.5
*@author YouthLin
*/
int saveload(pstu head){
	int choice,ch,t=0,j,i;
	FILE * fp;
	pstu p,p0,p1;
	char st[]=Str;
	system(CLEAR);
	system("color e4");		//e4	��������ɫ	���ֺ�ɫ
	printf("Home->Save/Loadn��ҳ->�浵����nn");
	printf("What would you want to do:tt����Ҫ��nn");

	printf("tt1.Savett1���浵n");
	printf("tt2.Loadtt2������n");
	printf("tt0.Backtt0������n");
	scanf("%d",&choice);
	if (choice==0){
		return 0;
	}
	else if (choice==1){
		printf ("Will cover the latest saved file.n���Ḳ�����һ�δ浵��nnt1.I know,continue.t1���õģ�������nt0.Oh no,Back.tt0����Ҫ�ˣ����ء�n");
		scanf ("%d",&i);

		if (i!=1){
			printf("You have to cancel the operation.Now back to main menu.n����ȡ�����������������˵���n");
			return 0;
		}//����

		if (front==NULL){
			printf("Needn't to save,there are nothing in the system.n����浵��ϵͳ�����κ���Ϣ��n");
			return 0;
		}
		if ((fp=fopen("save.sams","wb"))==NULL){
			printf("ERROR!Can not create file to save!n���󣡲��ܴ����浵�ļ���n");
			return 1;
		}/** �����ļ� */

		//�ļ�ͷ
		fwrite(st,length,1,fp);
		p=head;
		while (p!=NULL){

			fwrite(p,sizeof(stu),1,fp);
			p=p->next;
		}/** while */
		fclose(fp);
	 	printf("Successfully save to save.samst�ɹ������浵save.sams n");
	 	return 0;
	}/*choice==1*/

	else if (choice==2){
		p=(pstu)malloc(sizeof(stu));
		if((fp=fopen("save.sams","rb"))==NULL){
				printf("ERROR,Can not find or open file save.sams n�����Ҳ������ܴ򿪴浵save.sams n");

				return 1;
		}
		//printf("5555555555555555555555555555555555555555555555555555");
		if (front!=NULL){
			printf("Record already existed,You want:t���м�¼����ѡ��n");
			printf("t(1. )Addtt(2. )Coveragett(0. )Backn");
			printf("t(1��)����tt(2��)����tt(0��)����n");
			scanf("%d",&ch);
			if (ch!=1&&ch!=2){
				return 0;
			}//����

			if (ch==2){
				p0=front;
				p1=p0->next;
				while (p1->next!=NULL){		//����ɾ��ԭ������
					free(p0);
					p0=p;
					p1=p1->next;
				}//ɾ��

				front=NULL;
				/**
				*@Update : 2013-12-29
				*
				*��Ҫ���ö�β����Ϊ
				*@see inqueuce
				*��Ӻ��� ��Ҫ�ж�rear�Ƿ�Ϊnull
				*
				*/
				rear=NULL;

				people=0;
			} //����
		}//���м�¼

		//printf("5555555555555555555555555555555555555555555555555555");
		fread(st,length,1,fp);	//�����ļ�ͷ

		while(!feof(fp)){

			fread(p,sizeof(stu),1,fp);

			p->next=NULL;

			//printf("%d;%s;n%f/%f/%f;n%onn",p->num,p->name,p->score[0],p->score[1],p->score[3],p->next);

			j=inqueuce(p);
			if (j)
				return 1;		//j����Ӻ������أ�j=1��ʧ�ܣ�return�����˵�
			if (j==0){
				t++;
			}//j=0,��ӳɹ���

		}//�ļ�����

		fclose(fp);
		/********************************  "�о�����" ����һ��  Ϊ��ô�� �����һ��ɾ��******************************************/
		p0=front;
		p=p0->next;
		while(p->next!=NULL){
			p0=p;
			p=p->next;
		}
		rear=p0;
		free(p);

		t-=1;
		rear->next=NULL;
		people+=t;

	 	//float score[NS];        //NS=8 1-6�ɼ� 0ƽ�� 7�ܷ�

	 	/**
	  	*�д�����
	  	*
	  	*/
	 	if(p->score[6]!=0)
	 			k=6;
	 	else if (p->score[5]!=0)
	 			k=5;
	 	else if (p->score[4]!=0)
	 			k=4;
		else if (p->score[3!=0])
				k=3;
		else if (p->score[2]!=0)
				k=2;
		else if (p->score[1]!=0)
				k=1;
		//�ж� k ��Ŀ����
		//	printf("k========%dpeople=======%dn",k,people);

	 	printf("Successfully load %d records.n�ɹ�����%d����¼n",t,t);

	 	printf("nCurrent number of student is %d.Number of course is %d.n��ǰϵͳѧ������Ϊ%d�ˡ���Ŀ����Ϊ%dnn",people,k,people,k);

		output(front);


	} //choice==2




	return 0;
} /* saveload */


/**
*ɾ������
*@since 1.5.2
@author YouthLin
*
*/
int deleteone(){
	int id,i,ch,g=0;
	pstu p0,p;
	system (CLEAR);
	system ("color 1e");		//1e	��ɫ ����ɫ
	printf ("Home->Delete itemsn��ҳ->����ɾ��nn");
	printf ("Please input the id you want to delete:n������Ҫɾ����ѧ�ţ�n");
	scanf ("%d",&id);

	p0=NULL;
	p=front;
	while (p!=NULL){	//��ѧ��
		if (p->num==id){
			g++;
			printf ("%-10d %-15s ",p->num,p->name);
			for (i=1;i<=k;i++)
				printf ("  %3.0f",p->score[i]);
			printf("n");
		}//�г�
		p0=p;
		p=p->next;	//����
	}
	//û�ҵ�
	if (g==0){
		printf("nCan not find the student!n�Ҳ�����ѧ�ţ�n");
		return 0;
	}

	printf ("Are you sure to delete the above?nȷ��ɾ������ѧ����Ϣ��ntt1.Yestt0���ǵ�ntt0.No.tt0������n");
	scanf ("%d",&ch);
	if (ch!=1){
		printf("Operation has been canceled.Now back to main menu.n������ȡ���������������˵���n");
		return 0;
	}


	p0=front;
	p=p0->next;
	if (p0->num==id){
		front=p;
		people-=1;
		free(p0);
		printf("Delete successful!nɾ���ɹ���nn");
		return 0;
	}//ɾ����ͷ

	while (p->next!=NULL){//�����ڶ���Ϊֹ
		if(p->num==id){
			p=p->next;
			free(p0->next);
			p0->next=p;
			people-=1;
			printf("Delete successful!nɾ���ɹ���nn");
			return 0;
		}
		p0=p;
		p=p->next;
	}
	if (p->next==NULL){//��β
		if(p->num==id){
			rear=p0;
			free(p);
			people-=1;
			rear->next=NULL;	//��β��next��Ϊnull��������
			printf("Delete successful!nɾ���ɹ���nn");
			return 0;
		}
	}



	return 0;
} //delete
