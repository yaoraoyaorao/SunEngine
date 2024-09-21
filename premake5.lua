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
IncludeDir["glm"] = "SunEngine/vendor/glm"
IncludeDir["stb_image"] = "SunEngine/vendor/stb_image"

include "SunEngine/vendor/GLFW"
include "SunEngine/vendor/Glad"
include "SunEngine/vendor/imgui"

project "SunEngine"
    location "SunEngine"
    kind "StaticLib"
    language "C++"
    staticruntime "on"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sunpch.h"
    pchsource "SunEngine/src/sunpch.cpp"

    files
    {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp",
       "%{prj.name}/vendor/stb_image/**.h",
       "%{prj.name}/vendor/stb_image/**.cpp",
       "%{prj.name}/vendor/glm/glm/**.hpp",
       "%{prj.name}/vendor/glm/glm/**.inl",
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs 
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.stb_image}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SUN_PLATFORM_WINDOWS",
            "SUN_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "SUN_ENABLE_ASSERTS"
        }

    filter "configurations:Debug"
        defines "SUN_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "SUN_DIST"
        runtime "Release"
        optimize "on"

project "SandBox"
    location "SandBox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"


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
        "SunEngine/src",
        "SunEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
	{
		"SunEngine"
	}

    filter "system:windows"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SUN_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "SUN_DEBUG"
        symbols "on"

    filter "configurations:Release"
        defines "SUN_RELEASE"
        optimize "on"

    filter "configurations:Dist"
        defines "SUN_DIST"
        optimize "on"