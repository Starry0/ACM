/**http://youthlin.com
*子函数 功能 4、6、10、13
*@author zxq
*@package Student Achievement Management System
*@subpackage zxq.cpp
*@since main_v1.4.cpp
*/


/**
*功能4--计算每个学生的总成绩和平均成绩
*@Date 2013-12-24
@Author 张孝全
*/
int cal_every_stu(pstu head,int j){
                 	//如果j=1则是其他子函数调用,不输出
    system("color 0f");     	//0f    背景黑色   文字亮白色
	pstu p0,p;
	p0=NULL;
	p=head;

	if(p==NULL){
		printf("Home->Calculate total and average score of every studentn首页->计算学生的总分和平均分nn");
		printf("No content to calculate.t没有可供计算的东东.n");
        return 0;
	}
	while(p!=NULL){
        //若少于6科,其它是0
		p->score[7]=p->score[1]+p->score[2]+p->score[3]+p->score[4]+p->score[5]+p->score[6];
		p->score[0]=p->score[7]/k;
		p0=p;
		p=p->next;
	}
	if (j!=1){
		printf("Home->Calculate total and average score of every studentn首页->计算学生的总分和平均分nn");
		printf("学号Idtt姓名Namettt总分Totalt平均分Averagenn");
		p=head;
		while(p!=NULL){
      	  //float score[NS];        //NS=8 1-6成绩 0平均 7总分
       	 printf("%-10dt%-15s  tt%5.0ftt%5.2fn",p->num,p->name,p->score[7],p->score[0]);
       	 p=p->next;
		}/* while */
		printf("n");
	}/** 输出 */
	return 0;
}/** 计算每个学生的总成绩和平均成绩 */

/**
*功能13--将每个学生个人信息和成绩写入文件
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

    printf("Home->Write to a filen首页->保存至文件nn");
    if (p==NULL){
        printf("There are nothing need to write to a file.n没有内容写入文件啦~~n");
        return 0;
    }
    printf("Please input file name:t输入文件名:n");
    scanf("%s",filename);
    if((fp=(fopen(filename,"a")))==NULL){
        printf("Can not open file!! :( t打开文件失败!!n");

    }
    cal_every_stu(head,1);      //计算总分平均分

    fprintf(fp,"学号Idtt姓名Namet");
    for(i=1;i<=k;i++)
        fprintf(fp,"%4d ",i,i);
    fprintf(fp,"平均Ave 总分Totnn");
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

    printf("successfully write to file :) t成功写入文件n");

    ifsave=1;   //已保存

    return 0;
}/**写入文件*/


/**
*功能6--按总分从低到高排序
*方法 : 插入排序
*参考 ：教材P336-338
*原版例子！
*@Author 	：张孝全
*@Date 		: 2013-12-26
*@Update 	: 22:20
*改进		：逆序、正序都用这个！
*i=1从高到低	i=0从低到高 (v1.4.2 弃用)
*/
qstu sort_by_total_asc(qstu head,int j){
	pstu p,p0,r,r0,q;
	cal_every_stu(head,1);
	p0=NULL;
	p=head;
	if (!j){
		printf("Home->Sort in ascending order by total score of every studentn首页->按每个学生的总分由低到高排出名次表nn");
	}
	if (p==NULL){
		printf("Nothing can be sortedn没有可供排序的内容n");
		return head;
	}
	while(p!=NULL){/* 逐项处理，把p加入到子序列中，并保持base--p排好序 */
		/* 寻找q要插入的位置 r0,r */
		r=head;

		while((r->score[7]<p->score[7])&&(r!=p)){
				r0=r;
				r=r->next;
		}

		/* p插入到r0,r之间 */
		if (r!=p){		/* 若r==p，在链尾，则不用插入 */
			/* 把p独立出来，令q指向它 */
			q=p;
			p0->next=p->next;
			p=p0;
			/* 插入 */
			if (r==head){	/* 插在链首 */
				q->next=head;
				head=q;
			}else{			/* 插在r0,r之间 */
				q->next=r;
				r0->next=q;
			}/* if--else */
		}/* if */
		/* 前进 */
		p0=p;
		p=p->next;
	}/* while */


//	output(head);
	return head;
} /* 排列 */


/**
*功能10--按照姓名查找学生的成绩
*
*/
int search_by_name(pstu head){
	int i=0,flag=1,ii;
	int gole=0;
	char name0[NL];
	pstu p=head;
	system(CLEAR);
	printf("Home->Search by namen首页->按姓名查询学生排名及其考试成绩nn");
	if (head==NULL){
		printf("There are nothing.t什么都没有.n");
		return 0;
	}
	//还需调用排名函数！:@Update : 2013-12-26 OK
	//p=sort_by_total_des(head);
	//p=front;

	 /**
	 *@UPdate : 2013-12-27
	 *不在此函数内部调用排名函数sort_by_total_des，而在调用此函数之前调用
	 */


   	printf("please input a name:n");
	scanf("%s",name0);
while(flag){
	system(CLEAR);
	printf("Home->Search by name->Resultsn首页->按姓名查询学生排名及其考试成绩->结果nn");
	printf("学号Id      姓名Namet   总分Total   排名Rank  ");
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
 		printf("没有您要找的信息！请重新输入(输入EXIT退出查询)n");

 		scanf("%s",name0);
 		if(strcmp(name0,"EXIT")==0)
 			flag=0;
			p=head;	//拨回指针 （@Update : 2013-12-27 @By :　Ｙｏｕｔｈ．Ｌｉｎ）
			i=0;
	}
	else
		return 0;
} /*  while */
 	return 0;
}
