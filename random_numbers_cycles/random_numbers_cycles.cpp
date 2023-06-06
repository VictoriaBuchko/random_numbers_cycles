#include <iostream>
using namespace std;

int main() {
    cout << "Task 1---------------------------------------------------------------------------------\n";
    //1. Определить, параллельна ли определённая прямая линия оси ординат, либо оси абсцисс.
    //Прямая задаётся двумя точками. прямая задаётся 2 точками, у каждой из которых есть позиция по Х и по У. 
    //то есть, нужно ввести с клавиатуры 4 числа (x1, y1, x2, y2).


    float x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    if (x1 == x2) {
        cout << "The line is parallel to the y-axis\n";
    }
    else if (y1 == y2) {
        cout << "The line is parallel to the x-axis\n";

    }
    else {
        cout << "The line is not parallel to either the x-axis or the y-axis\n";
    }


    cout << "Task 2---------------------------------------------------------------------------------\n";
    //2. Проверить, имеет ли введённое число вещественную часть.
    //Например, числа 3.14 и 2.5 - имеют вещественную часть, а числа 5 и 10 - нет.
    //(пригодится явное преобразование типов).

    float number;

    cout << "Enter a number: ";
    cin >> number;

    if (number != (int)number) {
        cout << "The number has a decimal part\n";
    }
    else {
        cout << "The number does not have a decimal part\n";
    }

    cout << "Task 3---------------------------------------------------------------------------------\n";
    //3. Указать с клавиатуры текущее время (количество часов, минут, секунд).
    //Проверить корректность введённых значений. например, вводится с клавиатуры 3 числа - 18, 47, 15.
    //программа должна сказать, что это время корректное. или например, если ввести 25, 67, -2 программа говорит,
    //что время некорректное.

    int hours, minutes, seconds;

    cout << "Enter the time (hours, minutes, seconds): ";
    cin >> hours >> minutes >> seconds;

    bool rightTime = true;

    if (hours < 0 || hours >= 24) {
        rightTime = false;
    }

    if (minutes < 0 || minutes >= 60) {
        rightTime = false;
    }

    if (seconds < 0 || seconds >= 60) {
        rightTime = false;
    }

    if (rightTime) {
        cout << "Entered time is correct\n";
    }
    else {
        cout << "Entered time is not correct\n";
    }


    cout << "Task 4---------------------------------------------------------------------------------\n";

    //4. Ввести с клавиатуры шестизначный номер трамвайного (троллейбусного) билета,
    //и определить является ли он счастливым (совпадают суммы трёх первых и трёх последних цифр билета).
    //вводить нужно числа от 000000 до 999999.

    int ticketNumber;

    while (true) {
        cout << "Enter a six-digit ticket number (000000-999999): ";
        cin >> ticketNumber;

        if (ticketNumber >= 0 && ticketNumber <= 999999) {
            // Проверяем количество цифр в номере билета

            int digitCount = 0;
            int temp = ticketNumber;

            while (temp > 0) {
                temp /= 10;
                digitCount++;
            }

            if (digitCount == 6) {
                break;
            }
        }
    }

    int digit1 = ticketNumber / 100000;       // Первая цифра
    int digit2 = (ticketNumber / 10000) % 10; // Вторая цифра
    int digit3 = (ticketNumber / 1000) % 10;  // Третья цифра
    int digit4 = (ticketNumber / 100) % 10;   // Четвертая цифра
    int digit5 = (ticketNumber / 10) % 10;    // Пятая цифра
    int digit6 = ticketNumber % 10;           // Шестая цифра

    int sumFirstThreeDigits = digit1 + digit2 + digit3;
    int sumLastThreeDigits = digit4 + digit5 + digit6;

    if (sumFirstThreeDigits == sumLastThreeDigits) {
        cout << "The ticket is a lucky ticket\n";
    }
    else {
        cout << "The ticket is not a lucky ticket\n";
    }

    cout << "Task 5---------------------------------------------------------------------------------\n";
    //5*. Ввести любую дату (день, месяц и год вводятся по отдельности).
    //Проверить корректность введённых значений. Вывести дату следующего дня.


    int year, month, day;
    cout << "Enter day, month, year: \n";
    cin >> day >> month >> year;

    bool rightDate;

    if (year < 0) {//проверка на то что введенный год это положительное число
        rightDate = false;
    }
    else if (month < 1 || month > 12) {//проверка на месяц
        rightDate = false;
    }
    else {
        int daysInMonth;

        switch (month) {
        case 2://2 месяц в зависимости от года имеет разное количество дней 
            
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {// проверка високосного года
                daysInMonth = 29;
            }
            else {
                daysInMonth = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
            break;
        }

        if (day < 1 || day > daysInMonth) {//если было введенно некоректное количество дней, программа выдаст сообщение
            rightDate = false;
        }
        else {
            rightDate = true;
        }
    }

    if (rightDate) {//делаем проверку на вывлд завтрашней даты
        int nextDay = day;
        int nextMonth = month;
        int nextYear = year;

        nextDay++;//добавляем день

        if (nextDay > 31 || (nextDay > 30 && (nextMonth == 4 || nextMonth == 6 || nextMonth == 9 || nextMonth == 11)) || (nextDay > 29 && nextMonth == 2) || (nextDay > 28 && nextMonth == 2)) {
           
            //если количество дней привышает указаное в определенном месяце, то к месяцу добавляеться 1 а дни начинаються с 1
            nextDay = 1;
            nextMonth++;

            if (nextMonth > 12) {
                //если номер месяца обновился и он больше 12, то это означает начало нового года, отсчет месяцев начинаеться с 1
                nextMonth = 1;
                nextYear++;
            }
        }

        cout << "Next day's date is: " << nextDay << " " << nextMonth << " " << nextYear << "\n";
    }
    else {
        cout << "Invalid date\n";
    }

    return 0;
}



