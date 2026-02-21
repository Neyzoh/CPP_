#include <iostream>
#include <string>
#include <fstream>

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

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Invalid number of argument." << std::endl;
        return 1;
    }

    std::ifstream filestream(av[1]);
    if (!filestream)
    {
        std::cerr << "Couldn't open infile." << std::endl;
        return 1;
    }

    std::string file = std::string(av[1]) + ".replace";
    std::ofstream outstream(file.c_str());
    if (!outstream)
    {
        std::cerr << "Couldn't open outfile." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(filestream, line))
    {
        outstream << replace(line, av[2], av[3]);
        if (!filestream.eof())
            outstream << std::endl;
    }

    filestream.close();
    outstream.close();

    return 0;
}