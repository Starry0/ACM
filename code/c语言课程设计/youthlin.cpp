/**
*子函数 功能 1、2、5、8、11
*@author Youthlin  http://youthlin.com/
*@package Student Achievement Management System
*@subpackage youthlin.cpp
*@since main_v1.0.cpp
*/

#define Str "SAMS filenStudent Achievement Management Systemn学生成绩管理系统n"
#define length (sizeof(Str))
/**
*定义入队函数
*参考自教材P335
*
*由 从文件读入和手动录入 调用
*/
int inqueuce(pstu head){
	pstu p;
	int i;
	if ((p=(pstu)malloc(sizeof(stu)))==NULL){
		printf("Memory allocation failure!t内存申请失败！tn");
		return 1;					//失败有返回值。在read（）里用来判断~~~
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
*输出
*输出  调试用
*/
int output(pstu pstu0){
	pstu p,p0;
	p=pstu0;
	p0=NULL;
	if (k==0||front==NULL){
		printf("No available content for output :( t没有可供输出的内容...tn");
		system(P);
		return 0;
	}
	while(p!=NULL){

		int i=0;

		printf("%-10d %-15s t",p->num,p->name);		//输出 学号姓名
		for(i=0;i<NS;i++){
			printf(" %3.0f ",p->score[i]);				//输出 成绩
		}
		printf("n");
		//printf("[Output]n");
	p0=p;
	p=p->next;
	}

	return 0;
}



/**
*功能1--从文件读入
*@Author Youth.Lin
*@since main_v0.1.cpp
*@LastUpDate : 2013-12-25
*最先写的函数，调了最久的。。。
*/
int read(){
	int i,t=0,ch,j,yn,flag;			//i控制循环，t为记录，j接受入队函数返回值，ch为选项 ,flag判断分数是否正常 	k0接受临时k
	struct student stu0;
	struct student * pstu0;
	pstu0=&stu0;
	char f[160];				//文件名
	FILE *fp;					//文件指针
	system(CLEAR);
	printf("Home->Read from filen首页->从文件读入nn");

	//系统中已有记录时
	if (front!=NULL){
		getchar();
		printf("Record already existed,still add record?t已有记录，追加？(1-yes,other-no)n");
		scanf("%d",&yn);		//字符型%c太不好控制了。。。用数字也不错，一直在小键盘敲....
		getchar();
		if(yn !=1)
			return 0;			//不追加，返回至主菜单
	}/* if */

 	//while(1)是为了选择出错后可以continue回来
	while (1){
		j=0;
		system(CLEAR);
		system("color 2f");		//2f 背景绿色	前景亮白色
		/**导航
		*@since 1.5
		*@author YouthLin
		*/
		printf("Home->Read from filen首页->从文件读入nn");
		//提示文件的格式
		printf("You have choose to read infomation from file,nplease ensure your file formot is as follows:n");
		printf("您选择了从文件导入学生信息，请确保您的文件格式如下：n");
		printf("the number of courses in the sample file is 6.t示例文件中科目数默认为6.n");
		printf("(The first line will be ignored.t第一行将被忽略。 n<=6 )nn");
		printf("   学号tt姓名tt高数t科目2t科目3t科目4t...t科目nttn");
		printf("   54131001tliuruitaot80t75t68t86t78t90n");
		printf("   54131002tchenmeilint90t85t78t88t68t95n");
		printf("   ......t......tnn");
		printf("t1. I have read about it.t我知道了nt2. Use sample file.tt使用示例文件nt0. Back to main menu.tt返回主菜单n");
		scanf("%d",&ch);

		if (ch==0)
			return 0;
		//返回主菜单

		/* 用户文件 */
		if (ch==1){

			//当前 队空的话
			if (k==0&&people==0){
				printf("Please input the number of courses:t请输入课程科目数量：n");
				/**
				*科目数与文件不一致会卡死。。。
				*@Update : 2013-12-25
				*/
				printf("Please make sure your input is equal to the file's number of courses!nOR it will be cause unpredictable consequences!!!n");
				printf("请确保您输入的科目数与文件内是一致的！n否则将导致不可预料的后果！！！n");
				/* update */
				scanf("%d",&k);
				if (k<1||k>6){
					k=0;					// 初始化回去
					printf("Input error!tttt输入有误！tn");
					system(P);
					continue;	/* 至whule(1)文件格式提示 */
				}/*检查科目门数*/
			}
			//不空，即已有记录
			else{
				printf("The current numble of courses is %d.ttn当前系统课程为%d科。tn",k,k);
				printf("nTo change the course number, please restart this program.tn要更改当前科目门数请重启本程序。tn");
				printf("nForced to read a file whose number of courses is different with current courses will cause unpredictable consequences.n");
				printf("强行读入与当前系统科目数不一致的文件将导致不可预料的后果！tn");
			}/*if--else*/


			printf("nPlease input your filename:tt请输入文件名：tn");
			scanf("%s",&f);

			if ((fp=fopen(f,"r"))==NULL){
				printf("Error! Can not open file!tt打开文件失败！tn");
				system(P);
				continue;
			}/*打开文件*/

			while(fgetc(fp)!='n');					//略过第一行
			while (!feof(fp)){
				if (fgetc(fp)=='n')continue;		//回车空行直接跳过//continued至上一行while(!feof()) 文件未结束
				else{
					fseek(fp,-2L,1);				//若不是回车空行，也执行了上一条fgetc ，所以要往前拨回一个字符
					fscanf(fp,"%d%s",&stu0.num,&stu0.name);
					for (i=1;i<k+1;i++)
						fscanf(fp,"%f",&stu0.score[i]);		//切记切记浮点型！！！
				}/*if--else*/

				//规范化临时结构体
				stu0.score[0]=0;
				stu0.score[NS-1]=0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						stu0.score[i]=0.0;
				}/*规范化 为入队准备*/


				/**
				*检查分数是否在区间0-100内
				*@Update : 2013-12-25
				*/
				flag=0;
				for (i=1;i<=k;i++){
					if (stu0.score[i]>100||stu0.score[i]<0)
						flag=1;			//分数不正常，flag标志置为1
				}
				if (flag){
					printf("Please check your file and make sure the score is 0-100.n请检查文件并确保分数在0-100内！n");
					fclose(fp);

					return 1;
				} /* 检查分数合法性 */



				/*入队*/
				j=inqueuce(&stu0);
				if (j)
					return 1;		//j由入队函数返回，j=1则失败，return回主菜单
				if (j==0){
					t++;		//t记录数
					continue;
				}//j=0,入队成功，继续。这里continue是对while文件结束
			}/*while文件结束*/

			/*关闭文件*/
			fclose(fp);

			printf("nSuccessfully read %d record.tt成功读入%d条记录。tn",t,t);
			people+=t;		//当前人数更新
			t=0;
			printf("nCurrent number of student is %d .t当前系统学生人数为%d人。tnn",people,people);
			output(front);
			return 0;			//返回主菜单。
		}/*if ch==1 用户文件*/

		/* 示例文件 */
		if (ch==2){
			if ((fp=fopen("sample.dat","r"))==NULL){
				printf("Can not open the sample file!t打开示例文件失败！tn");
				system(P);
				continue;		//继续提示文件格式,continue至while (1)
			}/*打开文件*/

			//printf("k===========%d",k);
			if (!(k==0||k==6)){
				/**
				*判断当前科目数量
				*@Update : 2013-12-25
				*/
				printf("The current numble of courses is %d.ttn当前系统课程为%d科。tn",k,k);
				printf("The number of course in the sample file is 6.t示例文件默认科目数为6科n");
				printf("nForced to read a file whose number of courses is different with current courses will cause unpredictable consequences.n");
				printf("强行读入与当前系统科目数不一致的文件将导致不可预料的后果！tn");
				printf("nPlease back to chose another item.tt请返回重选...n");
				system(P);
				continue;
			}


			k=6;	//示例文件默认科目为6

			while (fgetc(fp)!='n');		//略过第一行

			while (!feof(fp)){
				if (fgetc(fp)=='n')continue;		//回车空行直接跳过
				else{
					fseek(fp,-2L,1);				//若不是回车空行，也执行了上一条fgetc ，所以要往前拨回一个字符

					fscanf(fp,"%d",&pstu0->num);
					fscanf(fp,"%s",pstu0->name);
					for(i=1;i<=6;i++){
						fscanf(fp,"%f",&stu0.score[i]);		//特别要注意，定义时score是浮点型，输入输出score都要用%f
					}

				}/*if--else*/

				stu0.score[0]=0;
				stu0.score[NS-1]=0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						stu0.score[i]=0.0;
				}/* 这不是多此一举，这是宏定义NS的意义所在（目前NS=8）  */

				/*//调试查看输出看是否正确读入
				printf("调试查看%d/ %s/t",stu0.num,pstu0->name);
				for(i=0;i<NS;i++){
					printf("%4.0f",pstu0->score[i]);
				}
				printf("n");
				*/

				j=inqueuce(&stu0);	//入队
				//printf("%d%s%4.0f%4.0fn",front->num,front->name,front->score[1],front->score[2]);

				if (j)
					return 1;		//返回主函数，出错提示信息在inqueuce
				if(j==0){
					t++;
					continue;		//continue至while文件未结束
					//printf("%d   %s  %dn",front->num,front->name,front->score[1]);
				}/*if*/

				//printf("%d   %s  %dn",front->num,front->name,front->score[1]);
			}/*while 文件结束 */

			/*关闭文件*/
			fclose(fp);

			printf("Successfully read %d record.ttt成功读入%d条记录。n",t,t);
			people+=t;		//当前人数更新
			printf("nCurrent number of student is %d .tt当前系统学生人数为%d人。nn",people,people);
			output(front);
			//printf("%dtt%st%dtn",front->num,front->name,front->score[1]);
			//printf("%d   %s  %dn",front->num,front->name,front->score[1]);


			return 0;			//返回主菜单。
		}/*if ch==2 示例文件*/


		else{

			printf("nSelect not correct...ttt选择有误。。。tn");
			/*
			printf("Press any key to continue.tt按任意键继续。tn");
			//_getch();
			getchar();			//getchar是一个很不友好的家伙，改用pause
			getchar();
			*/

			//printf("nD==%dC--%cS--%on",ch,ch,ch);

			ch=0;
			//printf("D==%dC--%cS--%on",ch,ch,ch);

			system(P);
			continue;
		}	//continue回去文件格式提示 while(1)

	}/*while（1）*/
	return 0;
}/*  read()  */


