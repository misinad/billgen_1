// BaseGeneration.cpp : Defines the entry point for the console application.
//
// Base of Abonents. Semenistchev I.A., Sinadskii A.N. : Defines the entry point for the console application.
//

#include "stdafx.h"//����������� �������
#include <string>
#include <math.h>//�������������� ������� (��� pow)
#include <time.h>//��� ������������� �������

unsigned int sluch = 0;//��� ��������� ���������� �����

int numpatterns = 3;//���������� �������� �����������

int ChooseProvider()//�������� ���������� ���������
{
	int provider;
	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
	provider = (1 + rand() % 4);// ��������� �������� �� 0 �� 4
	return(provider);//MTS=1;Megafon=2;Beeline=3;Tele2=4
};



int ChooseAge(int status0) // ����� ��������
{
    srand((unsigned int)time(NULL));// ��� ������ ���������� �����
    int age;
    float status1;
    status1 = status0 % 10;
    if ((status1 == 1) || (status1 == 2)) // ���� ���� ��� ����
        age = 18 + rand() % 50;// ��������� ������� �� 18 �� 68 ��� ���������
    else  // ���� �������
        age = 14 + rand() % 4;// ��������� ������� �� 14 �� 18 ��� �������
    return(age);
}

unsigned long long int ChoosePassport(int age, unsigned long long int old_pass_num) // ����� ������ ��������
{
    unsigned long long int passport_num, passport_num1;
    int yeariss;
    passport_num = 10 + rand() % 90; // ������ 2 ����� - ����� ������ ��������
    if (age < 20) 	// ���� ������� ����� � 14 ���
        yeariss = (2020 -  (age - 14)) % 100;
    else
        if (age < 45) 	// ���� ������� ����� � 20 ���
            yeariss = (2020 -  (age - 20)) % 100;
        else // ���� ������� ����� � 45 ���
            yeariss = (2020 -  (age - 45)) % 100;
    passport_num = passport_num * 100 + yeariss; // ����������� ����� ��������
    old_pass_num = old_pass_num % 1000000; // ��������� 6 ����� ����������� ��������
    passport_num1 = old_pass_num + (1 + rand() % 10);// ���������� ������ �������� �� ����� ot 1 do 10
    passport_num = passport_num * 1000000 + passport_num1; // ������ � ������ � ������� ��������
    return(passport_num);
}



void ChooseImei(int imei[15], long int mtac[100], long int mtac2[100],/*����� ���������� �� ���������*/ int numerrors)//�������� ��������� imei
{
	int chislo, i;
	/*long int mtac2[100];//����� mtac*///������� ������ ��������� �������

	for (i = 0; i < 100; i++)//�������� mtac
	{
		mtac2[i] = mtac[i];
	}

	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
	chislo = rand() % (100 - numerrors);//��������� �������� ot 0 do ����������� �������� tac

	if (mtac2[chislo] > 35000000)
	{
		for (i = 0; i < 8; i++)
		{
			imei[i] = mtac2[chislo] / pow(10, 7 - i);//���������� �������� ������
			mtac2[chislo] = mtac2[chislo] - imei[i] * pow(10, 7 - i);//��������� �����, ������ ������������ ������
		};
	}
	else
	{
		imei[0] = 0;
		for (i = 1; i < 8; i++)
		{
			imei[i] = mtac2[chislo] / pow(10, 7 - i);//���������� �������� ������
			mtac2[chislo] = mtac2[chislo] - imei[i] * pow(10, 7 - i);
		};
	};


	for (i = 8; i < 14; i++)
	{
		imei[i] = rand() % 10;//��������� �������� �� 0 �� 9 (�������� �����)
	}

	imei[14] = 0;//���������� ����� ����; ���� �����������
}

