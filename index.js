var iopi = require("./build/Release/iopi.node");
iopi.init(0x21);
iopi.setPinDirection(0x21, 1, 0x00);
iopi.writePin(0x21, 1, 1);
setTimeout(() => {
  iopi.writePin(0x21, 1, 0);
}, 5000);
