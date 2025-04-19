cmake_minimum_required(VERSION 3.5)  

# 设置项目名称  
project(Alogrithm)  

# 设置C++标准  
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  

# 启用文件夹组织（在IDE中如Visual Studio分组显示）  
set_property(GLOBAL PROPERTY USE_FOLDERS ON)  

# 获取当前目录下的所有分类目录（一级子目录）  
file(GLOB category_dirs RELATIVE ${CMAKE_SOURCE_DIR} "*")  
list(REMOVE_ITEM category_dirs "CMakeFiles")  # 排除CMake生成目录  

# 遍历每个分类目录  
foreach(category_dir ${category_dirs})  
    # 检查是否是目录  
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${category_dir})  
        # 查找该分类目录下的common目录（如果存在）  
        set(common_dir "${CMAKE_SOURCE_DIR}/${category_dir}/Common")  
        set(common_include_path "")
        set(common_code_files "")
        
        if(IS_DIRECTORY ${common_dir})  
            set(common_include_path ${common_dir})
            file(GLOB common_code_files ${common_dir}/*.h ${common_dir}/*.cpp)
        endif()

        # 获取该分类目录下的所有项目目录（排除common目录）  
        file(GLOB project_dirs RELATIVE ${CMAKE_SOURCE_DIR}/${category_dir}   
            "${CMAKE_SOURCE_DIR}/${category_dir}/*")  
        
        # 遍历每个项目目录  
        foreach(project_dir ${project_dirs})  
            # 获取完整路径并检查是否是目录（且不是common目录）  
            get_filename_component(project_name ${project_dir} NAME)  
            set(full_project_dir "${CMAKE_SOURCE_DIR}/${category_dir}/${project_name}")  
            set(project_folder_path "Source/${category_dir}/${project_name}")  
            
            if(IS_DIRECTORY ${full_project_dir} AND NOT ${project_name} STREQUAL "Common")  
                # 查找该项目的所有源文件  
                file(GLOB sources   
                    ${common_code_files}
                    ${full_project_dir}/*.cpp  
                    ${full_project_dir}/*.c  
                    ${full_project_dir}/*.cc  
                    ${full_project_dir}/*.cxx  
                    ${full_project_dir}/*.h  
                    ${full_project_dir}/*.hpp  
                )  
                
                # 如果有源文件，则创建可执行目标  
                if(sources)  
                    # 创建可执行文件（名称格式：分类_项目）  
                    set(target_name "${project_name}")  
                    add_executable(${target_name} ${sources})  
                    
                    # 设置property folder（IDE中的分组）  
                    set_target_properties(${target_name} PROPERTIES   
                        FOLDER "${project_folder_path}"  
                    )  
                    
                    # 添加common目录到包含路径（如果存在）  
                    if(common_include_path)  
                        target_include_directories(${target_name} PRIVATE ${common_include_path})  
                    endif()  
                    
                    # 添加项目自身目录到包含路径  
                    target_include_directories(${target_name} PRIVATE ${full_project_dir})  
                    
                    message(STATUS "Added target: ${target_name} (Folder: ${category_dir})")  
                endif()  
            endif()  
        endforeach()  
    endif()  
endforeach()  