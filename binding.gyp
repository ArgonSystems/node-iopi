{
  "variables":{
    "arch%":"x86_64",
    "lib%":"lib"
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
      "-Wl,-rpath='$$ORIGIN/../../lib/'",
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
        # "../<(lib)/ABElectronics_C_Libraries/IOPi/ABE_IoPi.so",
      ]
    }
  ]
}
