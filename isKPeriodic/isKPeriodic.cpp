#include <iostream>
#include <string>

bool IsKPeriodic(std::string const& str, int k)
{
    if (str.size() < k)  // Если размер строки меньше размера подстроки
        return false;
    if (str.size() == k)  // Если размер строки равен размеру подстроки
        return true;
    if (str.size() % k != 0)  // Если размер строки НЕ делится на размер подстроки без остатка
        return false;
    // Если мы дошли до этой строчки программы, то точно известно, что длина строки больше длины одной подстроки,
    // а также мы точно знаем, что длина строки кратна размеру подстроки. Дальше нужно 
    // проверить являются ли все куски строки одинаковыми.
    std::string const sub = str.substr(0, k);
    for (auto i = 0; i < str.size(); i += k)
        // Если хотябы одна часть строки не равна, то возвращаем false.
        if (str.substr(i, k) != sub)
            return false;
    // Если дошли сюда значит все части строки одинаковые.
    return true;
}

int main()
{
    std::cout
        << IsKPeriodic("abcabcabcabc", 3) << std::endl  // true
        << IsKPeriodic("dsvnfdsjkfbs", 3) << std::endl  // false
        << IsKPeriodic("xyxy", 2) << std::endl  // true
        << IsKPeriodic("xyxy", 3) << std::endl  // false
        << IsKPeriodic("kkkkkkkkk", 9) << std::endl  // true
        << IsKPeriodic("abc", 3) << std::endl  // true
        << IsKPeriodic("DFG ", 2) << std::endl  // false
        << IsKPeriodic("dfg", 5) << std::endl;  // false
    return 0;
}
