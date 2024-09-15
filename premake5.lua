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
IncludeDir["Glad"] = "SunEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SunEngine/vendor/imgui"
include "SunEngine/vendor/GLFW"
include "SunEngine/vendor/Glad"
include "SunEngine/vendor/imgui"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SUN_PLATFORM_WINDOWS",
            "SUN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "SUN_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SUN_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SUN_DIST"
        buildoptions "/MD"
        optimize "On"