#include <stdio.h>
// #include <string.h>
#include <time.h> // для использования времени
#include <cstdlib> // для rand

// параметры конфигурации - получаются из конфигурационного файла в main()
int CITY_SIZE; // размер города в длину (и ширину)
int NUM_HUMANS; // количество абонентов в городе
int NUM_TIMESLOTS; // количество временных отрезков
int START1_FROM_HOME_TIMESLOT; // время, с которого начинают ходить на работу
int START2_FROM_HOME_TIMESLOT; // время, до которого все выходят на работу
int START1_FROM_WORK_TIMESLOT; // время, с которого начинают выходить с работы
int START2_FROM_WORK_TIMESLOT; // время, до которого все выходят с работы

int LocToMap(int X, int Y)
{
    int numOnMap = Y * CITY_SIZE + X;
    return numOnMap;
}

// любой объект карты - дом, магазин, работа
class MapObject
{
public:
    MapObject()
    {
        X = rand() % (CITY_SIZE - 1);
        Y = rand() % (CITY_SIZE - 1);
    }
    int X, Y;
};

class Human
{
public:
    Human(int id_default, int num_houses, MapObject * houses, int num_works)
    {
        this->id = id_default;
        this->house = rand() % (num_houses - 1);
        this->work = rand() % (num_works - 1);
        this->X = houses[house].X;
        this->Y = houses[house].Y;
        this->was_in_shop = 0;
        this->from_home_timeslot = START1_FROM_HOME_TIMESLOT + rand() % (START2_FROM_HOME_TIMESLOT - START1_FROM_HOME_TIMESLOT);
        this->from_work_timeslot = START1_FROM_WORK_TIMESLOT + rand() % (START2_FROM_WORK_TIMESLOT - START1_FROM_WORK_TIMESLOT);
    }
    int id;
    int house; // выбор номера дома для человека
    int work; // выбор номера работы для человека
    int X; // текущее положение человека по X
    int Y; // текущее положение человека по Y
    bool was_in_shop; // # был ли в магазине
    int from_home_timeslot; // время выхода из дома
    int from_work_timeslot; // время выхода с работы

    void Move(int timeslot, MapObject *houses, MapObject *shops, MapObject *works, int num_shops)
    {
        if (timeslot >= from_home_timeslot) // если время до выхода на работу
        {
            if (timeslot < from_work_timeslot) // если время выхода на работу или самой работы
                this->MoveToDirection(works[this->work].X, works[this->work].Y); // перемещение по направлению к работе
            else // если время выхода с работы или позже
            {
                if (this->was_in_shop == 1) // если в магазине уже был
                    MoveToDirection(houses[this->house].X, houses[this->house].Y); // перемещение по направлению к дому
                else // если в магазине ещё не был
                {
                    int next_X = houses[this->house].X; // цель - дом
                    int next_Y = houses[this->house].Y;
                    for (int i = 0; i < num_shops; i++) // для каждого из магазинов
                        if ((this->was_in_shop == 0) && (this->X - 1 <= shops[i].X) && (shops[i].X  <= this->X + 1) && (this->Y - 1 <= shops[i].Y) && (shops[i].Y <= this->Y + 1)) // если магазин рядом и из всех магазинов ни в один не зашёл
                        {
                            next_X = shops[i].X; // цель - магазин
                            next_Y = shops[i].Y;
                            this->was_in_shop = 1; // побывал в магазине
                        }
                    this->MoveToDirection(next_X, next_Y); // шаг или в магазин, или к дому
                }
            }
        }
    }
    void MoveToDirection(int place_x, int place_y)
    {
        if ((this->X != place_x) || (this->Y != place_y)) // если человек не на месте, то двигается к цели
        {
            if (this->X != place_x) // если по X человек ещё не на месте
            {
                if (this->X < place_x) // если по X человек левее цели
                    this->X++; // шаг вправо
                else // если по X человек правее цели
                    this->X--; // шаг влево
            }
            if (this->Y != place_y) // если по Y человек ещё не на месте
            {
                if (this->Y < place_y) // если по Y человек ниже цели
                    this->Y++; // шаг вверх
                else // если по Y человек выше цели
                    this->Y--; // шаг вниз
            }
        }
    }
    // запись полученной позиции
    void Log(int **locupds, int timeslot)
    {
        locupds[this->id][timeslot] = LocToMap(this->X, this->Y);
    }
};

