#ifndef STRUCT_DATA
#define STRUCT_DATA
#include <iostream>
#include <cstring>

template<typename Type>
class MyVector{
    size_t maxSize;
    size_t size;
    Type *pData;
public:

    /**
     * @brief Конструктор для создания объекта класса
     * @param mS Изначальная максимальныя длина 
     */
    MyVector(size_t mS = 1) : maxSize(mS), size(0) {
        pData = new Type[maxSize];
    }


    /**
     * @brief Деструктор объекта класса
     */
    ~MyVector(){
        static int i = 1;
        std::cout << i << std::endl;
        delete [] pData;
    }

    /**
     * @brief конструктор копирования
     * @param obj Объект класса с которого будем копировать
     */
    MyVector(const MyVector<Type> & obj) : maxSize(obj.maxSize), size(obj.size) {
        if (std::is_same<Type, char*>::value){
            pData = new char*[size];
            for (int i = 0; i < size; i++) {
                pData[i] = new char [strlen(obj.pData[i]) + 1];
                strcpy(pData[i], obj.pData[i]);
            }
            return;
        } else {
            pData = new Type[size];
            for (int i = 0; i < size; i++ ) { pData[i] = obj.pData[i]; }
        }
    }

    /**
     * @brief Добавление элемента в массив
     * @param arg Параметр добавления
     * @return Возвращает добавилься или не добавился параметр
     */
    virtual bool add_element(Type arg){
        if (size+1 >= maxSize)
            if (!resize(true))
                return false;
        if (std::is_same<Type, char*>::value){
            pData[size] = new char[strlen(arg) + 1];
            strcpy(pData[size], arg);
            size++;
            return true;
        }
        pData[size] = arg;
        size++;
        return true;
    }

    /**
     * @brief Удаление аргумента из массива
     * @param el Парамент, который удаляем
     * @return Удалился или нет параметр
     */
    virtual bool delete_element(Type el){
        int idx = find(el);
        if (idx == -1){
            std::cerr << "нет элемента в массиве" << std::endl;
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (i>=idx) pData[i] = pData[i+1];
        }

        if (size-1 < maxSize/4 )
            if (!resize(false))
                return false;
        size--;
        return true;
    }

    /**
     * @brief Изменение размера массива
     * @param flg Параметр для понимания уменьшать или увеличивать длину
     * @return Получилось ли измннить длину
     */
    bool resize(bool flg){
        if (flg)
            maxSize*=2;
        else
            maxSize/=2;
        Type* temp = new Type[maxSize];
        if (temp == nullptr){
            std::cerr << "Memory error" << std::endl;
            return false;
        }
        for (int i = 0; i < size; i++ ){ temp[i] = pData[i]; }
        delete [] pData;
        pData = temp;
        return true;
    }

    /**
     * @brief Нахождение елемнта в масисиве
     * @param el Аргумент, который нужно найти
     * @return индекс по каторому находится элемент
     */
    int find(Type el) const {
        if (std::is_same<Type, char*>::value){
            for (int i = 0; i < size; i++){
                if (std::strcmp(pData[i], el) == 0)
                    return i;
            }
            return -1;
        }
        for (int i = 0; i < size; i++){
            if (pData[i] == el)
                return i;
        }
        return -1;
    }

    /**
     * @brief Вывод массива
     */
    void print() const {
        std::cout << '{';
        for (int i = 0; i < size; i++){
            std::cout << ' ' << pData[i] << ' ';
        }
        std::cout << '}' << std::endl;
    }
    size_t getMS() const {return maxSize;}
    size_t getS() const {return size;}
};



#endif // STRUCT_DATA