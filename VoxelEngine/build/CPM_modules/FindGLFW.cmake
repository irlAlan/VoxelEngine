include("/home/irlalan/secret/Cpp/VoxelEngine/VoxelEngine/build/cmake/CPM_0.40.0.cmake")
CPMAddPackage("NAME;GLFW;GITHUB_REPOSITORY;glfw/glfw;GIT_TAG;3.3.2;OPTIONS;GLFW_BUILD_TESTS OFF;GLFW_BUILD_EXAMPLES OFF;GLFW_BULID_DOCS OFF")
set(GLFW_FOUND TRUE)