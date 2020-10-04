#ifndef FOLDER_HEADER
#define FOLDER_HEADER

#include <string>
#include <unordered_set>
#include <map>

class Folder {
    std::string a_name;
    std::unordered_set<std::string> a_keywords;
    std::map<int, Folder*> a_folders;

public:
    Folder(std::string&& name);

    //duplicated code from Link; put in separate class, contained by Link/Folder?
//    void AddKeyword(std::string&& keyword); //todo: review universal references...
//    void RemoveKeyword(const std::string& keyword);
//    std::string ListKeywords() const;

};


#endif
