#include "gtest/gtest.h"
#include "tset.h"

//void prime_numbers()
//{
//    int n, m, k, count;
//
//    setlocale(LC_ALL, "Russian");
//    std::cout << "Тестирование программ поддержки множества\n";
//    std::cout << "              Решето Эратосфена\n";
//    std::cout << "Введите верхнюю границу целых значений - ";
//    cin  >> n;
//    TSet s(n + 1);
//    // заполнение множества
//    for (m = 2; m <= n; m++)
//        s.InsElem(m);
//    // проверка до sqrt(n) и удаление кратных
//    for (m = 2; m * m <= n; m++)
//        // если м в s, удаление кратных
//        if (s.IsMember(m))
//            for (k = 2 * m; k <= n; k += m)
//                if (s.IsMember(k))
//                    s.DelElem(k);
//    // оставшиеся в s элементы - простые числа
//    std::cout << "\nПечать множества некратных чисел\n" << s << "\n";
//    cout << endl << "Печать простых чисел" << endl;
//    count = 0;
//    k = 1;
//    for (m = 2; m <= n; m++)
//        if (s.IsMember(m))
//        {
//            count++;
//            cout << setw(3) << m << " ";
//            if (k++ % 10 == 0)
//                cout << endl;
//        }
//    cout << endl;
//    cout << "В первых " << n << " числах " << count << " простых" << endl;
//}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}