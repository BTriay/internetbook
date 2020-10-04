#ifndef LINK_HEADER
#define LINK_HEADER

#include <string>
#include <unordered_set>

class Link {
    std::string a_name;
    std::string a_url;
    std::unordered_set<std::string> a_keywords;

public:
    Link(std::string&& name, std::string&& url);

    void AddKeyword(std::string&& keyword); //todo: review universal references...
    void RemoveKeyword(const std::string& keyword);
    std::string ListKeywords() const;

};


#endif
