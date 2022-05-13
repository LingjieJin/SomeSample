/**
 * 解释 explicit 关键字
 * 
 * C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的, 
 * 跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式)
 * 
 * 当类的声明和定义分别在两个文件中时，explicit只能写在在声明中，不能写在定义中。
 * 
 * google的c++规范中提到explicit的优点是可以避免不合时宜的类型变换，缺点无。
 * 所以google约定所有单参数的构造函数都必须是显示的，
 * 只有极少数情况下拷贝构造函数可以不声明称explicit。例如作为其他类的透明包装器的类。
 */

class Test1
{
private:
    int n;

public:
    Test1(int num) : n(num) {}
    ~Test1() {}
};

class Test2
{
private:
    int n;

public:
    explicit Test2(int num) : n(num) {}
    ~Test2() {}
};

int main()
{

    Test1 t1 = 12;

    /*  编译无法通过 
        无法从“int”转换为“Test2”
    */
    // Test2 t2 = 13;
    Test2 t2(14);

    return 0;
}
