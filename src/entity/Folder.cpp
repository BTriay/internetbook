#include "Folder.h"
#include "src/config/logger.h"

Folder::Folder(std::string &&name) : a_name(name) {
    LOG_DEBUG("New folder created: " + name);
}
