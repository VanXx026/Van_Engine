workspace "Van_Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Van_Engine"
	location "Van_Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VAN_PLATFORM_WINDOWS",
			"VAN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VAN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VAN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Van_Engine/vendor/spdlog/include",
		"Van_Engine/src"
	}

	links
	{
		"Van_Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"VAN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VAN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "VAN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "VAN_DIST"
		optimize "On"