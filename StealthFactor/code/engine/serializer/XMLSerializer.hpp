#pragma once

#include <string>
#include <pugixml/pugixml.hpp>
#include <engine/serializer/Serializer.hpp>

namespace engine
{
	namespace serializer
	{
		class XMLSerializer : public Serializer
		{
		public:
			XMLSerializer(const std::string& fileName);

			// Inherited via Serializer
			void loadValue(const std::string& valueName, std::string& value) override;
			void loadValue(const std::string& valueName, float& value) override;
			void loadValue(const std::string& valueName, int& value) override;

		private:
			const std::string& _fileName;
			pugi::xml_node _root;
		};
	}
}