#include <iostream>
#include <cli.hpp>
#include <engine/Engine.hpp>
#include <platform/platform.hpp>

int main(int argc, const char **argv)
{
	cli::Parser parser(argc, argv);

	parser.help()
		<< R"(Stealth Factor)";

	auto dataPath = parser.option("data")
		.description("Path to data directory")
		.defaultValue("data")
		.getValue();

	platform::Platform currentPlatform;

	if (!currentPlatform.setWorkingDirectory(dataPath))
	{
		std::cerr << "Error while set working directory\n";
		return -1;
	}

	engine::Engine::getInstance().loadConfiguration();
	engine::Engine::getInstance().run();

	return 0;
}
