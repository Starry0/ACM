/**http://youthlin.com/
*子函数 功能 3、7、9、12
*@author lrt
*@package Student Achievement Management System
*@subpackage lrt.cpp
*@since main_v1.4.1.cpp
*/

/**
*功能3--计算每门课程的总分和平均分
*@Date :  2013-12-26 01:31
*By : Youthlin
*/
int cal_every_cou(pstu head){
    system(CLEAR);
    system("color 0f");     //0f 背景黑色   文字亮白色
    pstu p;
    p=head;
    int i;
    /** 导航 */
	printf("Home->Calculate total and average score of every coursen首页->计算每门课程的总分和平均分nn");
    if (p==NULL){
        printf("No content to calculate...t没有可供计算的东东...n");
        //system(P);
        return 0;
    }/* 队空 */

    while(p!=NULL){
            //计算总分
            for(i=1;i<=k;i++){
            	course[i][0]+=p->score[i];  //第i门课
            }/* 总分 */
            p=p->next;
    }/* while */

    //计算平均分
    for(i=1;i<=k;i++){
        course[i][1]=course[i][0]/people;
    }/* for 平均分 */

    /**course[7][2] 1-6保存6门科目的	0总分	1平均分*/

    /** 输出 */
    for(i=1;i<=k;i++)
        printf("t科目%d",i);
    printf("n总分:t");
    for(i=1;i<=k;i++)
        printf("%5.0ft",course[i][0]);
    printf("n平均:t");
    for(i=1;i<=k;i++)
        printf("%5.2ft",course[i][1]);
    printf("nn");


    return 0;
}/* 计算每门课程总分和平均分 */

/**
*功能12--输出每个学生的学号,姓名,各科成绩,总分,和平均分
*@Date 2013-12-26 02:09
*By : Youthlin
*/
int list(pstu head,int j){
    int ch,i,t;
    if (!j){
    	printf("Home->List recordn首页->输出成绩表nn");
    }
    pstu p=head;
    if (p==NULL){
        printf("No content to list...t没有给你看的内容额...n");
        return 0;
    }//队空
    cal_every_stu(head,1);      //计算总分平均分

    printf("学号Idtt姓名Namet");
    for(i=1;i<=k;i++)
        printf("%4d ",i);
    printf("平均Ave 总分Totnn");
    while(p!=NULL){
        printf("%-10d %-15s t",p->num,p->name);
        for(i=1;i<=k;i++)
            printf("%4.0f ",p->score[i]);
        printf("t%5.2ft%5.0fn",p->score[0],p->score[7]);
        p=p->next;
    }/* while */
    printf("n");

    /**
	*新增筛选
	*筛选出优秀，不及格
	*@since 1.6
	*@date 2013-12-29 22:24
	*@author YouthLin
	**/
	if (!j){
		t=0;
		printf ("tttYou can also:tt你还可以:n");
		printf ("t1.Screening excellent list.ttt1、筛选优秀名单n");
		printf ("t2.Screening good list.tttt2、筛选良好名单n");
		printf ("t3.Screening Medium list.ttt3、筛选优秀名单n");
		printf ("t4.Screening Pass list.tttt4、筛选及格名单n");
		printf ("t5.Screening failing list.ttt5、筛选不及格名单n");
		printf ("t0.Back.tttttt0、返回nn");
		scanf("%d",&ch);
		if (ch!=1&&ch!=2&&ch!=3&&ch!=4&&ch!=5){
			return 0;
		}

		p=head;
		printf("n学号Idtt姓名Namet");
		for(i=1;i<=k;i++)
   			printf("%4d ",i);
   		printf("平均Ave 总分Totnn");	//打印表头

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
				printf("Not find...ttt没找到相关信息...n");
			}

			return 0;
		}//优秀
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
				printf("Not find...ttt没找到相关信息...n");
			}
			return 0;
		}// 良好
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
				printf("Not find...ttt没找到相关信息...n");
			}
			return 0;
		}//中等
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
				printf("Not find...ttt没找到相关信息...n");
			}
			return 0;
		} //及格
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
				printf("Not find...ttt没找到相关信息...n");
			}
			return 0;
		} //不及格

	} //筛选

    return 0;
}/* list输出 */

/**
*功能7--按学号从小到大排出成绩表
*@Author ： 刘瑞涛
*@Date	:	2013-12-26
*交换数据
*
*/
int sort_by_num(pstu head){
	pstu p,q;
	int bnum,l,i;
	char bname[NL];
	float bscore[NS];
	system(CLEAR);
	printf("Home->Sort in ascending order by numbern首页->按学号由小到大排出成绩表nn");
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
*功能9--按照学号查找学生的成绩
*@Date : 2013-12-27
*/
int search_by_num(pstu head){
	int i=0,flag=1,gole=0,id,ii;
	pstu p=head;
	system(CLEAR);
	printf("Home->Search by numblen首页->按学号查询学生排名及其考试成绩nn");
	if (head==NULL){
		printf("There are nothing.t什么都没有.n");
		return 0;
	}
   	printf("please input the student id:n");
	//scanf("%d",id);
	scanf("%d",&id);
while(flag){
	system(CLEAR);
	printf("Home->Search by numble->Resultsn首页->按学号查询学生排名及其考试成绩->结果nn");
	printf("学号Id     姓名Namet   总分Total   排名Rank  ");
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

 		printf("没有您要找的信息！请重新输入(输入-1退出查询)n");
 		scanf("%d",&id);
 		getchar();
 		if(id==-1)
 			flag=0;
		//printf("%d[调试]n",id);
	 	p=head;
	 	i=0;
 	}
 	else
		return 0;
} /* while */

 	return 0;
}
