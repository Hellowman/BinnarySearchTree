#include "../include/BinarySearchTree.h"
#include <string>
#include <fstream>


int main()
{
    BinarySearchTree<int> test1{3,5,8,12,90,54};
    BinarySearchTree<std::string> test2{"a","z","v","go"};
    BinarySearchTree<double> test3{0.73,8.56,0.644,8.5};

    std::ofstream out("D:\\test.txt");
    out << test2;
    out.close();
    BinarySearchTree<int>* test4 = new BinarySearchTree<int>();
    std::ifstream in("D:\\int.txt");
    in >> *test4;
    in.close();
    std::cout << test1.size() << std::endl;
    std::string p="g";
    std::cout << test2.find(p)<< std::endl;// если 0 - nullptr else -find
    return 0;
}