/**
*功能2--手动输入
*@Author Youth.Lin
*@since main_v1.3.cpp
*/
int append(){
	int i,t=0,j,yn,ch,flag;			//i控制循环，t为记录，j接受入队函数返回值
	pstu pstu0;
	pstu0=(pstu)malloc(sizeof(stu));
	system(CLEAR);
	printf("Home->Append record manullyn首页->手工录入nn");

	//系统中已有记录时
	if (front!=NULL){
		getchar();
		printf("Record already existed,still add record?t已有记录，追加？(1-yes,other-no)tn");
		scanf("%d",&yn);
		getchar();

		if(yn !=1)
			return 0;			//不追加，返回至主菜单
	}/* if */

	while(1){
		system(CLEAR);
		system("color 2f");		//2f 背景绿色	前景亮白色
		printf("Home->Append record manullyn首页->手工录入nn");

		printf("Tips:You can Batch Import student information via read from filen小提示：您可以选择从文件批量导入学生信息哦nn");
		printf("t1.Continue to append record manuallyt1、继续手工导入n");
		printf("t0.Go back to main menu.ttt0、返回至主菜单n");
		printf("nPlease input your choice:t键入您的选择：n");
		scanf("%d",&ch);

		if (ch==0)
			return 0;
		else if (ch==1){
			if (k==0){
				printf("Please input the number of courses:tt请输入课程科目数量：n");
				printf("The number of courses CAN NOT be modified.t课程科目数量将『不能』再修改！n");
				scanf("%d",&k);
				if (k<1||k>6){
					k=0;

					printf("Input error!ttttt输入有误！tn");
					system(P);
					continue;		//至while 1 小菜单
				} /* 检查输入 */
			}/* k==0 */

			/* k!=0 */
			printf("The current numble of courses is %d.ttn当前系统课程为%d科。tn",k,k);
			printf("nTo change the course number, please restart this program.tn要更改当前科目门数请重启本程序。tnn");

			printf("Pease input Student ID:t请输入学号：n");
			scanf("%d",&(pstu0->num));
			//system(P);
			printf("Please input name:t请输入学生姓名：n");
			scanf("%s",pstu0->name);
			printf("Please input %d scores:t请输入%d门成绩n",k,k);
			for (i=1;i<=k;i++)
				scanf("%f",&(pstu0->score[i]));
			getchar();
			/* 回显确认 */
			printf("nIs it right?t确认一下：nn");
			printf("%d %s ",pstu0->num,pstu0->name);
			for (i=1;i<=k;i++)
				printf("%4.0f ",pstu0->score[i]);
			printf("n");
			/* 回显确认 */
			printf("n:) Yes,it's right.(input 1)ttt没错（输入1）n");
			printf(":( No I want to Re-enter.(input any other)t不对，重新输入（输入其他数）nn");
			scanf("%d",&yn);
			if (yn==1){
				/**
				*检查分数是否在区间0-100内
				*@Update : 2013-12-25
				*/
				flag=0;
				for (i=1;i<=k;i++){
					if (pstu0->score[i]>100||pstu0->score[i]<0)
						flag=1;			//分数不正常，flag标志置为1
				}
				if (flag){

					printf("Please check your input and make sure the score is 0-100.n请检查输入并确保分数在0-100内！n");
					system(P);
					continue;	//至小菜单
				} /* 检查分数合法性 */

				pstu0->score[0]=0.0;
				pstu0->score[NS-1]=0.0;
				if (k<NS-2){
					for (i=NS-2;i>k;i--)
						pstu0->score[i]=0.0;
				}/*规范化 为入队准备*/

				j=inqueuce(pstu0);
				if (j)
					return 1;		//j由入队函数返回，j=1则失败，return回主菜单
				if (j==0){
					t++;		//t记录数
				}//j=0,入队成功，
			}/* 回显确认没错 */
			else
				continue;
			/* 有错 *//////continue至小菜单

		 	printf("nSuccessfully read %d record.tt成功读入%d条记录。tn",t,t);
			people+=t;		//当前人数更新
			printf("Current number of student is %d .t当前系统学生人数为%d人。tn",people,people);

			printf("nContinue to append record?tt继续输入吗？n(1--yestother--no)n");
			scanf("%d",&yn);
			if (yn==1){
				t=0;	//@Update : 2013-12-27 不重置t会导致全局变量people有错
				continue;
			}

			else{
     //               output(front);
				return 0;
			}
			/* 继续否 */
		}/* ch==1 */
		else{
			printf("Select not correct...ttt选择有误。。。tn");
			system(P);
			continue;
		} /* 小菜单选择错误 */

	}/* while(1) */

	return 0;
}/* append() */

