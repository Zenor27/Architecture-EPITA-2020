#include "XMLSerializer.hpp"

#include <iostream>

namespace engine
{
	namespace serializer
	{
		XMLSerializer::XMLSerializer(const std::string& fileName)
			: _fileName(fileName)
		{
			pugi::xml_document document;
			auto isLoaded = document.load_file(fileName.c_str());
			if (isLoaded)
			{
				_root = document.first_child();
			}
			else
			{
				std::cerr << "Error while loading: " << fileName;
			}

		}

		void XMLSerializer::loadValue(const std::string& valueName, std::string& value)
		{
			value = _root.child_value(valueName.c_str());
		}

		void XMLSerializer::loadValue(const std::string& valueName, float& value)
		{
			value = std::stof(_root.child_value(valueName.c_str()));
		}
		void XMLSerializer::loadValue(const std::string& valueName, int& value)
		{
			value = std::stoi(_root.child_value(valueName.c_str()));
		}
	}
}

