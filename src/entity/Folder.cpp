#include "Folder.h"
#ifndef TESTPROJ
    #include "src/config/logger.h"
#else
    #include "logger.h"
#endif

Folder::Folder(std::string &&name) : a_name(name) {
    LOG_DEBUG("New folder created: " + name);
}
