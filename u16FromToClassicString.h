#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

std::string u16toClassicString(const std::u16string& internal) {
    // std::locale::global(std::locale("ru_RU.utf8")); // place it in main()

    auto& f = std::use_facet<std::codecvt<char16_t, char, std::mbstate_t>>(std::locale());

    std::mbstate_t mb{}; // initial shift state
    std::string external(internal.size() * f.max_length(), '\0');

    const char16_t* from_next;
    char* to_next;

    f.out(mb, &internal[0], &internal[internal.size()], from_next,
          &external[0], &external[external.size()], to_next);

    external.resize(to_next - &external[0]);

    return external;
}

std::u16string ClassicToU16String(const std::string& external) {
    // std::locale::global(std::locale("ru_RU.utf8")); // place it in main()

    auto& f = std::use_facet<std::codecvt<char16_t, char, std::mbstate_t>>(std::locale());

    std::mbstate_t mb = std::mbstate_t(); // initial shift state
    std::u16string internal(external.size(), '\0');

    const char* from_next;
    char16_t* to_next;

    f.in(mb, &external[0], &external[external.size()], from_next,
         &internal[0], &internal[internal.size()], to_next);

    internal.resize(to_next - &internal[0]);

    return internal;
}

std::ostream& operator<<(std::ostream& out, const std::u16string& u16str) {
    out << u16toClassicString(u16str);
    return out;
}
