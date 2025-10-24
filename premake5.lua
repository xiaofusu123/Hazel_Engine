workspace "Hazel"
	architecture "x64"
    startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "hazel/vendor/GLFW/include"
IncludeDir["Glad"] = "hazel/vendor/Glad/include"
IncludeDir["Imgui"] = "hazel/vendor/imgui"

include "hazel/vendor/GLFW"
include "hazel/vendor/Glad"
include "hazel/vendor/imgui"

project "Hazel"
	location "hazel"
	kind "SharedLib"
	language "C++"
    staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "%{prj.name}/src/hzpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.Imgui}"
	}
    
    links
    {
        "GLFW",
        "Glad",
        "Imgui",
        "opengl32.lib"
    }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"HZ_BUILD_DLL",
			"UNICODE",
            "_UNICODE"
		}

		postbuildcommands
		{
            "if not exist \"../bin/" .. outputdir .. "/Sandbox\" mkdir \"../bin/" .. outputdir .. "/Sandbox\"",
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
        runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
        runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
    staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"hazel/vendor/spdlog/include",
		"hazel/src"
	}

	links
	{
		"hazel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		buildoptions { "/utf-8" }

		defines
		{
			"HZ_PLATFORM_WINDOWS",
			"UNICODE",
            "_UNICODE"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
        runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HZ_RELEASE"
        runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HZ_DIST"
        runtime "Release"
		optimize "On"