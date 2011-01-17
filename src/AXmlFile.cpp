#include "AXmlFile.hh"

namespace lbmy
{
  namespace xml
  {

    AXmlFile::AXmlFile(std::string const& path) :
      _path(path)
    {
    }

    AXmlFile::~AXmlFile()
    {
    }

    std::string const& AXmlFile::getFullPath() const
    {
      return _path;
    }

    std::string AXmlFile::getPath() const
    {
      return std::string(_path.substr(0, _path.find_last_of('/')));
    }

  } // namespace xml
} // namespace lbmy
