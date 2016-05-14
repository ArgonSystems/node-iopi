{
  "variables":{
    "arch%":"x86_64",
    "lib%":"lib",
    "ABE%":"lib/ABElectronics_C_Libraries/IOPi"
  },
  "target_defaults":{
    "defines":[

    ],
    "cflags": [
      "-std=c++11",
      "-w"
    ],
    "cflags_cc": [
      "-std=c++11",
      "-w"
    ],
    "ldflags": [
      "-std=c++11",
      "-w",
      "-Wl,-rpath='$$ORIGIN/../../lib/'"
    ],
    "include_dirs":[
      "<!(node -e \"require('nan')\")",
      "<(ABE)"
    ],
  },
  "targets":[
    {
      "target_name":"iopi",
      "sources":["<(ABE)/ABE_helpers.c", "<(ABE)/ABE_IoPi.c", "src/main.cpp"],
      "libraries":[
        # "../<(lib)/ABElectronics_C_Libraries/IOPi/ABE_IoPi.so",
      ]
    }
  ]
}
