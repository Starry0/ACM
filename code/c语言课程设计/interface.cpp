/**
*界面
*@pakage : SAMS
*@subpackage : interface
*@Author : Youth.Lin
* http://youthlin.com/
*包括欢迎界面、主菜单界面、关于、反馈等非功能项界面
*
*/

/**   输出提示音   */
void a(void){
	printf("a");
	/**
	*@Date : 2013-12-27 21:26
	*@Author : Youth.Lin
	*
	*/
}

/**...欢迎...*/
void welcome(){
	int i;
	system("color 0e");		//0e 黑背景  淡黄色前景
	system(CLEAR);
	printf("*******************************************************************************nn");
	printf("***************tt欢迎使用学生成绩管理系统！tt***************nn");
	printf("*******************************************************************************nn");
	printf("***************tt陈美霖   张孝全   刘瑞涛tt***************nn");
	printf("*******************************************************************************nn");
	printf("nnStrongly recommended that you read the help instructions first in the main menun强烈建议使用前先阅读菜单内的帮助说明！！nn");
	printf("Loading...tt");
	for (i=0;i<101;i+=1){
		printf("%3d%%bbbb",i);
		Sleep(50);
	}
	printf("nLoading is complete....");
	for (i=0;i<5;i++){
		printf(".a");
		Sleep(500);
	}

	printf("n");
}/** welcome */


/** 菜单 */
void menu(){
	system(CLEAR);
	system("color 0a");			//0a 黑背景  淡绿色前景
	printf("tttStudent Achievement Management Systemntttt学生成绩管理系统nn");
	printf(" ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓n");
	printf(" ┃ttPlease slect.ttt请选择ttt     ┃n");
	printf(" ┃    ttttttttt     ┃n");

	printf(" ┃1. Read from a file .tt   1、从文件读入tt     ┃n");							/////cml
	printf(" ┃2. Append record manully .tt   2、手工录入ttt     ┃n");						/////cml
	printf(" ┃3. Calculate total and averaget   3、计算每门课程的tt     ┃n");					/////lrt
	printf(" ┃   score of every course . tt      总分和平均分tt     ┃n");
	printf(" ┃4. Calculate total and averaget   4、计算每个学生的tt     ┃n");					/////zxq
	printf(" ┃   score of every student . tt      总分和平均分tt     ┃n");
	printf(" ┃5. Sort in descending order byt   5、按每个学生的总tt     ┃n");					/////cml
	printf(" ┃   total score of every student . t      分由高到低排出名次表t     ┃n");
	printf(" ┃6. Sort in ascending order byt   6、按每个学生的总tt     ┃n");					/////zxq
	printf(" ┃   total score of every student . t      分由低到高排出名次表t     ┃n");
	printf(" ┃7. Sort in ascending order by num.t   7、按学号由小到大排出成绩表t     ┃n");		/////lrt
	printf(" ┃8. Sort in ascending order by name.t   8、按姓名的字典顺序排出成绩表     ┃n");	/////cml
	printf(" ┃9. Search  by numble.tt   9、按学号查询学生排名及其考试成绩 ┃n");				/////lrt
	printf(" ┃10. Search  by name.ttt   10、按姓名查询学生排名及其考试成绩┃n");				/////zxq
	printf(" ┃11. Statistic analysis for every course 11、按等级统计考试成绩t     ┃n");			/////cml
	printf(" ┃12. List record. ttt   12、输出成绩表tt     ┃n");								/////lrt
	printf(" ┃13. Write to a file. tt   13、保存至文件tt     ┃n");							/////zxq

	printf(" ┃14. Save/Load. ttt   14、读档/存档tt     ┃n");
	printf(" ┃15. Delete items. ttt   15、单项删除ttt     ┃n");
	printf(" ┃16. Help. tttt   16、帮助ttt     ┃n");
	printf(" ┃17. About. tttt   17、关于ttt     ┃n");
	printf(" ┃0. Exit .tttt    0、退出ttt     ┃n");

	printf(" ┃tPlease input your choice.t     键入您的选择:tt     ┃n");
	printf(" ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛n");


}/* main menu */


//http://youthlin.com/



/** ***Help 帮助*** */
int help(){
	system(CLEAR);
	system("color 1e");		//1e	蓝色背景		淡黄色文字
	printf("Home->Helpn首页->帮助nn");
	printf("*******************************************************************************n");
	printf("*0.Operation tips  tttttt      操作提示*n");
	printf("*******************************************************************************n");
	printf("**程序输入大部分是菜单选择，请按提示输入相应《数字》,输入其它字符可能导致错误**nn");
	printf("** program input is mostly to choose the menu.please follow the prompts to **n");
	printf("**enter the appropriate number, enter other characters may cause errors**nn");

	printf("*******************************************************************************n");
	printf("*1.About read from filetttttt关于从文件读入*n");
	printf("*******************************************************************************n");

	printf("***请勿修改示例文件的《任何》内容 ，否则可能导致程序死机或其它不可预料的错误***nn");
	printf("***Do not modify the sample file any content, or it may cause the program ***n");
	printf("** tttto crash or other unexpected errortt    ***nn");

	printf("*若您使用自己的文件,请确保文件中每行一条信息,而且文件中科目数量与您输入的一致**nn");
	printf("** If you use your own file, make sure the file is only one record per line, **n");
	printf("* t and the file number of subjects is consistent with your input.t     **nn");

	printf("*科目的数量《要求》不超过6科,文件第一行可以是表头指示信息 ,不会读入第一行内容**nn");
	printf("*Number of subjects request not more than six subjects, the first line of  **n");
	printf("*the file header can be instructions, the program does not read the first line*nn");

	printf("*并且文件末尾《不是》空行，意味着文件是以最后一个分数结尾的，而 *不是* 回车符**nn");
	printf("** And at the end of file is not blank  , means that the file ends with  a **n");
	printf("**   ttstudent's score, rather than a carriage returntt     **nn");

	printf("***任何试图读入不符合规范的文件的操作的后果都是不可预料的，后果由用户自己承当**nn");
	printf("**Any attempt to Read Non-compliant files，the consequences are unpredictable**n");
	printf("** ttBy the users themselves bear the consequences.tt     **n");

	printf("*******************************************************************************n");



	//getchar();
	return 0;

}/** Help */