// создаёт заданное количество человек
Human * CreateHumans(Human *humans, int num_humans, int num_houses, MapObject *houses, int num_works)
{
    for (int i = 0; i < num_humans; i++)
        humans[i] = Human(i, num_houses, houses, num_works);
    return humans;
}

int main()
{
    srand((unsigned int)time(NULL));// для работы случайного числа
    FILE *config_file;
    config_file = fopen("patterns.conf", "r");
    if (config_file == NULL)
        printf("\nНевозможно открыть конфигурационный файл на чтение !!!\n");
    else
    {
          fscanf(config_file,"%d %d %d %d %d %d %d", &CITY_SIZE, &NUM_HUMANS, &NUM_TIMESLOTS, &START1_FROM_HOME_TIMESLOT, &START2_FROM_HOME_TIMESLOT, &START1_FROM_WORK_TIMESLOT, &START2_FROM_WORK_TIMESLOT); // считывание параметров конфигурации
    }
    fclose(config_file);
    START1_FROM_HOME_TIMESLOT = int(float(START1_FROM_HOME_TIMESLOT) / 24.0 * NUM_TIMESLOTS); // время, с которого начинают ходить на работу
    START2_FROM_HOME_TIMESLOT = int(float(START2_FROM_HOME_TIMESLOT) / 24.0 * NUM_TIMESLOTS); // время, до которого все выходят на работу
    START1_FROM_WORK_TIMESLOT = int(float(START1_FROM_WORK_TIMESLOT) / 24.0 * NUM_TIMESLOTS); // время, с которого начинают выходить с работы
    START2_FROM_WORK_TIMESLOT = int(float(START2_FROM_WORK_TIMESLOT) / 24.0 * NUM_TIMESLOTS); // время, до которого все выходят с работы
    // описание множеств домов, магазинов, работ
    int num_houses = int(CITY_SIZE * CITY_SIZE / 2); // дома - в половине ячеек карты
    int num_shops = int(CITY_SIZE * CITY_SIZE / 4); // магазины - в четверти ячеек карты
    int num_works = int(CITY_SIZE * CITY_SIZE / 4); // работы - в четверти ячеек карты
    MapObject *houses, *shops, *works; // указатели на массивы объектов
    // выделение памяти для массивов объектов
    houses = (MapObject *)malloc(num_houses * sizeof(MapObject));
    shops = (MapObject *)malloc(num_shops * sizeof(MapObject));
    works = (MapObject *)malloc(num_works * sizeof(MapObject));
    // наполнение массивов объектами
    for (int i = 0; i < num_houses; i++)
        houses[i] = MapObject();
    for (int i = 0; i < num_shops; i++)
        shops[i] = MapObject();
    for (int i = 0; i < num_works; i++)
        works[i] = MapObject();

    // описание массива для хранения шаблонов
    int **locupds; // указатель на массив
    locupds = (int **)malloc(NUM_HUMANS * sizeof(int *)); // выделение памяти для массива массивов
    for (int i = 0; i < NUM_HUMANS; i++) // каждому человеку
        locupds[i] = (int *)malloc(NUM_TIMESLOTS * sizeof(int *)); // выделение ячеек времени

    // создание массива людей
    Human *humans;
    humans = (Human *)malloc(NUM_HUMANS * sizeof(Human)); // выделение памяти для массива людей

    humans = CreateHumans(humans, NUM_HUMANS, num_houses, houses, num_works);

    for (int timeslot = 0; timeslot < NUM_TIMESLOTS; timeslot++)
    {
        for (int j = 0; j < NUM_HUMANS; j++)
        {
            humans[j].Move(timeslot, houses, shops, works, num_shops); // шаг человека
            humans[j].Log(locupds, timeslot); // запись шага в шаблон
        }
    }

    // вывод в файл
    FILE *out;
    out = fopen("patterns.txt", "w");
    if (out == NULL)
        printf("\nНевозможно открыть файл на запись !!!\n");
    else
    {
        for (int human_num = 0; human_num < NUM_HUMANS; human_num++) // для каждого человеко-шаблона
        {
            for (int timeslot = 0; timeslot < NUM_TIMESLOTS; timeslot++) // для каждого отрезка времени
                fprintf(out, "%d ", locupds[human_num][timeslot]);
            fprintf(out, "\n");
        }
    }
    fclose(out);
    // освобождение памяти
    free(humans);
    free(locupds);
    free(houses);
    free(shops);
    free(works);
}
