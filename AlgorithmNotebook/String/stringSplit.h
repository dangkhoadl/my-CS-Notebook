

// Example: 
// 		split_("abc,def,ghi", ',') = vector<string> {"abc", "def", "ghi"}

template<typename Out>
void split_(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}
std::vector<std::string> split_(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split_(s, delim, std::back_inserter(elems));
    return elems;
}