void ChooseMsisdn(int nomerprovidera, int msisdn[11]/*���������� msisdn*/)//�������� msisdn � ����������� �� ��������� ����� � ����������� msisdn
{
	int i, newmsisdn[11]/*������������ msisdn*/;
	int nomerkodaopeatora;
	newmsisdn[0] = 7;
	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����

	switch (nomerprovidera)//�� ������ ��������� �������� ��������� � ����� �����
	{
	case 1://MTC
	{
		nomerkodaopeatora = rand() % 2;
		switch (nomerkodaopeatora)
		{
		case 0: newmsisdn[1] = 9; newmsisdn[2] = 8; newmsisdn[3] = 2; break;
		case 1: newmsisdn[1] = 9; newmsisdn[2] = 1; newmsisdn[3] = 2; break;
		};
	}; break;
	case 2://Megafon
	{
		nomerkodaopeatora = rand() % 4;
		switch (nomerkodaopeatora)
		{
		case 0: newmsisdn[1] = 9; newmsisdn[2] = 2; newmsisdn[3] = 2; break;
		case 1: newmsisdn[1] = 9; newmsisdn[2] = 3; newmsisdn[3] = 2; break;
		case 2: newmsisdn[1] = 9; newmsisdn[2] = 9; newmsisdn[3] = 9; break;
		case 3: newmsisdn[1] = 9; newmsisdn[2] = 2; newmsisdn[3] = 9; break;
		};
	}; break;
	case 3://Beeline
	{
		nomerkodaopeatora = rand() % 4;
		switch (nomerkodaopeatora)
		{
		case 0: newmsisdn[1] = 9; newmsisdn[2] = 0; newmsisdn[3] = 3; break;
		case 1: newmsisdn[1] = 9; newmsisdn[2] = 0; newmsisdn[3] = 5; break;
		case 2: newmsisdn[1] = 9; newmsisdn[2] = 0; newmsisdn[3] = 6; break;
		case 3: newmsisdn[1] = 9; newmsisdn[2] = 0; newmsisdn[3] = 9; break;
		};
	}; break;
	case 4://Tele2
	{
		nomerkodaopeatora = rand() % 2;
		switch (nomerkodaopeatora)
		{
		case 0: newmsisdn[1] = 9; newmsisdn[2] = 0; newmsisdn[3] = 2; break;
		case 1: newmsisdn[1] = 9; newmsisdn[2] = 9; newmsisdn[3] = 2; break;
		};
	}; break;
	};

	for (i = 4; i < 11; i++)//������������ ��������� 11 ���� ������� � �����
	{
		newmsisdn[i] = msisdn[i];
	};

	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
	newmsisdn[10] = newmsisdn[10] + (1 + rand() % 10);//���������� msisdn �� ����� ot 1 do 10

	i = 10;
	while ((newmsisdn[i] > 9) && (i>0))//���� ���� ����-�� ���� ����� ������ 9 � ��� ������ �� ������� �������
	{
		newmsisdn[i] = newmsisdn[i] - 10;//��������� ���� ������ �� 10
		newmsisdn[i - 1] = newmsisdn[i - 1] + 1;//����������� ��������� ������ �� �������
		i--;//��������� � ���������� �������
	};
	for (i = 0; i < 11; i++)//������������ �� ������� ������
	{
		msisdn[i] = newmsisdn[i];
	};
}

void ChooseLacCellID(int nomerprovidera, int kolichestvostrok, int laccellid[2], int *mlac, int *mcellid)
{
	int schetchiklac/*�������*/;
	int lacleft, lacright;//������� ������

	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
	lacleft = (nomerprovidera - 1) * kolichestvostrok / 4;//����� ������� ������
	lacright = nomerprovidera * kolichestvostrok / 4;//������ ������� ������
	schetchiklac = lacleft + rand() % (lacright - lacleft);//��������� ����� � ��������� �� lacleft �� lacright
	laccellid[0] = mlac[schetchiklac];//���������� �������� LAC
	laccellid[1] = mcellid[schetchiklac];//���������� �������� CELLID
}

int ChoosePattern()
{
	int patternnumber;
	srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
	patternnumber = rand() % numpatterns;
	return (patternnumber);
}

