#include <iostream>
#include <vector>// библиотека векторов - это структура данных, которая уже является моделью динамического массива. 
//vector < тип данных > <имя вектора>;
#include <iomanip>

double example() { //функция где происходит уже готовое простое вычесление 

    double result;
    char sign;//знак выражения 

    result = multiplication();// функция с приоритетными знаками -/

    while (true)
    {
        sign = cin.get();// использывание оператор принятия как струтуру с готовыми функциями

        switch (sign)
        {
        case '+':
            result += multiplication(); // функция с приоритетными знаками -/
            break;
        case '-':
            result -= multiplication(); // функция с приоритетными знаками -/
            break;
        default:
            cin.putback(sign);
            return result;
        }
    }

};
double multiplication() {

    double result;// выбрала дабл лучше чем float
    char sign;
    
    double temp;// временная переменная для хранения 

    result = power();

    while (true)
    {
        sign = cin.get();//считывает данные из входного потока данных и ожидает нажатия клавиши

        switch (sign)
        {
        case '*':
            result *= power();
            break;
        case '/':
            temp = power();

            if (temp == 0.0)
            {
                cout << "\tКто делит на 0?!\a" << endl;
                exit(-1);//возврат к меню
            }

            result /= temp;
            break;
        default:
            cin.putback(sign);
            return result;
        }
    }
};
double power() {
    double result;
     
    char sing;
    vector < double > arr;// vector <int> ivector = {<элемент [0]>, <[1]>, <[2]>};

    arr.push_back(staples());// push_back () — это один из способов вставить новый элемент в конец вектора, который увеличивает размер вектора на 1.

    while (true)
    {
        sing = cin.get();//читывает данные из входного потока данных и ожидает нажатия клавиши

        while (sing == ' ')
            sing = cin.get();//пробелы 

        if (sing == '^')
            arr.push_back(staples());// это один из способов вставить новый элемент в конец вектора, который увеличивает размер вектора на 1
        else
        {
            cin.putback(sing);//Метод putback - загоняет символ обратно в поток, т.е.при последующем get он снова прочитается.
            break;
        }
    }

    for (int i = arr.size() - 1; i > 0; i--)//озвращает размер конкретного контейнера списка. Другими словами, он возвращает количество элементов, присутствующих в контейнере списка.
        arr[i - 1] = pow(arr[i - 1], arr[i]);//Чтобы выполнить возведение в степень в C++, имеют тип данных дабл, по этому везде они и спользованы а не Float 

    return arr[0];




};
double staples() {//скобки
    double result;
    char bracket;//тоже скобка
    int sign = 1;

    bracket = cin.get();//читывает данные из входного потока данных и ожидает нажатия клавиши

    while (bracket == ' ')// пока не будет равно пробелу, 
        bracket = cin.get();//читывает данные из входного потока данных и ожидает нажатия клавиши

    switch (bracket)
    {
    case '-':
        sign = -1;
    case '+':
        bracket = cin.get();
        break;
    }

    while (bracket == ' ')
        bracket = cin.get();

    if (bracket == '(')// находит скобку выражения 
    {
        result = multiplication();
        bracket = cin.get();

        if (bracket != ')')// если ошибки в напи сании скобок
        {
            cout << "Проверить правильность рассатновки скобок!\a" << endl;
            exit(-1);
        }
    }
    else
    {
        cin.putback(bracket);//тод putback() вставляет символ в поток ввод
        result = total();
    }

    return sign * result;
};
double total() {//итог
    double result = 0.0;
    char digit;
    double k = 10.0;
    int sign = 1;

    digit = cin.get();

    switch (digit)
    {
    case '-':
        sign = -1;
        break;
    default:
        if (digit != '+')
            cin.putback(digit);

        break;
    }

    while (true)
    {
        digit = cin.get();

        while (digit == ' ')
            digit = cin.get();

        if (digit >= '0' && digit <= '9')
            result = result * 10.0 + (digit - '0');
        else
        {
            cin.putback(digit);//тод putback() вставляет символ в поток ввод
            break;
        }
    }

    digit = cin.get();

    if (digit == '.')
    {
        while (true)
        {
            digit = cin.get();

            while (digit == ' ')
                digit = cin.get();

            if (digit >= '0' && digit <= '9')
            {
                result += (digit - '0') / k;
                k *= 10.0;
            }
            else
            {
                cin.putback(digit);// меттод putback() вставляет символ в поток ввод
                break;
            }
        }
    }
    else
        cin.putback(digit);// тод putback() вставляет символ в поток ввод

    return sign * result;

};
using namespace std;
int main()
{
    double n;

    setlocale(LC_ALL, "Rus");//подключение русского языка
    system("color 3F");// цвет 
    cout << "\t Arithmetic calculator! \n"<< endl;// вывод стоки на экран

    cout << "\t+++++++++++++++++++++++++ \n";
    cout << "\tВведите выражение:__ ";

    n = example();// вызов вункции пример 

    cout << setprecision(12) << "\t\tРезультат вычисления:__ " << n << endl;// вывод на экран результат 

    cin.get();
    cin.get();
    
}

//Мы знаем, что в векторе для обращения к ячейке используются индексы.Обычно мы их используем совместно с квадратными скобками[].
//
//Но в C++ есть еще один способ это сделать благодаря функции — at().В скобках мы должны указать индекс той ячейки, к которой нужно обратиться.
//reserve, это функция, с помощью которой мы говорим компилятору, какое количество ячеек нам нужно использовать.
//Но есть еще одни способ добавления векторов в вектор.Для этого способа мы будем использовать функцию push_back()
// информация по вектарам взята из codelessons.ru



