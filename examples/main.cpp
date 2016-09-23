#include <iostream>
#include <cstring> //для size_t
#include <fstream>
#include "../include/BinarySearchTree.h"

template <typename T>
void print(std::ostream& out, BinarySearchTree<T>& tree, std::string name){
    out << name << ": ";
    if (tree.empty())
        out << "is empty.\n";
    else
        out << tree << "\n";
    return;
}

int main() {
    auto a = {5, 3, 1, 2, 4}; //a - std::initializer_list<int>]
    BinarySearchTree<int> b(a);

    if(b.find(5))
        std::cout << "such value as 6 was found." << std::endl;
    if(b.find(8))
        std::cout << "such value as 7 was found." << std::endl; //такое значение как 7 не найдено.

    print(std::cout, b, "b");
    if (b.insert(4))
        std::cout << "3 was inserted" << std::endl; //не выводит, тк элемент 3 уже есть
    if (b.insert(10))
        std::cout << "10 was inserted" << std::endl;
    print(std::cout, b, "b");

    BinarySearchTree<int> bin;
    std::cout << "input bin: ";
    std::cin >> bin; //проверка потокового ввода

    print(std::cout, bin, "bin");

    std::fstream f(" ", std::ios::out); //открываем и очищаем файл
    if (!f.is_open())
    { std::cout << "can't open the file" << std::endl; return 0; }
    print(f, bin, "");

    BinarySearchTree<int> bout;
    f.close();
    f.open(" ", std::ios::in);
    f.seekg(0, std::ios::beg);
    f >> bout; //прoверка файлового ввода
    std::cout << "read from file: "; // bout; //просмотр того, что считалось из файла
    print(std::cout, bout, "bout");

    auto list = {2, 1, 4, 5, 3};
    auto newList = {9, 8, 7, 6, 5};
    BinarySearchTree<int> b1(list);
    print(std::cout, b1, "b1 before moving");//конструктор перемещения
    BinarySearchTree<int> b2(std::move(b1)); //конструктор перемещения
    print(std::cout, b2, "b2 after move c-tor");//конструктор перемещения
    print(std::cout, b1, "b1 after moving");//конструктор перемещения

    BinarySearchTree<int> bst(newList);
    print(std::cout, bst, "bst");
    b2 = std::move(bst); //оператор перемещения
    print(std::cout, bst, "bst after moving to b2 by move=");
    print(std::cout, b2, "b2");

    BinarySearchTree<int> c(newList);
    print(std::cout, c, "c");
    BinarySearchTree<int> newC(a);
    print(std::cout, newC, "newC");
    newC = c;
    print(std::cout, newC, "newC (after copy= of c)");//вывод на экран

    BinarySearchTree<int> newnewC(newC);
    print(std::cout, newnewC, "newnewC (after move c-tor)");

    if (c == newnewC)
        std::cout << "c == newnewC" << std::endl;
    else
        std::cout << "c != newnewC" << std::endl;

    if (b == c)
        std::cout << "b == c" << std::endl;
    else
        std::cout << "b != c" << std::endl; return (0);
}
