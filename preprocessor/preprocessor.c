#include <preprocessor/preprocessor.h>

void preprocess(std::string* source_file, std::ofstream* destination_ofstream) {

    std::ifstream source_file_ifstream;
    source_file_ifstream.open(*source_file, std::ios::in);

    std::string line;
    while (std::getline(source_file_ifstream, line))
    {
        // Process str
        std::cout << line << std::endl;

        std::string trimmed_line = trim_copy(line);

        if (trimmed_line.rfind(".include", 0) == 0) { // pos = 0 limits the search to the prefix

            // s starts with prefix
            printf(".include found! %s\n", trimmed_line.c_str());

            // std::vector<std::string> x = split_string_by_delimiter(trimmed_line, ' ');
            // int i = 0;
            // for (std::string& temp : x) {
            //     std::cout << i << ") " << temp << std::endl;
            //     i++;
            // }

            std::vector<std::string> word_vector;

            std::size_t prev = 0, pos;
            while ((pos = line.find_first_of(" \t", prev)) != std::string::npos)
            {
                if (pos > prev) {
                    word_vector.push_back(line.substr(prev, pos-prev));
                }
                prev = pos+1;
            }
            if (prev < line.length()) {
                word_vector.push_back(line.substr(prev, std::string::npos));
            }

            std::string included_filename;
            int i = 0;
            for (std::string& temp : word_vector) {

                std::cout << i << ") " << temp << std::endl;
                if (i == 1) {
                    included_filename = temp;
                }

                i++;
            }

            std::cout << "included_filename: " << included_filename << std::endl;

            included_filename = included_filename.substr(1, included_filename.length() - 2);

            preprocess(&included_filename, destination_ofstream);

        } else {

            *destination_ofstream << line << std::endl;

        }


    }

    source_file_ifstream.close();

}