/**...关于...*/
int about(){
	system(CLEAR);
	system("color b0");
	printf("Home->Aboutn首页->关于nn");
	printf("tttt关于我们tn");
	printf("n本程序由吉林大学软件学院2013级10班陈美霖、张孝全、刘瑞涛合作完成。nn");
	printf("本作品采用nt“知识共享署名-非商业使用-相同方式共享 4.0 国际许可协议”nt (CC BY-NC-SA 4.0)n进行许可。n");
	printf("n您可以nt复制、发行、展览、表演、放映、广播或通过信息网络传播本作品；tn");
	printf("t自由复制、散布、展示及演出本作品；tn");
	printf("n唯需遵守：n");
	printf("t署名tt您必须按照作者或者许可人指定的方式对作品进行署名;n");
	printf("t非商业使用t您不得为商业目的而使用本作品;tn");
	printf("t相同方式共享t若您改变转变或更改本作品，仅在遵守tn");
	printf("ttt与本作品相同的授权条款下，您才能散布本作品的派生作品。n");
	printf("n要查看该许可协议，可访问nthttp://creativecommons.org/licenses/by-nc-sa/4.0/deed.zhnn");
	printf("ttttAbout ustn");
	printf("nThis program is wrriten by Software College of Jilin University Grade 2013 n");
	printf("Class 10 Chen Meilin,Zhang xiaoquan,Liu ruitaonn");
	printf("This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License(CC BY-NC-SA 4.0).nn");
	printf("nTo view a copy of this license,visitnthttp://creativecommons.org/licenses/by-nc-sa/4.0/nnn");
	printf("You are free to ntShare--copy and redistribute the material in any medium or format. n");
	printf("tAdapt--remix transform,and buid upon the material. n");
	printf("The licensor can't revoke these freedoms as long as you follow the license terms. n");
	printf("Under the following terms: n");
	printf("tAttribution  -- You must give appropriate credit provide a linkn");
	printf("tttto the license,and indicate if changes were made.n");
	printf("tttYou may do so in any reasonable manner,but not in any.n");
	printf("tttway that suggest the licenseor endless you or your use.n");
	printf("tNonCommercial-- You may not use the material for commercial purposes.n");
	printf("tShareAlike   -- If you remix,transform ,or buid upon the material ,ntttyou must distribute your contributions under the same ntttlicense as the same original.n");
	//system(P);

	return 0;
}/**about*/

/**。。。反馈。。。*/
int feedback(){
	system(CLEAR);
	printf("Thank you for use this program!tt感谢使用本程序！tn");
	printf("If you have any comments or tt如果您有任何意见或建议，tn");
	printf("suggestions,please give us feedback.t欢迎给我们反馈tn");
	printf("Yon can email to:ttt您可以发送电子邮件至：tn");
	printf("ntt chenml5513@mails.jlu.edu.cnnntt zhangxq5513@mails.jlu.edu.cnnntt liurt5513@mails.jlu.edu.cnnnnn");
	return 0;
}/*feedback*/

/**  退出  */
int quit(){
	int yn,i;
	system(CLEAR);
	system("color e1");			//e1	背景淡黄色	文字黑色
	printf("Home->Quitn首页->退出nn");
	if(front==NULL){
		printf("You haven't even stated using this program,are you sure to exit?n您还未使用本程序，确定退出？n(1--yes other--no)n");
		scanf("%d",&yn);
		if(yn==1){
			feedback();
			printf("The system will exit in");
			for(i=9;i>=0;i--){
				printf(" %d second!t系统将在%d秒后退出！bbbbbbbbbbbbbbbbbb",i,i);
				Sleep(1000);
			}
			//system(P);
			a();
			system(CLEAR);
			system("color");
			exit(0);
		}
		else
			return 0;
	}/*if队空*/
	else{
		if(ifsave==0){
			printf("You haven't save to file,Are you sure to exit?t您还未保存，真的要退出吗？tn(1--yestother--no)n");
			scanf("%d",&yn);
			if (yn!=1)
				return 0;
		}
		else{
			printf("Are you sure to exit!?t真的要退出吗？n(1--yes other--no)n");
			getchar();
			scanf("%d",&yn);
			//printf("%d",yn);
			if(yn==1){
				feedback();
				/*@since v1.1	当时不能用
				*@update : 2013-12-26	已经支持暂停了
				*/
				printf("The system will exit in");
				for(i=9;i>=0;i--){
					printf(" %d second!t系统将在%d秒后退出！bbbbbbbbbbbbbbbbbb",i,i);
					Sleep(1000);
				}
				//system(P);
				a();
				system(CLEAR);
				system("color");
				exit(0);
			}
			else{
				//system(P);
				return 0;
			}/*if-确定退出-else*/
		}/*保存*/

		feedback();
		printf("The system will exit in");
		for(i=9;i>=0;i--){
			printf(" %d second!t系统将在%d秒后退出！bbbbbbbbbbbbbbbbbb",i,i);
			Sleep(1000);
		}
		//system(P);
		a();
		system(CLEAR);
		system("color");
		exit(0);
	}/*队不空*/
}/*quit*/
