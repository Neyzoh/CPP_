#include <iostream>
#include <string>

std::string replace(std::string buf, const std::string s1, const std::string s2)
{
    if (s1.empty()) return buf; 

    size_t pos = 0;
    size_t s1_len = s1.length();
    size_t s2_len = s2.length();

    while ((pos = buf.find(s1, pos)) != std::string::npos)
    {
        buf = buf.substr(0, pos) + s2 + buf.substr(pos + s1_len);
        pos += s2_len;
    }
    return buf;
}

int main() 
{
    std::string test = "hello hello world";
    test = replace(test, "hello", "hi");
    std::cout << test << std::endl;
}
