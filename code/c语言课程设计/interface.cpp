/**
*����
*@pakage : SAMS
*@subpackage : interface
*@Author : Youth.Lin
* http://youthlin.com/
*������ӭ���桢���˵����桢���ڡ������ȷǹ��������
*
*/

/**   �����ʾ��   */
void a(void){
	printf("a");
	/**
	*@Date : 2013-12-27 21:26
	*@Author : Youth.Lin
	*
	*/
}

/**...��ӭ...*/
void welcome(){
	int i;
	system("color 0e");		//0e �ڱ���  ����ɫǰ��
	system(CLEAR);
	printf("*******************************************************************************nn");
	printf("***************tt��ӭʹ��ѧ���ɼ�����ϵͳ��tt***************nn");
	printf("*******************************************************************************nn");
	printf("***************tt������   ��Тȫ   ������tt***************nn");
	printf("*******************************************************************************nn");
	printf("nnStrongly recommended that you read the help instructions first in the main menunǿ�ҽ���ʹ��ǰ���Ķ��˵��ڵİ���˵������nn");
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


/** �˵� */
void menu(){
	system(CLEAR);
	system("color 0a");			//0a �ڱ���  ����ɫǰ��
	printf("tttStudent Achievement Management Systemnttttѧ���ɼ�����ϵͳnn");
	printf(" ������������������������������������������������������������������������������n");
	printf(" ��ttPlease slect.ttt��ѡ��ttt     ��n");
	printf(" ��    ttttttttt     ��n");

	printf(" ��1. Read from a file .tt   1�����ļ�����tt     ��n");							/////cml
	printf(" ��2. Append record manully .tt   2���ֹ�¼��ttt     ��n");						/////cml
	printf(" ��3. Calculate total and averaget   3������ÿ�ſγ̵�tt     ��n");					/////lrt
	printf(" ��   score of every course . tt      �ֺܷ�ƽ����tt     ��n");
	printf(" ��4. Calculate total and averaget   4������ÿ��ѧ����tt     ��n");					/////zxq
	printf(" ��   score of every student . tt      �ֺܷ�ƽ����tt     ��n");
	printf(" ��5. Sort in descending order byt   5����ÿ��ѧ������tt     ��n");					/////cml
	printf(" ��   total score of every student . t      ���ɸߵ����ų����α�t     ��n");
	printf(" ��6. Sort in ascending order byt   6����ÿ��ѧ������tt     ��n");					/////zxq
	printf(" ��   total score of every student . t      ���ɵ͵����ų����α�t     ��n");
	printf(" ��7. Sort in ascending order by num.t   7����ѧ����С�����ų��ɼ���t     ��n");		/////lrt
	printf(" ��8. Sort in ascending order by name.t   8�����������ֵ�˳���ų��ɼ���     ��n");	/////cml
	printf(" ��9. Search  by numble.tt   9����ѧ�Ų�ѯѧ���������俼�Գɼ� ��n");				/////lrt
	printf(" ��10. Search  by name.ttt   10����������ѯѧ���������俼�Գɼ���n");				/////zxq
	printf(" ��11. Statistic analysis for every course 11�����ȼ�ͳ�ƿ��Գɼ�t     ��n");			/////cml
	printf(" ��12. List record. ttt   12������ɼ���tt     ��n");								/////lrt
	printf(" ��13. Write to a file. tt   13���������ļ�tt     ��n");							/////zxq

	printf(" ��14. Save/Load. ttt   14������/�浵tt     ��n");
	printf(" ��15. Delete items. ttt   15������ɾ��ttt     ��n");
	printf(" ��16. Help. tttt   16������ttt     ��n");
	printf(" ��17. About. tttt   17������ttt     ��n");
	printf(" ��0. Exit .tttt    0���˳�ttt     ��n");

	printf(" ��tPlease input your choice.t     ��������ѡ��:tt     ��n");
	printf(" ������������������������������������������������������������������������������n");


}/* main menu */


//http://youthlin.com/



/** ***Help ����*** */
int help(){
	system(CLEAR);
	system("color 1e");		//1e	��ɫ����		����ɫ����
	printf("Home->Helpn��ҳ->����nn");
	printf("*******************************************************************************n");
	printf("*0.Operation tips  tttttt      ������ʾ*n");
	printf("*******************************************************************************n");
	printf("**��������󲿷��ǲ˵�ѡ���밴��ʾ������Ӧ�����֡�,���������ַ����ܵ��´���**nn");
	printf("** program input is mostly to choose the menu.please follow the prompts to **n");
	printf("**enter the appropriate number, enter other characters may cause errors**nn");

	printf("*******************************************************************************n");
	printf("*1.About read from filetttttt���ڴ��ļ�����*n");
	printf("*******************************************************************************n");

	printf("***�����޸�ʾ���ļ��ġ��κΡ����� ��������ܵ��³�����������������Ԥ�ϵĴ���***nn");
	printf("***Do not modify the sample file any content, or it may cause the program ***n");
	printf("** tttto crash or other unexpected errortt    ***nn");

	printf("*����ʹ���Լ����ļ�,��ȷ���ļ���ÿ��һ����Ϣ,�����ļ��п�Ŀ�������������һ��**nn");
	printf("** If you use your own file, make sure the file is only one record per line, **n");
	printf("* t and the file number of subjects is consistent with your input.t     **nn");

	printf("*��Ŀ��������Ҫ�󡷲�����6��,�ļ���һ�п����Ǳ�ͷָʾ��Ϣ ,��������һ������**nn");
	printf("*Number of subjects request not more than six subjects, the first line of  **n");
	printf("*the file header can be instructions, the program does not read the first line*nn");

	printf("*�����ļ�ĩβ�����ǡ����У���ζ���ļ��������һ��������β�ģ��� *����* �س���**nn");
	printf("** And at the end of file is not blank  , means that the file ends with  a **n");
	printf("**   ttstudent's score, rather than a carriage returntt     **nn");

	printf("***�κ���ͼ���벻���Ϲ淶���ļ��Ĳ����ĺ�����ǲ���Ԥ�ϵģ�������û��Լ��е�**nn");
	printf("**Any attempt to Read Non-compliant files��the consequences are unpredictable**n");
	printf("** ttBy the users themselves bear the consequences.tt     **n");

	printf("*******************************************************************************n");



	//getchar();
	return 0;

}/** Help */



/**...����...*/
int about(){
	system(CLEAR);
	system("color b0");
	printf("Home->Aboutn��ҳ->����nn");
	printf("tttt��������tn");
	printf("n�������ɼ��ִ�ѧ���ѧԺ2013��10������ء���Тȫ�������κ�����ɡ�nn");
	printf("����Ʒ����nt��֪ʶ��������-����ҵʹ��-��ͬ��ʽ���� 4.0 �������Э�顱nt (CC BY-NC-SA 4.0)n������ɡ�n");
	printf("n������nt���ơ����С�չ�������ݡ���ӳ���㲥��ͨ����Ϣ���紫������Ʒ��tn");
	printf("t���ɸ��ơ�ɢ����չʾ���ݳ�����Ʒ��tn");
	printf("nΨ�����أ�n");
	printf("t����tt�����밴�����߻��������ָ���ķ�ʽ����Ʒ��������;n");
	printf("t����ҵʹ��t������Ϊ��ҵĿ�Ķ�ʹ�ñ���Ʒ;tn");
	printf("t��ͬ��ʽ����t�����ı�ת�����ı���Ʒ����������tn");
	printf("ttt�뱾��Ʒ��ͬ����Ȩ�����£�������ɢ������Ʒ��������Ʒ��n");
	printf("nҪ�鿴�����Э�飬�ɷ���nthttp://creativecommons.org/licenses/by-nc-sa/4.0/deed.zhnn");
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

/**����������������*/
int feedback(){
	system(CLEAR);
	printf("Thank you for use this program!tt��лʹ�ñ�����tn");
	printf("If you have any comments or tt��������κ�������飬tn");
	printf("suggestions,please give us feedback.t��ӭ�����Ƿ���tn");
	printf("Yon can email to:ttt�����Է��͵����ʼ�����tn");
	printf("ntt chenml5513@mails.jlu.edu.cnnntt zhangxq5513@mails.jlu.edu.cnnntt liurt5513@mails.jlu.edu.cnnnnn");
	return 0;
}/*feedback*/

/**  �˳�  */
int quit(){
	int yn,i;
	system(CLEAR);
	system("color e1");			//e1	��������ɫ	���ֺ�ɫ
	printf("Home->Quitn��ҳ->�˳�nn");
	if(front==NULL){
		printf("You haven't even stated using this program,are you sure to exit?n����δʹ�ñ�����ȷ���˳���n(1--yes other--no)n");
		scanf("%d",&yn);
		if(yn==1){
			feedback();
			printf("The system will exit in");
			for(i=9;i>=0;i--){
				printf(" %d second!tϵͳ����%d����˳���bbbbbbbbbbbbbbbbbb",i,i);
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
	}/*if�ӿ�*/
	else{
		if(ifsave==0){
			printf("You haven't save to file,Are you sure to exit?t����δ���棬���Ҫ�˳���tn(1--yestother--no)n");
			scanf("%d",&yn);
			if (yn!=1)
				return 0;
		}
		else{
			printf("Are you sure to exit!?t���Ҫ�˳���n(1--yes other--no)n");
			getchar();
			scanf("%d",&yn);
			//printf("%d",yn);
			if(yn==1){
				feedback();
				/*@since v1.1	��ʱ������
				*@update : 2013-12-26	�Ѿ�֧����ͣ��
				*/
				printf("The system will exit in");
				for(i=9;i>=0;i--){
					printf(" %d second!tϵͳ����%d����˳���bbbbbbbbbbbbbbbbbb",i,i);
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
			}/*if-ȷ���˳�-else*/
		}/*����*/

		feedback();
		printf("The system will exit in");
		for(i=9;i>=0;i--){
			printf(" %d second!tϵͳ����%d����˳���bbbbbbbbbbbbbbbbbb",i,i);
			Sleep(1000);
		}
		//system(P);
		a();
		system(CLEAR);
		system("color");
		exit(0);
	}/*�Ӳ���*/
}/*quit*/
