#include "structData/structData.h"

int main(int argc, char* argv[]){
    MyVector<char*> vector;
    vector.add_element("hy");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl;
    vector.add_element("ey");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl;
    vector.add_element("ly");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl;
    vector.add_element("ly");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl;
    vector.add_element("oy");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl;
    vector.print();
    std::cout << vector.find("ly") << std::endl;
    vector.delete_element("5y");
    std::cout << vector.getS() << " " << vector.getMS() << std::endl; 
    MyVector<char*>vector2(vector);
    vector2.print();
    vector2.add_element("4y");
    vector2.print();

    return 0;
}
