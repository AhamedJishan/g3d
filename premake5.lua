workspace "g3d"
    configurations {"Debug", "Release"}
    architecture "x86_64"
    startproject "g3d_test"

    outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project "g3d"
    location "g3d"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/include/g3d/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "%{prj.name}/include"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"

project "g3d_test"
    location "test"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "g3d/include"
    }

    links
    {
        "g3d"
    }

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

    filter "configurations:Debug"
        symbols "On"
    
    filter "configurations:Release"
        optimize "On"
