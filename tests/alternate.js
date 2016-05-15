var Timer = require("nanotimer");
var LED = require("./led");
var leds=[
  new LED(0x20,{red:1}),
  new LED(0x20,{red:2}),
  new LED(0x20,{red:3}),
  new LED(0x20,{red:4}),
  new LED(0x20,{red:5}),
  new LED(0x20,{red:6}),
  new LED(0x20,{red:7}),
  new LED(0x20,{red:8}),
];
process.on('SIGINT', function(){
  for(let x in leds){
    leds[x].close();
  }
  process.exit();
}.bind(null, {exit:true}));
var timer=new Timer();
var at=0;
var previous=at;
var loop=function(){
  previous=at;
  at++;
  if(at>=leds.length){
    at=0;
  }
  leds[previous].close();
  leds[at].open();
  timer.setTimeout(loop,'','1s');
};
timer.setTimeout(loop,'','1s');