void main()
{
	struct FIO {
		char familiaM[30],//������� �������
			familiaW[30],//������� �������
			nameM[30],//��� �������
			otchM[30],//�������� �������
			nameW[30],//��� �������
			otchW[30];//�������� �������
	};

	setlocale(LC_CTYPE, "rus");

	char NumComm[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char *pos;/*��� �������� � ������ \n*/
	FILE *FamiliaMan, *FamiliaWoman, *Result, *Otchestvoman, *NameMan, *NameWoman, *OtchestvoWoman;
	int  m = 0, j = 0,
		rOtchPrimBoy/*���������� ��� ���������� ������ ��������(�)*/,
		rOtchPrimGirl/*���������� ��� ���������� ������ ��������(�)*/,
		rComm/*��� ���������� ������ ����������*/,
		rNameM/*��� ���������� ������ ����� ��������*/,
		rNameW/*��� ���������� ������ ����� ��������*/,
		rFamilia/*��� ���������� ������ �������*/,
		rOtchM/*��� ���������� ������ ��������(�)*/,
		rOtchW/*��� ���������� ������ ��������(�)*/,
		population/*������� ������� ����� �������������*/,
		randomsex/*����������� �������� � ��� �*/;

	int unic = 1/*���������� ����� � ����*/;

	struct FIO base[650];

	int k, l/*��������*/, numerrors = 0, nomerprovidera;/*������� ������ ��� ������*/
	int age; // ������� ��������
	unsigned long long int  old_pass_num = 1111111111, passport_num; // ����� �������� ��������
	int imsi[15], imei[15], msisdn[11];
	long int mtac[100], mtac2[100];//������ �������� tac

	int *mlac, *mcellid;//������� �������� lac � cellid
	int numstroklaccellid = 0;//���������� ����� � ����� �� ���������� lac � cellid
	int schet1 = 0, schet2 = 0, schet3 = 0/*�������*/;
	char testsimvol/* = '1'*/;//��� ���������� ���������� �����
	char check1 = 0;
	char *check = &check1;//��� �������� �� ������� �������� (����� �����)
	FILE *Laccellidf;//��������� ��� ����� �� ���������� lac � cellid
	int laccellid[2];//��� ������ �� �������
	int pattern;//����� �������
				//�������� ����� ��� LAC � CELLID
	fopen_s(&Laccellidf, "E:\\�����������\\�������\\����� ��� �������\\laccellid.txt", "rt");//��������� ����
	do//������ ���������� �����
	{
		testsimvol = fgetc(Laccellidf);//��������� ������
		if (testsimvol == '\n') numstroklaccellid++;//����������� ������� �����
	} while (testsimvol != 'e');

	mlac = (int*)calloc(numstroklaccellid, sizeof(int));//������������� ������ ������� LAC
	mcellid = (int*)calloc(numstroklaccellid, sizeof(int));//������������� ������ ������� CELLID
	fseek(Laccellidf, 0, SEEK_SET);//��������� ������ � ������ �����
	for (schet1 = 0; schet1 < numstroklaccellid; schet1++)
	{
		fscanf_s(Laccellidf, "%d", &mlac[schet1]);
		fscanf_s(Laccellidf, "%d", &mcellid[schet1]);
	}
	fclose(Laccellidf);//��������� ����
					   //�������� ����� ��� IMEI
	FILE *txt;//��������� ��� �������� ����� 
	fopen_s(&txt, "E:\\�����������\\�������\\����� ��� �������\\imeitac.txt", "rt");//��������� ����
	k = 0;
	while (k < (100 - numerrors))//���� �� ������� ��� 100 ��������
	{
		fscanf_s(txt, "%d", &mtac[k]);//��������� ��������
		if ((mtac[k] > 1000000) || (mtac[k] < 35999999))//���� �������� ������ ������
		{
			k++;//������� � ��������� ��� � ��������� ������
		}
		else
		{
			k--;//������� � ��������� ��� � �� �� ������ ������
			numerrors++;//����������� ������� ������
			printf("Error in file imeitac.txt");
		};
	};
	fclose(txt);//��������� ����
				//������ ���������� �������� ��� IMSI
	srand((unsigned int)time(NULL) + sluch); sluch++;
	for (k = 0; k < 15; k++)
	{
		imsi[k] = 1 + rand() % 3;
	};
	//������ ���������� �������� ��� MSISDN
	srand((unsigned int)time(NULL) + sluch); sluch++;
	for (k = 0; k < 11; k++)
	{
		msisdn[k] = 1 + rand() % 3;
	};
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	struct MyStruct
	{
		int imsi[15];
		int imei[15];
		int msisdn[11];
	};

	MyStruct *human;//human ���� ��������� �� MyStruct

	fopen_s(&Otchestvoman, "E:\\�����������\\�������\\����� ��� �������\\Otchestvoman.txt", "r");
	fopen_s(&NameMan, "E:\\�����������\\�������\\����� ��� �������\\NameMan.txt", "r");
	fopen_s(&FamiliaMan, "E:\\�����������\\�������\\����� ��� �������\\FamiliaMan.txt", "r");
	fopen_s(&FamiliaWoman, "E:\\�����������\\�������\\����� ��� �������\\FamiliaWoman.txt", "r");
	fopen_s(&OtchestvoWoman, "E:\\�����������\\�������\\����� ��� �������\\OtchestvoWoman.txt", "r");
	fopen_s(&NameWoman, "E:\\�����������\\�������\\����� ��� �������\\NameWoman.txt", "r");
	fopen_s(&Result, "E:\\�����������\\�������\\����� ��� �������\\Result.txt", "w");

	printf("���������: ");
	scanf_s("%d", &population);
	human = new MyStruct[population];//������������ ��������� ������ ��� ������ �������� �� N ���������

	for (m = 0; m < 650; m++)//��������� ���� ������� ������� � ��������� ���
	{
		fgets(base[m].familiaM, 30, FamiliaMan);
		pos = strrchr(base[m].familiaM, '\n');
		if (pos)
			base[m].familiaM[pos - base[m].familiaM] = 0;
	}
	for (m = 0; m < 650; m++)//��������� ���� ������� ������� � ��������� ���
	{
		fgets(base[m].familiaW, 30, FamiliaWoman);
		pos = strrchr(base[m].familiaW, '\n');
		if (pos)
			base[m].familiaW[pos - base[m].familiaW] = 0;
	}
	for (m = 0; m < 50; m++)//��������� ����� �������
	{
		fgets(base[m].nameM, 30, NameMan);
		pos = strrchr(base[m].nameM, '\n');
		if (pos)
			base[m].nameM[pos - base[m].nameM] = 0;
	}
	for (m = 0; m < 50; m++)//��������� �������� ������� ��� ��������� � �����
	{
		fgets(base[m].otchM, 30, Otchestvoman);
		pos = strrchr(base[m].otchM, '\n');
		if (pos)
			base[m].otchM[pos - base[m].otchM] = 0;
	}
	for (m = 0; m < 50; m++)//��������� �������� ������� ��� ��������� � �����
	{
		fgets(base[m].otchW, 30, OtchestvoWoman);
		pos = strrchr(base[m].otchW, '\n');
		if (pos)
			base[m].otchW[pos - base[m].otchW] = 0;
	}
	for (m = 0; m < 50; m++)//��������� ����� �������
	{
		fgets(base[m].nameW, 30, NameWoman);
		pos = strrchr(base[m].nameW, '\n');
		if (pos)
			base[m].nameW[pos - base[m].nameW] = 0;
	}
	//����� ����������
	fprintf(Result, "� ����� ������� ��� �������� ����. ����. LAC CellID	   IMSI	     IMEI	   MSISDN\n");
	//����� � ������ ����� ���������� �� ������ �� 5�� �������
	for (m = 0; m < 0.027*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rFamilia = rand() % 59;//�������� ������� �� ���-59 ��� ���������� �������������
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameM = rand() % 46;//����� ���������� ����� ����, ����� �� ����� ���������� ������� ��� �����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameW = rand() % 50;//����� ���������� ����� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchM = rand() % 50;//����� ���������� �������� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchW = rand() % 50;//����� ���������� �������� ��� ����
		pattern = ChoosePattern();//�������� ����� ������� ���������

								  //����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 51 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM].nameM,//��� ����
			base[rOtchM].otchM,//�������� ����
			pattern,//����� ������� ���������
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);//��������� �������
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(51);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 52 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//����� �� �������, �� � ������� ����
			base[rNameW].nameW,//��������� ������� ���
			base[rOtchW].otchW,//��������� ������� ��������
			pattern,//������
			NumComm[rComm],//��������� ���������(���� ���)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);//��������� �������
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(52);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 53 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM + 1].nameM,//��� �������
			base[rNameM].otchM,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(53);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 54 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM + 2].nameM,//��� �������
			base[rNameM].otchM,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(54);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ������
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 55 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//������� � ����� ����
			base[rNameM + 3].nameW,//��� �������
			base[rNameM].otchW,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(55);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//����� �� ���� ������������

									  //����� ���������� � ������ �� 4�� �������
	for (m = 0; m < 0.076*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rFamilia = 60 + rand() % 108;//�������� ������� � ������ �� 60..168
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameM = rand() % 46;//����� ���������� ����� ����, ����� �� ����� ���������� ������� ��� �����
		rNameW = rand() % 50;//����� ���������� ����� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchM = rand() % 50;//����� ���������� �������� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchW = rand() % 50;//����� ���������� �������� ��� ����

							 //����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		rComm = nomerprovidera;//����� �����������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 41 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM].nameM,//��� ����
			base[rOtchM].otchM,//�������� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(41);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 42 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//����� �� �������, �� � ������� ����
			base[rNameW].nameW,//��������� ������� ���
			base[rOtchW].otchW,//��������� ������� ��������
			pattern,
			NumComm[rComm],//��������� ���������(���� ���)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(42);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 43 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM + 1].nameM,//��� �������
			base[rNameM].otchM,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(43);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 44 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM + 2].nameM,//��� �������
			base[rNameM].otchM,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(44);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//����� �� ���� ������������

									  //����� ���������� � ������ �� 3�� ������� 
	for (m = 0; m < 0.067*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rFamilia = 169 + rand() % 99;//�������� ������� � ������ �� 169..268
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameM = rand() % 46;//����� ���������� ����� ����, ����� �� ����� ���������� ������� ��� �����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameW = rand() % 50;//����� ���������� ����� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchM = rand() % 50;//����� ���������� �������� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchW = rand() % 50;//����� ���������� �������� ��� ����

							 //����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 31 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM].nameM,//��� ����
			base[rOtchM].otchM,//�������� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(31);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 32 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//����� �� �������, �� � ������� ����
			base[rNameW].nameW,//��������� ������� ���
			base[rOtchW].otchW,//��������� ������� ��������
			pattern,
			NumComm[rComm],//��������� ���������(���� ���)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(32);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 33 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM + 1].nameM,//��� �������
			base[rNameM].otchM,//�������� �������, �� ���� ��� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(33);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//����� �� ���� ������������

									  //����� ���������� � ������ �� 2�� ������� 
	for (m = 0; m < 0.04*population; m++)
	{
		rFamilia = 269 + rand() % 72;//�������� ������� � ������ �� 269..341
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameM = rOtchPrimBoy = rOtchPrimGirl = rand() % 46;//����� ���������� ����� ����, ����� �� ����� ���������� ������� ��� �����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rNameW = rand() % 50;//����� ���������� ����� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchM = rand() % 50;//����� ���������� �������� ��� ����
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		rOtchW = rand() % 50;//����� ���������� �������� ��� ����

							 //����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 21 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//������� � ����� ����
			base[rNameM].nameM,//��� ����
			base[rOtchM].otchM,//�������� ����
			pattern,
			NumComm[rComm],//����� ����������
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(21);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
		//����� ������ � ����
		nomerprovidera = ChooseProvider();//�������� ���������� ����������
		rComm = nomerprovidera;//����� �����������
		pattern = ChoosePattern();//�������� ����� ������� ���������
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
		fprintf(Result, "%d 22 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//����� �� �������, �� � ������� ����
			base[rNameW].nameW,//��������� ������� ���
			base[rOtchW].otchW,//��������� ������� ��������
			pattern,
			NumComm[rComm],//��������� ���������(���� ���)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//���� �� ������ imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//���� �� ������ imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//���� �� ������ msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		age = ChooseAge(22);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//��������� ������ � ����� ��� ��������
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//����� �� ���� ������������

									  //����� ���������� �� �������� �����
	for (m = 0; m < 0.28*population; m++)//��������� ����������� ����
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
		randomsex = rand() % 2;//����� ���� 50/50
		if (randomsex < 1) {
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rNameM = rand() % 50;//����� ���������� �����
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rOtchM = rand() % 50;//����� ���������� ��������
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rFamilia = rand() % 650;//����� ��������� �������

			nomerprovidera = ChooseProvider();//�������� ���������� ����������
			rComm = nomerprovidera;//����� �����������
			pattern = ChoosePattern();//�������� ����� ������� ���������
			ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
			fprintf(Result, "%d 11 %s %s %s %d %c %d %d ",
				unic,
				base[rFamilia].familiaM,
				base[rNameM].nameM,
				base[rOtchM].otchM,
				pattern,
				NumComm[rComm],
				laccellid[0],//LAC
				laccellid[1]);//CellID
			ChooseImsi(nomerprovidera, imsi);
			ChooseImei(imei, mtac, mtac2, numerrors);
			ChooseMsisdn(nomerprovidera, msisdn);
			for (l = 0; l < 15; l++)//���� �� ������ imsi
			{
				fprintf(Result, "%d", imsi[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 15; l++)//���� �� ������ imei
			{
				fprintf(Result, "%d", imei[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 11; l++)//���� �� ������ msisdn
			{
				fprintf(Result, "%d", msisdn[l]);
			};
			fprintf(Result, " ");//��������� ������ � ����� ��� ��������
			age = ChooseAge(11);
			fprintf(Result, "%d", age);
			passport_num = ChoosePassport(age, old_pass_num);
			fprintf(Result, "%llu", passport_num);
			fprintf(Result, " ");//��������� ������ � ����� ��� ��������
			fprintf(Result, "\n");
			unic++;
		}
		else {
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rNameW = rand() % 50;
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rOtchW = rand() % 50;
			srand((unsigned int)time(NULL) + sluch); sluch++;//��� ������ ���������� �����
			rFamilia = rand() % 650;

			nomerprovidera = ChooseProvider();//�������� ���������� ����������
			rComm = nomerprovidera;//����� �����������
			pattern = ChoosePattern();//�������� ����� ������� ���������
			ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//����� LAC � CellID (���������� �������)
			fprintf(Result, "%d 12 %s %s %s %d %c %d %d ",
				unic,
				base[rFamilia].familiaW,
				base[rNameW].nameW,
				base[rOtchW].otchW,
				pattern,
				NumComm[rComm],
				laccellid[0],//LAC
				laccellid[1]);//CellID
			ChooseImsi(nomerprovidera, imsi);
			ChooseImei(imei, mtac, mtac2, numerrors);
			ChooseMsisdn(nomerprovidera, msisdn);
			for (l = 0; l < 15; l++)//���� �� ������ imsi
			{
				fprintf(Result, "%d", imsi[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 15; l++)//���� �� ������ imei
			{
				fprintf(Result, "%d", imei[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 11; l++)//���� �� ������ msisdn
			{
				fprintf(Result, "%d", msisdn[l]);
			};
			fprintf(Result, " ");//��������� ������ � ����� ��� ��������
			age = ChooseAge(12);
			fprintf(Result, "%d", age);
			passport_num = ChoosePassport(age, old_pass_num);
			fprintf(Result, "%llu", passport_num);
			fprintf(Result, " ");//��������� ������ � ����� ��� ��������
			fprintf(Result, "\n");
			unic++;
		}
	}

	fclose(OtchestvoWoman);
	fclose(Result);
	fclose(NameWoman);
	fclose(FamiliaMan);
	fclose(FamiliaWoman);
	fclose(NameMan);
	fclose(Otchestvoman);

	delete[]human; //������������ ������
	printf("\a");
	system("pause");
}
