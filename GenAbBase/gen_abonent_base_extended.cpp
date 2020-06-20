// BaseGeneration.cpp : Defines the entry point for the console application.
//
// Base of Abonents. Semenistchev I.A., Sinadskii A.N. : Defines the entry point for the console application.
//

#include "stdafx.h"//стандартные функции
#include <string>
#include <math.h>//математические функции (для pow)
#include <time.h>//для использования времени

unsigned int sluch = 0;//для изменения случайного числа

int numpatterns = 3;//количество шаблонов перемещений

int ChooseProvider()//выбирает случайного оператора
{
	int provider;
	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
	provider = (1 + rand() % 4);// случайное значение от 0 до 4
	return(provider);//MTS=1;Megafon=2;Beeline=3;Tele2=4
};



int ChooseAge(int status0) // выбор возраста
{
    srand((unsigned int)time(NULL));// для работы случайного числа
    int age;
    float status1;
    status1 = status0 % 10;
    if ((status1 == 1) || (status1 == 2)) // если отец или мать
        age = 18 + rand() % 50;// случайный возраст от 18 до 68 для взрослого
    else  // если ребенок
        age = 14 + rand() % 4;// случайный возраст от 14 до 18 для ребенка
    return(age);
}

unsigned long long int ChoosePassport(int age, unsigned long long int old_pass_num) // выбор номера паспорта
{
    unsigned long long int passport_num, passport_num1;
    int yeariss;
    passport_num = 10 + rand() % 90; // первые 2 цифры - место выдачи паспорта
    if (age < 20) 	// если паспорт выдан в 14 лет
        yeariss = (2020 -  (age - 14)) % 100;
    else
        if (age < 45) 	// если паспорт выдан в 20 лет
            yeariss = (2020 -  (age - 20)) % 100;
        else // если паспорт выдан в 45 лет
            yeariss = (2020 -  (age - 45)) % 100;
    passport_num = passport_num * 100 + yeariss; // добавлениие серии паспорта
    old_pass_num = old_pass_num % 1000000; // последние 6 чисел предыдущего паспорта
    passport_num1 = old_pass_num + (1 + rand() % 10);// увеличение номера паспорта на число ot 1 do 10
    passport_num = passport_num * 1000000 + passport_num1; // строка с серией и номером паспорта
    return(passport_num);
}



void ChooseImei(int imei[15], long int mtac[100], long int mtac2[100],/*потом переделать на локальную*/ int numerrors)//выбирает случайный imei
{
	int chislo, i;
	/*long int mtac2[100];//копия mtac*///сделать вместо параметра функции

	for (i = 0; i < 100; i++)//копируем mtac
	{
		mtac2[i] = mtac[i];
	}

	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
	chislo = rand() % (100 - numerrors);//случайное значение ot 0 do осмысленных значений tac

	if (mtac2[chislo] > 35000000)
	{
		for (i = 0; i < 8; i++)
		{
			imei[i] = mtac2[chislo] / pow(10, 7 - i);//записвыаем значение разрда
			mtac2[chislo] = mtac2[chislo] - imei[i] * pow(10, 7 - i);//уменьшаем число, удаляя максимальный разряд
		};
	}
	else
	{
		imei[0] = 0;
		for (i = 1; i < 8; i++)
		{
			imei[i] = mtac2[chislo] / pow(10, 7 - i);//записвыаем значение разрда
			mtac2[chislo] = mtac2[chislo] - imei[i] * pow(10, 7 - i);
		};
	};


	for (i = 8; i < 14; i++)
	{
		imei[i] = rand() % 10;//случайное значение от 0 до 9 (серийный номер)
	}

	imei[14] = 0;//дописываем число Луна; надо пересчитать
}

void ChooseMsisdn(int nomerprovidera, int msisdn[11]/*предыдущий msisdn*/)//выбирает msisdn в зависимости от оператора связи и предыдущего msisdn
{
	int i, newmsisdn[11]/*генерируемый msisdn*/;
	int nomerkodaopeatora;
	newmsisdn[0] = 7;
	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа

	switch (nomerprovidera)//по номеру оператора выбираем четвертую и пятую цифру
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

	for (i = 4; i < 11; i++)//переписываем последние 11 цифр старого в новый
	{
		newmsisdn[i] = msisdn[i];
	};

	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
	newmsisdn[10] = newmsisdn[10] + (1 + rand() % 10);//увеличение msisdn на число ot 1 do 10

	i = 10;
	while ((newmsisdn[i] > 9) && (i>0))//пока есть хотя-бы одно число больше 9 и нет выхода за границы массива
	{
		newmsisdn[i] = newmsisdn[i] - 10;//уменьшаем этот разряд на 10
		newmsisdn[i - 1] = newmsisdn[i - 1] + 1;//увеличиваем следующий разряд на единицу
		i--;//переходим к следующему разряду
	};
	for (i = 0; i < 11; i++)//переписываем по старому адресу
	{
		msisdn[i] = newmsisdn[i];
	};
}

