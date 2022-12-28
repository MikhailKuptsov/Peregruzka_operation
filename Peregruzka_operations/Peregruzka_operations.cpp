#include <iostream>
#include <string>

using namespace std;

/*Надо убрать read и display, а вместо них переопределить операции ввода вывода*/

class Fraction {
private:
    long first;
    unsigned short second;

public:
    Fraction() {
        first = 0;
        second = 0;
    }

    Fraction(long f, unsigned short s) {
        first = f;
        second = s;
    }
    //перегрузка операций
    friend ostream& operator<<(ostream& out, Fraction& p) {
        out << "First = " << p.first << endl;
        out << "Second = " << p.second << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& p) {
        in >> p.first;
        in >> p.second;
        return in;
    }

    string toString() {
        string s = to_string(first) + "." + to_string(second);
        return s;
    }


    Fraction operator+(Fraction& a)  // сложение
    {
        double one, two;
        one = a.second;
        two = a.second;
        one += a.first;
        two += a.second;
        int num10 = one.transferTo10() + two.transferTo10();
        cout << "Sum: " << one + two << endl;
        return num10;
    }


    Fraction operator-(Fraction& a)  //разность
    {
        double one, two;
        one = a.second;
        two = a.second;
        one += a.first;
        two += a.second;
        int num10 = one.transferTo10() - two.transferTo10();
        cout << "Sum: " << one - two << endl;
        return num10;
    }


    Fraction operator*(Fraction& a)  //умножение
    {
        double one, two;
        one = a.second;
        two = a.second;
        one += a.first;
        two += a.second;
        int num10 = one.transferTo10() * two.transferTo10();
        cout << "Mul: " << one * two << endl;
        return num10;
    }


    //Равенство
    static void operator==(Fraction a, Fraction b) {
        double one, two;
        one = a.second;
        while (one > 1)
            one /= 10;
        one += a.first;
        two = b.second;
        while (two > 1)
            two /= 10;
        two += b.first;

        if (one == two)
            cout << "одинаковы" << endl;
        else if (one > two)
            cout << "Первое число больше второго" << endl;
        else
            cout << "Второе число больше первого" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Fraction A;
    cout << A;
    cout << "\n";

    Fraction N(5, 2);
    cout << N;
    cout << "Число 1: " << N.toString() << "\n\n";

    Fraction M;
    cin >> M;
    cout << M;
    cout << "Число 2: " << M.toString() << "\n\n";

    A = N + M;
    A = N - M;
    A = N * M;
    if (N == M) {
        cout << "True";
    };
}
