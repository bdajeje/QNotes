#include "file.hpp"

#include <iostream>
#include <fstream>
#include "exception.hpp"

namespace files {

std::string read( const std::string& filepath )
{
  std::ifstream file(filepath.c_str());
  if( !file.is_open() )
	throw utils::Exception("Cannot read file: " + filepath);

  // Get length of file
  file.seekg(0, file.end);
  const int length = file.tellg();
  file.seekg(0, file.beg);

  // If file content is empty, exit
  if( length < 1 )
	return {};

  // Read the file
  std::string result;
  result.resize( length );
  file.read(&result[0], length);

  // Close the file and return good read
  file.close();

  return result;
}

} // namespace files

