workspace "SunEngine"
    
    architecture "x64"
    
    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "SunEngine/vendor/GLFW/include"

include "SunEngine/vendor/GLFW"

project "SunEngine"
    location "SunEngine"
    kind "SharedLib"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sunpch.h"
    pchsource "SunEngine/src/sunpch.cpp"

    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SUN_PLATFORM_WINDOWS",
            "SUN_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "SUN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SUN_DIST"
        optimize "On"

project "SandBox"
    location "SandBox"
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
        "SunEngine/vendor/spdlog/include",
        "SunEngine/src"
    }

    links
	{
		"SunEngine"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SUN_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SUN_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SUN_DIST"
        optimize "On"