{
  "variables":{
    "arch%":"x86_64",
    "lib%":"lib/x86_64"
  },
  "target_defaults":{
    "defines":[

    ],
    "cflags": [
      "-std=c++11",
      "-w",
    #   "-fPIC"
    ],
    "cflags_cc": [
      "-std=c++11",
      "-w",
    #   "-fPIC"
    ],
    "ldflags": [
      "-std=c++11",
      "-w",
      "-Wl,-rpath='$$ORIGIN/../../lib/x86_64/'",
    #   "-fPIC"
    ],
    "include_dirs":[
      "includes",
      "<!(node -e \"require('nan')\")",
    ],
  },
  "targets":[
    {
      "target_name":"iopi",
      "sources":["src/main.cpp"],
      "libraries":[
        # "../<(lib)/libname.so",
      ]
    }
  ]
}
