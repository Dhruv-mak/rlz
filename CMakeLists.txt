cmake_minimum_required (VERSION 3.14)

project (RLZ LANGUAGES CXX VERSION 1.0.0)

set (seqan3_git_tag "3.3.0")

message (STATUS "Fetching SeqAn3 ${seqan3_git_tag}:")

include (FetchContent)
FetchContent_Declare (
    seqan3_fetch_content
    GIT_REPOSITORY "https://github.com/seqan/seqan3.git"
    GIT_TAG "${seqan3_git_tag}"
)

# Download and make SeqAn3 available.
FetchContent_MakeAvailable (seqan3_fetch_content)

# Include both main.cpp and rlz.cpp in the executable.
add_executable (rlz src/main.cpp src/rlz.cpp)
# add_executable (rlz src/main.cpp )

# Set up everything needed to use SeqAn3 and sharg with rlz:
target_link_libraries (rlz PUBLIC seqan3::seqan3)

