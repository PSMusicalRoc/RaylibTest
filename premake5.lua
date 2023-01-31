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
        "include/**.h",
        "include/vendor/imgui/*.cpp",
        "include/vendor/imgui/misc/cpp/imgui_stdlib*"
    }

    removefiles {
        "include/vendor/imgui/backends/*"
    }

    files {
        "include/vendor/imgui/backends/imgui_impl_opengl3*",
        "include/vendor/imgui/backends/imgui_impl_glfw*",
    }

    includedirs {
        "include/roc",
        "include/vendor/raylib/src",
        "include/vendor/raygui/src",
        "include/vendor/imgui",
        "include/vendor/imgui/backends",
        "include/vendor/imgui/misc/cpp/"
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

    defines { "RAYGUI_IMPLEMENTATION" }


    filter "configurations:Debug"
        defines {"ROC_DEBUG"}
        symbols "On"
    
    filter "configurations:Release"
        kind "WindowedApp"
        defines {"ROC_RELEASE"}
        optimize "On"