/*
*功能5--按总分从高至低排序
*方法：主元排序|选择排序
*主元排序：教材 p138-139
*需要交换链表中两项：教材p330
*@Date : 2013-12-24
*/

/**
*功能5--按总分从高至低排序
*方法：冒泡排序
*@Old 旧方法 主元排序:失败...
*需要交换链表中两项：教材p330
*@Date : 2013-12-26
*/

/**
*功能5--按总分从高至低排序
*方法 : 插入排序
*参考 ：教材P336-338
*原版例子！
*@Date : 2013-12-26
*/
pstu sort_by_total_des(pstu head,int j){
	pstu p,p0,r,r0,q;
	cal_every_stu(head,1);
	p0=NULL;
	p=head;
	if (!j){//j=0，主函数调用以排序，输出当前位置
		printf("Home->Sort in descending order by total score of every studentn首页->按每个学生总分由高到低排序nn");
	}//j!=0 不输出

	if (p==NULL){
		printf("Nothing can be sortedn没有可供排序的内容n");
		return head;
	}

	while(p!=NULL){/* 逐项处理，把p加入到子序列中，并保持base--p排好序 */
		/* 寻找q要插入的位置 r0,r */
		r=head;

		while((r->score[7]>p->score[7])&&(r!=p)){
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


	return head;
} /* 排列 */


/**
*功能11--等级统计
*@Author Youth.Lin
*@草稿 : 2013-12-24
*@Date : 2013-12-25 22:24完工!
*/
int statistic (pstu head){
	system(CLEAR);
	system("color 4e");		//4e	背景红色	文字淡黄色
	pstu p0=NULL,p;
	int i,grade[7][5]={{0},{0},{0},{0}};        //grade[i][0-4]表示i科优秀-不及格
	float temp;
	char filename[160];
	FILE * fp;

	/**
	*新增 获取当前时间
	*@Date 2013-12-29 16:10
	*@link http://zhidao.baidu.com/link?url=o3Xma9gGC1DgrpVW_5sv9s2CqAeHElWEObJXtR3LR_jjqspsBAc5bEkCGLRBk5zOOdJk3Tcu3XNelQAIQiaOTq
	*用于输出至文件
	*/
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );



	printf("Home->Statistic analysis for every coursen首页->按等级统计考试成绩nn");
	if (front==NULL){
		printf("Er...statistic what?t你先输入会屎啊？n");
		return 0;
	} /* 队空 */
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
                printf("Error!the achievement can NOT be <0 or >100t出错了!分数不能小于0或大于100!n");
                return 1;
            }
        }/* for */
        p0=p;
        p=p->next;
	}/* while */
	/* 统计完成 */

	/* 输出至屏幕 */
	printf("      ║优秀  优秀率  良好  良好率  中等  中等率  及格  及格率  不及格  不及格率n");
	printf("═══╬════════════════════════════════════n");
	for(i=1;i<=k;i++){
        printf("科目 %d║%3d  %6.2f%%  %3d  %6.2f%%  %3d  %6.2f%%   %3d  %6.2f%%   %3d   %6.2f%%n",i,grade[i][0],grade[i][0]*100.0/people,grade[i][1],grade[i][1]*100.0/people,grade[i][2],grade[i][2]*100.0/people,grade[i][3],grade[i][3]*100.0/people,grade[i][4],grade[i][4]*100.0/people);
        //输出k门科目 5 个等级
	}
	while(1){
        printf("nPlease input a filename to save the statistic result:n请输入文件名以保存以上统计信息：n");
        printf("(Will create a file,if file already exist the result will be write to the end of the file.将会创建这个文件，如果文件已经存在则从文件尾写入。)n");
        scanf("%s",filename);
        if ((fp=fopen(filename,"a"))==NULL){
            printf("Can not creat the file!t创建文件失败！n");
            continue;
        }/* 打开文件 */
        //fprintf(fp,"////////////////////////////////////////////////////////////////////////////////n");
        //fprintf(fp,"//The fallows are statistical results of Student Achievement Management System//n");
        //fprintf(fp,"//Copyright (c)2013 Software College of Jilin University Grade 2013 Class 10////n//By Chen Meilin,Zhang xiaoquan,Liu ruitao//////////////////////////////////////n");
        //fprintf(fp,"////////////////////////////////////////////////////////////////////////////////");
        fprintf(fp,"n      ║优秀  优秀率  良好  良好率  中等  中等率  及格  及格率  不及格  不及格率n");
        fprintf(fp,"═══╬════════════════════════════════════n");
        for(i=1;i<=k;i++){
            fprintf(fp,"科目 %d║%3d  %6.2f%%  %3d  %6.2f%%  %3d  %6.2f%%   %3d  %6.2f%%   %3d   %6.2f%%n",i,grade[i][0],grade[i][0]*100.0/people,grade[i][1],grade[i][1]*100.0/people,grade[i][2],grade[i][2]*100.0/people,grade[i][3],grade[i][3]*100.0/people,grade[i][4],grade[i][4]*100.0/people);
        //输出k门科目 5 个等级
        }
        fprintf (fp,"nSaved in: %4d-%02d-%02d %02d:%02d:%02dtttt",1900+timeinfo->tm_year, 1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);
        fprintf (fp,"%s", asctime (timeinfo) );
		fprintf(fp,"nn");


        fclose(fp);//关闭文件
        printf("Write to file successful!t写入文件成功!n");

        return 0;
	}/* while (1) */
	return 0;
}/* 统计 */

