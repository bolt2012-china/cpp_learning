//
// Created by bolt on 25-1-19.
//
/*
 *static cast
 *static_cast<目标类型>(被转对象)
 */

//相应的，也可以转换引用类型，将基类引用转换为派生类引用
#include <iostream>
/*
class Base {
public:
    virtual ~Base() = default; // 基类必须具有虚函数
};

class Derived : public Base {
public:
    void show() {
        std::cout << "Derived class method" << std::endl;
    }
};

int main() {
    Base* ptr_base = new Derived; // 基类指针指向派生类对象

    // 将基类指针转换为派生类指针
    Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base);

    if (ptr_derived) {
        ptr_derived->show(); // 成功转换，调用派生类方法
    } else {
        std::cout << "Dynamic cast failed!" << std::endl;
    }

    delete ptr_base;
    return 0;
}
*/
/*这是一个把常量转换为非const的例子
int main() {
    const int i = 10;
    int r = const_cast<int&>(i);    //这里要打&
    std::cout << r << std::endl;
}
*/

/*这是reinterpret_cast,用于同一对象的类型转换
*/
int main() {
    float f = 3.1;
    int i = reinterpret_cast<int&>(f);  //访问地址
    //注意reinterpret是一种非常低级的方式，它只是通过访问对应的地址来找那块地址对应的某种类型的对象，一般不会输出预期结果
    //可以使用static_cast
    int t = static_cast<int>(f);
    std::cout << "i = " << i << std::endl;
    std::cout << "t = " << t << std::endl;
    return 0;
}