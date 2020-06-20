#include <fstream>
#include<string>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	//БЛОК ЗАПИСИ ДАННЫХ В ФАЙЛ
	setlocale(LC_ALL, "Russian");
	vector<int>sum1;
	vector<int>sum2;
	vector<int>sum3;
	vector<int>file1_vector;
	vector<int>file2_vector;
	vector<int>file3_vector;
	string line;
	//файл 1 (считываение данных)
	ifstream file1("1.txt"); // окрываем файл 1 для чтения
	if (file1.is_open())
	{
		while (getline(file1, line))
		{
			file1_vector.push_back(stoi(line)); //все строки записаны в вектор(универсальный динамически массив)
		}
	}
	//файл 2 (считываение данных)
	ifstream file2("2.txt");// окрываем файл 2 для чтения
	if (file2.is_open())
	{
		while (getline(file2, line))
		{
			file2_vector.push_back(stoi(line)); //все строки записаны в вектор(универсальный динамически массив)
		}
	}
	//файл 3 (считываение данных)
	ifstream file3("3.txt");// окрываем файл 3 для чтения
	if (file3.is_open())
	{
		while (getline(file3, line))
		{
			file3_vector.push_back(stoi(line)); //все строки записаны в вектор(универсальный динамически массив)
		}
	}
	file1.close();
	file2.close();
	file3.close();     // закрываем файлы

	ofstream out;          // поток для записи
	out.open("4.txt");    // окрываем файл для записи
	for (int i = 0; i < 24; i++)
	{
		out << file1_vector[i] << " " << file2_vector[i] << " " << file3_vector[i] << " " << endl;
	}
	out.close();

	file1_vector[0];

	//МАТ ЧАСТЬ
	int m = 0;
	for (int i = 0; i < 24; i++)
	{
		m = m + file1_vector[i];
		sum1.push_back(m);
	}
	m = 0;
	for (int i = 0; i < 24; i++)
	{
		m = m + file2_vector[i];
		sum2.push_back(m);
	}
	m = 0;
	for (int i = 0; i < 24; i++)
	{
		m = m + file3_vector[i];
		sum3.push_back(m);
	}


	
	int rand1 = 0, rand2 = 0, rand3 = 0;
	rand1 = rand() % sum1[23];
	rand2 = rand() % sum2[23];
	rand3 = rand() % sum3[23];
	int i = 0;
	int index1=0, index2 = 0, index3 = 0;
	
	 if ((rand1 - sum1[i]) > (sum1[i +1] - rand1))
	 {
		index1 = i + 1;
	 }
	 else
	 {
		index1 = i;
	 }

	i = 0;

	while (rand2 > sum2[i])
	{
		i++;
	}
	 if ((rand2 - sum2[i]) > (sum2[i + 1] - rand2))
	 {
		index2 = i + 1;
	 }
	 else
	 {
		index2 = i;
	 }

	i = 0;
	while (rand3 > sum3[i])
	{
		i++;
	}
	 if ((rand3 - sum3[i]) > (sum3[i + 1] - rand3))
	 {
		index3 = i + 1;
	 }
	 else
	 {
		index3 = i;
	 }
	cout << index1<<" "<< index2 << " " << index3<< endl; //- это тестовый вывод для понимания результата программы
	return 0;
}