void ChooseLacCellID(int nomerprovidera, int kolichestvostrok, int laccellid[2], int *mlac, int *mcellid)
{
	int schetchiklac/*счетчик*/;
	int lacleft, lacright;//границы выбора

	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
	lacleft = (nomerprovidera - 1) * kolichestvostrok / 4;//левая граница выбора
	lacright = nomerprovidera * kolichestvostrok / 4;//правая граница выбора
	schetchiklac = lacleft + rand() % (lacright - lacleft);//случайное число в диапазоне от lacleft до lacright
	laccellid[0] = mlac[schetchiklac];//записываем значение LAC
	laccellid[1] = mcellid[schetchiklac];//записываем значение CELLID
}

int ChoosePattern()
{
	int patternnumber;
	srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
	patternnumber = rand() % numpatterns;
	return (patternnumber);
}

void main()
{
	struct FIO {
		char familiaM[30],//фамилия мужская
			familiaW[30],//фамилия женская
			nameM[30],//имя мужское
			otchM[30],//отчество мужское
			nameW[30],//имя женское
			otchW[30];//отчество женское
	};

	setlocale(LC_CTYPE, "rus");

	char NumComm[10] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char *pos;/*для удаления в строке \n*/
	FILE *FamiliaMan, *FamiliaWoman, *Result, *Otchestvoman, *NameMan, *NameWoman, *OtchestvoWoman;
	int  m = 0, j = 0,
		rOtchPrimBoy/*переменная для случайного выбора отчества(м)*/,
		rOtchPrimGirl/*переменная для случайного выбора отчества(ж)*/,
		rComm/*для случайного выбора комутатора*/,
		rNameM/*для случайного выбора имени мужского*/,
		rNameW/*для случайного выбора имени женского*/,
		rFamilia/*для случайного выбора фамилии*/,
		rOtchM/*для случайного выбора отчества(м)*/,
		rOtchW/*для случайного выбора отчества(ж)*/,
		population/*сколько человек нужно сгенерировать*/,
		randomsex/*вероятность создания М или Ж*/;

	int unic = 1/*уникальный номер в базе*/;

	struct FIO base[650];

	int k, l/*счетчики*/, numerrors = 0, nomerprovidera;/*счетчик ошибок при чтении*/
	int age; // возраст абонента
	unsigned long long int  old_pass_num = 1111111111, passport_num; // номер паспорта абонента
	int imsi[15], imei[15], msisdn[11];
	long int mtac[100], mtac2[100];//массив значений tac

	int *mlac, *mcellid;//массивы значений lac и cellid
	int numstroklaccellid = 0;//количество строк в файле со значениями lac и cellid
	int schet1 = 0, schet2 = 0, schet3 = 0/*счетчик*/;
	char testsimvol/* = '1'*/;//для нахождения количества строк
	char check1 = 0;
	char *check = &check1;//для проверки на наличие пробелов (конец файла)
	FILE *Laccellidf;//указатель для файла со значениями lac и cellid
	int laccellid[2];//для вывода из функции
	int pattern;//номер шаблона
				//ОТКРЫТИЕ ФАЙЛА ДЛЯ LAC и CELLID
	fopen_s(&Laccellidf, "E:\\Университет\\Биллинг\\Файлы для запуска\\laccellid.txt", "rt");//открываем файл
	do//узнаем количество строк
	{
		testsimvol = fgetc(Laccellidf);//считываем символ
		if (testsimvol == '\n') numstroklaccellid++;//увеличиваем счетчик строк
	} while (testsimvol != 'e');

	mlac = (int*)calloc(numstroklaccellid, sizeof(int));//устанавливаем размер массива LAC
	mcellid = (int*)calloc(numstroklaccellid, sizeof(int));//устанавливаем размер массива CELLID
	fseek(Laccellidf, 0, SEEK_SET);//перенести курсор в начало файла
	for (schet1 = 0; schet1 < numstroklaccellid; schet1++)
	{
		fscanf_s(Laccellidf, "%d", &mlac[schet1]);
		fscanf_s(Laccellidf, "%d", &mcellid[schet1]);
	}
	fclose(Laccellidf);//закрываем файл
					   //ОТКРЫТИЕ ФАЙЛА ДЛЯ IMEI
	FILE *txt;//указатель для открытия файла 
	fopen_s(&txt, "E:\\Университет\\Биллинг\\Файлы для запуска\\imeitac.txt", "rt");//открываем файл
	k = 0;
	while (k < (100 - numerrors))//пока не считали все 100 значений
	{
		fscanf_s(txt, "%d", &mtac[k]);//считываем значение
		if ((mtac[k] > 1000000) || (mtac[k] < 35999999))//если считался нужный формат
		{
			k++;//считать в следующий раз в следующую ячейку
		}
		else
		{
			k--;//считать в следующий раз в ту же ячейку заново
			numerrors++;//увеличиваем счетчик ошибок
			printf("Error in file imeitac.txt");
		};
	};
	fclose(txt);//закрываем файл
				//ЗАПИСЬ НАЧАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ IMSI
	srand((unsigned int)time(NULL) + sluch); sluch++;
	for (k = 0; k < 15; k++)
	{
		imsi[k] = 1 + rand() % 3;
	};
	//ЗАПИСЬ НАЧАЛЬНОГО ЗНАЧЕНИЯ ДЛЯ MSISDN
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

	MyStruct *human;//human есть указатель на MyStruct

	fopen_s(&Otchestvoman, "E:\\Университет\\Биллинг\\Файлы для запуска\\Otchestvoman.txt", "r");
	fopen_s(&NameMan, "E:\\Университет\\Биллинг\\Файлы для запуска\\NameMan.txt", "r");
	fopen_s(&FamiliaMan, "E:\\Университет\\Биллинг\\Файлы для запуска\\FamiliaMan.txt", "r");
	fopen_s(&FamiliaWoman, "E:\\Университет\\Биллинг\\Файлы для запуска\\FamiliaWoman.txt", "r");
	fopen_s(&OtchestvoWoman, "E:\\Университет\\Биллинг\\Файлы для запуска\\OtchestvoWoman.txt", "r");
	fopen_s(&NameWoman, "E:\\Университет\\Биллинг\\Файлы для запуска\\NameWoman.txt", "r");
	fopen_s(&Result, "E:\\Университет\\Биллинг\\Файлы для запуска\\Result.txt", "w");

	printf("Население: ");
	scanf_s("%d", &population);
	human = new MyStruct[population];//динамическое выделение памяти под массив структур из N элементов

	for (m = 0; m < 650; m++)//заполняем поле фамилии мужские в структуре ФИО
	{
		fgets(base[m].familiaM, 30, FamiliaMan);
		pos = strrchr(base[m].familiaM, '\n');
		if (pos)
			base[m].familiaM[pos - base[m].familiaM] = 0;
	}
	for (m = 0; m < 650; m++)//заполняем поле фамилии женские в структуре ФИО
	{
		fgets(base[m].familiaW, 30, FamiliaWoman);
		pos = strrchr(base[m].familiaW, '\n');
		if (pos)
			base[m].familiaW[pos - base[m].familiaW] = 0;
	}
	for (m = 0; m < 50; m++)//заполняем имена мужские
	{
		fgets(base[m].nameM, 30, NameMan);
		pos = strrchr(base[m].nameM, '\n');
		if (pos)
			base[m].nameM[pos - base[m].nameM] = 0;
	}
	for (m = 0; m < 50; m++)//заполняем отчества мужские для родителей и детей
	{
		fgets(base[m].otchM, 30, Otchestvoman);
		pos = strrchr(base[m].otchM, '\n');
		if (pos)
			base[m].otchM[pos - base[m].otchM] = 0;
	}
	for (m = 0; m < 50; m++)//заполняем отчества женские для родителей и детей
	{
		fgets(base[m].otchW, 30, OtchestvoWoman);
		pos = strrchr(base[m].otchW, '\n');
		if (pos)
			base[m].otchW[pos - base[m].otchW] = 0;
	}
	for (m = 0; m < 50; m++)//заполняем имена женские
	{
		fgets(base[m].nameW, 30, NameWoman);
		pos = strrchr(base[m].nameW, '\n');
		if (pos)
			base[m].nameW[pos - base[m].nameW] = 0;
	}
	//Вывод заголовков
	fprintf(Result, "№ СоцСт Фамилия Имя Отчество Шабл. Комм. LAC CellID	   IMSI	     IMEI	   MSISDN\n");
	//вывод в начале файла информации об семьях из 5ти человек
	for (m = 0; m < 0.027*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rFamilia = rand() % 59;//выбираем фамилию из ТОП-59 для реализации распределения
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameM = rand() % 46;//выбор случайного имени отца, сразу же выбор одинаковых отчеств для детей
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameW = rand() % 50;//выбор случайного имени для жены
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchM = rand() % 50;//выбор случайного отчества для мужа
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchW = rand() % 50;//выбор случайного отчества для мужа
		pattern = ChoosePattern();//выбираем номер шаблона поведения

								  //вывод записи о муже
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 51 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM].nameM,//имя мужа
			base[rOtchM].otchM,//отчество мужа
			pattern,//номер шаблона поведения
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);//обновляем массивы
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(51);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о жене
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 52 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//такая же фамилия, но в женском роде
			base[rNameW].nameW,//случайное женское имя
			base[rOtchW].otchW,//случайное женское отчество
			pattern,//шаблон
			NumComm[rComm],//случайный комутатор(пока что)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);//обновляем массивы
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(52);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о сыне
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 53 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM + 1].nameM,//имя ребенка
			base[rNameM].otchM,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(53);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод запись о сыне
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 54 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM + 2].nameM,//имя ребенка
			base[rNameM].otchM,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(54);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод запись о дочери
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 55 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//фамилия в семье одна
			base[rNameM + 3].nameW,//имя ребенка
			base[rNameM].otchW,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(55);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//чтобы не было переполнения

									  //вывод информации о семьях из 4ех человек
	for (m = 0; m < 0.076*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rFamilia = 60 + rand() % 108;//выбираем фамилию в списке от 60..168
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameM = rand() % 46;//выбор случайного имени отца, сразу же выбор одинаковых отчеств для детей
		rNameW = rand() % 50;//выбор случайного имени для жены
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchM = rand() % 50;//выбор случайного отчества для мужа
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchW = rand() % 50;//выбор случайного отчества для мужа

							 //вывод записи о муже
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		rComm = nomerprovidera;//выбор коммутатора
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 41 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM].nameM,//имя мужа
			base[rOtchM].otchM,//отчество мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(41);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о жене
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 42 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//такая же фамилия, но в женском роде
			base[rNameW].nameW,//случайное женское имя
			base[rOtchW].otchW,//случайное женское отчество
			pattern,
			NumComm[rComm],//случайный комутатор(пока что)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(42);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о сыне
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 43 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM + 1].nameM,//имя ребенка
			base[rNameM].otchM,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(43);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод запись о сыне
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 44 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM + 2].nameM,//имя ребенка
			base[rNameM].otchM,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(44);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//чтобы не было переполнения

									  //вывод информации о семьях из 3ех человек 
	for (m = 0; m < 0.067*population; m++)
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rFamilia = 169 + rand() % 99;//выбираем фамилию в списке от 169..268
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameM = rand() % 46;//выбор случайного имени отца, сразу же выбор одинаковых отчеств для детей
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameW = rand() % 50;//выбор случайного имени для жены
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchM = rand() % 50;//выбор случайного отчества для мужа
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchW = rand() % 50;//выбор случайного отчества для мужа

							 //вывод записи о муже
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 31 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM].nameM,//имя мужа
			base[rOtchM].otchM,//отчество мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(31);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о жене
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 32 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//такая же фамилия, но в женском роде
			base[rNameW].nameW,//случайное женское имя
			base[rOtchW].otchW,//случайное женское отчество
			pattern,
			NumComm[rComm],//случайный комутатор(пока что)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(32);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о сыне
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 33 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM + 1].nameM,//имя ребенка
			base[rNameM].otchM,//отчество ребенка, то есть имя мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(33);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//чтобы не было переполнения

									  //вывод информации о семьях из 2ух человек 
	for (m = 0; m < 0.04*population; m++)
	{
		rFamilia = 269 + rand() % 72;//выбираем фамилию в списке от 269..341
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameM = rOtchPrimBoy = rOtchPrimGirl = rand() % 46;//выбор случайного имени отца, сразу же выбор одинаковых отчеств для детей
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rNameW = rand() % 50;//выбор случайного имени для жены
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchM = rand() % 50;//выбор случайного отчества для мужа
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		rOtchW = rand() % 50;//выбор случайного отчества для мужа

							 //вывод записи о муже
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 21 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaM,//фамилия в семье одна
			base[rNameM].nameM,//имя мужа
			base[rOtchM].otchM,//отчество мужа
			pattern,
			NumComm[rComm],//номер комутатора
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(21);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
		//вывод записи о жене
		nomerprovidera = ChooseProvider();//выбираем случайного провайдера
		rComm = nomerprovidera;//выбор коммутатора
		pattern = ChoosePattern();//выбираем номер шаблона поведения
		ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
		fprintf(Result, "%d 22 %s %s %s %d %c %d %d ",
			unic,
			base[rFamilia].familiaW,//такая же фамилия, но в женском роде
			base[rNameW].nameW,//случайное женское имя
			base[rOtchW].otchW,//случайное женское отчество
			pattern,
			NumComm[rComm],//случайный комутатор(пока что)
			laccellid[0],//LAC
			laccellid[1]);//CellID
		ChooseImsi(nomerprovidera, imsi);
		ChooseImei(imei, mtac, mtac2, numerrors);
		ChooseMsisdn(nomerprovidera, msisdn);
		for (l = 0; l < 15; l++)//цикл по цифрам imsi
		{
			fprintf(Result, "%d", imsi[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 15; l++)//цикл по цифрам imei
		{
			fprintf(Result, "%d", imei[l]);
		};
		fprintf(Result, " ");
		for (l = 0; l < 11; l++)//цикл по цифрам msisdn
		{
			fprintf(Result, "%d", msisdn[l]);
		};
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		age = ChooseAge(22);
		fprintf(Result, "%d", age);
		passport_num = ChoosePassport(age, old_pass_num);
		fprintf(Result, "%llu", passport_num);
		fprintf(Result, " ");//вписываем пробел в конце для удобства
		fprintf(Result, "\n");
		unic++;
	}

	if (sluch > 2000000000) sluch = 0;//чтобы не было переполнения

									  //вывод информации об одиноких людях
	for (m = 0; m < 0.28*population; m++)//генерация абонентской базы
	{
		srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
		randomsex = rand() % 2;//выбор пола 50/50
		if (randomsex < 1) {
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rNameM = rand() % 50;//выбор случайного имени
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rOtchM = rand() % 50;//выбор случайного отчества
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rFamilia = rand() % 650;//выбор случайной фамилии

			nomerprovidera = ChooseProvider();//выбираем случайного провайдера
			rComm = nomerprovidera;//выбор коммутатора
			pattern = ChoosePattern();//выбираем номер шаблона поведения
			ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
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
			for (l = 0; l < 15; l++)//цикл по цифрам imsi
			{
				fprintf(Result, "%d", imsi[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 15; l++)//цикл по цифрам imei
			{
				fprintf(Result, "%d", imei[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 11; l++)//цикл по цифрам msisdn
			{
				fprintf(Result, "%d", msisdn[l]);
			};
			fprintf(Result, " ");//вписываем пробел в конце для удобства
			age = ChooseAge(11);
			fprintf(Result, "%d", age);
			passport_num = ChoosePassport(age, old_pass_num);
			fprintf(Result, "%llu", passport_num);
			fprintf(Result, " ");//вписываем пробел в конце для удобства
			fprintf(Result, "\n");
			unic++;
		}
		else {
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rNameW = rand() % 50;
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rOtchW = rand() % 50;
			srand((unsigned int)time(NULL) + sluch); sluch++;//для работы случайного числа
			rFamilia = rand() % 650;

			nomerprovidera = ChooseProvider();//выбираем случайного провайдера
			rComm = nomerprovidera;//выбор коммутатора
			pattern = ChoosePattern();//выбираем номер шаблона поведения
			ChooseLacCellID(nomerprovidera, numstroklaccellid, laccellid, mlac, mcellid);//выбор LAC и CellID (обновление массива)
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
			for (l = 0; l < 15; l++)//цикл по цифрам imsi
			{
				fprintf(Result, "%d", imsi[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 15; l++)//цикл по цифрам imei
			{
				fprintf(Result, "%d", imei[l]);
			};
			fprintf(Result, " ");
			for (l = 0; l < 11; l++)//цикл по цифрам msisdn
			{
				fprintf(Result, "%d", msisdn[l]);
			};
			fprintf(Result, " ");//вписываем пробел в конце для удобства
			age = ChooseAge(12);
			fprintf(Result, "%d", age);
			passport_num = ChoosePassport(age, old_pass_num);
			fprintf(Result, "%llu", passport_num);
			fprintf(Result, " ");//вписываем пробел в конце для удобства
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

	delete[]human; //Освобождение памяти
	printf("\a");
	system("pause");
}