/**
*功能8-- 按姓名字典顺序排出成绩表
*
*/
pstu sort_by_name(pstu head){
	pstu p,p0,r,r0,q;
	//cal_every_stu(head,1);
	p0=NULL;
	p=head;
	system(CLEAR);
	printf("Home->Sort in ascending order by namen首页->按姓名的字典顺序排出成绩表nn");
	while(p!=NULL){/* 逐项处理，把p加入到子序列中，并保持base--p排好序 */
		/* 寻找q要插入的位置 r0,r */
		r=head;

		while((strcmp(r->name,p->name)<0)&&(r!=p)){
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
*存档读档
*@since 1.5
*@author YouthLin
*/
int saveload(pstu head){
	int choice,ch,t=0,j,i;
	FILE * fp;
	pstu p,p0,p1;
	char st[]=Str;
	system(CLEAR);
	system("color e4");		//e4	背景淡黄色	文字红色
	printf("Home->Save/Loadn首页->存档读档nn");
	printf("What would you want to do:tt您想要：nn");

	printf("tt1.Savett1、存档n");
	printf("tt2.Loadtt2、读档n");
	printf("tt0.Backtt0、返回n");
	scanf("%d",&choice);
	if (choice==0){
		return 0;
	}
	else if (choice==1){
		printf ("Will cover the latest saved file.n将会覆盖最近一次存档。nnt1.I know,continue.t1、好的，继续。nt0.Oh no,Back.tt0、不要了，返回。n");
		scanf ("%d",&i);

		if (i!=1){
			printf("You have to cancel the operation.Now back to main menu.n您已取消操作，返回至主菜单。n");
			return 0;
		}//返回

		if (front==NULL){
			printf("Needn't to save,there are nothing in the system.n不需存档，系统内无任何信息。n");
			return 0;
		}
		if ((fp=fopen("save.sams","wb"))==NULL){
			printf("ERROR!Can not create file to save!n错误！不能创建存档文件！n");
			return 1;
		}/** 创建文件 */

		//文件头
		fwrite(st,length,1,fp);
		p=head;
		while (p!=NULL){

			fwrite(p,sizeof(stu),1,fp);
			p=p->next;
		}/** while */
		fclose(fp);
	 	printf("Successfully save to save.samst成功创建存档save.sams n");
	 	return 0;
	}/*choice==1*/

	else if (choice==2){
		p=(pstu)malloc(sizeof(stu));
		if((fp=fopen("save.sams","rb"))==NULL){
				printf("ERROR,Can not find or open file save.sams n错误！找不到或不能打开存档save.sams n");

				return 1;
		}
		//printf("5555555555555555555555555555555555555555555555555555");
		if (front!=NULL){
			printf("Record already existed,You want:t已有记录，请选择：n");
			printf("t(1. )Addtt(2. )Coveragett(0. )Backn");
			printf("t(1、)新增tt(2、)覆盖tt(0、)返回n");
			scanf("%d",&ch);
			if (ch!=1&&ch!=2){
				return 0;
			}//返回

			if (ch==2){
				p0=front;
				p1=p0->next;
				while (p1->next!=NULL){		//还需删除原有链表
					free(p0);
					p0=p;
					p1=p1->next;
				}//删除

				front=NULL;
				/**
				*@Update : 2013-12-29
				*
				*需要重置队尾，因为
				*@see inqueuce
				*入队函数 需要判断rear是否为null
				*
				*/
				rear=NULL;

				people=0;
			} //覆盖
		}//已有记录

		//printf("5555555555555555555555555555555555555555555555555555");
		fread(st,length,1,fp);	//读入文件头

		while(!feof(fp)){

			fread(p,sizeof(stu),1,fp);

			p->next=NULL;

			//printf("%d;%s;n%f/%f/%f;n%onn",p->num,p->name,p->score[0],p->score[1],p->score[3],p->next);

			j=inqueuce(p);
			if (j)
				return 1;		//j由入队函数返回，j=1则失败，return回主菜单
			if (j==0){
				t++;
			}//j=0,入队成功，

		}//文件结束

		fclose(fp);
		/********************************  "研究发现" 会多读一项  为甚么呢 把最后一项删除******************************************/
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

	 	//float score[NS];        //NS=8 1-6成绩 0平均 7总分

	 	/**
	  	*有待完善
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
		//判断 k 科目数量
		//	printf("k========%dpeople=======%dn",k,people);

	 	printf("Successfully load %d records.n成功载入%d条记录n",t,t);

	 	printf("nCurrent number of student is %d.Number of course is %d.n当前系统学生人数为%d人。科目数量为%dnn",people,k,people,k);

		output(front);


	} //choice==2




	return 0;
} /* saveload */


/**
*删除功能
*@since 1.5.2
@author YouthLin
*
*/
int deleteone(){
	int id,i,ch,g=0;
	pstu p0,p;
	system (CLEAR);
	system ("color 1e");		//1e	蓝色 淡黄色
	printf ("Home->Delete itemsn首页->单项删除nn");
	printf ("Please input the id you want to delete:n请输入要删除的学号：n");
	scanf ("%d",&id);

	p0=NULL;
	p=front;
	while (p!=NULL){	//找学号
		if (p->num==id){
			g++;
			printf ("%-10d %-15s ",p->num,p->name);
			for (i=1;i<=k;i++)
				printf ("  %3.0f",p->score[i]);
			printf("n");
		}//列出
		p0=p;
		p=p->next;	//遍历
	}
	//没找到
	if (g==0){
		printf("nCan not find the student!n找不到该学号！n");
		return 0;
	}

	printf ("Are you sure to delete the above?n确定删除以上学生信息吗？ntt1.Yestt0、是的ntt0.No.tt0、不了n");
	scanf ("%d",&ch);
	if (ch!=1){
		printf("Operation has been canceled.Now back to main menu.n操作已取消，即将返回主菜单。n");
		return 0;
	}


	p0=front;
	p=p0->next;
	if (p0->num==id){
		front=p;
		people-=1;
		free(p0);
		printf("Delete successful!n删除成功！nn");
		return 0;
	}//删除链头

	while (p->next!=NULL){//倒数第二项为止
		if(p->num==id){
			p=p->next;
			free(p0->next);
			p0->next=p;
			people-=1;
			printf("Delete successful!n删除成功！nn");
			return 0;
		}
		p0=p;
		p=p->next;
	}
	if (p->next==NULL){//链尾
		if(p->num==id){
			rear=p0;
			free(p);
			people-=1;
			rear->next=NULL;	//链尾的next变为null！！！！
			printf("Delete successful!n删除成功！nn");
			return 0;
		}
	}



	return 0;
} //delete
