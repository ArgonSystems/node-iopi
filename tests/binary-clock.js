var Timer = require("nanotimer");
var LED = require("./led");
var leds=[
  new LED(0x26,{red:1}),
  new LED(0x26,{red:2}),
  new LED(0x26,{red:3}),
  new LED(0x26,{red:4}),
  new LED(0x26,{red:5}),
  new LED(0x26,{red:6}),
  new LED(0x26,{red:7}),
  new LED(0x26,{red:8}),
];
process.on('SIGINT', function(){
  for(let x in leds){
    leds[x].close();
  }
  process.exit();
}.bind(null, {exit:true}));
var timer=new Timer();
var second=0;
var loop=function(){
  if(second<255){
    second++;
  }
  var bits=(second >>> 0).toString(2);
  console.log(bits);
  for(let x=leds.length-bits.length;x>leds.length;x++){
    if(bits[x]=="1"){
      leds[x].open();
    }else{
      leds[x].close();
    }
  }
  timer.setTimeout(loop,'','1s');
};
timer.setTimeout(loop,'','1s');
