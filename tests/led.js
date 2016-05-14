var iopi = require("../index");
var sleep = require("sleep").sleep;
var usleep = require("sleep").usleep;
iopi.init(bus);

var led=new LED(0x27,{red:1,green:2,blue:3});
process.on('SIGINT', function(){
  led.closeChannel("red");
  led.closeChannel("green");
  led.closeChannel("blue");
}.bind(null, {exit:true}));

while(true){
  led.openChannel("red");
  led.closeChannel("red");
  sleep(3);
  led.openChannel("green");
  led.closeChannel("green");
  sleep(3);
  led.openChannel("blue");
  led.closeChannel("blue");
  sleep(3);
}
// iopi.setPinDirection(0x27, 1, 0x00);
// iopi.writePin(0x27, 1, 1);
// iopi.setPinDirection(0x27, 2, 0x00);
// iopi.writePin(0x27, 2, 1);
// setTimeout(() => {
//   iopi.writePin(0x27, 1, 0);
//   iopi.writePin(0x27, 2, 0);
// }, 500);
