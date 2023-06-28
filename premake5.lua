workspace "PEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "PEngine/vendor/glfw/include"

include "PEngine/vendor/glfw"

project "PEngine"
	location "PEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")
	
	pchheader "ppch.h"
	pchsource "PEngine/src/ppch.cpp"

	files 
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
	}

	links
	{
		"glfw",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines 
		{
			"PE_PLATFORM_WINDOWS",
			"PE_BUILD_DLL",
			"PE_ENABLE_ASSERTS"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PE_RELEASE"
		optimize "On"
		
	filter "configurations:Dis"
		defines "PE_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("intermediate/" .. outputdir .. "/%{prj.name}")
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"PEngine/vendor/spdlog/include",
		"PEngine/src",
	}

	links
	{
		"PEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		defines 
		{
			"PE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PE_RELEASE"
		optimize "On"
