var LED = require("./led");
var Button = require("./button");
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
var at=0;
var previous=at;
var next=function(){
  leds[previous].close();
  leds[at].open();
  previous=at;
  at++;
  if(at>=leds.length){
    at=0;
  }
};
var button=new Button(0x21,1,next);
