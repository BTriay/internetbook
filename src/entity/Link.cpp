#include "Link.h"
#include "src/config/logger.h"

Link::Link(std::string&& name, std::string&& url) : a_name(name), a_url(url) {
    LOG_DEBUG("New link created: " + name + "=" + url);
}

void Link::add_keyword(std::string&& keyword){
    a_keywords.emplace(keyword);
    LOG_DEBUG("Keyword '" + keyword + "' added to the link " + a_name);
}

void Link::remove_keyword(const std::string& keyword){
    auto it = a_keywords.find(keyword);
    if (it != a_keywords.end())
        a_keywords.erase(it);
}

std::string Link::list_keywords() const{ //necessary? probably not the best return type
    std::string result;
    for (auto& k : a_keywords)
        result += k + "; ";
    return result;
}
