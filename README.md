# u16stringConverter

This header file realize two functions for easy convertion from/to u16string/string.

The code is based on examples on https://en.cppreference.com/w/cpp/locale/codecvt/in and https://en.cppreference.com/w/cpp/locale/codecvt/out

You may test it with an example:

```
int main() {
    std::locale::global(std::locale("ru_RU.utf8")); // choose here your locale

    std::string cstr = "ПРИВЕТ";
    std::u16string str = ClassicToU16String(cstr);
    str[1] = std::towlower(str[1]);

    std::u16string wstr = u"ПОКА";
    wstr[2] = std::towlower(wstr[2]);

    std::cout << str << " и " << wstr << std::endl;
}
```
