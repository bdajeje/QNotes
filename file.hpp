#ifndef UTILS_FILE_HPP
#define UTILS_FILE_HPP

#include <string>
#include <vector>

namespace files {

/*! Read a file
 *  \param filepath to access the file
 *  \param result   [out] where to store content of the read file
 *  \return true if everything was ok, false otherwise
 *  \warning the content of the result will be override
 */
std::string read(const std::string& filepath);

}

#endif // UTILS_FILE_HPP
