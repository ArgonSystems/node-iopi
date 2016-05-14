var Timer = require("nanotimer");
var LED = require("./led");
var usleep = require("sleep").usleep;
var led=new LED(0x27,{red:1,green:2,blue:3});
process.on('SIGINT', function(){
  led.close();
  process.exit();
}.bind(null, {exit:true}));
var timer=new Timer();
var loop=function(){
  led.openChannel("red");
  usleep(1000);
  led.closeChannel("red");
  led.openChannel("green");
  usleep(1000);
  led.closeChannel("green");
  led.openChannel("blue");
  usleep(1000);
  led.closeChannel("blue");
  timer.setTimeout(loop,'','100u');
};
timer.setTimeout(loop,'','100u');
