/*Создать стек для символов.Максимальный размер стека вводится с экрана.
Создать функции для ввода, вывода и определения размера стека.
Вводить символы с экрана в стек.
В случае совпадения вводимого символа с вершиной стека  вывести размер стека.*/

#include <iostream>
#include <windows.h>
#include <locale>

using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int maxSize;
public:
    Stack(int size) {
        maxSize = size;
        arr = new char[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top == maxSize - 1) {
            cout << "Стек переполнен\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Стек пуст. Невозможно извлечь символ\n";
            return '\0';
        }
        char popped = arr[top--];
        cout << "Извлеченный символ: " << popped << endl;
        return popped;
    }

    int getSize() {
        return top + 1;
    }

    char peek() {
        if (top == -1) {
            cout << "Стек пуст. Невозможно просмотреть верхний символ\n";
            return '\0';
        }
        cout << "Верхний символ стека: " << arr[top] << endl;
        return arr[top];
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Rus");

    int maxSize;
    cout << "Введите максимальный размер стека: ";
    cin >> maxSize;

    Stack stack(maxSize);

    int choice;
    char symbol;
    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Ввести символ в стек\n";
        cout << "2. Вывести размер стека\n";
        cout << "3. Извлечь символ из стека\n";
        cout << "4. Посмотреть верхний символ стека\n";
        cout << "5. Выйти\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите символ: ";
            cin >> symbol;
            stack.push(symbol);
            break;
        case 2:
            cout << "Размер стека: " << stack.getSize() << endl;
            break;
        case 3:
            stack.pop();
            break;
        case 4:
            stack.peek();
            break;
        case 5:
            cout << "Выход из программы\n";
            return 0;
        default:
            cout << "Некорректный ввод\n";
        }
    }

    return 0;
}