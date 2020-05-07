characterset "Unicode"

cppdialect "C++11"

debugargs {
	"-data",
	"../../../data",
}

defines {
	"dSINGLE",
}

flags {
	"FatalWarnings",
	"MultiProcessorCompile",
	"NoPCH",
}

configurations {
	"Debug",
	"Release",
}

platforms {
	"Linux32",
	"Linux64",
	"Win32",
	"Win64",
}

systemversion "10.0"

warnings "Extra"

filter "configurations:Debug"
	defines {
		"DEBUG",
	}
	runtime "Debug"
	symbols "On"
	targetsuffix "-d"

filter "configurations:Release"
	defines {
		"NDEBUG",
	}
	optimize "On"
	runtime "Release"


filter "platforms:Win*"
	system "Windows"

filter "platforms:Linux*"
	system "Linux"

filter "platforms:*32"
	architecture "x86"

filter "platforms:*64"
	architecture "x64"


workspace "StealthFactor"
	language "C++"
	location "build"
	startproject "Engine"

project "Platform"
	files {
		"code/platform/**",
	}
	includedirs {
		"code",
		"dep/include",
	}
	location "build/platform"
	kind "StaticLib"
	-- rtti "Off"

	filter "platforms:Linux*"
		files {
			"code/platform-linux/**",
		}

	filter "platforms:Linux32"
		targetdir "build/Platform/Linux32"
	filter "platforms:Linux64"
		targetdir "build/Platform/Linux64"


	filter "platforms:Win*"
		files {
			"code/platform-windows/**",
		}
	filter "platforms:Win32"
		targetdir "build/Platform/Win32"
	filter "platforms:Win64"
		targetdir "build/Platform/Win64"





project "Engine"
	files {
		"code/engine/**",
	}
	includedirs {
		"code",
		"dep/include",
	}
	location "build/Engine"
	kind "ConsoleApp"
	-- rtti "Off"

	links {
		"Platform",
	}

	filter "platforms:Linux*"
		links {
			"ode",
			"sfml-graphics",
			"sfml-network",
			"sfml-system",
			"sfml-window",
		}

	filter "platforms:Linux32"
		debugdir "dep/linux/bin32"
		libdirs {
			"dep/linux/lib32",
		}
		targetdir "build/Engine/Linux32"

	filter "platforms:Linux64"
		debugdir "dep/linux/bin64"
		libdirs {
			"dep/linux/lib64",
		}
		targetdir "build/Engine/Linux64"



	filter "platforms:Win*"
		links {
			"winmm",
			"ws2_32",
		}

	filter { "platforms:Win*", "configurations:Debug" }
		links {
			"ode_singled",
			"sfml-graphics-d",
			"sfml-network-d",
			"sfml-system-d",
			"sfml-window-d",
		}

	filter { "platforms:Win*", "configurations:Release" }
		links {
			"ode_single",
			"sfml-graphics",
			"sfml-network",
			"sfml-system",
			"sfml-window",
		}

	filter "platforms:Win32"
		debugdir "dep/windows/bin32"
		libdirs {
			"dep/windows/lib32",
		}
		targetdir "build/Engine/Win32"

	filter "platforms:Win64"
		debugdir "dep/windows/bin64"
		libdirs {
			"dep/windows/lib64",
		}
		targetdir "build/Engine/Win64"
