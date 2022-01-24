file(REMOVE_RECURSE
  "libvector.pdb"
  "libvector.so"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/vector-shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
