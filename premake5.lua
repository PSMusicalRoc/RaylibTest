workspace "RaylibTest"
    configurations {"Debug", "Release"}


project "RayGame"
    kind "ConsoleApp"
    targetdir "bin"

    prebuildcommands {
        "cd include/vendor/raylib/src && make",
        "cp include/vendor/raylib/src/libraylib.a libs"
    }

    files {
        "src/**.cpp",
        "include/**.h"
    }

    includedirs {
        "include/roc",
        "include/vendor/raylib/src"
    }

    libdirs {
        "libs"
    }
    links {
        "raylib",
        "opengl32",
        "gdi32",
        "winmm"
    }


    filter "configurations:Debug"
        defines {"ROC_DEBUG"}
        symbols "On"
    
    filter "configurations:Release"
        kind "WindowedApp"
        defines {"ROC_RELEASE"}
        optimize "On"
