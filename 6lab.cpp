#include <iostream>
#include <exception>

// Перечисление кодов ошибок
enum class ErrorCode
{
    WrongValue,
    TooOld,
    NotBornYet,
    NegativeNumber
};

// Класс собственного исключения
struct MyException : std::exception
{
    static const char* get_message_by_code(ErrorCode code)
    {
        switch (code)
        {
        case ErrorCode::WrongValue: return "Введено некорректное число";
        case ErrorCode::TooOld: return "Слишком старый год рождения";
        case ErrorCode::NotBornYet: return "Вы ещё не родились";
        case ErrorCode::NegativeNumber: return "Отрицательные числа запрещены";
        }
        return "Неизвестная ошибка";
    }

    MyException(ErrorCode code)
        : std::exception(get_message_by_code(code))
    {
    }
};

static void task()
{
    int choice = 0;
    int birthYear = 0;

    try
    {
        std::cout << "Введите число 1, 2 или 3: ";
        std::cin >> choice;

        if (choice < 1 || choice > 3)
            throw MyException(ErrorCode::WrongValue);

        switch (choice)
        {
        case 1: std::cout << "Один\n"; break;
        case 2: std::cout << "Два\n"; break;
        case 3: std::cout << "Три\n"; break;
        }

        std::cout << "Введите год вашего рождения: ";
        std::cin >> birthYear;

        if (birthYear < 0)
            throw MyException(ErrorCode::NegativeNumber);
        else if (birthYear > 2025)
            throw MyException(ErrorCode::NotBornYet);
        else if (birthYear < 1850)
            throw MyException(ErrorCode::TooOld);

        std::cout << "Спасибо!" << std::endl;
    }
    catch (const MyException& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

int main()
{
    std::setlocale(LC_ALL, "Russian");

    task();
}
