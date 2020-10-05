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
    std::string name() const { return a_name; }
    std::string url() const { return a_url; }

    //duplicated code from Link; put in separate class, contained by Link/Folder?
    void add_keyword(std::string&& keyword); //todo: review universal references...
    void remove_keyword(const std::string& keyword);
    std::string list_keywords() const;

};


#endif
