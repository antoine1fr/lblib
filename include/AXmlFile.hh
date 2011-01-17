#ifndef AXMLFILE_HH_
# define AXMLFILE_HH_

# include <string>

namespace lbmy
{
  namespace xml
  {
    class AXmlFile
    {
      public:
	typedef enum
	{
	  OK,		///< File opened, no error.
	  NOT_OPENED,	///< File not opened, no error.
	  NOT_FOUND,	///< The file doesn't exist.
	  CANT_OPEN,	///< The file exists but can't be opened.
	  END_OF_FILE	///< File opened, no more data to read.
	} TStatus;

      protected:
	std::string	_path;
	TStatus		_status;

      protected:
	/**
	 * The default constructor.
	 *
	 * It tries to open the file.
	 * @see TStatus
	 *
	 * @param path : the file's path.
	 */
	AXmlFile(std::string const&path = "");

      private:
	/**
	 * Copy constructor.
	 */
	AXmlFile(AXmlFile const& xmlFile);

	/**
	 * Copy operator.
	 */
	AXmlFile const& operator  = (AXmlFile const& xmlFile);

      public:
	/**
	 * Destructor
	 */
	virtual ~AXmlFile();

	/**
	 * @return the full file paths (as it has been given by the user).
	 */
	std::string const&	getFullPath() const;

	/**
	 * @return the file's path without the file's name.
	 */
	std::string		getPath() const;

	/**
	 * Opens the file.
	 *
	 * If the file aleady is opened then it does nothing.
	 * Changes the file's status (@see TStatus).
	 *
	 * @param path : the file's path (if no sent to the default constructor).
	 *
	 * @return the file's status.
	 */
	virtual TStatus		open(std::string const& path) = 0;
    };

  } // namespace xml
} // namespace lbmy

#endif // !AXMLFILE_HH_
