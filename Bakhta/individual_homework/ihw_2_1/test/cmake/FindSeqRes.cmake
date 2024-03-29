# The places to look for the tinyxml2 folders
set(FIND_SEQRES_PATHS
        ~/Documents/Frameworks/seqres
        )

# The location of the include folder (and thus the header files)
# find_path uses the paths we defined above as places to look
# Saves the location of the header files in a variable called TINYXML2_INCLUDE_DIR
find_path(SEQRES_INCLUDE_DIR seqres.h   # The variable to store the path in and the name of the header files
        PATH_SUFFIXES include               # The folder name containing the header files
        PATHS ${FIND_SEQRES_PATHS})       # Where to look (defined above)

# The location of the lib folder (and thus the .a file)
# find_library uses the paths we defined above as places to look
# Saves the location of the .a file in a variable called TINYXML2_LIBRARY
find_library(SEQRES_LIBRARY               # The variable to store where it found the .a files
        NAMES seqres                      # The name of the .a file (without the extension and without the 'lib')
        PATH_SUFFIXES lib                   # The folder the .a file is in
        PATHS ${FIND_SEQRES_PATHS})               # Where to look (defined above)