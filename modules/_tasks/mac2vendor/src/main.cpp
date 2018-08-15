#include "pch.h"

/* Parses mac-l.txt (from assets folder) file in order to lookup Vendor by MAC-address */

typedef std::vector<_tstring> RawBoxType;
typedef std::vector<std::pair<_tstring, _tstring>> BoxType;
void _tmain(int argc, TCHAR* argv[])
{
	try
	{
		//! Read source file.
		boost::filesystem::path sourceFilePath(argv[0]);
		sourceFilePath.remove_filename();
		sourceFilePath /= _T("ma-l.txt");
		if (!boost::filesystem::exists(sourceFilePath))
			throw std::runtime_error("Source file does not exist. Copy it from assets folder");

		_tifstream sourceFile;
		sourceFile.open(sourceFilePath.wstring().c_str(), _tifstream::in);
		if (sourceFile.fail())
			throw std::runtime_error("Unable to open source file");

		_tstring text;
		_tstring base16(_T("(base 16)"));
		RawBoxType rawBox;
		while (std::getline(sourceFile, text))
		{
			std::size_t found = text.find(base16);
			if (found != std::string::npos)
				rawBox.push_back(text);
		}
		sourceFile.close();
		_tcout << rawBox.size() << " entries have been found"  << std::endl;

		//! Split mac and vendor.
		BoxType box;
		for (const RawBoxType::value_type& val : rawBox)
		{
			//! Copy mac.
			std::size_t macPos = val.find_first_of(_T(" "));
			if (macPos == std::string::npos)
			{
				_tcerr << "Unable to locate space in: " << val << std::endl;
				continue;
			}
			_tstring mac;
			_tstring::size_type macSize = macPos;
			mac.resize(macSize);
			std::size_t macCopied = val.copy(&mac[0], macSize, 0);
			mac[macCopied] = _T('\0');

			//! Copy vendor.
			std::size_t vendorPos = val.find_last_of(_T("\t"));
			if (vendorPos == std::string::npos)
			{
				_tcerr << "Unable to locate tab in" << val << std::endl;
				continue;
			}
			_tstring vendor;
			_tstring::size_type vendorSize = (val.size() - 1) - vendorPos;
			vendor.resize(vendorSize);
			std::size_t vendorCopied = val.copy(&vendor[0], vendorSize, vendorPos + 1);
			vendor[vendorCopied] = _T('\0');

			box.push_back(std::make_pair(mac, vendor));
		}
		_tcout << box.size() << " pairs have been found" << std::endl;

		//! Write to result file.
		boost::filesystem::path resultFilePath(argv[0]);
		resultFilePath.remove_filename();
		resultFilePath /= _T("macData.txt");
		_tofstream resultFile;
		resultFile.open(resultFilePath.wstring().c_str(), _tofstream::out);
		if (resultFile.fail())
			throw std::runtime_error("Unable to open result file");

		for (const BoxType::value_type& val : box)
		{
			resultFile << boost::uuids::to_wstring(boost::uuids::random_generator()());
			resultFile << _T("\t") << val.first;
			resultFile << _T("\t") << val.second << std::endl;
		}
		_tcout << box.size() << " entries have been written to result file" << std::endl;
		_tcout << "See bin directory" << std::endl;
	}
	catch (const std::exception& e)
	{
		_tcerr << "Error occurred: " << e.what() << std::endl;
	}
}