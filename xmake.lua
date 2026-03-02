set_targetdir("./build")
add_rules("mode.debug", "mode.release")
set_languages("c++23")

-- 设置debug模式的编译选项
if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
    add_cxflags("-g3", "-O0", "-ldl")
    add_mxflags("-g3", "-O0", "-ldl")
end

-- 设置release模式的编译选项
if is_mode("release") then
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
    add_cxflags("-O2", "-DNDEBUG", "-ldl")
    add_mxflags("-O2", "-DNDEBUG", "-ldl")
end

includes("lib/testkit")

target("crepl")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("test/*.cpp")
    add_deps("testkit")
    add_includedirs("./include",{public = true})