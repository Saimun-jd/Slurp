workspace "Slurp"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to rool path
IncludeDir = {}
IncludeDir["GLFW"] = "Slurp/vendor/GLFW/include"

include "Slurp/vendor/GLFW"


project "Slurp"
    location "Slurp"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Slurp/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/src/Slurp/Platfrom/Windows",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
           "SL_PLATFORM_WINDOWS" ,
           "SL_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "SL_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "SL_RELEASE"
        runtime "Release"
        symbols "On"

    filter "configurations:Dist"
        defines "SL_DIST"
        runtime "Release"
        symbols "On"

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
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Slurp/vendor/spdlog/include",
        "Slurp/src"
    }

    links
    {
        "Slurp"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
           "SL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SL_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "SL_RELEASE"
        runtime "Release"
        symbols "On"

    filter "configurations:Dist"
        defines "SL_DIST"
        runtime "Release"
        symbols "On"
