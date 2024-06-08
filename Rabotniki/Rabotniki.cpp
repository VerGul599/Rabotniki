#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

class Worker
{
private:
    std::string name;
    std::string surname;
    int experience;
    double hourlyWage;
    int hoursWorked;

public:
    Worker(std::string n, std::string s, int e, double hw, int h)
    {
        name = n;
        surname = s;
        experience = e;
        hourlyWage = hw;
        hoursWorked = h;
    }

    double calculateSalary()
    {
        double salary = hourlyWage * hoursWorked;
        double bonus = calculateBonus();
        return salary + bonus;
    }

    double calculateBonus()
    {
        double bonus = 0;
        if (experience < 1)
        {
            bonus = 0;
        }
        else if (experience < 3)
        {
            bonus = 0.05 * hourlyWage * hoursWorked;
        }
        else if (experience < 5)
        {
            bonus = 0.08 * hourlyWage * hoursWorked;
        }
        else
        {
            bonus = 0.15 * hourlyWage * hoursWorked;
        }
        return bonus;
    }

    void displayInfo()
    {
        std::cout << "ФИ: " << name << " " << surname << "\n";
        std::cout << "Опыт: " << experience << " лет" << "\n";
        std::cout << "Почасовая оплата: " << hourlyWage << "\n";
        std::cout << "Отработано часов: " << hoursWorked << "\n";
        std::cout << "Зарплата: " << calculateSalary() << "\n";
        std::cout << "Премия: " << calculateBonus() << "\n";
    }

    void writeToFile()
    {
        std::ofstream file("workers.txt", std::ios::app);
        if (file.is_open())
        {
            file << name << " " << surname << " " << experience << " " << hourlyWage << " " << hoursWorked;
            file.close();
        }
        else
        {
            std::cout << "Невозможно открыть";
        }
    }
};

void readFromFile()
{
    std::ifstream file("workers.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::cout << line;
        }
        file.close();
    }
    else
    {
        std::cout << "Невозможно открыть";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Worker worker1("Вероника", "Гуляева", 1, 125.0, 45);
    Worker worker2("Фарит", "Мулагалиев", 9, 200.0, 100);
    Worker worker3("Юлия", "Сбоева", 1, 130.0, 70);

    worker1.writeToFile();
    worker2.writeToFile();
    worker3.writeToFile();

    worker1.displayInfo();
    std::cout << "\n";
    worker2.displayInfo();
    std::cout << "\n";
    worker3.displayInfo();


    return 0;
}